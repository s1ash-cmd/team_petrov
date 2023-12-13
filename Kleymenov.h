#pragma once
#include <iostream>
#include <list>
#include <algorithm>  // ��� std::move
using namespace std;

template <typename T, template<typename...> class Container>
void merge(Container<T>& result, Container<T>& left, Container<T>& right) {
    auto leftIter = left.begin();
    auto rightIter = right.begin();
    while (leftIter != left.end() && rightIter != right.end()) {
        if (*leftIter < *rightIter) {
            result.splice(result.end(), left, leftIter++);
        }
        else {
            result.splice(result.end(), right, rightIter++);
        }
    }
    result.splice(result.end(), left, leftIter, left.end());
    result.splice(result.end(), right, rightIter, right.end());
}

template <typename T, template<typename...> class Container>
void mergeSort(Container<T>& lst) {
    if (lst.size() <= 1) {
        return;
    }
    list<T> left, right;
    auto middle = std::next(lst.begin(), lst.size() / 2);
    left.splice(left.begin(), lst, lst.begin(), middle);
    right.splice(right.begin(), lst, middle, lst.end());
    mergeSort(left);
    mergeSort(right);
    lst.clear();  // ������� ������������ ������
    merge(lst, left, right);
}
