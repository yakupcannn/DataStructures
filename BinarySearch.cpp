#include<iostream>
using namespace std;
int binarySearch(int[],int,int);
int main()
{
	int arr[] = { 3,8,10,11,20,50,55,60,65,70,72,90,91,94,96,99 };
	int size = sizeof(arr) /sizeof(int);
	cout<<"The element is stored in "<<binarySearch(arr,size,57);




	return 0;
}
int binarySearch(int arr[], int size,int key)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (arr[middle] == key)
			return middle;
		else if (arr[middle] < key)
		{
		   left=middle+1;
		}
		else
		{
			right =middle-1;
		}
	}
	return -1;
}