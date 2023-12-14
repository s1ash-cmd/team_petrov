#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <forward_list>
#include <string>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <chrono>

#include "Mikhailova.h"
#include "Skryagina.h"
#include "Lavrova.h"
#include "Kleymenov.h"
#include "Gadjiev.h"
#include "Afanasyeva.h"

using namespace std;

template <typename T>
list<T> listfromfile(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Unable to open the file" << endl;
        return {};
    }

    list<T> numbers;
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string token;

        while (getline(iss, token, ',')) {
            try {
                size_t pos;
                T number = stoul(token, &pos);

                if (pos != token.size()) {
                    throw invalid_argument("Invalid data in the file");
                }

                numbers.push_front(number);
            }
            catch (const exception& e) {
                cerr << e.what() << endl;
                numbers.clear();
                return numbers;
            }
        }
    }

    inputFile.close();
    return numbers;
}

template <typename T>
forward_list<T> flistfromfile(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Unable to open the file" << endl;
        return {};
    }

    forward_list<T> numbers;
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string token;

        while (getline(iss, token, ',')) {
            try {
                size_t pos;
                T number = stoul(token, &pos);

                if (pos != token.size()) {
                    throw invalid_argument("Invalid data in the file");
                }

                numbers.push_front(number);
            }
            catch (const exception& e) {
                cerr << e.what() << endl;
                numbers.clear();
                return numbers;
            }
        }
    }

    inputFile.close();
    return numbers;
}

int main() {
    list<int> selectionsortl = listfromfile<int>("int_1000.txt");
    list<int> combsortl = listfromfile<int>("int_1000.txt");
    list<int> insertionsortl = listfromfile<int>("int_1000.txt");
    list<int> mergesortl = listfromfile<int>("int_1000.txt");
    list<int> heapsortl = listfromfile<int>("int_1000.txt");
    list<int> bubblesortl = listfromfile<int>("int_1000.txt");

    auto start1 = chrono::steady_clock::now();
    bubbleSort(bubblesortl);
    auto end1 = chrono::steady_clock::now();

    cout << "bubbleSort: "
        << chrono::duration_cast<chrono::microseconds>(end1 - start1).count()
        << " mcs" << endl;

    auto start2 = chrono::steady_clock::now();
    combsort(combsortl);
    auto end2 = chrono::steady_clock::now();

    cout << "combsort: "
        << chrono::duration_cast<chrono::microseconds>(end2 - start2).count()
        << " mcs" << endl;

    auto start3 = chrono::steady_clock::now();
    heapSort(heapsortl);
    auto end3 = chrono::steady_clock::now();

    cout << "heapSort: "
        << chrono::duration_cast<chrono::microseconds>(end3 - start3).count()
        << " mcs" << endl;

    auto start4 = chrono::steady_clock::now();
    mergeSort(mergesortl);
    auto end4 = chrono::steady_clock::now();

    cout << "mergesort: "
        << chrono::duration_cast<chrono::microseconds>(end4 - start4).count()
        << " mcs" << endl;

    auto start5 = chrono::steady_clock::now();
    InsertionSort(insertionsortl);
    auto end5 = chrono::steady_clock::now();

    cout << "insertionsort: "
        << chrono::duration_cast<chrono::microseconds>(end5 - start5).count()
        << " mcs" << endl;

    auto start6 = chrono::steady_clock::now();
    selectionSort(selectionsortl);
    auto end6 = chrono::steady_clock::now();

    cout << "selectionsort: "
        << chrono::duration_cast<chrono::microseconds>(end6 - start6).count()
        << " mcs" << endl;

    return 0;
}