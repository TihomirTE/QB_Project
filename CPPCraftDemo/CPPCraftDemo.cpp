#include "stdafx.h"
#include "customMemoryDB.h"
#include "QBMemoryDB.h"

#include <assert.h>
#include <chrono>
#include <iostream>

int main(int argc, _TCHAR* argv[])
{
    using namespace std::chrono;

    // My version
    MemoryDB data;
    data.PopulateData("testdata", 1000);

    auto startTimer = high_resolution_clock::now();

    // Find a record that contains and measure the perf
    data.FindRecord("column0", "678");
    data.FindRecord("column1", "testdata500");
    data.FindRecord("column2", "24");
    data.FindRecord("column3", "567testdata");

    auto stopTimer = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTimer - startTimer);
    std::cout << "My version " << duration.count() << " microseconds" << std::endl;
    std::cout << std::endl;

    data.DeleteRecordByID(501);
    data.FindRecord("column1", "testdata501");

    // QB version
    QBMemoryDB qbData;
    qbData.PopulateDummyData("testdata", 1000);
    auto startTimer1 = high_resolution_clock::now();

    // Find a record that contains and measure the perf

    qbData.QBFindMatchingRecords("column0", "678");
    auto filteredSet = qbData.QBFindMatchingRecords("column1", "testdata500");
    qbData.QBFindMatchingRecords("column2", "24");
    qbData.QBFindMatchingRecords("column3", "567testdata");
    
    auto stopTimer1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stopTimer1 - startTimer1);
    std::cout << "QB version " << duration1.count() << " microseconds" << std::endl;

    // make sure that the function is correct
    assert(filteredSet.size() == 1);

	return 0;
}

