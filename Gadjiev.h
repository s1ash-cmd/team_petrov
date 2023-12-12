#pragma once
#include <list>

template <typename T>
void InsertionSort(std::list<T>& arr) {
    for (auto iter = std::next(arr.begin()); iter != arr.end(); ++iter) {
        auto key = *iter;
        auto prev_iter = iter;

        while (prev_iter != arr.begin() && *std::prev(prev_iter) > key) {
            *prev_iter = *std::prev(prev_iter);
            --prev_iter;
        }

        *prev_iter = key;
    }
}
