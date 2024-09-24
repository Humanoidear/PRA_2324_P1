#ifndef LIST_H
#define LIST_H

#include <stdexcept> // Para std::out_of_range
#include <iostream>  // Para depuración opcional

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    // Constructor
    List() : head(nullptr), tail(nullptr), length(0) {}

    // Destructor
    ~List() {
        clear();
    }

    // Insertar en una posición específica
    void insert(int pos, T e) {
        if (pos < 0 || pos > length) {
            throw std::out_of_range("Posición fuera del rango");
        }

        Node* newNode = new Node(e);
        
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            if (length == 0) tail = head; // Si la lista estaba vacía
        } else {
            Node* prev = getNode(pos - 1);
            newNode->next = prev->next;
            prev->next = newNode;
            if (pos == length) tail = newNode; // Si insertamos al final
        }

        length++;
    }

    // Agregar al final de la lista
    void append(T e) {
        insert(length, e);
    }

    // Agregar al principio de la lista
    void prepend(T e) {
        insert(0, e);
    }

    // Eliminar y devolver el elemento en la posición especificada
    T remove(int pos) {
        if (pos < 0 || pos >= length) {
            throw std::out_of_range("Posición fuera del rango");
        }

        Node* toDelete;
        T removedData;
        
        if (pos == 0) {
            toDelete = head;
            head = head->next;
            if (length == 1) tail = nullptr; // Si eliminamos el único elemento
        } else {
            Node* prev = getNode(pos - 1);
            toDelete = prev->next;
            prev->next = toDelete->next;
            if (pos == length - 1) tail = prev; // Si eliminamos el último
        }

        removedData = toDelete->data;
        delete toDelete;
        length--;
        return removedData;
    }

    // Obtener el elemento en una posición especificada
    T get(int pos) const {
        if (pos < 0 || pos >= length) {
            throw std::out_of_range("Posición fuera del rango");
        }
        return getNode(pos)->data;
    }

    // Buscar la posición de un elemento
    int search(T e) const {
        Node* current = head;
        for (int i = 0; i < length; i++) {
            if (current->data == e) {
                return i;
            }
            current = current->next;
        }
        return -1; // No encontrado
    }

    // Comprobar si la lista está vacía
    bool empty() const {
        return length == 0;
    }

    // Obtener el tamaño de la lista
    int size() const {
        return length;
    }

private:
    // Obtener el nodo en una posición especificada
    Node* getNode(int pos) const {
        if (pos < 0 || pos >= length) {
            throw std::out_of_range("Posición fuera del rango");
        }

        Node* current = head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current;
    }

    // Limpiar la lista
    void clear() {
        while (!empty()) {
            remove(0);
        }
    }
};

#endif // LIST_H

