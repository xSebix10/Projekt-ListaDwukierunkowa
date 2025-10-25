#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "IListIterator.h"
#include "Node.h"
#include <stdexcept>

/**
 * @file ListIterator.h
 * @brief Iterator dla listy dwukierunkowej
 *
 * Umozliwia poruszanie sie po elementach listy dwukierunkowej w obu kierunkach.
 */
template<typename T>
class ListIterator : public IListIterator<T> {
private:
    Node<T>* current; ///< Wskaznik na aktualny element

public:
    /**
     * @brief Konstruktor iteratora
     * @param start Wskaznik na element, od ktorego zaczyna iteracje
     */
    explicit ListIterator(Node<T>* start) : current(start) {}

    /** Sprawdza, czy istnieje nastepny element */
    bool has_next() const override { return current && current->next; }

    /** Sprawdza, czy istnieje poprzedni element */
    bool has_prev() const override { return current && current->prev; }

    /** Przesuwa iterator na nastepny element */
    void next() override {
        if (!current) throw std::out_of_range("Iterator: brak elementu");
        if (!current->next) throw std::out_of_range("Iterator: brak kolejnego elementu");
        current = current->next;
    }

    /** Przesuwa iterator na poprzedni element */
    void prev() override {
        if (!current) throw std::out_of_range("Iterator: brak elementu");
        if (!current->prev) throw std::out_of_range("Iterator: brak poprzedniego elementu");
        current = current->prev;
    }

    /** Zwraca wartosc aktualnego elementu */
    T& value() override {
        if (!current) throw std::out_of_range("Iterator: brak elementu");
        return current->data;
    }

    /** Zwraca surowy wskaznik na aktualny wezel (uzywane przez liste) */
    Node<T>* get_node() const { return current; }
};

#endif // LISTITERATOR_H
