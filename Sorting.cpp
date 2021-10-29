//
// Created by Thiago André Ferreira Medeiros on 10/28/2021.
//

#include "Sorting.h"

/*
 *  Class that creates data,
 *  Sorts data according to selected algorithm and
 *  Checks if it was correctly sorted
 */
Sorting::Sorting(Parameters parameters) {
    size = parameters.getNumberElements();

    if (parameters.isElementsConstant()) {
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    } else if (parameters.isElementsRandom()) {
        for (int i = 0; i < size; ++i) {
            data[i] = rand();
        }
    } else if (parameters.isElementsSorted()) {
        for (int i = 0; i < size; ++i) {
            data[i] = i;
        }
    }

    if (parameters.isSelectionSort()) {
        algorithmName = SELECTION_SORT_NAME;
    } else if (parameters.isInsertionSort()) {
        algorithmName = INSERTION_SORT_NAME;
    } else if (parameters.isQuickSort()) {
        algorithmName = QUICKSORT_NAME;
    }
}

/*
 *  Implements Selection Sort Algorithm
 */
void Sorting::selectionSort() {
    int i, j, min_idx;

    for (i = 0; i < size-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (data[j] < data[min_idx])
                min_idx = j;

        swap(data[min_idx], data[i]);
    }
}

/*
 *  Implements Insertion Sort Algorithm
 */
void Sorting::insertionSort() {
    int i, key, j;

    for (i = 1; i < size; i++)
    {
        key = data[i];
        j = i - 1;

        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

/*
 *  Implements QuickSort Algorithm
 */
void Sorting::quickSortMedianOfThree(int start, int end) {
    int pivot;

    if (end - start < 2) {
        return;
    }

    pivot = medianOfThreePartition(start, end);

    quickSortMedianOfThree(start, pivot);

    quickSortMedianOfThree(pivot, end);
}

/*
 *  Calculates the median-of-three as a pivot,
 *  Partition the data according to it and
 *  Returns the pivot position in the data
 */
int Sorting::medianOfThreePartition(int start, int end) {
    int x = data[start];
    int y = data[(end - start) / 2 + start];
    int z = data[end - 1];
    int i = start - 1;
    int j = end;

    if (y > x && y < z ||
        y > z && y < x ) {
        x = y;
    } else if (z > x && z < y ||
               z > y && z < x ) {
        x = z;
    }

    while (true) {
        do  {
            j--;
        } while (data[j] > x);

        do  {
            i++;
        } while (data[i] < x);

        if  (i < j) {
            swap(data[i], data[j]);
        } else {
            return j+1;
        }
    }
}

/*
 *  Verify if the data was correctly sorted
 */
bool Sorting::verifySorting() {
    for (int i = 1; i < size; ++i) {
        if (data[i - 1] > data[i]) {
            return false;
        }
    }

    return true;
}

/*
 *  Returns cpu time in nanoseconds
 */
double get_cpu_time(){
    FILETIME a,b,c,d;
    if (GetProcessTimes(GetCurrentProcess(),&a,&b,&c,&d) != 0){
        //  Returns total user time.
        //  Can be tweaked to include kernel times as well.
        return
                (double)(d.dwLowDateTime |
                         ((unsigned long long)d.dwHighDateTime << 32)) * 0.1;
    }else{
        //  Handle error
        return 0;
    }
}

/*
 *  Sort data according to the selected algorithm,
 *  prints the time taken to sort and
 *  verifies if it was corrected sorted.
 */
void Sorting::sort() {
    time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    double start = get_cpu_time();
    double end;

    if (algorithmName == SELECTION_SORT_NAME) {
        time = chrono::system_clock::to_time_t(chrono::system_clock::now());

        cout << "<call_sort> " << ctime(&time);

        start = get_cpu_time();

        selectionSort();
    } else if (algorithmName == INSERTION_SORT_NAME) {
        time = chrono::system_clock::to_time_t(chrono::system_clock::now());

        cout << "<call_sort> " << ctime(&time);

        start = get_cpu_time();

        insertionSort();
    } else if (algorithmName == QUICKSORT_NAME) {
        time = chrono::system_clock::to_time_t(chrono::system_clock::now());

        cout << "<call_sort> " << ctime(&time);

        start = get_cpu_time();

        quickSortMedianOfThree(0, size);
    }

    end = get_cpu_time();

    double elapsed = (end - start);

    time = chrono::system_clock::to_time_t(chrono::system_clock::now());

    cout << "<end_time> " << ctime(&time);

    printf("\nTime taken: %.0f nanoseconds\n\n", elapsed);

    if (verifySorting()) {
        cout << "Data correctly sorted after running " << algorithmName << ".\n";
    } else {
        cout << "Data incorrectly sorted after running " << algorithmName << ".\n";
    }
}
