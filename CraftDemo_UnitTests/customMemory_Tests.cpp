#include "pch.h"
#include "CppUnitTest.h"
#include "../CPPCraftDemo/customMemoryDB.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomMemoryTests
{
	MemoryDB data;
	Record_Collection collection;
	RecordDb record(5, "test5", 5, "5test");

	TEST_MODULE_INITIALIZE(Initialize_Data)
	{
		data.PopulateData("test", 1000);
		collection = data.GetRecordCollection();
	}

	TEST_CLASS(CustomMemoryTests)
	{
	public:
		TEST_METHOD(Collection_Size)
		{
			Assert::AreEqual(1000, (int)collection.size());
		}

		TEST_METHOD(Fill_Correct_Record)
		{
			std::string column1 = collection.begin()->column1;

			Assert::AreEqual("test0", column1.c_str());
		}

		TEST_METHOD(Find_Column0)
		{
			auto result = data.FindRecord("column0", "5");

			Assert::AreEqual(1, (int)result.size());
			Assert::AreEqual(record.column0, result.begin()->column0);
			Assert::AreEqual(record.column1, result.begin()->column1);
			Assert::AreEqual(record.column2, result.begin()->column2);
			Assert::AreEqual(record.column3, result.begin()->column3);
		}

		TEST_METHOD(Find_Column1)
		{
			auto result = data.FindRecord("column1", "test5");

			Assert::AreEqual(1, (int)result.size());
			Assert::AreEqual(record.column0, result.begin()->column0);
			Assert::AreEqual(record.column1, result.begin()->column1);
			Assert::AreEqual(record.column2, result.begin()->column2);
			Assert::AreEqual(record.column3, result.begin()->column3);
		}

		TEST_METHOD(Find_Column2)
		{
			auto result = data.FindRecord("column2", "5");

			Assert::AreEqual(10, (int)result.size());
			Assert::AreEqual(record.column2, result.begin()->column2);
		}

		TEST_METHOD(Find_Column3)
		{
			auto result = data.FindRecord("column3", "5test");

			Assert::AreEqual(1, (int)result.size());
			Assert::AreEqual(record.column0, result.begin()->column0);
			Assert::AreEqual(record.column1, result.begin()->column1);
			Assert::AreEqual(record.column2, result.begin()->column2);
			Assert::AreEqual(record.column3, result.begin()->column3);
		}

		TEST_METHOD(Delete_Record)
		{
			MemoryDB dataDeletedRecord;
			dataDeletedRecord.DeleteRecordByID(0);
			auto collectionDeletedRecord = dataDeletedRecord.GetRecordCollection();
			RecordDb deletedRecord(0, "test0", 0, "0test");

			Assert::AreNotEqual(deletedRecord.column0, collectionDeletedRecord.begin()->column0);
		}
	};
}
