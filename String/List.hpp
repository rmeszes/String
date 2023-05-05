#ifndef LIST_H
#define LIST_H
#include <stdexcept>
#include <iostream>
template<class T> class List
{
	struct ListElement {
		T data;
		ListElement* next;
		ListElement(T data, ListElement* p = nullptr) :next(p), data(data) {}
	};
	ListElement* start, * current;
public:
    List() :start(nullptr), current(nullptr) {}
    List(const T& data) : start(new ListElement(data)), current(start) {}
    void Add(const T& data) {
        if (start == nullptr) {
            start = current = new ListElement(data);
        }
        else {
            ListElement* p;
            for (p = start; p->next != nullptr; p = p->next);
            p->next = new ListElement(data);
        }
    }
    bool Next(T& data) {
        if (current->next == nullptr) {
            current = start;
            return false;
        }
        data = current->data;
        current = current->next;
        return true;
    }
    ~List() {
        ListElement* p = start;
        while (p != nullptr) {
            ListElement* temp = p;
            p = p->next;
            delete temp;
        }
        start = nullptr;
        current = nullptr;
    }
    T getCurrent() const {
        return current->data;
    }
    T* operator[](const size_t i) { //indexelõ op., írhatóan adja vissza az adat pointerét
        ListElement* p = start;
        for (size_t j = 0; j < i; j++) {
            p = p->next;
            if (p == nullptr) {
                throw std::out_of_range("List_out_of_bound"); //TODO catch, teszt
            }
        }
        return &p->data;
    }
    const T operator[](const size_t i) const { //indexelõ op., const esetén
        ListElement* p = start;
        for (size_t j = 0; j < i; j++) {
            p = p->next;
            if (p == nullptr) {
                throw std::out_of_range("List_out_of_bound"); //TODO catch, teszt
            }
        }
        return p->data;
    }
};

#endif // !LIST_H