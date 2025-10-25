#include <iostream>
#include "ListFactory.h"

/**
 * @file main.cpp
 * @brief Testowanie funkcjonalnosci listy dwukierunkowej
 *
 * Program tworzy liste przy uzyciu wzorca Factory, dodaje i usuwa elementy,
 * wyswietla liste w obu kierunkach oraz testuje iterator.
 */

int main() {
    // Tworzymy listę typu int przez wzorzec Factory
    auto* list = ListFactory::create<int>();
    int error = 0;

    // Dodawanie elementów
    list->push_back(10);       ///< Dodaje element na koniec
    list->push_front(5);       ///< Dodaje element na poczatek
    list->push_back(20);       ///< Dodaje element na koniec
    list->insert_at(1, 7);     ///< Wstawia element na indeks 1 (lista: 5, 7, 10, 20)

    std::cout << "Lista (od poczatku): ";
    list->print_forward();     ///< Wyswietlenie listy od poczatku

    std::cout << "Lista (od konca): ";
    list->print_backward();    ///< Wyswietlenie listy od konca

    // Test iteratora
    auto it = list->begin_iterator();
    try {
        std::cout << "\nIterator - startowy element: " << it.value() << std::endl;

        if (it.has_next()) {
            it.next();
            std::cout << "Iterator - nastepny element: " << it.value() << std::endl;
        }
        if (it.has_next()) {
            it.next();
            std::cout << "Iterator - nastepny element: " << it.value() << std::endl;
        }
        if (it.has_prev()) {
            it.prev();
            std::cout << "Iterator - poprzedni element: " << it.value() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Blad iteratora: " << e.what() << std::endl;
    }

    // Usuwanie elementów
    try {
        list->pop_front(); ///< Usuwa pierwszy element
        list->pop_back();  ///< Usuwa ostatni element
    }
    catch (const std::exception& e) {
        std::cerr << "Blad przy usuwaniu: " << e.what() << std::endl;
    }

    std::cout << "\nPo usunieciach (od poczatku): ";
    list->print_forward(); ///< Wyswietlenie listy po usunieciach

    try {
        if (list->size() > 1) list->remove_at(1); ///< Usuwa element pod indeksem 1
    }
    catch (const std::exception& e) {
        std::cerr << "Blad remove_at: " << e.what() << std::endl;
    }
    std::cout << "Po remove_at(1): ";
    list->print_forward(); ///< Wyswietlenie listy po remove_at

    // Test czyszczenia listy
    list->clear();
    std::cout << "\nPo clear() - rozmiar listy: " << list->size() << std::endl;

    delete list; ///< Zwolnienie pamieci
    return 0;
}
