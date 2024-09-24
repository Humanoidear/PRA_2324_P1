#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "list.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;                    // Puntero al array dinámico
    int max;                   // Tamaño máximo del array
    int n;                     // Número de elementos en la lista
    static const int MINSIZE = 2; // Tamaño mínimo del array

    // Método para redimensionar el array
    void resize(int new_size) {
        T* newArr = new T[new_size]; // Crear nuevo array de tamaño new_size
        for (int i = 0; i < n; i++) {
            newArr[i] = arr[i]; // Copiar datos al nuevo array
        }
        delete[] arr;           // Liberar memoria del array antiguo
        arr = newArr;           // Actualizar puntero
        max = new_size;         // Actualizar tamaño máximo
    }

public:
    // Constructor sin argumentos
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    // Destructor
    ~ListArray() {
        delete[] arr; // Liberar memoria dinámica
    }

    // Método insert: inserta un elemento en la posición pos
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera del rango");
        }
        if (n == max) {
            resize(max * 2); // Aumentar el tamaño del array si está lleno
        }
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1]; // Desplazar elementos a la derecha
        }
        arr[pos] = e; // Insertar nuevo elemento
        n++;
    }

    // Método append: agrega un elemento al final de la lista
    void append(T e) override {
        insert(n, e); // Insertar en la última posición
    }

    // Método prepend: agrega un elemento al principio de la lista
    void prepend(T e) override {
        insert(0, e); // Insertar en la primera posición
    }

    // Método remove: elimina y devuelve el elemento en la posición pos
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera del rango");
        }
        T removedElement = arr[pos];
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1]; // Desplazar elementos a la izquierda
        }
        n--;
        if (n > 0 && n < max / 4) {
            resize(max / 2); // Reducir el tamaño del array si está "demasiado vacío"
        }
        return removedElement;
    }

    // Método get: devuelve el elemento en la posición pos
    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera del rango");
        }
        return arr[pos];
    }

    // Método search: devuelve la posición de la primera ocurrencia del elemento, o -1 si no se encuentra
    int search(T e) const override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }

    // Método empty: devuelve true si la lista está vacía
    bool empty() const override {
        return n == 0;
    }

    // Método size: devuelve el número de elementos en la lista
    int size() const override {
        return n;
    }

    // Sobrecarga del operador [] para acceder a los elementos de la lista
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera del rango");
        }
        return arr[pos];
    }

    // Sobrecarga del operador << para imprimir la lista
    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i];
            if (i < list.n - 1) out << ", ";
        }
        out << "]";
        return out;
    }
};

#endif // LISTARRAY_H

