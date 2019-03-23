// Copyright (c) Team CharLS. All rights reserved. See the accompanying "LICENSE.md" for licensed use.

#pragma once

#ifdef __cplusplus
namespace charls
{
namespace impl
{
#endif

// The following enum values are for C applications, for C++ the enum are defined after these definitions.
// For the documentation, see the C++ enum definitions.

enum CharlsApiResult
{
    CHARLS_API_RESULT_SUCCESS = 0,
    CHARLS_API_RESULT_INVALID_ARGUMENT = 1,
    CHARLS_API_RESULT_PARAMETER_VALUE_NOT_SUPPORTED = 2,
    CHARLS_API_RESULT_DESTINATION_BUFFER_TOO_SMALL = 3,
    CHARLS_API_RESULT_SOURCE_BUFFER_TOO_SMALL = 4,
    CHARLS_API_RESULT_INVALID_ENCODED_DATA = 5,
    CHARLS_API_RESULT_TOO_MUCH_ENCODED_DATA = 6,
    CHARLS_API_RESULT_INVALID_OPERATION = 7,
    CHARLS_API_RESULT_BIT_DEPTH_FOR_TRANSFORM_NOT_SUPPORTED = 8,
    CHARLS_API_RESULT_COLOR_TRANSFORM_NOT_SUPPORTED = 9,
    CHARLS_API_RESULT_ENCODING_NOT_SUPPORTED = 10,
    CHARLS_API_RESULT_UNKNOWN_JPEG_MARKER_FOUND = 11,
    CHARLS_API_RESULT_JPEG_MARKER_START_BYTE_NOT_FOUND = 12,
    CHARLS_API_RESULT_NOT_ENOUGH_MEMORY = 13,
    CHARLS_API_RESULT_UNEXPECTED_FAILURE = 14,
    CHARLS_API_RESULT_START_OF_IMAGE_MARKER_NOT_FOUND = 15,
    CHARLS_API_RESULT_START_OF_FRAME_MARKER_NOT_FOUND = 16,
    CHARLS_API_RESULT_INVALID_MARKER_SEGMENT_SIZE = 17,
    CHARLS_API_RESULT_DUPLICATE_START_OF_IMAGE_MARKER = 18,
    CHARLS_API_RESULT_DUPLICATE_START_OF_FRAME_MARKER = 19,
    CHARLS_API_RESULT_DUPLICATE_COMPONENT_ID_IN_SOF_SEGMENT = 20,
    CHARLS_API_RESULT_UNEXPECTED_END_OF_IMAGE_MARKER = 21,
    CHARLS_API_RESULT_INVALID_JPEGLS_PRESET_PARAMETER_TYPE = 22,
    CHARLS_API_RESULT_JPEGLS_PRESET_EXTENDED_PARAMETER_TYPE_NOT_SUPPORTED = 23,
    CHARLS_API_RESULT_INVALID_ARGUMENT_WIDTH = 100,
    CHARLS_API_RESULT_INVALID_ARGUMENT_HEIGHT = 101,
    CHARLS_API_RESULT_INVALID_ARGUMENT_COMPONENT_COUNT = 102,
    CHARLS_API_RESULT_INVALID_ARGUMENT_BITS_PER_SAMPLE = 103,
    CHARLS_API_RESULT_INVALID_ARGUMENT_INTERLEAVE_MODE = 104,
    CHARLS_API_RESULT_INVALID_ARGUMENT_DESTINATION = 105,
    CHARLS_API_RESULT_INVALID_ARGUMENT_SOURCE = 106,
    CHARLS_API_RESULT_INVALID_ARGUMENT_THUMBNAIL = 107,
    CHARLS_API_RESULT_INVALID_ARGUMENT_SPIFF_ENTRY_SIZE = 108,
    CHARLS_API_RESULT_INVALID_PARAMETER_WIDTH = 200,
    CHARLS_API_RESULT_INVALID_PARAMETER_HEIGHT = 201,
    CHARLS_API_RESULT_INVALID_PARAMETER_COMPONENT_COUNT = 202,
    CHARLS_API_RESULT_INVALID_PARAMETER_BITS_PER_SAMPLE = 203,
    CHARLS_API_RESULT_INVALID_PARAMETER_INTERLEAVE_MODE = 204,
};

enum CharlsInterleaveMode
{
    CHARLS_INTERLEAVE_MODE_NONE = 0,
    CHARLS_INTERLEAVE_MODE_LINE = 1,
    CHARLS_INTERLEAVE_MODE_SAMPLE = 2
};

enum CharlsColorTransformation
{
    CHARLS_COLOR_TRANSFORMATION_NONE = 0,
    CHARLS_COLOR_TRANSFORMATION_HP1 = 1,
    CHARLS_COLOR_TRANSFORMATION_HP2 = 2,
    CHARLS_COLOR_TRANSFORMATION_HP3 = 3,
};

typedef enum charls_spiff_profile_id
{
    CHARLS_SPIFF_PROFILE_ID_NONE = 0,
    CHARLS_SPIFF_PROFILE_ID_CONTINUOUS_TONE_BASE = 1,
    CHARLS_SPIFF_PROFILE_ID_CONTINUOUS_TONE_PROGRESSIVE = 2,
    CHARLS_SPIFF_PROFILE_ID_BI_LEVEL_FACSIMILE = 3,
    CHARLS_SPIFF_PROFILE_ID_CONTINUOUS_TONE_FACSIMILE = 4
} charls_spiff_profile_id;

typedef enum charls_spiff_color_space
{
    CHARLS_SPIFF_COLOR_SPACE_BI_LEVEL = 0,
    CHARLS_SPIFF_COLOR_SPACE_YCBCR_ITU_BT_709_VIDEO = 1,
    CHARLS_SPIFF_COLOR_SPACE_NONE = 2,
    CHARLS_SPIFF_COLOR_SPACE_YCBCR_ITU_BT_601_1_RGB = 3,
    CHARLS_SPIFF_COLOR_SPACE_YCBCR_ITU_BT_601_1_VIDEO = 4,
    CHARLS_SPIFF_COLOR_SPACE_GRAYSCALE = 8,
    CHARLS_SPIFF_COLOR_SPACE_PHOTO_YCC = 9,
    CHARLS_SPIFF_COLOR_SPACE_RGB = 10,
    CHARLS_SPIFF_COLOR_SPACE_CMY = 11,
    CHARLS_SPIFF_COLOR_SPACE_CMYK = 12,
    CHARLS_SPIFF_COLOR_SPACE_YCCK = 13,
    CHARLS_SPIFF_COLOR_SPACE_CIE_LAB = 14
} charls_spiff_color_space;

typedef enum charls_spiff_compression_type
{
    CHARLS_SPIFF_COMPRESSION_TYPE_UNCOMPRESSED = 0,
    CHARLS_SPIFF_COMPRESSION_TYPE_MODIFIED_HUFFMAN = 1,
    CHARLS_SPIFF_COMPRESSION_TYPE_MODIFIED_READ = 2,
    CHARLS_SPIFF_COMPRESSION_TYPE_MODIFIED_MODIFIED_READ = 3,
    CHARLS_SPIFF_COMPRESSION_TYPE_JBIG = 4,
    CHARLS_SPIFF_COMPRESSION_TYPE_JPEG = 5,
    CHARLS_SPIFF_COMPRESSION_TYPE_JPEG_LS = 6
} charls_spiff_compression_type;

typedef enum charls_spiff_resolution_units
{
    CHARLS_SPIFF_RESOLUTION_UNITS_ASPECT_RATIO = 0,
    CHARLS_SPIFF_RESOLUTION_UNITS_DOTS_PER_INCH = 1,
    CHARLS_SPIFF_RESOLUTION_UNITS_DOTS_PER_CENTIMETER = 2
} charls_spiff_resolution_units;

typedef enum charls_spiff_entry_tag
{
    CHARLS_SPIFF_ENTRY_TAG_TRANSFER_CHARACTERISTICS = 2,
    CHARLS_SPIFF_ENTRY_TAG_COMPONENT_REGISTRATION = 3,
    CHARLS_SPIFF_ENTRY_TAG_IMAGE_ORIENTATION = 4,
    CHARLS_SPIFF_ENTRY_TAG_THUMBNAIL = 5,
    CHARLS_SPIFF_ENTRY_TAG_IMAGE_TITLE = 6,
    CHARLS_SPIFF_ENTRY_TAG_IMAGE_DESCRIPTION = 7,
    CHARLS_SPIFF_ENTRY_TAG_TIME_STAMP = 8,
    CHARLS_SPIFF_ENTRY_TAG_VERSION_IDENTIFIER = 9,
    CHARLS_SPIFF_ENTRY_TAG_CREATOR_IDENTIFICATION = 10,
    CHARLS_SPIFF_ENTRY_TAG_PROTECTION_INDICATOR = 11,
    CHARLS_SPIFF_ENTRY_TAG_COPYRIGHT_INFORMATION = 12,
    CHARLS_SPIFF_ENTRY_TAG_CONTACT_INFORMATION = 13,
    CHARLS_SPIFF_ENTRY_TAG_TILE_INDEX = 14,
    CHARLS_SPIFF_ENTRY_TAG_SCAN_INDEX = 15,
    CHARLS_SPIFF_ENTRY_TAG_SET_REFERENCE = 16
} charls_spiff_entry_tag;

#ifdef __cplusplus
}
}
#endif


#ifdef __cplusplus

#include <cstddef>
#include <cstdint>
#include <system_error>


// GCC 5.0 cannot handle [[deprecated]] on enum values
#if defined(__GNUC__) && !defined(__clang__)
#define CHARLS_ENUM_DEPRECATED
#else
#define CHARLS_ENUM_DEPRECATED [[deprecated]]
#endif


namespace charls
{
/// <summary>
/// Defines the result values that are returned by the CharLS API functions.
/// </summary>
enum class jpegls_errc
{
    /// <summary>
    /// The operation completed without errors.
    /// </summary>
    success = impl::CHARLS_API_RESULT_SUCCESS,

    /// <summary>
    /// This error is returned when one of the arguments is invalid and no specific reason is available.
    /// </summary>
    invalid_argument = impl::CHARLS_API_RESULT_INVALID_ARGUMENT,

    /// <summary>
    /// This error is returned when the JPEG stream contains a parameter value that is not supported by this implementation.
    /// </summary>
    parameter_value_not_supported = impl::CHARLS_API_RESULT_PARAMETER_VALUE_NOT_SUPPORTED,

    /// <summary>
    /// The destination buffer is too small to hold all the output.
    /// </summary>
    destination_buffer_too_small = impl::CHARLS_API_RESULT_DESTINATION_BUFFER_TOO_SMALL,

    /// <summary>
    /// The source buffer is too small, more input data was expected.
    /// </summary>
    source_buffer_too_small = impl::CHARLS_API_RESULT_SOURCE_BUFFER_TOO_SMALL,

    /// <summary>
    /// This error is returned when the encoded bit stream contains a general structural problem.
    /// </summary>
    invalid_encoded_data = impl::CHARLS_API_RESULT_INVALID_ENCODED_DATA,

    /// <summary>
    /// Too much compressed data.The decoding process is ready but the input buffer still contains encoded data.
    /// </summary>
    too_much_encoded_data = impl::CHARLS_API_RESULT_TOO_MUCH_ENCODED_DATA,

    /// <summary>
    /// This error is returned when a method call is invalid for the current state.
    /// </summary>
    invalid_operation = impl::CHARLS_API_RESULT_INVALID_OPERATION,

    /// <summary>
    /// The bit depth for transformation is not supported.
    /// </summary>
    bit_depth_for_transform_not_supported = impl::CHARLS_API_RESULT_BIT_DEPTH_FOR_TRANSFORM_NOT_SUPPORTED,

    /// <summary>
    /// The color transform is not supported.
    /// </summary>
    color_transform_not_supported = impl::CHARLS_API_RESULT_COLOR_TRANSFORM_NOT_SUPPORTED,

    /// <summary>
    /// This error is returned when an encoded frame is found that is not encoded with the JPEG-LS algorithm.
    /// </summary>
    encoding_not_supported = impl::CHARLS_API_RESULT_ENCODING_NOT_SUPPORTED,

    /// <summary>
    /// This error is returned when an unknown JPEG marker code is found in the encoded bit stream.
    /// </summary>
    unknown_jpeg_marker_found = impl::CHARLS_API_RESULT_UNKNOWN_JPEG_MARKER_FOUND,

    /// <summary>
    /// This error is returned when the algorithm expect a 0xFF code (indicates start of a JPEG marker) but none was found.
    /// </summary>
    jpeg_marker_start_byte_not_found = impl::CHARLS_API_RESULT_JPEG_MARKER_START_BYTE_NOT_FOUND,

    /// <summary>
    /// This error is returned when the implementation could not allocate memory for its internal buffers.
    /// </summary>
    not_enough_memory = impl::CHARLS_API_RESULT_NOT_ENOUGH_MEMORY,

    /// <summary>
    /// This error is returned when the implementation encountered a failure it did not expect. No guarantees can be given for the state after this error.
    /// </summary>
    unexpected_failure = impl::CHARLS_API_RESULT_UNEXPECTED_FAILURE,

    /// <summary>
    /// This error is returned when the first JPEG marker is not the SOI marker.
    /// </summary>
    start_of_image_marker_not_found = impl::CHARLS_API_RESULT_START_OF_IMAGE_MARKER_NOT_FOUND,

    /// <summary>
    /// This error is returned when the SOF JPEG marker is not found before the SOS marker.
    /// </summary>
    start_of_frame_marker_not_found = impl::CHARLS_API_RESULT_START_OF_FRAME_MARKER_NOT_FOUND,

    /// <summary>
    /// This error is returned when the segment size of a marker segment is invalid.
    /// </summary>
    invalid_marker_segment_size = impl::CHARLS_API_RESULT_INVALID_MARKER_SEGMENT_SIZE,

    /// <summary>
    /// This error is returned when the stream contains more then one SOI marker.
    /// </summary>
    duplicate_start_of_image_marker = impl::CHARLS_API_RESULT_DUPLICATE_START_OF_IMAGE_MARKER,

    /// <summary>
    /// This error is returned when the stream contains more then one SOF marker.
    /// </summary>
    duplicate_start_of_frame_marker = impl::CHARLS_API_RESULT_DUPLICATE_START_OF_FRAME_MARKER,

    /// <summary>
    /// This error is returned when the stream contains duplicate component identifiers in the SOF segment.
    /// </summary>
    duplicate_component_id_in_sof_segment = impl::CHARLS_API_RESULT_DUPLICATE_COMPONENT_ID_IN_SOF_SEGMENT,

    /// <summary>
    /// This error is returned when the stream contains an unexpected EOI marker.
    /// </summary>
    unexpected_end_of_image_marker = impl::CHARLS_API_RESULT_UNEXPECTED_END_OF_IMAGE_MARKER,

    /// <summary>
    /// This error is returned when the stream contains an invalid type parameter in the JPEG-LS segment.
    /// </summary>
    invalid_jpegls_preset_parameter_type = impl::CHARLS_API_RESULT_INVALID_JPEGLS_PRESET_PARAMETER_TYPE,

    /// <summary>
    /// This error is returned when the stream contains an unsupported type parameter in the JPEG-LS segment.
    /// </summary>
    jpegls_preset_extended_parameter_type_not_supported = impl::CHARLS_API_RESULT_JPEGLS_PRESET_EXTENDED_PARAMETER_TYPE_NOT_SUPPORTED,

    /// <summary>
    /// The argument for the width parameter is outside the range [1, 65535].
    /// </summary>
    invalid_argument_width = impl::CHARLS_API_RESULT_INVALID_ARGUMENT_WIDTH,

    /// <summary>
    /// The argument for the height parameter is outside the range [1, 65535].
    /// </summary>
    invalid_argument_height = impl::CHARLS_API_RESULT_INVALID_ARGUMENT_HEIGHT,

    /// <summary>
    /// The argument for the component count parameter is outside the range [1, 255].
    /// </summary>
    invalid_argument_component_count = impl::CHARLS_API_RESULT_INVALID_ARGUMENT_COMPONENT_COUNT,

    /// <summary>
    /// The argument for the bit per sample parameter is outside the range [2, 16].
    /// </summary>
    invalid_argument_bits_per_sample = impl::CHARLS_API_RESULT_INVALID_ARGUMENT_BITS_PER_SAMPLE,

    /// <summary>
    /// The argument for the interleave mode is not (None, Sample, Line) or invalid in combination with component count.
    /// </summary>
    invalid_argument_interleave_mode = impl::CHARLS_API_RESULT_INVALID_ARGUMENT_INTERLEAVE_MODE,

    /// <summary>
    /// The destination buffer or stream is not set.
    /// </summary>
    invalid_argument_destination = impl::CHARLS_API_RESULT_INVALID_ARGUMENT_DESTINATION,

    /// <summary>
    /// The source buffer or stream is not set.
    /// </summary>
    invalid_argument_source = impl::CHARLS_API_RESULT_INVALID_ARGUMENT_SOURCE,

    /// <summary>
    /// The arguments for the thumbnail and the dimensions don't match.
    /// </summary>
    invalid_argument_thumbnail = impl::CHARLS_API_RESULT_INVALID_ARGUMENT_THUMBNAIL,

    /// <summary>
    /// The argument for the entry size parameter is outside the range [0, 65528].
    /// </summary>
    invalid_argument_spiff_entry_size = impl::CHARLS_API_RESULT_INVALID_ARGUMENT_SPIFF_ENTRY_SIZE,

    /// <summary>
    /// This error is returned when the stream contains a width parameter defined more then once or in an incompatible way.
    /// </summary>
    invalid_parameter_width = impl::CHARLS_API_RESULT_INVALID_PARAMETER_WIDTH,

    /// <summary>
    /// This error is returned when the stream contains a height parameter defined more then once in an incompatible way.
    /// </summary>
    invalid_parameter_height = impl::CHARLS_API_RESULT_INVALID_PARAMETER_HEIGHT,

    /// <summary>
    /// This error is returned when the stream contains a component count parameter outside the range [1,255]
    /// </summary>
    invalid_parameter_component_count = impl::CHARLS_API_RESULT_INVALID_PARAMETER_COMPONENT_COUNT,

    /// <summary>
    /// This error is returned when the stream contains a bits per sample (sample precision) parameter outside the range [2,16]
    /// </summary>
    invalid_parameter_bits_per_sample = impl::CHARLS_API_RESULT_INVALID_PARAMETER_BITS_PER_SAMPLE,

    /// <summary>
    /// This error is returned when the stream contains an interleave mode (ILV) parameter outside the range [0, 2]
    /// </summary>
    invalid_parameter_interleave_mode = impl::CHARLS_API_RESULT_INVALID_PARAMETER_INTERLEAVE_MODE,

    // Legacy enum names, will be removed in a future release.
    OK CHARLS_ENUM_DEPRECATED = success,
    InvalidJlsParameters CHARLS_ENUM_DEPRECATED = invalid_argument,
    ParameterValueNotSupported CHARLS_ENUM_DEPRECATED = invalid_encoded_data,
    UncompressedBufferTooSmall CHARLS_ENUM_DEPRECATED = destination_buffer_too_small,
    CompressedBufferTooSmall CHARLS_ENUM_DEPRECATED = source_buffer_too_small,
    InvalidCompressedData CHARLS_ENUM_DEPRECATED = invalid_encoded_data,
    TooMuchCompressedData CHARLS_ENUM_DEPRECATED = too_much_encoded_data,
    UnsupportedColorTransform CHARLS_ENUM_DEPRECATED = color_transform_not_supported,
    UnsupportedEncoding CHARLS_ENUM_DEPRECATED = encoding_not_supported,
    UnknownJpegMarker CHARLS_ENUM_DEPRECATED = unknown_jpeg_marker_found,
    MissingJpegMarkerStart CHARLS_ENUM_DEPRECATED = jpeg_marker_start_byte_not_found,
    UnexpectedFailure CHARLS_ENUM_DEPRECATED = unexpected_failure
};

[[deprecated]] typedef jpegls_errc ApiResult;

/// <summary>
/// Defines the interleave modes for multi-component (color) pixel data.
/// </summary>
enum class InterleaveMode
{
    /// <summary>
    /// The data is encoded and stored as component for component: RRRGGGBBB.
    /// </summary>
    None = impl::CHARLS_INTERLEAVE_MODE_NONE,

    /// <summary>
    /// The interleave mode is by line. A full line of each component is encoded before moving to the next line.
    /// </summary>
    Line = impl::CHARLS_INTERLEAVE_MODE_LINE,

    /// <summary>
    /// The data is encoded and stored by sample. For RGB color images this is the format like RGBRGBRGB.
    /// </summary>
    Sample = impl::CHARLS_INTERLEAVE_MODE_SAMPLE
};

/// <summary>
/// Defines color space transformations as defined and implemented by the JPEG-LS library of HP Labs.
/// These color space transformation decrease the correlation between the 3 color components, resulting in better encoding ratio.
/// These options are only implemented for backwards compatibility and NOT part of the JPEG-LS standard.
/// The JPEG-LS ISO/IEC 14495-1:1999 standard provides no capabilities to transport which color space transformation was used.
/// </summary>
enum class ColorTransformation
{
    /// <summary>
    /// No color space transformation has been applied.
    /// </summary>
    None = impl::CHARLS_COLOR_TRANSFORMATION_NONE,

    /// <summary>
    /// Defines the reversible lossless color transformation:
    /// G = G
    /// R = R - G
    /// B = B - G
    /// </summary>
    HP1 = impl::CHARLS_COLOR_TRANSFORMATION_HP1,

    /// <summary>
    /// Defines the reversible lossless color transformation:
    /// G = G
    /// B = B - (R + G) / 2
    /// R = R - G
    /// </summary>
    HP2 = impl::CHARLS_COLOR_TRANSFORMATION_HP2,

    /// <summary>
    /// Defines the reversible lossless color transformation of Y-Cb-Cr):
    /// R = R - G
    /// B = B - G
    /// G = G + (R + B) / 4
    /// </summary>
    HP3 = impl::CHARLS_COLOR_TRANSFORMATION_HP3,
};

enum class spiff_profile_id : uint8_t
{
    none = impl::CHARLS_SPIFF_PROFILE_ID_NONE,
    continuous_tone_base = impl::CHARLS_SPIFF_PROFILE_ID_CONTINUOUS_TONE_BASE,
    continuous_tone_progressive = impl::CHARLS_SPIFF_PROFILE_ID_CONTINUOUS_TONE_PROGRESSIVE,
    bi_level_facsimile = impl::CHARLS_SPIFF_PROFILE_ID_BI_LEVEL_FACSIMILE,
    continuous_tone_facsimile = impl::CHARLS_SPIFF_PROFILE_ID_CONTINUOUS_TONE_FACSIMILE
};

enum class spiff_color_space : uint8_t
{
    bi_level = impl::CHARLS_SPIFF_COLOR_SPACE_BI_LEVEL,
    ycbcr_itu_bt_709_video = impl::CHARLS_SPIFF_COLOR_SPACE_YCBCR_ITU_BT_709_VIDEO,
    none = impl::CHARLS_SPIFF_COLOR_SPACE_NONE,
    ycbcr_itu_bt_601_1_rgb = impl::CHARLS_SPIFF_COLOR_SPACE_YCBCR_ITU_BT_601_1_RGB,
    ycbcr_itu_bt_601_1_video = impl::CHARLS_SPIFF_COLOR_SPACE_YCBCR_ITU_BT_601_1_VIDEO,
    grayscale = impl::CHARLS_SPIFF_COLOR_SPACE_GRAYSCALE,
    photo_ycc = impl::CHARLS_SPIFF_COLOR_SPACE_PHOTO_YCC,
    rgb = impl::CHARLS_SPIFF_COLOR_SPACE_RGB,
    cmy = impl::CHARLS_SPIFF_COLOR_SPACE_CMY,
    cmyk = impl::CHARLS_SPIFF_COLOR_SPACE_CMYK,
    ycck = impl::CHARLS_SPIFF_COLOR_SPACE_YCCK,
    cie_lab = impl::CHARLS_SPIFF_COLOR_SPACE_CIE_LAB
};

enum class spiff_compression_type : uint8_t
{
    uncompressed = impl::CHARLS_SPIFF_COMPRESSION_TYPE_UNCOMPRESSED,
    modified_huffman = impl::CHARLS_SPIFF_COMPRESSION_TYPE_MODIFIED_HUFFMAN,
    modified_read = impl::CHARLS_SPIFF_COMPRESSION_TYPE_MODIFIED_READ,
    modified_modified_read = impl::CHARLS_SPIFF_COMPRESSION_TYPE_MODIFIED_MODIFIED_READ,
    jbig = impl::CHARLS_SPIFF_COMPRESSION_TYPE_JBIG,
    jpeg = impl::CHARLS_SPIFF_COMPRESSION_TYPE_JPEG,
    jpeg_ls = impl::CHARLS_SPIFF_COMPRESSION_TYPE_JPEG_LS
};

enum class spiff_resolution_units : uint8_t
{
    aspect_ratio = impl::CHARLS_SPIFF_RESOLUTION_UNITS_ASPECT_RATIO,
    dots_per_inch = impl::CHARLS_SPIFF_RESOLUTION_UNITS_DOTS_PER_INCH,
    dots_per_centimeter = impl::CHARLS_SPIFF_RESOLUTION_UNITS_DOTS_PER_CENTIMETER
};

// Official defined SPIFF tags defined in Table F.5 (ISO/IEC 10918-3)
enum class spiff_entry_tag : uint32_t
{
    transfer_characteristics = impl::CHARLS_SPIFF_ENTRY_TAG_TRANSFER_CHARACTERISTICS,
    component_registration = impl::CHARLS_SPIFF_ENTRY_TAG_COMPONENT_REGISTRATION,
    image_orientation = impl::CHARLS_SPIFF_ENTRY_TAG_IMAGE_ORIENTATION,
    thumbnail = impl::CHARLS_SPIFF_ENTRY_TAG_THUMBNAIL,
    image_title = impl::CHARLS_SPIFF_ENTRY_TAG_IMAGE_TITLE,
    image_description = impl::CHARLS_SPIFF_ENTRY_TAG_IMAGE_DESCRIPTION,
    time_stamp = impl::CHARLS_SPIFF_ENTRY_TAG_TIME_STAMP,
    version_identifier = impl::CHARLS_SPIFF_ENTRY_TAG_VERSION_IDENTIFIER,
    creator_identification = impl::CHARLS_SPIFF_ENTRY_TAG_CREATOR_IDENTIFICATION,
    protection_indicator = impl::CHARLS_SPIFF_ENTRY_TAG_PROTECTION_INDICATOR,
    copyright_information = impl::CHARLS_SPIFF_ENTRY_TAG_COPYRIGHT_INFORMATION,
    contact_information = impl::CHARLS_SPIFF_ENTRY_TAG_CONTACT_INFORMATION,
    tile_index = impl::CHARLS_SPIFF_ENTRY_TAG_TILE_INDEX,
    scan_index = impl::CHARLS_SPIFF_ENTRY_TAG_SCAN_INDEX,
    set_reference = impl::CHARLS_SPIFF_ENTRY_TAG_SET_REFERENCE
};


} // namespace charls

namespace std
{

template<>
struct is_error_code_enum<charls::jpegls_errc> final : true_type
{
};

} // namespace std

using charls_jpegls_errc = charls::jpegls_errc;

using CharlsApiResultType = charls::jpegls_errc;
using CharlsInterleaveModeType = charls::InterleaveMode;
using CharlsColorTransformationType = charls::ColorTransformation;

using charls_spiff_profile_id = charls::spiff_profile_id;
using charls_spiff_color_space = charls::spiff_color_space;
using charls_spiff_compression_type = charls::spiff_compression_type;
using charls_spiff_resolution_units = charls::spiff_resolution_units;
using charls_spiff_entry_tag = charls::spiff_entry_tag;

#else

#include <stdint.h>

typedef enum CharlsApiResult charls_jpegls_errc;
typedef enum CharlsApiResult CharlsApiResultType;
typedef enum CharlsInterleaveMode CharlsInterleaveModeType;
typedef enum CharlsColorTransformation CharlsColorTransformationType;

#endif


struct charls_spiff_header
{
    uint16_t version;                               // SPIFF version
    charls_spiff_profile_id profile_id;             // Application profile
    uint8_t component_count;                        // Number of color components
    int32_t height;                                 // Number of lines in image
    int32_t width;                                  // Number of samples per line
    charls_spiff_color_space color_space;           // Color space used by image data
    uint8_t bits_per_sample;                        // Number of bits per sample
    charls_spiff_compression_type compression_type; // Type of data compression used
    charls_spiff_resolution_units resolution_units; // Type of resolution units
    int32_t vertical_resolution;                    // Vertical resolution
    int32_t horizontal_resolution;                  // Horizontal resolution
};


typedef struct charls_frame_info
{
    int32_t width;
    int32_t height;
    int32_t bits_per_sample;
    int32_t component_count;
} charls_frame_info;


/// <summary>
/// Defines the JPEG-LS preset coding parameters as defined in ISO/IEC 14495-1, C.2.4.1.1.
/// JPEG-LS defines a default set of parameters, but custom parameters can be used.
/// When used these parameters are written into the encoded bit stream as they are needed for the decoding process.
/// </summary>
struct JpegLSPresetCodingParameters
{
    /// <summary>
    /// Maximum possible value for any image sample in a scan.
    /// This must be greater than or equal to the actual maximum value for the components in a scan.
    /// </summary>
    int32_t MaximumSampleValue;

    /// <summary>
    /// First quantization threshold value for the local gradients.
    /// </summary>
    int32_t Threshold1;

    /// <summary>
    /// Second quantization threshold value for the local gradients.
    /// </summary>
    int32_t Threshold2;

    /// <summary>
    /// Third quantization threshold value for the local gradients.
    /// </summary>
    int32_t Threshold3;

    /// <summary>
    /// Value at which the counters A, B, and N are halved.
    /// </summary>
    int32_t ResetValue;
};


struct JlsRect
{
    int32_t X;
    int32_t Y;
    int32_t Width;
    int32_t Height;
};


/// <summary>
/// Defines the parameters for the JPEG File Interchange Format.
/// The format is defined in the JPEG File Interchange Format v1.02 document by Eric Hamilton.
/// </summary>
/// <remarks>
/// The JPEG File Interchange Format is the de facto standard JPEG interchange format.
/// </remarks>
struct JfifParameters
{
    /// <summary>
    /// Version of the JPEG File Interchange Format.
    /// Should be set to zero to not write a JFIF header or to 1.02, encoded as: (1 * 256) + 2.
    /// </summary>
    int32_t version;

    /// <summary>
    /// Defines the units for the X and Y densities.
    /// 0: no units, X and Y specify the pixel aspect ratio.
    /// 1: X and Y are dots per inch.
    /// 2: X and Y are dots per cm.
    /// </summary>
    int32_t units;

    /// <summary>
    /// Horizontal pixel density
    /// </summary>
    int32_t Xdensity;

    /// <summary>
    /// Vertical pixel density
    /// </summary>
    int32_t Ydensity;

    /// <summary>
    /// Thumbnail horizontal pixel count.
    /// </summary>
    int32_t Xthumbnail;

    /// <summary>
    /// Thumbnail vertical pixel count.
    /// </summary>
    int32_t Ythumbnail;

    /// <summary>
    /// Reference to a buffer with thumbnail pixels of size Xthumbnail * Ythumbnail * 3(RGB).
    /// This parameter is only used when creating JPEG-LS encoded images.
    /// </summary>
    void* thumbnail;
};


struct JlsParameters
{
    /// <summary>
    /// Width of the image in pixels.
    /// This parameter is called "Number of samples per line" in the JPEG-LS standard.
    /// </summary>
    int32_t width;

    /// <summary>
    /// Height of the image in pixels.
    /// This parameter is called "Number of lines" in the JPEG-LS standard.
    /// </summary>
    int32_t height;

    /// <summary>
    /// The number of valid bits per sample to encode.
    /// Valid range 2 - 16. When greater than 8, pixels are assumed to stored as two bytes per sample, otherwise one byte per sample is assumed.
    /// This parameter is called "Sample precision" in the JPEG-LS standard, often also called "Bit Depth".
    /// </summary>
    int32_t bitsPerSample;

    /// <summary>
    /// The stride is the number of bytes from one row of pixels in memory to the next row of pixels in memory.
    /// Stride is sometimes called pitch. If padding bytes are present, the stride is wider than the width of the image.
    /// </summary>
    int32_t stride;

    /// <summary>
    /// The number of components.
    /// Typical 1 for monochrome images and 3 for color images or 4 if an alpha channel is present.
    /// Up to 255 components are supported by the JPEG-LS standard.
    /// </summary>
    int32_t components;

    /// <summary>
    /// Defines the allowed lossy error. Value 0 defines lossless.
    /// </summary>
    int32_t allowedLossyError;

    /// <summary>
    /// Determines the order of the color components in the compressed stream.
    /// </summary>
    CharlsInterleaveModeType interleaveMode;

    /// <summary>
    /// Color transformation used in the compressed stream. The color transformations are all lossless and
    /// are an HP proprietary extension of the standard. Do not use the color transformations unless
    /// you know the decoder is capable of decoding it. Color transform typically improve compression ratios only
    /// for synthetic images (non - photo-realistic computer generated images).
    /// </summary>
    CharlsColorTransformationType colorTransformation;

    /// <summary>
    /// If set to true RGB images will be decoded to BGR. BGR is the standard ordering in MS Windows bitmaps.
    /// </summary>
    char outputBgr;

    struct JpegLSPresetCodingParameters custom;
    struct JfifParameters jfif;
};


#ifdef __cplusplus

#include <iostream>


//
// ByteStreamInfo & FromByteArray helper function
//
// ByteStreamInfo describes the stream: either set rawStream to a valid stream, or rawData/count, not both.
// it's possible to decode to memory streams, but using rawData will always be faster.
struct ByteStreamInfo
{
    std::basic_streambuf<char>* rawStream;
    uint8_t* rawData;
    std::size_t count;
};


inline ByteStreamInfo FromByteArray(void* bytes, std::size_t count) noexcept
{
    return {nullptr, static_cast<uint8_t*>(bytes), count};
}


inline ByteStreamInfo FromByteArrayConst(const void* bytes, std::size_t count) noexcept
{
    return FromByteArray(const_cast<void*>(bytes), count);
}

#else

typedef struct charls_spiff_header charls_spiff_header;

#endif
