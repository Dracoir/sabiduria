/*
 * Sorting algorithms adapted from pseudocode taken from
 * "Data Structures, Algorithms, and Software Principles in C"
 *   by Thomas A. Standish
 *
 *  Created on: Feb 20, 2011
 *      Author: ricardorodriguez
 */

#ifndef SORTS_H_
#define SORTS_H_

namespace Sabiduria {

namespace Sorting {

class Sorts {
public:
	Sorts();
	virtual ~Sorts();

	void QuickSort(int *intArray, int sizeOfArray);
	void MergeSort(int *firstArray, int sizeOfArray);

private:
	void QuickSort(int *intArray, int minSubscript, int maxSubscript);
	void Partition(int *intArray, int *leftArray, int *rightArray);
	void MergeSort(int *intArray, int firstSubscript, int lastSubscript);
	void Merge(int *intArray, int firstSubscript, int mid, int lastSubscript);
};

}
}
#endif /* SORTS_H_ */
