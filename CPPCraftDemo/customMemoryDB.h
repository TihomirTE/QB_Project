#pragma once

#include "stdafx.h"
#include "recordDb.h"

struct Column0 {};
struct Column1 {};
struct Column2 {};
struct Column3 {};

typedef boost::multi_index_container<
    RecordDb,
    boost::multi_index::indexed_by<
    boost::multi_index::hashed_unique<
    boost::multi_index::tag<Column0>,
    BOOST_MULTI_INDEX_MEMBER(RecordDb, unsigned, column0)
    >,
    boost::multi_index::hashed_unique<
    boost::multi_index::tag<Column1>,
    BOOST_MULTI_INDEX_MEMBER(RecordDb, const std::string, column1)
    >,
    boost::multi_index::hashed_non_unique<
    boost::multi_index::tag<Column2>,
    BOOST_MULTI_INDEX_MEMBER(RecordDb, long, column2)
    >,
    boost::multi_index::hashed_unique<
    boost::multi_index::tag<Column3>,
    BOOST_MULTI_INDEX_MEMBER(RecordDb, const std::string, column3)
    >
    >
>Record_Collection;

class MemoryDB
{
public:
    /// <summary>
    /// Find specific record by specific searching criteria (column)
    /// with the corresponding value
    /// </summary>
    /// <param name="searchedColumn">Choose the column to search the record</param>
    /// <param name="searchedElement">Value of the searching record</param>
    Record_Collection FindRecord(const std::string& searchedColumn, const std::string& searchedElement);

    /// <summary>
    /// Delete record by unique id column
    /// </summary>
    void DeleteRecordByID(unsigned id);

    /// <summary>
    /// Fill the memory data collection with testing records
    /// </summary>
    void PopulateData(const std::string& prefix, int numRecords);

    Record_Collection GetRecordCollection()
    {
        return recordCollection;
    }
private:
    Record_Collection recordCollection = {};
};
