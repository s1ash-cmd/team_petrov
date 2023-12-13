#pragma once
#include <list>

using namespace std;

list<int> InsertionSort(list<int>& arr) {
    for (auto iter = next(arr.begin()); iter != arr.end(); iter++) {
        auto prev_iter = iter;
        while (prev_iter != arr.begin() && *prev_iter >= *iter) {
            advance(prev_iter,-1);
        }
        list<int> ans;
        if (prev_iter == arr.begin() and *prev_iter>*iter) {
            ans.assign({ *iter });
            ans.insert(ans.end(), arr.begin(), iter);
            ans.insert(ans.end(), next(iter), arr.end());
        }
        else {
            ans.insert(ans.end(), arr.begin(), next(prev_iter));
            ans.push_back({ *iter });
            ans.insert(ans.end(), next(prev_iter), iter);
            ans.insert(ans.end(), next(iter), arr.end());
        }
        arr = ans;
    }
    return arr;
}