#pragma once

#include "stdafx.h"
#include "recordDb.h"

#include <vector>

/**
Represents a Record Collections
*/
typedef std::vector<RecordDb> QBRecordCollection;

class QBMemoryDB
{
public:
    /**
        Return records that contains a string in the StringValue field
        records - the initial set of records to filter
        matchString - the string to search for
    */
    QBRecordCollection QBFindMatchingRecords(const std::string& columnName, const std::string& matchString);

    /**
        Utility to populate a record collection
        prefix - prefix for the string value for every record
        numRecords - number of records to populate in the collection
    */
    QBRecordCollection PopulateDummyData(const std::string& prefix, unsigned numRecords);

private:
    QBRecordCollection recordCollection;
};


