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
/*
 * This demo shows how to use metadata descriptions
 * to store data structures such as GPS coordinates with associative time.
 */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>

#include "vmf/vmf.hpp"


using namespace vmf;
using namespace std;

string workingPath;

#define VIDEO_FILE (workingPath + "BlueSquare.avi")

void copyFile(const string& srcName, const char *dstName)
{
    ifstream src(srcName, ios::binary);
    ofstream dst(dstName, ios::binary);
    if (src && dst)
        dst << src.rdbuf();
    else
        VMF_EXCEPTION(IncorrectParamException, "Error copying '" + srcName + "' to '" + dstName + "'");
    //src.close();
    //dst.close();
}

int main(int argc, char *argv[])
{
    string appPath = argv[0];
#ifdef WIN32
    char delim = '\\';
#else
    char delim = '/';
#endif
    size_t pos = appPath.find_last_of(delim);

    if (pos != string::npos)
    {
        workingPath = appPath.substr(0, pos + 1);
    }

    // Copy test video file to another location.
    copyFile(VIDEO_FILE, "global_test.avi");

    cout << "VMF sample: read/write GPS location and time" << endl << endl;

    const string FILE_NAME = "global_test.avi";
    const string META_SOURCE_NAME = "test-id";

    const string GPS_SCHEMA_NAME = "GPS schema";
    const string GPS_DESC_NAME   = "GPS data";
    const string GPS_FIELD_COORD = "gps";
    const string GPS_FIELD_TIME  = "time";
    const string GPS_FIELD_NOTE  = "note";
    
    const string GPS_METADATA_ITEM1 = "lat=53.78,lng=132.46";
    const string GPS_METADATA_ITEM2 = "lat=53.28,lng=131.87";
    const string GPS_METADATA_ITEM3 = "lat=52.95,lng=131.41";
    const string GPS_METADATA_ITEM4 = "lat=52.49,lng=130.98";

    cout << "Adding metadata..." << endl;
    cout << "Opening file name '" << FILE_NAME << "'" << endl;

    // Open metadata stream
    MetadataStream mdStream;
    if (!mdStream.open(FILE_NAME, MetadataStream::Update))
    {
        cerr << "Can't open file " << FILE_NAME << endl;
        exit(1);
    }

    // Create GPS metadata description
    shared_ptr<MetadataDesc> gpsDesc(
);

    // Create GPS metadata schema
    shared_ptr<MetadataSchema> gpsSchema(
        new MetadataSchema(
            GPS_SCHEMA_NAME,
            { // desc-s
                MetadataDesc( // GPS metadata description
                    GPS_DESC_NAME,
                    { // fields
                        FieldDesc(GPS_FIELD_COORD),
                        FieldDesc(GPS_FIELD_TIME),
                        FieldDesc("note", Variant::type_string, true),
                    }
                ),
            }
    ));

    // Add description to the schema
    gpsSchema->add(gpsDesc);

    string t = "21.02.2013 18:35";
    cout << "Add metadata schema '" << GPS_SCHEMA_NAME << "'" << endl;

    // Add schema to metadata stream
    mdStream.addSchema(gpsSchema);

    shared_ptr<Metadata> gpsMetadata;

    t = "21.02.2013 18:45";
    cout << "Adding metadata's item '" << GPS_METADATA_ITEM1 << "' with associated time " << t << endl;
    
    // Create a metadata item
    gpsMetadata = shared_ptr<Metadata>(new Metadata(gpsDesc));

    // Fill item fields
    gpsMetadata->push_back(FieldValue(GPS_FIELD_COORD, GPS_METADATA_ITEM1));
    gpsMetadata->push_back(FieldValue(GPS_FIELD_TIME, t));

    // Add to metadata a new item
    mdStream.add(gpsMetadata);

    t = "21.02.2013 19:28";
    cout << "Adding metadata's item '" << GPS_METADATA_ITEM2 << "' with associated time " << t << endl;

    gpsMetadata = shared_ptr<Metadata>(new Metadata(gpsDesc));
    gpsMetadata->push_back(FieldValue(GPS_FIELD_COORD, GPS_METADATA_ITEM2));
    gpsMetadata->push_back(FieldValue(GPS_FIELD_TIME, t));
    mdStream.add(gpsMetadata);

    t = "21.02.2013 21:02";
    cout << "Adding metadata's item '" << GPS_METADATA_ITEM3 << "' with associated time " << t << endl;

    gpsMetadata = shared_ptr<Metadata>(new Metadata(gpsDesc));
    gpsMetadata->push_back(FieldValue(GPS_FIELD_COORD, GPS_METADATA_ITEM3));
    gpsMetadata->push_back(FieldValue(GPS_FIELD_TIME, t));
    mdStream.add(gpsMetadata);

    t = "21.02.2013 23:19";
    cout << "Adding metadata's item '" << GPS_METADATA_ITEM4 << "' with associated time " << t << endl;

    gpsMetadata = shared_ptr<Metadata>(new Metadata(gpsDesc));
    gpsMetadata->push_back(FieldValue(GPS_FIELD_COORD, GPS_METADATA_ITEM4));
    gpsMetadata->push_back(FieldValue(GPS_FIELD_TIME, t));
    mdStream.add(gpsMetadata);

    cout << "Save metadata" << endl << endl;

    // Save metadata to video file and close metadata stream
    mdStream.save();
    mdStream.close();

    cout << "Loading metadata..." << endl;
    cout << "Opening file name '" << FILE_NAME << "'" << endl;
    
    // Open new metadata stream to load and print saved metadata
    MetadataStream loadStream;
    if (!loadStream.open(FILE_NAME, MetadataStream::ReadOnly))
    {
        cerr << "Can't open file " << FILE_NAME << endl;
        exit(1);
    }

    cout << "Loading schema '" << GPS_SCHEMA_NAME << "'" << endl;
    if (!loadStream.load(GPS_SCHEMA_NAME))
    {
        cerr << "Can't load schema " << GPS_SCHEMA_NAME << endl;
        exit(1);
    }

    // Select all metadata items from loaded schema
    auto dataSet = loadStream.queryBySchema(GPS_SCHEMA_NAME);

    // and print them to console
    for (size_t i = 0; i < dataSet.size(); i++)
    {
        cout << "Getting item " << i << endl;
        auto metadataItem = dataSet[i];

        string coord = metadataItem->getFieldValue(GPS_FIELD_COORD);
        cout << "\tGPS coordinates are: " << coord << endl;

        string time = metadataItem->getFieldValue(GPS_FIELD_TIME);
        cout << "\tAssociated time is: " << time << endl;
    }

    // Close metadata stream
    loadStream.close();

    return 0;
}
