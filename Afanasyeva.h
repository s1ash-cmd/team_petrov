#pragma once
#ifndef COMBSORT_H
#define COMBSORT_H

#include <list>

template<typename T>
void combsort(std::list<T>& arr) {
    const double shrinkFactor = 1.3; // Коэффициент сжатия

    int size = arr.size();
    int gap = size;
    bool swapped = true;

    while (gap > 1 || swapped) {
        // Обновляем шаг сортировки
        if (gap > 1)
            gap = static_cast<int>(gap / shrinkFactor);

        swapped = false;

        // Перебираем элементы массива и меняем соседние, если необходимо
        auto it1 = arr.begin();
        auto it2 = std::next(it1, gap);

        for (; it2 != arr.end(); ++it1, ++it2) {
            if (*it2 < *it1) {
                std::iter_swap(it1, it2);
                swapped = true;
            }
        }
    }
}

#endif // COMBSORT_H