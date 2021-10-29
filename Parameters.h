//
// Created by Thiago André Ferreira Medeiros on 10/27/2021.
//

#ifndef PROJECT_1_PARAMETERS_H
#define PROJECT_1_PARAMETERS_H

#include <cstdlib>
#include <cstring>
#include <iostream>

#define SELECTION_SORT "s"
#define INSERTION_SORT "i"
#define QUICKSORT "q"

#define SORTED "s"
#define CONSTANT "c"
#define RANDOM "r"

using namespace std;

class Parameters {
private:
    int parameterCount = 0;
    int numberElements = -1;
    char **arguments;
    const char *sortingType;
    const char *elementsType;
    bool validity = false;

    void validateParameters();
    bool validateSortingType();
    bool validateNumberElements();
    bool validateElementsType();
public:
    Parameters(int argc, char **argv);
    bool isValid() const;
    bool isInsertionSort();
    bool isSelectionSort();
    bool isQuickSort();
    bool isElementsSorted();
    bool isElementsConstant();
    bool isElementsRandom();

    int getNumberElements() const;
};


#endif //PROJECT_1_PARAMETERS_H
