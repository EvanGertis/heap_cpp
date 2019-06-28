#pragma once
#include <vector>

class Heap
{
	// we represent the heap data structure with an array
	std::vector<int> heap;

	// sorted heap;
	std::vector<int> sortedHeap;

	//we want to track the size of the heap
	int heapSize = 0;

	constexpr static int CAPACITY = 10;
public:
	Heap();
	~Heap();

	// insertion takes O(1) running time 
	// we must ensure that heap properties are not violated so it can take up to Olog(n)
	// to fix the heap
	void insert(int item);

	// the maximum value would be the root node. 
	// this method should take O(1) 
	int getMax() const;

	// this method will return the max and remove the node associated with it
	int poll();

	std::vector<int> heapsort();

private:

	// this method will restore up the heap
	// running time is O(logN)
	void fixUp(int index);

	// this method will restore down the heap
	void fixDown(int index);

	// returns true if the heap is full
	bool isHeapFull() const;

};

