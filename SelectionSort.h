#include <iostream>
#include <list>
using namespace std;

template <typename T>
void selectionSort(list<T>& lst) {
    typename list<T>::iterator min;  // итератор для минимального элемента
    for (typename list<T>::iterator i = lst.begin(); i != lst.end(); ++i) {  // цикл по всем элементам списка
        min = i;  // предполагаем, что текущий элемент - минимальный
        for (typename list<T>::iterator j = next(i); j != lst.end(); ++j) {  // цикл для поиска минимального элемента среди оставшихся
            if (*j < *min) {  // если очередной элемент меньше текущего минимального
                min = j;  // обновляем минимальный элемент
            }
        }
        swap(*i, *min);  // меняем местами текущий элемент и минимальный элемент
    }
}