#include "pch.h"
#include "Heap.h"
#include <algorithm>

Heap::Heap()
{
	heap.resize(CAPACITY);
	sortedHeap.resize(CAPACITY);
}


Heap::~Heap()
{
}

void Heap::insert(int item)
{
	// we are not able to insert more items than the value of the capacity
	if (isHeapFull())
		throw std::overflow_error("Heap is full");

	//insert the item and increment the counter
	heap[heapSize] = item;
	++heapSize;

	// we insert the item to the last position of the array
	// then we restore up the heap
	fixUp(heapSize - 1);
}

int Heap::getMax() const
{
	if (heapSize == 0)
		throw std::length_error("Heap is empty");

	return heap[0];
}

int Heap::poll()
{
	int max = getMax();

	std::swap(heap[0], heap[heapSize - 1]);
	--heapSize;

	fixDown(0);
	return max;
}  

std::vector<int> Heap::heapsort()
{
	int size = heapSize;

	for (auto i = 0; i < size; i++) {
		sortedHeap[i] = poll();
	}

	return sortedHeap;
}

void Heap::fixUp(int index)
{
	// the parent index of the given node in the heap
	// we store the heap in an array
	int parentIndex = (index - 1) / 2;

	// while the inx > 0 means until we consider ll the items above the one we insterted
	// we have to swap the node witht the parent if the heap property is violated
	// it is a max heap so the max is located at the root node
	if (index > 0 && heap[index] > heap[parentIndex]) {
	std::swap(heap[index], heap[parentIndex]);
		fixUp(parentIndex);
	}
}

void Heap::fixDown(int index)
{
	// every node has a left and right child
	// for a given node i the left child is 2*i+1 and the right child is 2*i+2
	int indexLeft = 2 * index + 1;
	int indexRight = 2 * index + 2;

	// max heap so the parent node is always greater than the children
	int indexLargest = index;

	// if the left child is greater than the parent: largest is the left node
	if (indexLeft < heapSize && heap[indexLargest] < heap[indexLeft]) {
		indexLargest = indexLeft;
	}

	// if the right child is greater than the parent: largest is the right node
	if (indexRight < heapSize && heap[indexRight] > heap[indexLargest]) {
		indexLargest = indexRight;
	}

	// we do not want to swap items with themselves
	if (indexLargest != index) {
		std::swap(heap[index], heap[indexLargest]);
		fixDown(indexLargest);
	}
}

bool Heap::isHeapFull() const
{
	return CAPACITY == heapSize;
}
