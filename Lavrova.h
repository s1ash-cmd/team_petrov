#pragma once
#include <list>

template <typename T>
void heapify(std::list<T>& lst, typename std::list<T>::iterator it, typename std::list<T>::iterator end) {
    auto largest = it;
    auto left = std::next(it);
    auto right = std::next(it, 2);

    if (left != end && *left > *largest)
        largest = left;

    if (right != end && *right > *largest)
        largest = right;

    if (largest != it) {
        lst.splice(it, lst, largest);
        heapify(lst, largest, end);
    }
}

template <typename T>
void heapSort(std::list<T>& lst) {
    for (auto it = std::prev(lst.end()); it != lst.begin(); --it) {
        heapify(lst, lst.begin(), std::next(it));
    }

    for (auto it = std::prev(lst.end()); it != lst.begin(); --it) {
        lst.splice(it, lst, lst.begin());
        heapify(lst, lst.begin(), it);
    }
}