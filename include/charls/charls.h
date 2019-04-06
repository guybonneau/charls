// Copyright (c) Team CharLS. All rights reserved. See the accompanying "LICENSE.md" for licensed use.

#pragma once

#include "jpegls_error.h"

#ifdef __cplusplus
extern "C" {
#else
#include <stddef.h>
#include <stdbool.h>
#endif

struct charls_jpegls_decoder;
struct charls_jpegls_encoder;

#ifndef __cplusplus
typedef struct charls_jpegls_decoder charls_jpegls_decoder_t;
typedef struct charls_jpegls_encoder charls_jpegls_encoder_t;
#endif

CHARLS_API_IMPORT_EXPORT struct charls_jpegls_decoder* CHARLS_API_CALLING_CONVENTION
charls_jpegls_decoder_create(void);

CHARLS_API_IMPORT_EXPORT void CHARLS_API_CALLING_CONVENTION
charls_jpegls_decoder_destroy(const struct charls_jpegls_decoder* decoder);

CHARLS_API_IMPORT_EXPORT charls_jpegls_errc CHARLS_API_CALLING_CONVENTION
charls_jpegls_decoder_source_buffer(struct charls_jpegls_decoder* decoder, const void* buffer, size_t size);

CHARLS_API_IMPORT_EXPORT charls_jpegls_errc CHARLS_API_CALLING_CONVENTION
charls_jpegls_decoder_read_spiff_header(const struct charls_jpegls_decoder* decoder, charls_spiff_header* spiff_header, int32_t* header_found);

CHARLS_API_IMPORT_EXPORT charls_jpegls_errc CHARLS_API_CALLING_CONVENTION
charls_jpegls_decoder_read_header(const struct charls_jpegls_decoder* decoder);

CHARLS_API_IMPORT_EXPORT charls_jpegls_errc CHARLS_API_CALLING_CONVENTION
charls_jpegls_decoder_decode_to_buffer(const struct charls_jpegls_decoder* decoder, void* buffer, size_t size);


CHARLS_API_IMPORT_EXPORT struct charls_jpegls_encoder* CHARLS_API_CALLING_CONVENTION
charls_jpegls_encoder_create_buffer(void* destination_buffer, size_t size);

CHARLS_API_IMPORT_EXPORT void CHARLS_API_CALLING_CONVENTION
charls_jpegls_encoder_destroy(const struct charls_jpegls_encoder* encoder);

CHARLS_API_IMPORT_EXPORT void CHARLS_API_CALLING_CONVENTION
charls_jpegls_encoder_size(struct charls_jpegls_encoder* encoder, int32_t width, int32_t height);

CHARLS_API_IMPORT_EXPORT void CHARLS_API_CALLING_CONVENTION
charls_jpegls_encoder_near_lossless(struct charls_jpegls_encoder* encoder, int32_t near_lossless);

CHARLS_API_IMPORT_EXPORT void CHARLS_API_CALLING_CONVENTION
charls_jpegls_encoder_interleave_mode(struct charls_jpegls_encoder* encoder, CharlsInterleaveModeType mode);

CHARLS_API_IMPORT_EXPORT charls_jpegls_errc CHARLS_API_CALLING_CONVENTION
charls_jpegls_encoder_encode_from_buffer(struct charls_jpegls_encoder* encoder, const void* source, size_t source_size);

CHARLS_API_IMPORT_EXPORT charls_jpegls_errc CHARLS_API_CALLING_CONVENTION
charls_jpegls_encoder_write_spiff_header(struct charls_jpegls_encoder* encoder, const charls_spiff_header* spiff_header);

CHARLS_API_IMPORT_EXPORT charls_jpegls_errc CHARLS_API_CALLING_CONVENTION
charls_jpegls_encoder_write_spiff_entry(struct charls_jpegls_encoder* encoder, int32_t entry_tag, const void* entry_data, size_t entry_data_size);


/// <summary>
/// Encodes a byte array with pixel data to a JPEG-LS encoded (compressed) byte array.
/// </summary>
/// <param name="destination">Byte array that holds the encoded bytes when the function returns.</param>
/// <param name="destinationLength">Length of the array in bytes. If the array is too small the function will return an error.</param>
/// <param name="bytesWritten">This parameter will hold the number of bytes written to the destination byte array. Cannot be NULL.</param>
/// <param name="source">Byte array that holds the pixels that should be encoded.</param>
/// <param name="sourceLength">Length of the array in bytes.</param>
/// <param name="params">Parameter object that describes the pixel data and how to encode it.</param>
/// <param name="reserved">Reserved, pass NULL pointer (will be removed in next ABI update).</param>
CHARLS_API_IMPORT_EXPORT CharlsApiResultType CHARLS_API_CALLING_CONVENTION JpegLsEncode(
    void* destination,
    size_t destinationLength,
    size_t* bytesWritten,
    const void* source,
    size_t sourceLength,
    const struct JlsParameters* params,
    const void* reserved);

/// <summary>
/// Retrieves the JPEG-LS header. This info can be used to pre-allocate the uncompressed output buffer.
/// </summary>
/// <param name="source">Byte array that holds the JPEG-LS encoded data of which the header should be extracted.</param>
/// <param name="sourceLength">Length of the array in bytes.</param>
/// <param name="params">Parameter object that describes how the pixel data is encoded.</param>
/// <param name="reserved">Reserved, pass NULL pointer  (will be removed in next ABI update).</param>
CHARLS_API_IMPORT_EXPORT CharlsApiResultType CHARLS_API_CALLING_CONVENTION JpegLsReadHeader(
    const void* source,
    size_t sourceLength,
    struct JlsParameters* params,
    const void* reserved);

/// <summary>
/// Encodes a JPEG-LS encoded byte array to uncompressed pixel data byte array.
/// </summary>
/// <param name="destination">Byte array that holds the uncompressed pixel data bytes when the function returns.</param>
/// <param name="destinationLength">Length of the array in bytes. If the array is too small the function will return an error.</param>
/// <param name="source">Byte array that holds the JPEG-LS encoded data that should be decoded.</param>
/// <param name="sourceLength">Length of the array in bytes.</param>
/// <param name="params">Parameter object that describes the pixel data and how to decode it.</param>
/// <param name="reserved">Reserved, pass NULL pointer  (will be removed in next ABI update).</param>
CHARLS_API_IMPORT_EXPORT CharlsApiResultType CHARLS_API_CALLING_CONVENTION JpegLsDecode(
    void* destination,
    size_t destinationLength,
    const void* source,
    size_t sourceLength,
    const struct JlsParameters* params,
    const void* reserved);

CHARLS_API_IMPORT_EXPORT CharlsApiResultType CHARLS_API_CALLING_CONVENTION JpegLsDecodeRect(
    void* destination,
    size_t destinationLength,
    const void* source,
    size_t sourceLength,
    struct JlsRect roi,
    const struct JlsParameters* params,
    const void* reserved);

#ifdef __cplusplus
}

CHARLS_API_IMPORT_EXPORT CharlsApiResultType JpegLsEncodeStream(ByteStreamInfo destination, size_t& bytesWritten, ByteStreamInfo source, const JlsParameters& params);
CHARLS_API_IMPORT_EXPORT CharlsApiResultType JpegLsDecodeStream(ByteStreamInfo destination, ByteStreamInfo source, const JlsParameters* params);
CHARLS_API_IMPORT_EXPORT CharlsApiResultType JpegLsReadHeaderStream(ByteStreamInfo source, JlsParameters* params);

#endif
