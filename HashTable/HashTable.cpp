// HashTableC++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class HashTable
{
	int *array = nullptr;
	const int ARRAY_SIZE = 10;

	int Hash_func(int key)
	{
		int hash_code = key % ARRAY_SIZE;
		return hash_code;
	}
public:
	void Add(int key, int value)
	{
		if (!array)
		{
			array = new int[ARRAY_SIZE];
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				array[i] = 0;
			}
		}
		array[Hash_func(key)] = value;
	}

	void Print()
	{
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			std::cout << array[i] << "\n";
		}
	}

	int FindAt(int index)
	{
		int Number = array[Hash_func(index)];
		return Number;
	}

	int Find(int FindNumber)
	{
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (array[i] == FindNumber)
			{
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	HashTable h;
	h.Add(0, 1);
	h.Add(10, 2);
	h.Add(11, 3);
	h.Print();
	std::cout << h.FindAt(11) << "\n";
	std::cout << h.Find(3) << "\n";
}