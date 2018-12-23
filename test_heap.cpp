#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ALGOR_3_3/heap.h"
//#include "../ALGOR_3_3/"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests_for_3_lab
{		
	TEST_CLASS(test_heap)
	{
	public:
		
		TEST_METHOD(test_get_size_true)
		{
			Heap test_heap;

			test_heap.insert(5);
			test_heap.insert(4);
			test_heap.insert(3);
			test_heap.insert(2);
			test_heap.insert(1);
			Assert::IsTrue(test_heap.get_size()==5);
		}
		
			


		TEST_METHOD(test_at_true)
		{
			Heap test_heap;

			test_heap.insert(5);
			test_heap.insert(4);
			test_heap.insert(3);
			test_heap.insert(2);
			test_heap.insert(1);

			Assert::IsTrue(test_heap.at(0) == 5);
		}

		TEST_METHOD(test_at_exep)
		{
			Heap test_heap;

			test_heap.insert(5);
			test_heap.insert(4);
			test_heap.insert(3);
			test_heap.insert(2);
			test_heap.insert(1);

			
			try
			{
				test_heap.at(0);
			}
			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("Error", error.what());
			}
		}

		TEST_METHOD(test_at_exep_index_big)
		{
			Heap test_heap;

			test_heap.insert(5);
			test_heap.insert(4);
			test_heap.insert(3);
			test_heap.insert(2);
			test_heap.insert(1);
			try
			{
				test_heap.at(10);
			}
			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("Index is greater than list size", error.what());
			}
		}

		TEST_METHOD(test_heap_insert_true)
		{
			Heap test_heap;
			
			test_heap.insert(5);
			test_heap.insert(4);
			test_heap.insert(3);
			test_heap.insert(2);
			test_heap.insert(1);

			int* check_array = new int[5];
			check_array[0] = 5;
			check_array[1] = 4;
			check_array[2] = 3;
			check_array[3] = 2;
			check_array[4] = 1;

			//Assert::IsTrue (k.is_equal(elements, 5, k.create_width_iterator, k.get_size()));
			bool check = true;
			for (int i = 0; i < test_heap.get_size(); i++)
				if (test_heap.at(i) != check_array[i])
					check = false;
			Assert::IsTrue(check);
		}
		TEST_METHOD(test_heap_insert_false)
		{
			Heap test_heap;

			test_heap.insert(5);
			test_heap.insert(4);
			test_heap.insert(3);
			test_heap.insert(2);
			test_heap.insert(9);

			int* check_array = new int[5];
			check_array[0] = 5;
			check_array[1] = 4;
			check_array[2] = 3;
			check_array[3] = 2;
			check_array[4] = 9;

			//Assert::IsTrue (k.is_equal(elements, 5, k.create_width_iterator, k.get_size()));
			bool check = true;
			for (int i = 0; i < test_heap.get_size(); i++)
				if (test_heap.at(i) != check_array[i])
					check = false;
			Assert::IsFalse(check);
		}

		TEST_METHOD(test_heap_sorting_true)
		{
			Heap test_heap;

			 test_heap.insert(15);
			 test_heap.insert(4);
			 test_heap.insert(32);
			 test_heap.insert(2);
			 test_heap.insert(18);
		 	 test_heap.insert(98);
			 test_heap.insert(8);
			 test_heap.insert(16);
			 test_heap.insert(9);

			
			int* check_array = new int[9];
			check_array[0] = 98;
			check_array[1] = 18;
			check_array[2] = 32;
			check_array[3] = 16;
			check_array[4] = 4;
			check_array[5] = 15;
			check_array[6] = 8;
			check_array[7] = 2;
			check_array[8] = 9;

			bool check = true;
			for (int i = 0; i < test_heap.get_size(); i++)
				if (test_heap.at(i) != check_array[i])
					check = false;
			Assert::IsTrue(check);
		}
		TEST_METHOD(test_heap_sorting_false)
		{
			Heap test_heap;

			test_heap.insert(15);
			test_heap.insert(4);
			test_heap.insert(30);
			test_heap.insert(2);
			test_heap.insert(9);

			int* check_array = new int[5];
			check_array[0] = 30;
			check_array[1] = 15;
			check_array[2] = 9;
			check_array[3] = 4;
			check_array[4] = 2;

			bool check = true;
			for (int i = 0; i < test_heap.get_size(); i++)
				if (test_heap.at(i) != check_array[i])
					check = false;
			Assert::IsFalse(check);
		}
		
		TEST_METHOD(test_heap_remove_root_true)
		{
		Heap test_heap;

		test_heap.insert(5);
		test_heap.insert(6);
		test_heap.insert(7);
		test_heap.insert(21);
		test_heap.insert(12);
		test_heap.insert(54);
		test_heap.insert(40);
		test_heap.insert(32);
		test_heap.insert(2);
		test_heap.insert(1);

		test_heap.remove(54);

		int* check_array = new int[10];

		check_array[0] = 40;
		check_array[1] = 12;
		check_array[2] = 32;
		check_array[3] = 5;
		check_array[4] = 7;
		check_array[5] = 6;
		check_array[6] = 21;
		check_array[7] = 1;
		check_array[8] = 2;


		bool check = true;
		for (int i = 0; i < test_heap.get_size(); i++)
		if (test_heap.at(i) != check_array[i])
		check = false;

		Assert::IsTrue(check);
		}
		
		TEST_METHOD(test_heap_remove_middle_true)
		{
			Heap test_heap;

			test_heap.insert(15);
			test_heap.insert(4);
			test_heap.insert(32);
			test_heap.insert(2);
			test_heap.insert(18);
			test_heap.insert(98);
			test_heap.insert(8);
			test_heap.insert(16);
			test_heap.insert(9);

			test_heap.remove(18);

			int* check_array = new int[8];
			check_array[0] = 98;
			check_array[1] = 16;
			check_array[2] = 32;
			check_array[3] = 9;
			check_array[4] = 4;
			check_array[5] = 15;
			check_array[6] = 8;
			check_array[7] = 2;
			

			bool check = true;
			for (int i = 0; i < test_heap.get_size(); i++)
				if (test_heap.at(i) != check_array[i])
					check = false;
			Assert::IsTrue(check);
		}


		TEST_METHOD(test_heap_remove_leaflet_true)
		{
			Heap test_heap;

			test_heap.insert(5);
			test_heap.insert(4);
			test_heap.insert(3);
			test_heap.insert(2);
			test_heap.insert(1);

			test_heap.remove(2);

			int* check_array = new int[4];

			check_array[0] = 5;
			check_array[1] = 4;
			check_array[2] = 3;
			check_array[3] = 1;


			bool check = true;
			for (int i = 0; i < test_heap.get_size(); i++)
				if (test_heap.at(i) != check_array[i])
					check = false;
			Assert::IsTrue(check);
		}


		TEST_METHOD(test_heap_remove_exep)
		{
			Heap test_heap;

			test_heap.insert(5);
			test_heap.insert(4);
			test_heap.insert(3);
			test_heap.insert(2);
			test_heap.insert(1);

			try
			{
				test_heap.remove(12);
			}
			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("There is no such elem in tne heap", error.what());
			}
		}

		TEST_METHOD(test_print_complete_exp)
		{
			Heap test_heap;

			try
			{
				test_heap.print_complete();
			}
			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("Heap is empty", error.what());
			}
		}

	};
}