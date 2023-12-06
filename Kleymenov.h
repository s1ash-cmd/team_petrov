#pragma once
#include <iostream>
#include <list>
using namespace std;

template <typename T>
list<T> merge(const list<T>& left, const list<T>& right)
{
    list<T> result;
    auto leftIter = left.begin();
    auto rightIter = right.begin();
    while (leftIter != left.end() && rightIter != right.end())
    {
        if (*leftIter < *rightIter)
        {
            result.push_back(*leftIter);
            ++leftIter;
        }
        else {
            result.push_back(*rightIter);
            ++rightIter;
        }
    }
    while (leftIter != left.end())
    {
        result.push_back(*leftIter);
        ++leftIter;
    }
    while (rightIter != right.end())
    {
        result.push_back(*rightIter);
        ++rightIter;
    }
    return result;
}

template <typename T>
list<T> mergeSort(const list<T>& lst)
{
    if (lst.size() <= 1)
    {
        return lst;
    }
    list<T> left, right;
    auto middle = lst.begin();
    advance(middle, lst.size() / 2);
    copy(lst.begin(), middle, back_inserter(left));
    copy(middle, lst.end(), back_inserter(right));
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}