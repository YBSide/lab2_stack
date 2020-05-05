#pragma once

#include <cstddef>
#include <stdexcept>

using namespace std;

template <typename T>
class linked_list {
private:
    struct list_element {
        T data;
        list_element* next;
    };
    list_element *head, *tail;
    int size;
public:
    linked_list(T* items, int size) {
        int i = 0;

        this->size = size;

        this->head = new list_element;
        this->head->data = items[0];
        this->head->next = NULL;
        this->tail = this->head;
        for (i+1; i<size; ++i) {
            this->tail = this->tail->next;
            this->tail = new list_element;
            this->tail->data = items[i];
            this->tail->next = NULL;
        }
    }
    linked_list() {
        this->size = 1;
        this->head = NULL;
        this->tail = this->head;
    }
    linked_list(const linked_list<T> &list) {
        list_element *tmp = list.head;
        this->size = list.size;
        while (tmp != NULL) {
            prepend(tmp->data);
            tmp = tmp->next;
        }
    }

public:
    T get_first() {
        if (this->head == NULL)
            throw out_of_range("First element is NULL");
        return this->head->data;
    }
    T get_last() {
        if (this->tail == NULL)
            throw out_of_range("list's size = 1 and last element is NULL");
        return this->tail->data;
    }
    T get(int index) {
        if (index < 0 || index >= this->size)
            throw out_of_range("INDEX OUT OF RANGE!!! GET OUT!!!");
        int i = 0;
        list_element *tmp = this->head;
        while (i != index) {
            tmp = tmp->next;
            i++;
        }
        return tmp->data;
    }
    linked_list<T>* get_sub_list(int start_index, int end_index) {
        if (start_index < 0 || start_index >= this->size || end_index < 0 || end_index >= this->size)
            throw out_of_range("INDEX OUT OF RANGE!!! GET OUT!!!");

        int new_size = end_index - start_index + 1;

        T elements[new_size];
        int j = 0;
        for (int i=start_index; i<=end_index; ++i) {
            elements[j] = this->get(i);
            j++;
        }

        linked_list<T> new_list = this->linked_list(elements, new_size);
        return new_list;
    }
    int get_length() {
        return this->size;
    }



public:
    void prepend(T item) {
        this->size += 1;

        auto *tmp = new list_element;
        tmp->data = item;
        tmp->next = NULL;

        if (this->head == NULL) {
            this->head = tmp;
            this->tail = tmp;
        }
        else {
            this->tail->next = tmp;
            this->tail = this->tail->next;
        }
    }
    void append(T item) {
        this->size += 1;

        auto *tmp = new list_element;
        tmp->data = item;
        tmp->next = this->head;
        this->head = tmp;
    }
    void insert_at(T item, int index) {
        if (index<0 || index >= this->size)
            throw out_of_range("index out of range");
        // исключение!!

        list_element *tmp = this->head;
        list_element *pre_tmp = this->head;
        int i = 0;

        while(i != index) {
            i++;
            pre_tmp = tmp;
            tmp = tmp->next;
        }

        auto *new_element = new list_element;
        new_element->data = item;
        if (i != 0) {
            pre_tmp->next = new_element;
            new_element->next = tmp->next;
        }
        else {
            append(item);
            this->size -= 1;
        }
        this->size += 1;
    }
    void concat(linked_list<T> *list) {
        this->tail->next = list->head;
        this->tail = list->tail;
        this->size += list->size;
    }
};