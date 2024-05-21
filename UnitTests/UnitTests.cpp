#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2/Sorts.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		//Тест для поразрядной сортировки
		TEST_METHOD(RadixSortTest)
		{
			// Arrange
			std::vector<int> arr = { 3, 6, 1, 8, 2, 4 };

			// Act
			radixSort(arr);

			// Assert
			std::vector<int> expected = { 1, 2, 3, 4, 6, 8 };
			Assert::IsTrue(arr == expected);
		}

		//Тест для сортировки вставками
		TEST_METHOD(InsertionSortTest)
		{
			// Arrange
			std::vector<int> arr = { 3, 6, 1, 8, 2, 4 };

			// Act
			insertionSort(arr);

			// Assert
			std::vector<int> expected = { 1, 2, 3, 4, 6, 8 };
			Assert::IsTrue(arr == expected);
		}

		//Тест для пузырьковой сортировки
		TEST_METHOD(BubbleSortTest)
		{
			// Arrange
			std::vector<int> arr = { 3, 6, 1, 8, 2, 4 };

			// Act
			bubbleSort(arr);

			// Assert
			std::vector<int> expected = { 1, 2, 3, 4, 6, 8 };
			Assert::IsTrue(arr == expected);
		}

		//Тест для быстрой сортировки
		TEST_METHOD(QuickSortTest)
		{
			// Arrange
			std::vector<int> arr = { 3, 6, 1, 8, 2, 4 };

			// Act
			quickSort(arr);

			// Assert
			std::vector<int> expected = { 1, 2, 3, 4, 6, 8 };
			Assert::IsTrue(arr == expected);
		}

		//Тест для сортировки шейкера
		TEST_METHOD(CocktailSortTest)
		{
			// Arrange
			std::vector<int> arr = { 3, 6, 1, 8, 2, 4 };

			// Act
			cocktailSort(arr);

			// Assert
			std::vector<int> expected = { 1, 2, 3, 4, 6, 8 };
			Assert::IsTrue(arr == expected);
		}
	};
}
