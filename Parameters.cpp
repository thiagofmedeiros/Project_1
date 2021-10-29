//
// Created by Thiago André Ferreira Medeiros on 10/27/2021.
//

#include "Parameters.h"

/*
 *  Class that reads the parameters received from the command line
 *  and validates them.
 */
Parameters::Parameters(int argc, char** argv) {
    parameterCount = argc;
    arguments = argv;

    validateParameters();
}

/*
 *  Initializes class members and
 *  Calculate if they are valid
 */
void Parameters::validateParameters() {
    if (parameterCount != 4) {
        cout << "Expecting 3 arguments and you have entered " << parameterCount
             << " arguments:" << "\n";
        validity = false;
    } else {
        sortingType = arguments[1];
        numberElements = atoi(arguments[2]);
        elementsType = arguments[3];

        validity = validateSortingType() &&
                   validateNumberElements() &&
                   validateElementsType();
    }
}

/*
 *  Validates the sorting type
 */
bool Parameters::validateSortingType() {
    if (!(strcmp(sortingType, SELECTION_SORT) == 0 ||
          strcmp(sortingType, INSERTION_SORT) == 0 ||
          strcmp(sortingType, QUICKSORT) == 0)) {

        cout << "Not expecting " << sortingType
                  << " as sorting type:" << "\n";
        return false;
    }

    return true;
}

/*
 *  Validates the number of elements.
 *  Due to memory restrictions,
 *  saturates number of elements at 500000.
 */
bool Parameters::validateNumberElements() {
    if (!(numberElements == 10000 ||
          numberElements == 20000 ||
          numberElements == 30000 ||
          numberElements == 40000 ||
          numberElements == 50000 ||
          numberElements == 60000 ||
          numberElements == 70000 ||
          numberElements == 80000 ||
          numberElements == 90000 ||
          numberElements == 100000 ||
          numberElements == 500000 ||
          numberElements == 1000000 ||
          numberElements == 10000000 ||
          numberElements == 100000000 ||
          numberElements == 1000000000
    )) {
        cout << "Not expecting " << numberElements
                  << " as number of elements:" << "\n";
        return false;
    }

    if (numberElements > 500000) {
        cout << "Program only works at max 500000 number of elements:" << "\n";
        numberElements = 500000;
    }

    return true;
}

/*
 *  Validates the elements type
 */
bool Parameters::validateElementsType() {
    if (!(strcmp(elementsType, SORTED) == 0 ||
          strcmp(elementsType, CONSTANT) == 0 ||
          strcmp(elementsType, RANDOM) == 0)) {

        cout << "Not expecting " << elementsType
                  << " as elements type:" << "\n";
        return false;
    }

    return true;
}

bool Parameters::isValid() const {
    return validity;
}

bool Parameters::isSelectionSort() {
    return strcmp(sortingType, SELECTION_SORT) == 0;
}

bool Parameters::isInsertionSort() {
    return strcmp(sortingType, INSERTION_SORT) == 0;
}

bool Parameters::isQuickSort() {
    return strcmp(sortingType, QUICKSORT) == 0;
}

bool Parameters::isElementsSorted() {
    return strcmp(elementsType, SORTED) == 0;
}

bool Parameters::isElementsConstant() {
    return strcmp(elementsType, CONSTANT) == 0;
}

bool Parameters::isElementsRandom() {
    return strcmp(elementsType, RANDOM) == 0;
}

int Parameters::getNumberElements() const {
    return numberElements;
}
