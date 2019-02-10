// Copyright (c) Team CharLS. All rights reserved. See the accompanying "LICENSE.md" for licensed use.

#include "pch.h"

#include <charls/jpegls_decoder.h>

#include <vector>
#include <cstdio>

using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
using std::vector;

namespace CharLSUnitTest
{

TEST_CLASS(jpegls_decoder_test)
{
public:
    TEST_METHOD(create_destroy)
    {
        charls::jpegls_decoder decoder;
    }

    TEST_METHOD(decode_reference_file_from_buffer)
    {
        charls::jpegls_decoder decoder;

        std::vector<uint8_t> buffer{read_file("test/conformance/T8C0E0.JLS")};

        decoder.source_buffer(buffer.data(), buffer.size());
        decoder.read_header();
    }

    vector<uint8_t> read_file(const char* filename)
    {
        FILE* file = fopen(filename, "rb");
        if (!file)
            throw std::exception();

        fseek(file, 0, SEEK_END);
        const auto byteCountFile = static_cast<int>(ftell(file));
        fseek(file, 0, SEEK_SET);

        vector<uint8_t> buffer(byteCountFile);
        const size_t bytesRead = fread(buffer.data(), 1, buffer.size(), file);
        fclose(file);
        if (bytesRead != buffer.size())
            throw std::exception();

        return buffer;
    }
};

} // namespace CharLSUnitTest