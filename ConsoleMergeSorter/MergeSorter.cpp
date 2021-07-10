#include <iostream>
#include "MergeSorter.h"

void MergeSorter::merge(int array[], int const left, int const mid, int const right)
{
    //Temp Arrays
    auto const tempArrayOne = mid - left + 1;
    auto const tempArrayTwo = right - mid;

    //Creates Arrays
    auto* leftArray = new int[tempArrayOne],
        * rightArray = new int[tempArrayTwo];

    //Copy data to temp arrays left and right array
    for (auto i = 0; i < tempArrayOne; i++) {
        leftArray[i] = array[left + i];
    }
    for (auto j = 0; j < tempArrayTwo; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    auto indexOfTempArrayOne = 0,
        indexOfTempArrayTwo = 0;
    int indexOfMergedArray = left;

    //Merge the temp arrays back into array[left, right]
    while (indexOfTempArrayOne < tempArrayOne && indexOfTempArrayTwo < tempArrayTwo) {
        if (leftArray[indexOfTempArrayOne] <= rightArray[indexOfTempArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfTempArrayOne];
            indexOfTempArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfTempArrayTwo];
            indexOfTempArrayTwo++;
        }
        indexOfMergedArray++;
    }

    //Copy the remaining to left[]
    while (indexOfTempArrayOne < tempArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfTempArrayOne];
        indexOfTempArrayOne++;
        indexOfMergedArray++;
    }
    //Copy the remaining to right[]
    while (indexOfTempArrayTwo < tempArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfTempArrayTwo];
        indexOfTempArrayTwo++;
        indexOfMergedArray++;
    }

}

void MergeSorter::mergeSort(int array[], int begin, int end) {
    if (begin >= end)
        return; // Returns recursivly

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}