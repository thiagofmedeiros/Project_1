//
// Created by mirdo on 10/28/2021.
//

#ifndef PROJECT_1_SORTING_H
#define PROJECT_1_SORTING_H

#include <chrono>
#include <processthreadsapi.h>
#include "Parameters.h"

#define SELECTION_SORT_NAME "Selection Sort"
#define INSERTION_SORT_NAME "Insertion Sort"
#define QUICKSORT_NAME "QuickSort"

class Sorting {
private:
    int size;
    int data[500000]{};
    string algorithmName;
    void selectionSort();
    void insertionSort();
    void quickSortMedianOfThree(int start, int end);
    int medianOfThreePartition(int start, int end);
    bool verifySorting();
public:
    explicit Sorting(Parameters parameters);

    void sort();
};


#endif //PROJECT_1_SORTING_H
