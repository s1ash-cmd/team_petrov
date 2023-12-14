#include <iostream>
#include <list>
using namespace std;

template <typename T, template <typename...> class Container>
void selectionSort(Container<T>& lst) {
    typename Container<T>::iterator min;  // итератор для минимального элемента
    for (typename Container<T>::iterator i = lst.begin(); i != lst.end(); ++i) {  // цикл по всем элементам списка
        min = i;  // предполагаем, что текущий элемент - минимальный
        for (typename Container<T>::iterator j = next(i); j != lst.end(); ++j) {  // цикл для поиска минимального элемента среди оставшихся
            if (*j < *min) {  // если очередной элемент меньше текущего минимального
                min = j;  // обновляем минимальный элемент
            }
        }
        swap(*i, *min);  // меняем местами текущий элемент и минимальный элемент
    }
}                                             