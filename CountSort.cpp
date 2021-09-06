#include<iostream>
#include <vector>
using namespace std;
struct Item
{
	int key;
	char ch;
	Item()
	{

	}
	Item(int key, char ch)
	{
		this->key = key;
		this->ch = ch;
	}
};
void countSort(vector<int>&);
void countSortWithSatellite(vector<Item>&);
void printArray(vector<int>);
void print1Array(vector<Item>);
int main()
{
	//vector<int> arr = { 3,5,4,3,7,4,5,6,3,8,7,6,4};
	vector<int> arr = { 3,5,4,3,7,4,5,6,3,8,7,6,4,6,8,9,10,9};
	vector<Item>items = { Item(1,'a'),Item(4,'e'),Item(3,'r'),Item(1,'s'),Item(3,'v'),Item(2,'a'),Item(3,'f'),Item(1,'b')};
	countSort(arr);
	printArray(arr);
	countSortWithSatellite(items);
	cout << endl;
	print1Array(items);
	cout << endl << endl;
	return 0;
}
void countSort(vector<int> &arr)
{
	if (arr.size() > 1)
	{
		int min = arr[0], max = arr[0];
		for (int i = 1; i < arr.size(); i++)//find max and min
		{
			if (arr[i] < min)min = arr[i];
			else if (arr[i] > max)max = arr[i];
		}
		int size = max - min + 1;
		int* temp = new int[size];
		for (int i = 0; i < size; i++)temp[i] = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			temp[arr[i] - min]++;
		}
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < temp[i]; j++)
				arr[counter++] = i + min;
		}
		delete[] temp;
	}
	else return;
}
void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
		if (i != arr.size() - 1)
			cout << ",";
	}
}
void countSortWithSatellite(vector<Item>& arr)
{
	if (arr.size() > 1)
	{
		int min = arr[0].key, max = arr[0].key;
		for (int i = 1; i < arr.size(); i++)//find max and min
		{
			if (arr[i].key < min)min = arr[i].key;
			else if (arr[i].key > max)max = arr[i].key;
		}
		int size = max - min + 1;
		int* temp = new int[size];
		vector<Item>items(arr.size());
		for (int i = 0; i < size; i++)temp[i] = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			temp[arr[i].key - min]++;
		}
		for (int i = 1; i < size; i++)
		{
			temp[i] += temp[i - 1];
		}
		for (int i = arr.size()-1; i >= 0; i--)
		{
			items[temp[(arr[i].key)-min]-1].key = arr[i].key;
			items[temp[(arr[i].key)-min]-1].ch = arr[i].ch;
			temp[(arr[i].key)-min]--;
		}
		for (int i = 0; i < arr.size(); i++)
		{
			arr[i].key = items[i].key;
			arr[i].ch = items[i].ch;
		}
		delete[] temp;
	}
	else return;
}
void print1Array(vector<Item>items)
{
	for (int i = 0; i < items.size(); i++)
	{
		cout << items[i].key << "-->"<<items[i].ch<<endl;
	}
}