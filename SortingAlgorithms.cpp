#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int>&);
void bubbleSort(vector<int>&);
void insertionSort(vector<int>&);
void mergeSort(int[],int);
void quickSort(int[],int);
void quickSortWithHeuristic(int[],int);
int partition(int[], int);
int partitionWithMedian(int[], int);
int medianOf3(int[], int);
void mySwap(int&, int&);
int main()
{
	vector<int> arr = { 10,5,7,4,3,1,4,2};
	//int arr2[8] = { 10,5,7,4,3,1,9,8 };
	int arr2[10] = { 10,9,7,4,3,1,13,17,5,2};
	//selectionSort(arr);
	//bubbleSort(arr);
	//insertionSort(arr);
	//mergeSort(arr2, 6);
	//quickSort(arr2, 8);
	quickSortWithHeuristic(arr2, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl << "---------------------" << endl;
	return 0;
}
void selectionSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		int min = arr[i];
		for (int j =i+1; j < arr.size(); j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				mySwap(arr[i],arr[j]);
			}
				
		}
		arr[i] = min;
	}
}
void bubbleSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
			{
				mySwap(arr[i], arr[j]);
			}

		}
	}
}
void insertionSort(vector<int>& arr)
{
	int j;
	for (int i = 1; i < arr.size(); i++)
	{
		int temp = arr[i];
		for (j = i; j > 0&&arr[j-1]>temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}
void mergeSort(int arr[],int size)
{
	if (size==1)return;
	int middle = size / 2;
	mergeSort(arr, middle);
	mergeSort(&arr[middle],size-middle);
	//merge
	int* arrTemp = new int[size];
	int i =0,j=middle,k=0;
	while (i < middle && j <= size - 1)
	{
		if (arr[i] <= arr[j])arrTemp[k++] = arr[i++];
		else				 arrTemp[k++] = arr[j++];
	}
	while (i < middle)arrTemp[k++] = arr[i++];
	while (j < size)arrTemp[k++] = arr[j++];

	for (i = 0; i < size; i++)arr[i] = arrTemp[i];
	delete[] arrTemp;

}
void quickSort(int arr[], int size)
{
	if (size <= 1)return;
	int index = partition(arr, size);
	quickSort(arr, index);
	quickSort(arr+index+1,size-(index+1));
}
void quickSortWithHeuristic(int arr[], int size)
{
	if (size <= 1)return;
	if (size == 2)
	{
		if (arr[0] > arr[1])
		{
			mySwap(arr[0],arr[1]);
		}	
		return;
	}
	int index = partitionWithMedian(arr, size);
	quickSortWithHeuristic(arr, index);
	quickSortWithHeuristic(arr+index+1, size -index-1);

}
int partition(int arr[], int size)
{
	if (size <= 1)return 0;
	int pivot = arr[0];
	int i=1, j=size-1;
	while (1)
	{
		while (arr[j]>pivot)j--;
		while (arr[i]<pivot&&i<j)i++;
		if (i >= j)
			break;
		mySwap(arr[i],arr[j]);
		i++; j--;
	}
	arr[0] = arr[j];
	arr[j] = pivot;
	return j;
}
int partitionWithMedian(int arr[], int size)
{
	int pivot = medianOf3(arr, size);
	int i = 0, j = size - 2;
	while (1)
	{	
		while (arr[++i] < pivot);
		while (arr[--j] > pivot);
		if (i < j) mySwap(arr[i], arr[j]);
		else break;
	}
	mySwap(arr[i],arr[size-2]);
	return i;
}
int medianOf3(int arr[], int size)
{
	int start = 0;
	int end = size - 1;
	int median = (start + end) / 2;
	if (arr[start] > arr[median])mySwap(arr[start],arr[median]);
	if (arr[start] > arr[end])mySwap(arr[start],arr[end]);
	if (arr[median] > arr[end])mySwap(arr[median],arr[end]);
	mySwap(arr[median],arr[end - 1]);
	return arr[end - 1];
}
void mySwap(int& a, int& b)
{
	if (&a == &b)return;
	/*int temp;
	temp = b;
	b = a;
	a = temp;*/
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}