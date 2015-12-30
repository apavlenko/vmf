/*
 * Copyright 2015 Intel(r) Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http ://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "vmf/compressor_dummy.hpp"

namespace vmf {

void CompressorDummy::compress(const vmf_string &input, vmf_rawbuffer& output)
{
    //copies input to another buffer and writes result
    output = vmf_rawbuffer(input.c_str(), input.size());
}

void CompressorDummy::decompress(const vmf_rawbuffer& input, vmf_string& output)
{
    //copies code to another buffer and writes result
    output = vmf_string(input.data(), input.size());
}

class DummyCompressorRegistrator
{
public:
    DummyCompressorRegistrator()
    {
        std::shared_ptr<CompressorDummy> dc = std::make_shared<CompressorDummy>();
        Compressor::registerNew(std::dynamic_pointer_cast<Compressor>(dc));
    }
};

static DummyCompressorRegistrator dcr;

} /* vmf */
