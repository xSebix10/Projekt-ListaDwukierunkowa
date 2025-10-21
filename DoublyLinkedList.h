#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "IList.h"
#include "Node.h"
#include "IListIterator.h"
#include "ListIterator.h"
#include <cstddef>

/**
 * @file DoublyLinkedList.h
 * @brief Implementacja listy dwukierunkowej na stercie
 */

template<typename T>
class DoublyLinkedList : public IList<T> {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size_;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // podstawowe operacje
    void push_front(const T &value) override;
    void push_back(const T &value) override;
    void insert_at(size_t index, const T &value) override;

    void pop_front() override;
    void pop_back() override;
    void remove_at(size_t index) override;

    void clear() override;

    void print_forward() const override;
    void print_backward() const override;

    size_t size() const { return size_; }

    // iterator helper
    ListIterator<T> begin_iterator() const { return ListIterator<T>(head); }
    ListIterator<T> end_iterator() const { return ListIterator<T>(tail); }
};

#include "DoublyLinkedList.tpp"

#endif // DOUBLYLINKEDLIST_H
