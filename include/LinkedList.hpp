#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class LinkedList {
public:
    Node<T>* head;
    Node<T>* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insertar al principio
    void insertAtBeginning(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    // Insertar al final
    void insertAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insertar en una posición específica
    void insertAtIndex(int index, T data) {
        if (index < 0 || index > size()) {
            std::cout << "Índice inválido" << std::endl;
            return;
        }

        if (index == 0) {
            insertAtBeginning(data);
        } else if (index == size()) {
            insertAtEnd(data);
        } else {
            Node<T>* newNode = new Node<T>(data);
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    // Eliminar un nodo por su dato
    void deleteNode(T data) {
        Node<T>* current = head;
        while (current != nullptr && current->data != data) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Elemento no encontrado" << std::endl;
            return;
        }

        if (current == head) {
            head = head->next;
        } else if (current == tail) {
            tail = tail->prev;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
    }

    // Eliminar un nodo por su índice
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size()) {
            std::cout << "Índice inválido" << std::endl;
            return;
        }

        if (index == 0) {
            Node<T>* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node<T>* temp = current->next;
            current->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = current;
            }
            delete temp;
        }
    }

    // Buscar un elemento y devolver su índice
    int search(T data) {
        int index = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Elemento no encontrado
    }

    // Imprimir la lista
    void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Obtener el tamaño de la lista
    int size() {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};