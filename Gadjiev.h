#pragma once
#include <list>

template <typename T>
std::list<T> InsertionSort(std::list<T>& arr) {
    for (auto iter = std::next(arr.begin()); iter != arr.end(); ++iter) {
        auto prev_iter = iter;
        while (prev_iter != arr.begin() && *prev_iter >= *iter) {
            std::advance(prev_iter, -1);
        }
        std::list<T> ans;
        if (prev_iter == arr.begin() && *prev_iter > *iter) {
            ans.assign({ *iter });
            ans.insert(ans.end(), arr.begin(), iter);
            ans.insert(ans.end(), std::next(iter), arr.end());
        }
        else {
            ans.insert(ans.end(), arr.begin(), std::next(prev_iter));
            ans.push_back(*iter);
            ans.insert(ans.end(), std::next(prev_iter), iter);
            ans.insert(ans.end(), std::next(iter), arr.end());
        }
        arr = ans;
    }
    return arr;
}
