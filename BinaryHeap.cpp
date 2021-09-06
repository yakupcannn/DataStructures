#include<iostream>
#include"BinaryHeap.h"
using namespace std;
int main()
{
	BinaryHeap binaryheap;
	binaryheap.insert(2);
	binaryheap.insert(4);
	binaryheap.insert(3);
	binaryheap.insert(7);
	binaryheap.insert(5);
	binaryheap.insert(8);
	binaryheap.insert(9);
	binaryheap.insert(11);
	binaryheap.insert(9);
	binaryheap.insert(6);
	binaryheap.insert(10);
	binaryheap.printHeap();
	//cout <<"\n-----------deleting-------------\n";
	cout <<"\n-----------increasing-------------\n";
	binaryheap.decreaseKey(4, 6);
	//binaryheap.deleteMin();
	binaryheap.printHeap();



	return 0;
}