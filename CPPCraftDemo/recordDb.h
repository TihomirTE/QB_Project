#pragma once
#include <string>

/**
    Represents a Record Object
*/
struct RecordDb
{
    unsigned column0; // unique id column
    std::string column1; // unique column
    long column2; // non-unique column
    std::string column3; // unique column

    RecordDb(int column0_, const std::string& column1_, long column2_, const std::string& column3_) :
        column0(column0_),
        column1(column1_),
        column2(column2_),
        column3(column3_)
    {}
};
