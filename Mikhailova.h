#pragma once
#include <list>

using namespace std;

template <typename T>
void bubbleSort(list<T>& sortedList) {
    bool swapped;
    do
    {
        swapped = false; 
        auto prev = sortedList.begin();
        auto current = prev;
        ++current;
        while (current != sortedList.end()) {
            if (*prev > *current) {
                swap(*prev, *current);
                swapped = true;
            }
            ++prev;
            ++current;
        }
    } while (swapped);
}