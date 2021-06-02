#include "stdafx.h"
#include "QBMemoryDB.h"
#include "recordDb.h"

QBRecordCollection QBMemoryDB::QBFindMatchingRecords(const std::string& columnName, const std::string& matchString)
{
    QBRecordCollection result;
    std::copy_if(recordCollection.begin(), recordCollection.end(),
                 std::back_inserter(result),
                 [&](RecordDb rec) {
        if (columnName == "column0") {
            unsigned matchValue = std::stoul(matchString);
            return matchValue == rec.column0;
        }
        else if (columnName == "column1") {
            return rec.column1.find(matchString) != std::string::npos;
        }
        else if (columnName == "column2") {
            long matchValue = std::stol(matchString);
            return matchValue == rec.column2;
        }
        else if (columnName == "column3") {
            return rec.column3.find(matchString) != std::string::npos;
        }
        else {
            return false;
        }
        });

    return result;
}

QBRecordCollection QBMemoryDB::PopulateDummyData(const std::string& prefix, unsigned numRecords)
{
    recordCollection.reserve(numRecords);
    for (unsigned i = 0; i < numRecords; i++)
    {
        RecordDb rec(i, prefix + std::to_string(i), i % 100, std::to_string(i) + prefix);
        recordCollection.emplace_back(rec);
    }
    return recordCollection;
}