#pragma once
#include <iostream>
#include <list>

using namespace std;

// ������� ��� �������������� �������� "����" ����� ���� �����
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

// ������� ��� �������������� �������� "����" ����� ���� ����
void heapifyDown(list<int>& heap, list<int>::iterator it) {
    list<int>::iterator smallestChild;

    while (true) {
        smallestChild = it;

        // ������� �������� �� ���� �����
        auto leftChild = next(it);
        auto rightChild = next(it, 2);

        if (leftChild != heap.end() && *leftChild < *smallestChild)
            smallestChild = leftChild;

        if (rightChild != heap.end() && *rightChild < *smallestChild)
            smallestChild = rightChild;

        // ���� ������� ������� ��� ����� ���������, ��������� ����
        if (smallestChild == it)
            break;

        // �����, ������ ������� � ������� �������� � ��������� � ���������� ������
        swap(*it, *smallestChild);
        it = smallestChild;
    }
}

// ������� ��� ���������� ���� �� ������
void buildHeap(list<int>& heap) {
    auto it = next(heap.begin(), heap.size() / 2);

    while (it != heap.begin()) {
        heapifyDown(heap, it);
        it = prev(it);
    }

    heapifyDown(heap, heap.begin());
}

// ������� ��� ���������� ������ � �������������� HeapSort
void heapSort(list<int>& array) {
    // ������ ���� �� ������
    buildHeap(array);

    // ��������� �������� � ��������������� �������
    int size = array.size();

    for (int i = 0; i < size; i++) {
        swap(array.front(), array.back());
        array.pop_back();

        heapifyDown(array, array.begin());
    }
}