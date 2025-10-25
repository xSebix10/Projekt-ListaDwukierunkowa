#ifndef NODE_H
#define NODE_H

/**
 * @file Node.h
 * @brief Definicja wezla listy dwukierunkowej
 *
 * Kazdy wezel przechowuje wartosc typu T oraz wskazniki na poprzedni i nastepny element listy.
 */

template<typename T>
struct Node {
    T data;          ///< Wartosc przechowywana w wezle
    Node<T>* prev;   ///< Wskaznik na poprzedni element
    Node<T>* next;   ///< Wskaznik na nastepny element

    /**
     * @brief Konstruktor wezla
     * @param value Wartosc przechowywana w wezle
     */
    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

#endif // NODE_H
