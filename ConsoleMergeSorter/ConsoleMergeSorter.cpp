#include <iostream>
#include "MergeSorter.h"

void printArray(int array[], int size);

int main()
{
    MergeSorter m;
    int arrTo[] = {19026, 53070, 47038, 35720, 71715, 93820, 9674, 50620};
    auto arrSize = sizeof(arrTo) / sizeof(arrTo[0]);
    std::string fakeInput;

    std::cout << "Given array is: ";
    printArray(arrTo, arrSize);
    std::cout << "\n\n";
    m.mergeSort(arrTo, 0, arrSize - 1);
    std::cout << "Sorted array is: ";
    printArray(arrTo, arrSize);
    std::cout << "\n";
    std::cin >> fakeInput;

    return 0;
}

void printArray(int array[], int size) {
    for (auto i = 0; i < size; i++) {
        std::cout << array[i] << "  ";
    }
}