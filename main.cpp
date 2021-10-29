#include "Parameters.h"
#include <chrono>
#include <ctime>

int medianOfThreePartition(int data[], int start, int end) {
    int pivot = data[start];
    int y = data[(end - start) / 2 + start];
    int z = data[end - 1];
    int i = start - 1;
    int j = end;

    if (y > pivot && y < z ||
        y > z && y < pivot ) {
        pivot = y;
    } else if (z > pivot && z < y ||
                z > y && z < pivot ) {
        pivot = z;
    }

    while (true) {
        do  {
            j--;
        } while (data[j] > pivot);

        do  {
            i++;
        } while (data[i] < pivot);

        if  (i < j) {
            swap(data[i], data[j]);
        } else {
            return j+1;
        }
    }
}

void quickSortMedian(int data[],int start,int end) {
    int median;

    if (end - start < 2) {
        return;
    }

    median = medianOfThreePartition(data,start,end);

    quickSortMedian(data,start,median);

    quickSortMedian(data,median,end);
}

void insertionSort(int data[], int size)
{
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

void selectionSort(int data[], int size) {
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

bool verifySorting(const int data[], int size) {
    for (int i = 1; i < size; ++i) {
        if (data[i - 1] > data[i]) {
            return false;
        }
    }

    return true;
}

int main(int argc, char** argv) {
    clock_t tStart = clock();
    string algorithm;

    time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());

    cout << "<start_time> " << ctime(&time);

    cout << "Reading and validating parameters " << "\n";

    Parameters parameters(argc, argv);

    printf("Time taken: %.3fs\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    if (!parameters.isValid()) {
        return 1;
    }

    int size = parameters.getNumberElements();

    cout << "Creating data " << "\n";

    int data[500000];

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

    printf("Time taken: %.3fs\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    if (parameters.isSelectionSort()) {
        algorithm = "Selection Sort";

        time = chrono::system_clock::to_time_t(chrono::system_clock::now());

        cout << "<call_sort> " << ctime(&time);

        tStart = clock();
        selectionSort(data, size);
    } else if (parameters.isInsertionSort()) {
        algorithm = "Insertion Sort";

        time = chrono::system_clock::to_time_t(chrono::system_clock::now());

        cout << "<call_sort> " << ctime(&time);

        tStart = clock();
        insertionSort(data, size);
    } else if (parameters.isQuickSort()) {
        algorithm = "QuickSort";

        time = chrono::system_clock::to_time_t(chrono::system_clock::now());

        cout << "<call_sort> " << ctime(&time);

        tStart = clock();
        quickSortMedian(data, 0, size);
    }

    time = chrono::system_clock::to_time_t(chrono::system_clock::now());

    cout << "<end_time> " << ctime(&time);

    printf("Time taken: %.3fs\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    if (verifySorting(data, size)) {
        cout << "Data correctly sorted after running " << algorithm << ".\n\n";
    } else {
        cout << "Data incorrectly sorted after running " << algorithm << ".\n\n";
    }

    return 0;
}
