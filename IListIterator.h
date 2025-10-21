#ifndef ILISTITERATOR_H
#define ILISTITERATOR_H

/**
 * @file IListIterator.h
 * @brief Interfejs iteratora
 */

template<typename T>
class IListIterator {
public:
    virtual ~IListIterator() = default;
    virtual bool has_next() const = 0;
    virtual bool has_prev() const = 0;
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual T& value() = 0;
};

#endif // ILISTITERATOR_H
