\
        #include <iostream>
        #include "ListFactory.h"

        int main() {
            // Tworzymy listę typu int przez wzorzec Factory
            auto *list = ListFactory::create<int>();

            // Dodajemy elementy
            list->push_back(10);
            list->push_front(5);
            list->push_back(20);
            list->insert_at(1, 7); // lista: 5, 7, 10, 20

            std::cout << "Lista (od poczatku): ";
            list->print_forward();

            std::cout << "Lista (od konca): ";
            list->print_backward();

            // Iterator
            auto it = list->begin_iterator();
            try {
                std::cout << "\\nIterator - startowy element: " << it.value() << std::endl;

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
            } catch (const std::exception &e) {
                std::cerr << "Blad iteratora: " << e.what() << std::endl;
            }

            // Usuwanie elementów
            try {
                list->pop_front(); // usuwa 5
                list->pop_back();  // usuwa 20
            } catch (const std::exception &e) {
                std::cerr << "Blad przy usuwaniu: " << e.what() << std::endl;
            }

            std::cout << "\nPo usunieciach (od poczatku): ";
            list->print_forward();

            try {
                if (list->size() > 1) list->remove_at(1); // usuwa 10 (zostaje 7)
            } catch (const std::exception &e) {
                std::cerr << "Blad remove_at: " << e.what() << std::endl;
            }
            std::cout << "Po remove_at(1): ";
            list->print_forward();

            // Test czyszczenia
            list->clear();
            std::cout << "\nPo clear() - rozmiar listy: " << list->size() << std::endl;

            delete list; // zwolnienie pamięci
            return 0;
        }
