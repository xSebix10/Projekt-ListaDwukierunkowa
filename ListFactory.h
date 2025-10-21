#ifndef LISTFACTORY_H
#define LISTFACTORY_H

#include "DoublyLinkedList.h"

/**
 * @file ListFactory.h
 * @brief Prosty wzorzec Factory do tworzenia listy dwukierunkowej
 */
class ListFactory {
public:
    /**
     * @brief Tworzy nową listę dwukierunkową na stercie.
     * @tparam T Typ elementów listy
     * @return Wskaźnik do nowo utworzonej listy
     */
    template<typename T>
    static DoublyLinkedList<T>* create() {
        return new DoublyLinkedList<T>();
    }
};

#endif // LISTFACTORY_H
