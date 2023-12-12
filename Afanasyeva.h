#pragma once
#ifndef COMBSORT_H
#define COMBSORT_H

#include <list>
#include <iterator>

template<typename T>
void combsort(std::list<T>& arr) {
    const double shrinkFactor = 1.3; // Коэффициент сжатия

    int size = arr.size();
    int gap = size;
    bool swapped = true;

    do {
        // Обновляем шаг сортировки
        if (gap > 1)
            gap = static_cast<int>(gap / shrinkFactor);

        if (gap < 1) {
            gap = 1;
        }

        swapped = false;

        auto it1 = arr.begin();
        auto it2 = std::next(it1, gap);

        while (it2 != arr.end()) {
            if (*it2 < *it1) {
                std::iter_swap(it1, it2);
                swapped = true;
            }
            ++it1;
            ++it2;
        }
    } while (gap > 1 || swapped);
}

#endif // COMBSORT_H
