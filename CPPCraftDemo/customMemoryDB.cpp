#include "stdafx.h"
#include "customMemoryDB.h"
#include "recordDb.h"

#include <iostream>

Record_Collection MemoryDB::FindRecord(const std::string& searchedColumn, const std::string& searchedElement)
{
	Record_Collection result {};
	if (searchedColumn == "column0")
	{
		auto& column0Index = recordCollection.get<Column0>();
		auto column0It = column0Index.find(std::stoul(searchedElement));
		if (column0It != column0Index.end())
		{
			result.emplace(*column0It);
			std::cout << "Column0 " << column0It->column0 << " " << column0It->column1 << std::endl;
		}
	}
	else if (searchedColumn == "column1")
	{
		auto& column1Index = recordCollection.get<Column1>();
		auto column1It = column1Index.find(searchedElement);
		if (column1It != column1Index.end())
		{
			result.emplace(*column1It);
			std::cout << "Column1 " << column1It->column0 << " " << column1It->column1 << std::endl;
		}
	}
	else if (searchedColumn == "column2")
	{
		auto& column2Index = recordCollection.get<Column2>();
		auto column2It = column2Index.equal_range(std::stol(searchedElement));
		for (auto it = column2It.first; it != column2It.second; ++it)
		{
			result.emplace(*it);
			std::cout << it->column2 << ", ";
		}
		std::cout << std::endl;
	}
	else if (searchedColumn == "column3")
	{
		auto& column3Index = recordCollection.get<Column3>();
		auto column3It = column3Index.find(searchedElement);
		if (column3It != column3Index.end())
		{
			result.emplace(*column3It);
			std::cout << "Column3 " << column3It->column0 << " " << column3It->column3 << " " << std::endl;
		}
	}

	return result;
}

void MemoryDB::PopulateData(const std::string& prefix, int numRecords)
{
	recordCollection.reserve(numRecords);
	for (int i = 0; i < numRecords; ++i)
	{
		recordCollection.emplace(RecordDb(i, prefix + std::to_string(i), i % 100, std::to_string(i) + prefix));
	}
}

void MemoryDB::DeleteRecordByID(unsigned id)
{
	auto& idIndex = recordCollection.get<Column0>();
	auto idIt = idIndex.erase(id);
}