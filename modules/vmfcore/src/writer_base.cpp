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

#include "vmf/writer_base.hpp"
#include "vmf/rwconst.hpp"

namespace vmf
{

class MetadataAccessor: public Metadata
{
public:
    MetadataAccessor( const std::shared_ptr< MetadataDesc >& spDescription )
      : Metadata(spDescription) { }
    MetadataAccessor( const Metadata& oMetadata )
      : Metadata(oMetadata) { }
    using Metadata::setId;
    virtual ~MetadataAccessor() {}
};


std::string WriterBase::compress(const std::string& input)
{
    if(!compressorId.empty())
    {
        std::shared_ptr<Compressor> compressor = Compressor::create(compressorId);
        vmf_rawbuffer compressedBuf;
        compressor->compress(input, compressedBuf);
        // Compressed binary data should be represented in base64
        // because of '\0' symbols
        std::string compressed = Variant::base64encode(compressedBuf);

        //Store compressed data in a format of current implementation
        std::shared_ptr<vmf::MetadataSchema> cSchema;
        cSchema = std::make_shared<vmf::MetadataSchema>(COMPRESSED_DATA_SCHEMA_NAME);
        VMF_METADATA_BEGIN(COMPRESSED_DATA_DESC_NAME);
            VMF_FIELD_STR(COMPRESSION_ALGO_PROP_NAME);
            VMF_FIELD_STR(COMPRESSED_DATA_PROP_NAME);
        VMF_METADATA_END(cSchema);

        std::shared_ptr<Metadata> cMetadata;
        cMetadata = std::make_shared<Metadata>(cSchema->findMetadataDesc(COMPRESSED_DATA_DESC_NAME));
        cMetadata->push_back(FieldValue(COMPRESSION_ALGO_PROP_NAME, compressorId));
        cMetadata->push_back(FieldValue(COMPRESSED_DATA_PROP_NAME,  compressed));

        MetadataAccessor metadataAccessor(*cMetadata);
        metadataAccessor.setId(0);
        cMetadata = std::make_shared<Metadata>(metadataAccessor);

        MetadataSet cSet;
        cSet.push_back(cMetadata);
        std::vector< std::shared_ptr<MetadataSchema> > cSchemas;
        cSchemas.push_back(cSchema);

        const IdType nextId = 1;
        const std::string filePath = "";
        const std::string checksum = "";
        std::vector<std::shared_ptr<MetadataStream::VideoSegment>> segments;

        //create writer with no compression enabled
        std::string outputString;
        std::shared_ptr<WriterBase> writer = this->createNewInstance();
        writer->compressorId.clear();
        outputString = writer->store(nextId, filePath, checksum, segments, cSchemas, cSet);

        return outputString;
    }
    else
    {
        return input;
    }
}

}
