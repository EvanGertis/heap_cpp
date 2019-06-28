#include "pch.h"
#include <iostream>
#include <stdlib.h> /* rand */
#include "Heap.h"

void showVec(std::vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " | ";
	}
	std::cout << std::endl;
}

int main()
{
	Heap heap;
	
	for (int i = 0; i < 10; i++) {
		int randomInteger = rand();
		heap.insert(randomInteger);
		std::cout << randomInteger << " | ";
	}
	std::cout << std::endl;

	showVec(heap.heapsort());
}
