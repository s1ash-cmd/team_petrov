#include <iostream>
#include <list>
using namespace std;

template <typename T, template <typename...> class Container>
void selectionSort(list<T>& lst) {
    typename list<T>::iterator min;  // �������� ��� ������������ ��������
    for (typename list<T>::iterator i = lst.begin(); i != lst.end(); ++i) {  // ���� �� ���� ��������� ������
        min = i;  // ������������, ��� ������� ������� - �����������
        for (typename list<T>::iterator j = next(i); j != lst.end(); ++j) {  // ���� ��� ������ ������������ �������� ����� ����������
            if (*j < *min) {  // ���� ��������� ������� ������ �������� ������������
                min = j;  // ��������� ����������� �������
            }
        }
        swap(*i, *min);  // ������ ������� ������� ������� � ����������� �������
    }
}
