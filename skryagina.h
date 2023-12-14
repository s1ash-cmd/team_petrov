#include <iostream>
#include <list>
using namespace std;

template <typename T, template <typename...> class Container>
void selectionSort(Container<T>& lst) {
    typename Container<T>::iterator min;  // �������� ��� ������������ ��������
    for (typename Container<T>::iterator i = lst.begin(); i != lst.end(); ++i) {  // ���� �� ���� ��������� ������
        min = i;  // ������������, ��� ������� ������� - �����������
        for (typename Container<T>::iterator j = next(i); j != lst.end(); ++j) {  // ���� ��� ������ ������������ �������� ����� ����������
            if (*j < *min) {  // ���� ��������� ������� ������ �������� ������������
                min = j;  // ��������� ����������� �������
            }
        }
        swap(*i, *min);  // ������ ������� ������� ������� � ����������� �������
    }
}                                             