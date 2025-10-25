#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "IList.h"
#include "Node.h"
#include "IListIterator.h"
#include "ListIterator.h"
#include <cstddef>

/**
 * @file DoublyLinkedList.h
 * @brief Lista dwukierunkowa przechowywana na stercie
 */

template<typename T>
class DoublyLinkedList : public IList<T> {
private:
    Node<T>* head; ///< Wskaznik na pierwszy element
    Node<T>* tail; ///< Wskaznik na ostatni element
    size_t size_;  ///< Liczba elementow

public:
    /** Konstruktor - tworzy pusta liste */
    DoublyLinkedList();

    /** Destruktor - usuwa wszystkie elementy */
    ~DoublyLinkedList();

    /** Dodaje element na poczatek listy */
    void push_front(const T& value) override;

    /** Dodaje element na koniec listy */
    void push_back(const T& value) override;

    /** Dodaje element na wskazany indeks */
    void insert_at(size_t index, const T& value) override;

    /** Usuwa element z poczatku listy */
    void pop_front() override;

    /** Usuwa element z konca listy */
    void pop_back() override;

    /** Usuwa element z pod wskazanego indeksu */
    void remove_at(size_t index) override;

    /** Czysci cala liste */
    void clear() override;

    /** Wyswietla liste od poczatku */
    void print_forward() const override;

    /** Wyswietla liste od konca */
    void print_backward() const override;

    /** Zwraca liczbe elementow */
    size_t size() const { return size_; }

    /** Zwraca iterator na pierwszy element */
    ListIterator<T> begin_iterator() const { return ListIterator<T>(head); }

    /** Zwraca iterator na ostatni element */
    ListIterator<T> end_iterator() const { return ListIterator<T>(tail); }
};

#include "DoublyLinkedList.tpp"

#endif // DOUBLYLINKEDLIST_H
