#ifndef ILIST_H
#define ILIST_H

/**
 * @file IList.h
 * @brief Interfejs listy dwukierunkowej (szablon)
 */

#include <cstddef>

template<typename T>
class IList {
public:
    virtual ~IList() = default;

    virtual void push_front(const T &value) = 0;
    virtual void push_back(const T &value) = 0;
    virtual void insert_at(size_t index, const T &value) = 0;

    virtual void pop_front() = 0;
    virtual void pop_back() = 0;
    virtual void remove_at(size_t index) = 0;

    virtual void clear() = 0;

    virtual void print_forward() const = 0;
    virtual void print_backward() const = 0;
};

#endif // ILIST_H
