#include <iostream>
#include <string>
#include <vector>

#include "Utility.h"

#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShakeSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "QuickSort_IN_SE.h"
#include "MergeSort_IN_SE.h"

typedef int KeyType;

int main() {
	std::vector<KeyType> v = {212, 237, 342, 132, 368, 347, 174, 672, 230, 154};
	//insertionSort(v, v.size());
	//selectionSort(v, v.size());
	//bubbleSort(v, v.size());
	//shakeSort(v, v.size());
	//heapSort(v, v.size());
	//quickSort(v, 0, v.size() - 1);
	mergeSort(v, 0, v.size() - 1);
	//shellSort(v, v.size() - 1, 0.5);
	//quickSort_IN_SE(v, v.size());
	//mergeSortInSe(v, v.size());
	std::cout << "Sorted: " << v;
}