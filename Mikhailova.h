#pragma once
#include <list>

using namespace std;

template <typename T, template <typename...> class Conteiner>
void bubbleSort(Conteiner<T>& sortedList) {
    bool swapped;
    do
    {
        swapped = false; 
        auto prev = sortedList.begin();
        auto current = prev;
        int count = 0;
        ++current;
        while (current != sortedList.end()) {
            if (*prev > *current) {
                swap(*prev, *current);
                swapped = true;
                count++;
            }
            ++prev;
            ++current;
        }
    } while (swapped);
}