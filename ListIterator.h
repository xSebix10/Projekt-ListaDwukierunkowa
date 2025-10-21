#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "IListIterator.h"
#include "Node.h"
#include <stdexcept>

/**
 * @file ListIterator.h
 * @brief Iterator dla listy dwukierunkowej
 */

template<typename T>
class ListIterator : public IListIterator<T> {
private:
    Node<T>* current;
public:
    explicit ListIterator(Node<T>* start) : current(start) {}

    bool has_next() const override { return current && current->next; }
    bool has_prev() const override { return current && current->prev; }

    void next() override {
        if (!current) throw std::out_of_range("Iterator: brak elementu");
        if (!current->next) throw std::out_of_range("Iterator: brak kolejnego elementu");
        current = current->next;
    }

    void prev() override {
        if (!current) throw std::out_of_range("Iterator: brak elementu");
        if (!current->prev) throw std::out_of_range("Iterator: brak poprzedniego elementu");
        current = current->prev;
    }

    T& value() override {
        if (!current) throw std::out_of_range("Iterator: brak elementu");
        return current->data;
    }

    // helper to get raw pointer (used by lista)
    Node<T>* get_node() const { return current; }
};

#endif // LISTITERATOR_H
