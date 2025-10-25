#ifndef ILISTITERATOR_H
#define ILISTITERATOR_H

/**
 * @file IListIterator.h
 * @brief Interfejs iteratora dla listy
 *
 * Definiuje podstawowe operacje iteratora: poruszanie się po liście
 * oraz pobieranie wartości bieżącego elementu.
 */

template<typename T>
class IListIterator {
public:
    /** Wirtualny destruktor */
    virtual ~IListIterator() = default;

    /** Sprawdza, czy istnieje następny element */
    virtual bool has_next() const = 0;

    /** Sprawdza, czy istnieje poprzedni element */
    virtual bool has_prev() const = 0;

    /** Przesuwa iterator na następny element */
    virtual void next() = 0;

    /** Przesuwa iterator na poprzedni element */
    virtual void prev() = 0;

    /** Zwraca referencję do wartości bieżącego elementu */
    virtual T& value() = 0;
};

#endif // ILISTITERATOR_H
