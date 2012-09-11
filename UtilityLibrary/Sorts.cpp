/*
 * Sorts.cpp
 *
 *  Created on: Feb 20, 2011
 *      Author: ricardorodriguez
 */

#include "Sorts.h"

namespace Utilities {

namespace Sorting {

////////////////////////////////////////////////////////////////////////////////////
Sorts::Sorts() {
	// TODO Auto-generated constructor stub

}

////////////////////////////////////////////////////////////////////////////////////
Sorts::~Sorts() {
	// TODO Auto-generated destructor stub
}

////////////////////////////////////////////////////////////////////////////////////
void Sorts::QuickSort(int *intArray, int maxSubscript)
{
	QuickSort(intArray, 0, maxSubscript-1);
}
////////////////////////////////////////////////////////////////////////////////////
void Sorts::QuickSort(int *intArray, int minSubscript, int maxSubscript)
{
	int i, j;

	if(minSubscript < maxSubscript)
	{
		i = minSubscript; j = maxSubscript;
		Partition(intArray, &i, &j);
		QuickSort(intArray, minSubscript, j);
		QuickSort(intArray, i, maxSubscript);
	}
}

////////////////////////////////////////////////////////////////////////////////////
void Sorts::MergeSort(int *intArray, int sizeOfArray)
{
	MergeSort(intArray, 0, sizeOfArray-1);
}

////////////////////////////////////////////////////////////////////////////////////
void Sorts::MergeSort(int *intArray, int firstSubscript, int lastSubscript)
{
	int mid;

	if (lastSubscript > firstSubscript) {
		mid = (lastSubscript + firstSubscript) / 2;
		MergeSort(intArray, firstSubscript, mid);
		MergeSort(intArray, (mid+1), lastSubscript);

		Merge(intArray, firstSubscript, mid+1, lastSubscript);
	}
}

////////////////////////////////////////////////////////////////////////////////////
void Sorts::Merge(int *intArray, int firstSubscript, int mid, int lastSubscript)
{
	int left          = firstSubscript,      // Variable used to control where to place items in temp array
	    lastLeft      = mid - 1,             // This variable will never change.  It will block the leftSubscript from incrementing
		numOfElements = lastSubscript - firstSubscript + 1;
	int *tempArray = new int[numOfElements]; // Temp array to hold all the variables


	// While we haven't swept past the middle, compare the first and mid values,
	// incrementing each with every respective comparison, if true, saving the smallest value
	// to the temp array
	while(firstSubscript <= lastLeft && mid <= lastSubscript)
	{
		if(intArray[firstSubscript] <= intArray[mid])
		{
			tempArray[left++] = intArray[firstSubscript++];
		} else {
			tempArray[left++] = intArray[mid++];
		}
	}

	// If the firstSubscript variable hasn't past the mid-1
	// value passed into the function, add its value to the temp array
	while(firstSubscript <= lastLeft)
	{
		tempArray[left++] = intArray[firstSubscript++];
	}

	// If the mid variable has not passed the last lastSubscript variable,
	// passed into the array, make sure to add the rest of the array values
	while(mid <= lastSubscript)
	{
		tempArray[left++] = intArray[mid++];
	}

	// Finally, copy the contents of the temp array into the integer array
	while(lastSubscript >= 0)
	{
		intArray[lastSubscript] = tempArray[lastSubscript++];
	}

	delete [] tempArray;
}

////////////////////////////////////////////////////////////////////////////////////
void Sorts::Partition(int *intArray, int *leftSubscript, int *rightSubscript)
{
	int tmp;
	int pivot = intArray[(*leftSubscript + *rightSubscript) / 2];

	      /* partition */
	      while (*leftSubscript <= *rightSubscript) {
	            while (intArray[*leftSubscript] < pivot)
	                  (*leftSubscript)++;
	            while (intArray[*rightSubscript] > pivot)
	                  (*rightSubscript)--;
	            if (*leftSubscript <= *rightSubscript) {
	                  tmp = intArray[*leftSubscript];
	                  intArray[*leftSubscript] = intArray[*rightSubscript];
	                  intArray[*rightSubscript] = tmp;
	                  (*leftSubscript)++;
	                  (*rightSubscript)--;
	            }
	      };
}
////////////////////////////////////////////////////////////////////////////////////

}
}
