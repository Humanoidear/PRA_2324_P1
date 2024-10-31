#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    int max;
    static const int MINSIZE = 2;
    void resize(int new_size);

public:
    T* arr;
    int n;
    // Inherited methods from List
    void insert(int pos, T e) override;
    void prepend(T e) override;
    void append(T e) override;
    T remove(int pos) override;
    T get(int pos) override;
    int search(T e) override;
    bool empty() override;
    int size() override;

    // New methods for ListArray
    ListArray();
    ~ListArray();
    T operator[](int pos);
    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
};

template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (n == max) {
        resize(max * 2);
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = e;
    n++;
}

template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
void ListArray<T>::append(T e) {
    insert(n, e);
}

template <typename T>
T ListArray<T>::remove(int pos) {
    T e = arr[pos];
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    if (n < max / 4) {
        resize(max / 2);
    }
    return e;
}

template <typename T>
T ListArray<T>::get(int pos) {
    return arr[pos];
}

template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == e) {
            return i;
        }
    }
    return -1;
}

template <typename T>
bool ListArray<T>::empty() {
    return n == 0;
}

template <typename T>
int ListArray<T>::size() {
    return n;
}

template <typename T>
ListArray<T>::ListArray() {
    arr = new T[MINSIZE];
    max = MINSIZE;
    n = 0;
}

template <typename T>
ListArray<T>::~ListArray() {
    delete[] arr;
}

template <typename T>
T ListArray<T>::operator[](int pos) {
    return arr[pos];
}

template <typename T>
std::ostream& operator<<(std::ostream &out, ListArray<T> &list) {
    for (int i = 0; i < list.n; i++) {
        out << list.arr[i] << " ";
    }
    return out;
}

template <typename T>
void ListArray<T>::resize(int new_size) {
    T* new_arr = new T[new_size];
    for (int i = 0; i < n; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    max = new_size;
}