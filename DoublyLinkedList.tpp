#ifndef DOUBLYLINKEDLIST_TPP
#define DOUBLYLINKEDLIST_TPP

#include <iostream>
#include <stdexcept>

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size_(0) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() { clear(); }

template<typename T>
void DoublyLinkedList<T>::push_front(const T &value) {
    Node<T>* node = new Node<T>(value);
    node->next = head;
    if (head) head->prev = node;
    head = node;
    if (!tail) tail = head;
    ++size_;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T &value) {
    Node<T>* node = new Node<T>(value);
    node->prev = tail;
    if (tail) tail->next = node;
    tail = node;
    if (!head) head = tail;
    ++size_;
}

template<typename T>
void DoublyLinkedList<T>::insert_at(size_t index, const T &value) {
    if (index > size_) throw std::out_of_range("index poza zakresem");
    if (index == 0) { push_front(value); return; }
    if (index == size_) { push_back(value); return; }

    Node<T>* cur = head;
    for (size_t i = 0; i < index; ++i) cur = cur->next;

    Node<T>* node = new Node<T>(value);
    node->prev = cur->prev;
    node->next = cur;
    cur->prev->next = node;
    cur->prev = node;
    ++size_;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if (!head) throw std::out_of_range("Lista pusta");
    Node<T>* tmp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete tmp;
    --size_;
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
    if (!tail) throw std::out_of_range("Lista pusta");
    Node<T>* tmp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete tmp;
    --size_;
}

template<typename T>
void DoublyLinkedList<T>::remove_at(size_t index) {
    if (index >= size_) throw std::out_of_range("index poza zakresem");
    if (index == 0) { pop_front(); return; }
    if (index == size_ - 1) { pop_back(); return; }

    Node<T>* cur = head;
    for (size_t i = 0; i < index; ++i) cur = cur->next;

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    --size_;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    Node<T>* cur = head;
    while (cur) {
        Node<T>* next = cur->next;
        delete cur;
        cur = next;
    }
    head = tail = nullptr;
    size_ = 0;
}

template<typename T>
void DoublyLinkedList<T>::print_forward() const {
    Node<T>* cur = head;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::print_backward() const {
    Node<T>* cur = tail;
    while (cur) {
        std::cout << cur->data;
        if (cur->prev) std::cout << " -> ";
        cur = cur->prev;
    }
    std::cout << std::endl;
}

#endif // DOUBLYLINKEDLIST_TPP
