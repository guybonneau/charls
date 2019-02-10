#pragma once

#include "charls.h"

#include <cstddef>
#include <vector>

// WARNING: THESE CLASSES ARE NOT FINAL AND THEIR DESIGN AND API MAY CHANGE

namespace charls
{
struct metadata_info_t
{
    int32_t width;
    int32_t height;
    int32_t bits_per_sample;
    int32_t component_count;
};


class jpegls_decoder final
{
public:
    void source_buffer(const void* source, const size_t source_size_bytes) const
    {
        const std::error_code ec = charls_jpegls_decoder_source_buffer(decoder_.get(), source, source_size_bytes);
        if (ec)
            throw jpegls_error(ec);
    }

    void read_header() const
    {
        const std::error_code ec = charls_jpegls_decoder_read_header(decoder_.get());
        if (ec)
            throw jpegls_error(ec);
    }

    void read_header(const void* source, const size_t source_size_bytes, std::error_code& error) noexcept
    {
        error = JpegLsReadHeader(source, source_size_bytes, &params_, nullptr);
        if (error)
            return;

        source_ = source;
        source_size_bytes_ = source_size_bytes;
        metadata_ = {params_.width, params_.height, params_.bitsPerSample, params_.components};
    }

    const metadata_info_t& metadata_info() const noexcept
    {
        return metadata_;
    }

    void decode(void* destination, const size_t destination_size_bytes) const
    {
        std::error_code error;
        decode(destination, destination_size_bytes, error);
        if (error)
            throw jpegls_error(error);
    }

    void decode(void* destination, const size_t destination_size_bytes, std::error_code& error) const noexcept
    {
        error = JpegLsDecode(destination, destination_size_bytes, source_, source_size_bytes_, &params_, nullptr);
    }

    size_t required_size() const noexcept
    {
        return static_cast<size_t>(params_.width) * params_.height * params_.components * (params_.bitsPerSample <= 8 ? 1 : 2);
    }

private:
    static charls_jpegls_decoder* create_decoder()
    {
        charls_jpegls_decoder* decoder = charls_jpegls_decoder_create();
        if (!decoder)
            throw std::bad_alloc();

        return decoder;
    }

    std::unique_ptr<charls_jpegls_decoder, void (*)(charls_jpegls_decoder*)> decoder_{create_decoder(), charls_jpegls_decoder_destroy};
    const void* source_{};
    size_t source_size_bytes_{};
    JlsParameters params_{};
    metadata_info_t metadata_{};
};

} // namespace charls
