#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked();
    ~ListLinked();

    void insert(int pos, T e) override;
    void prepend(T e) override;
    void append(T e) override;
    T remove(int pos) override;
    T get(int pos) override;
    int search(T e) override;
    bool empty() override;
    int size() override;

    T operator[](int pos);
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list);
};

template <typename T>
ListLinked<T>::ListLinked() {
    first = nullptr;
    n = 0;
}

template <typename T>
ListLinked<T>::~ListLinked() {
    while (first != nullptr) {
        Node<T>* aux = first;
        first = first->next;
        delete aux;
    }
}

template <typename T>
void ListLinked<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* newNode = new Node<T>(e);
    if (pos == 0) {
        newNode->next = first;
        first = newNode;
    } else {
        Node<T>* aux = first;
        for (int i = 0; i < pos - 1; i++) {
            aux = aux->next;
        }
        newNode->next = aux->next;
        aux->next = newNode;
    }
    n++;
}

template <typename T>
void ListLinked<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
void ListLinked<T>::append(T e) {
    insert(n, e);
}

template <typename T>
T ListLinked<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* aux = first;
    if (pos == 0) {
        first = first->next;
    } else {
        Node<T>* prev = nullptr;
        for (int i = 0; i < pos; i++) {
            prev = aux;
            aux = aux->next;
        }
        prev->next = aux->next;
    }
    T data = aux->data;
    delete aux;
    n--;
    return data;
}

template <typename T>
T ListLinked<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* aux = first;
    for (int i = 0; i < pos; i++) {
        aux = aux->next;
    }
    return aux->data;
}

template <typename T>
int ListLinked<T>::search(T e) {
    Node<T>* aux = first;
    for (int i = 0; i < n; i++) {
        if (aux->data == e) {
            return i;
        }
        aux = aux->next;
    }
    return -1;
}

template <typename T>
bool ListLinked<T>::empty() {
    return n == 0;
}

template <typename T>
int ListLinked<T>::size() {
    return n;
}

template <typename T>
T ListLinked<T>::operator[](int pos) {
    return get(pos);
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
    Node<T>* aux = list.first;
    while (aux != nullptr) {
        out << aux->data << " ";
        aux = aux->next;
    }
    return out;
}

#endif