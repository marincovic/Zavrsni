#include "CppUnitTest.h"
#include "../Structures/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(ListTest)
	{
	public:
		
		TEST_METHOD(List_SizeMethodReturnsZeroForEmptyList)
		{
			List<int> list;
			Assert::AreEqual(0, list.Size());
		}

		TEST_METHOD(List_AppendMethodIncreasesSizeOfListByOne)
		{
			List<int> list;
			list.Append(1);
			Assert::AreEqual(1, list.Size());
		}

		TEST_METHOD(List_GetAtMethodReturnsElementAtGivenIndex)
		{
			List<int> list;
			list.Append(5);
			Assert::AreEqual(5, list.GetAt(0));
		}

		TEST_METHOD(List_RemoveAtMethodDecreasesSizeOfList)
		{
			List<int> list;
			list.Append(5);
			list.Append(10);
			list.RemoveAt(0);
			Assert::AreEqual(1, list.Size());
		}

		TEST_METHOD(List_RemoveAtMethodForIndexZeroMovesSecondElementoTheStartOfList)
		{
			List<int> list;
			list.Append(5);
			list.Append(10);
			list.RemoveAt(0);
			Assert::AreEqual(10, list.GetAt(0));
		}

		TEST_METHOD(List_RemoveAtMethodForLastIndexRemovesElementFromTheEndOfList)
		{
			List<int> list;
			list.Append(5);
			list.Append(10);
			list.RemoveAt(list.Size() - 1);
			Assert::AreEqual(1, list.Size());
			Assert::AreEqual(5, list.GetAt(0));
		}

		TEST_METHOD(List_RemoveAtMethodThrowsExceptionForEmptyList)
		{
			try
			{
				List<int> list;
				list.RemoveAt(0);
				Assert::Fail(L"should throw exception");
			}
			catch (const std::out_of_range&)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(List_InsertAtMethodForZeroIndexInsertsElementToTheBeginningOfList)
		{
			List<int> list;
			list.Append(1);
			list.InsertAt(0, 5);
			Assert::AreEqual(2, list.Size());
			Assert::AreEqual(5, list.GetAt(0));
			Assert::AreEqual(1, list.GetAt(1));
		}

		TEST_METHOD(List_InsertAtMethodForLastIndexInsertsElementToTheEndOfList)
		{
			List<int> list;
			list.Append(1);
			list.InsertAt(1, 5);
			Assert::AreEqual(2, list.Size());
			Assert::AreEqual(1, list.GetAt(0));
			Assert::AreEqual(5, list.GetAt(1));
		}

		TEST_METHOD(List_InsertAtMethodThrowsExceptionForInvalidIndex)
		{
			try
			{
				List<int> list;
				list.InsertAt(1, 5);
				Assert::Fail();
			}
			catch (const std::out_of_range&)
			{
				Assert::IsTrue(true);
			}
		}
	};
}