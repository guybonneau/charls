// Copyright (c) Team CharLS. All rights reserved. See the accompanying "LICENSE.md" for licensed use.

#include <charls/charls.h>
#include <charls/jpegls_error.h>

#include "jpeg_stream_writer.h"
#include "jpegls_preset_coding_parameters.h"
#include "util.h"

#include <new>

using namespace charls;

struct charls_jpegls_encoder
{
    charls_jpegls_encoder(uint8_t* buffer, size_t size) noexcept
        : writer_{ByteStreamInfo{nullptr, buffer, size}}
    {
    }

    void write_spiff_header(const charls_spiff_header& spiff_header)
    {
        if (state_ != state::initial)
            throw jpegls_error{jpegls_errc::invalid_operation};

        writer_.WriteSpiffHeaderSegment(spiff_header);
        state_ = state::spiff_header;
    }

    void write_spiff_entry(int32_t entry_tag, const void* entry_data, size_t entry_data_size)
    {
        if (state_ != state::spiff_header)
            throw jpegls_error{jpegls_errc::invalid_operation};

        writer_.WriteSpiffDirectoryEntry(entry_tag, entry_data, entry_data_size);
    }

    void encode()
    {
        if (width < 1 || width > maximum_width)
            throw jpegls_error{jpegls_errc::invalid_argument_width};

        if (height < 1 || height > maximum_height)
            throw jpegls_error{jpegls_errc::invalid_argument_height};

        if (state_ == state::spiff_header)
        {
            writer_.WriteSpiffEndOfDirectoryEntry();
        }
        else
        {
            writer_.WriteStartOfImage();
        }

        writer_.WriteStartOfFrameSegment(width, height, bits_per_sample, component_count);

        if (color_transformation != ColorTransformation::None)
        {
            writer_.WriteColorTransformSegment(color_transformation);
        }

        if (!IsDefault(custom_preset_coding_parameters))
        {
            writer_.WriteJpegLSPresetParametersSegment(custom_preset_coding_parameters);
        }
        else if (bits_per_sample > 12)
        {
            const JpegLSPresetCodingParameters preset = ComputeDefault((1 << bits_per_sample) - 1, near_lossless);
            writer_.WriteJpegLSPresetParametersSegment(preset);
        }
    }

    int32_t width{};
    int32_t height{};
    int32_t bits_per_sample{};
    int32_t component_count{};
    int32_t near_lossless{};
    ColorTransformation color_transformation;
    JpegLSPresetCodingParameters custom_preset_coding_parameters{};

    const void* source{};
    size_t source_size{};
    void* destination_buffer{};
    size_t destination_size{};

    enum class state
    {
        initial,
        spiff_header,
        completed,
    };

    state state_{};
    JpegStreamWriter writer_;
};

extern "C"
{
    charls_jpegls_encoder* CHARLS_API_CALLING_CONVENTION
    charls_jpegls_encoder_create_buffer(void* destination_buffer, size_t size)
    {
        MSVC_WARNING_SUPPRESS(26402 26409) // don't use new and delete + scoped object and move
        return new (std::nothrow) charls_jpegls_encoder{static_cast<uint8_t*>(destination_buffer), size};
        MSVC_WARNING_UNSUPPRESS()
    }

    void CHARLS_API_CALLING_CONVENTION
    charls_jpegls_encoder_destroy(charls_jpegls_encoder* encoder)
    {
        MSVC_WARNING_SUPPRESS(26401 26409) // don't use new and delete + non-owner.
        delete encoder;
        MSVC_WARNING_UNSUPPRESS()
    }

    void CHARLS_API_CALLING_CONVENTION
    charls_jpegls_encoder_destination_buffer(charls_jpegls_encoder* encoder, void* buffer, size_t size)
    {
        encoder->destination_buffer = buffer;
        encoder->destination_size = size;
    }

    void CHARLS_API_CALLING_CONVENTION
    charls_jpegls_encoder_size(charls_jpegls_encoder* encoder, int32_t width, int32_t height)
    {
        encoder->width = width;
        encoder->height = height;
    }

    jpegls_errc CHARLS_API_CALLING_CONVENTION
    charls_jpegls_encoder_encode_from_buffer(charls_jpegls_encoder* encoder, const void* source, size_t source_size)
    {
        try
        {
            encoder->source = source;
            encoder->source_size = source_size;
            encoder->encode();
            return jpegls_errc::success;
        }
        catch (...)
        {
            return to_jpegls_errc();
        }
    }

    charls_jpegls_errc CHARLS_API_CALLING_CONVENTION
    charls_jpegls_encoder_write_spiff_header(charls_jpegls_encoder* encoder, const charls_spiff_header* spiff_header)
    {
        try
        {
            if (!encoder || !spiff_header)
                return jpegls_errc::invalid_argument;

            encoder->write_spiff_header(*spiff_header);
            return jpegls_errc::success;
        }
        catch (...)
        {
            return to_jpegls_errc();
        }
    }

    charls_jpegls_errc CHARLS_API_CALLING_CONVENTION
    charls_jpegls_encoder_write_spiff_entry(charls_jpegls_encoder* encoder, int32_t entry_tag, const void* entry_data, size_t entry_data_size)
    {
        try
        {
            if (!encoder || !entry_data)
                return jpegls_errc::invalid_argument;

            if (entry_data_size > 65528)
                return jpegls_errc::invalid_argument_spiff_entry_size;

            encoder->write_spiff_entry(entry_tag, entry_data, entry_data_size);
            return jpegls_errc::success;
        }
        catch (...)
        {
            return to_jpegls_errc();
        }
    }
}
