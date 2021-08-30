// HashTableC++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>

struct Node
{
	int key;
	int value;
};

class HashTable
{
	std::list<Node> *array = nullptr;
	int array_size = 10;

	int Hash_func(int key)
	{
		int hash_code = key % array_size;
		return hash_code;
	}

public:
	void Add(int key, int value)
	{
		if (!array)
		{
			array = new std::list<Node>[array_size];
		}
		array[Hash_func(key)].push_back({ key, value });
	}

	void SetArraySize(int size)
	{
		array_size = size;
		if (!array)
		{
			array = new std::list<Node>[array_size];
		}

		array->resize(array_size);
	}

	void Print()
	{
		for (int i = 0; i < array_size; i++)
		{
			std::cout << "[" << i << "]:";
			for (auto iter = array[i].begin(); iter != array[i].end(); iter++)
			{
				Node itter = *iter;
				std::cout << " " << itter.value;
			}
			std::cout << "\n";
		}
	}

	int Find(int key)
	{
		int size = array[Hash_func(key)].size();

		if (size == 0)
		{
			return -1;
		}
		else if (size == 1)
		{
			return (*array[Hash_func(key)].begin()).value;
		}
		else
		{ 
			for (Node& i : array[Hash_func(key)])
			{
				if (i.key)
				{
					return i.value;
				}
			}
		}
	}
};

int main()
{
	HashTable h;
	h.Add(0, 1);
	h.Add(10, 2);
	h.Add(13, 4);
	h.Add(13, 5);
	h.Add(12, 5);
	h.Add(12, 50);
	h.Print();
}