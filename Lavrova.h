#pragma once
#include <iostream>
#include <list>

using namespace std;

// Функция для восстановления свойства "кучи" вдоль пути вверх
void heapifyUp(list<int>& heap, list<int>::iterator it) {
    list<int>::iterator parent;

    while (it != heap.begin()) {
        parent = prev(it);

        if (*it > *parent)
            break;

        swap(*it, *parent);
        it = parent;
    }
}

// Функция для восстановления свойства "кучи" вдоль пути вниз
void heapifyDown(list<int>& heap, list<int>::iterator it) {
    list<int>::iterator smallestChild;

    while (true) {
        smallestChild = it;

        // Находим меньшего из двух детей
        auto leftChild = next(it);
        auto rightChild = next(it, 2);

        if (leftChild != heap.end() && *leftChild < *smallestChild)
            smallestChild = leftChild;

        if (rightChild != heap.end() && *rightChild < *smallestChild)
            smallestChild = rightChild;

        // Если текущий элемент уже самый маленький, завершаем цикл
        if (smallestChild == it)
            break;

        // Иначе, меняем местами с меньшим ребенком и переходим к следующему уровню
        swap(*it, *smallestChild);
        it = smallestChild;
    }
}

// Функция для построения кучи из списка
void buildHeap(list<int>& heap) {
    auto it = next(heap.begin(), heap.size() / 2);

    while (it != heap.begin()) {
        heapifyDown(heap, it);
        it = prev(it);
    }

    heapifyDown(heap, heap.begin());
}

// Функция для сортировки списка с использованием HeapSort
void heapSort(list<int>& array) {
    // Строим кучу из списка
    buildHeap(array);

    // Извлекаем элементы в отсортированном порядке
    int size = array.size();

    for (int i = 0; i < size; i++) {
        swap(array.front(), array.back());
        array.pop_back();

        heapifyDown(array, array.begin());
    }
}