//
// Created by Thiago André Ferreira Medeiros on 10/26/2021.
//
#include "Sorting.h"

int main(int argc, char** argv) {

    time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());

    cout << "<start_time> " << ctime(&time);

    Parameters parameters(argc, argv);

    if (!parameters.isValid()) {
        return 1;
    }

    Sorting sorting(parameters);

    sorting.sort();

    return 0;
}
