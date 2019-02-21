// Copyright (c) Team CharLS. All rights reserved. See the accompanying "LICENSE.md" for licensed use.

#pragma once

#include <charls/public_types.h>

#include <cstdint>
#include <vector>

namespace charls
{
enum class JpegMarkerCode : uint8_t;

// Purpose: minimal implementation to read a JPEG byte stream.
class JpegStreamReader final
{
public:
    explicit JpegStreamReader(ByteStreamInfo byteStreamInfo) noexcept;

    const JlsParameters& GetMetadata() const noexcept
    {
        return params_;
    }

    const JpegLSPresetCodingParameters& GetCustomPreset() const noexcept
    {
        return params_.custom;
    }

    void Read(ByteStreamInfo rawPixels);
    void ReadHeader(spiff_header* spiff_header = nullptr, bool* spiff_header_found = nullptr);

    void SetInfo(const JlsParameters& params) noexcept
    {
        params_ = params;
    }

    void SetRect(const JlsRect& rect) noexcept
    {
        rect_ = rect;
    }

    void ReadStartOfScan(bool firstComponent);
    uint8_t ReadByte();

private:
    void SkipByte();
    int ReadUInt16();
    int32_t ReadInt32();
    int32_t ReadSegmentSize();
    void ReadNBytes(std::vector<char>& destination, int byteCount);
    JpegMarkerCode ReadNextMarkerCode();
    void ValidateMarkerCode(JpegMarkerCode markerCode) const;

    int ReadMarkerSegment(JpegMarkerCode markerCode, int32_t segmentSize, spiff_header* spiff_header, bool* spiff_header_found);
    int ReadStartOfFrameSegment(int32_t segmentSize);
    static int ReadComment() noexcept;
    int ReadPresetParametersSegment(int32_t segmentSize);
    void ReadJfif();
    int TryReadApplicationData8Segment(int32_t segmentSize, spiff_header* spiff_header, bool* spiff_header_found);
    int TryReadSpiffHeaderSegment(spiff_header* spiff_header, bool& spiff_header_found);

    int TryReadHPColorTransformSegment();
    void AddComponent(uint8_t componentId);

    enum class state
    {
        created,
        header_section,
        spiff_header_section,
        image_section,
        frame_section,
        scan_section
    };

    ByteStreamInfo byteStream_;
    JlsParameters params_{};
    JlsRect rect_{};
    std::vector<uint8_t> componentIds_;
    state state_{};
};

} // namespace charls
