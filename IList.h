#ifndef ILIST_H
#define ILIST_H

/**
 * @file IList.h
 * @brief Interfejs dla listy dwukierunkowej (szablon)
 *
 * Definiuje podstawowe operacje na liście, takie jak dodawanie,
 * usuwanie, czyszczenie i wyświetlanie elementów.
 */

#include <cstddef>

template<typename T>
class IList {
public:
    /** Wirtualny destruktor */
    virtual ~IList() = default;

    /** Dodaje element na poczatek listy */
    virtual void push_front(const T& value) = 0;

    /** Dodaje element na koniec listy */
    virtual void push_back(const T& value) = 0;

    /** Dodaje element na wskazany indeks */
    virtual void insert_at(size_t index, const T& value) = 0;

    /** Usuwa element z poczatku listy */
    virtual void pop_front() = 0;

    /** Usuwa element z konca listy */
    virtual void pop_back() = 0;

    /** Usuwa element z pod wskazanego indeksu */
    virtual void remove_at(size_t index) = 0;

    /** Czysci cala liste */
    virtual void clear() = 0;

    /** Wyswietla liste od poczatku */
    virtual void print_forward() const = 0;

    /** Wyswietla liste od konca */
    virtual void print_backward() const = 0;
};

#endif // ILIST_H
