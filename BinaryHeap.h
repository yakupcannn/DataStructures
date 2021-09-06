#ifndef BINARY_HEAP
#define BINARY_HEAP
#include<vector>
#include<math.h>
#define INT_MIN -100000
using namespace std;
class BinaryHeap
{
public:
	BinaryHeap()
	{
		size = 1;
		heap.resize(size);
		heap[0] = INT_MIN;
	}
	int findMin()
	{
		if (size < 1)
			return -1;
		return heap[1];
	}
	void deleteMin()
	{
		if (size <= 1)
			return;
		//int min = findMin();
		heap[1] = heap[size - 1];
		size--;
		heap.resize(size);
		int node = 1;
		while (1)
		{
			int smallest = node;
			int leftChild = 2 * node;
			int rightChild = 2 * node + 1;
			if (leftChild < size && rightChild<size &&heap[leftChild] <= heap[rightChild])
			{
				if (heap[smallest] > heap[leftChild])
				{
					smallest = leftChild;
				}
			}
			else if (rightChild < size && leftChild < size && heap[leftChild] > heap[rightChild])
			{
				if (heap[smallest] > heap[rightChild])
				{
					smallest = rightChild;
				}
			}
			if (node == smallest)return;
			int temp = heap[node];
			heap[node] = heap[smallest];
			heap[smallest] = temp;
			node = smallest;
		}
	}
	void increaseKey(int index, int delta)
	{
		if (heap.size() > index)
		{
			int node = index;
			heap[index] += delta;
			while (1)
			{
				int smallest = node;
				int leftChild = 2 * node;
				int rightChild = 2 * node + 1;
				if (leftChild < size && rightChild < size && heap[leftChild] <= heap[rightChild])
				{
					if (heap[smallest] > heap[leftChild])
					{
						smallest = leftChild;
					}
				}
				else if (rightChild < size && leftChild < size && heap[leftChild] > heap[rightChild])
				{
					if (heap[smallest] > heap[rightChild])
					{
						smallest = rightChild;
					}
				}
				if (node == smallest)return;
				int temp = heap[node];
				heap[node] = heap[smallest];
				heap[smallest] = temp;
				node = smallest;
			}
		}
	}
	void decreaseKey(int index, int delta)
	{
		
		if (heap.size() > index)
		{
			int node = index;
			heap[index] -= delta;
			while (1)
			{
				int parent = node / 2;
				if (heap[parent] <= heap[node])return;
				int temp = heap[parent];
				heap[parent] = heap[node];
				heap[node] = temp;
				node = parent;
			}
		}
		
	}
	void insert(int key)
	{
		size++;
		heap.resize(size);
		heap[size - 1] = key;
		int node = size - 1;
		while (1)
		{
			int parent = node / 2;
			if (heap[parent] <= heap[node])return;
			int temp = heap[parent];
			heap[parent] = heap[node];
			heap[node] = temp;
			node = parent;

		}
	}
	void printHeap()
	{
		cout << "[";
		for (int i = 1; i < heap.size(); i++)
		{
			cout << heap[i];
			if (i < size - 1)
				cout << ",";
		}
		cout << "]";
	}
private:
	int size;
	vector<int> heap;
};
#endif // BINARY_HEAP

