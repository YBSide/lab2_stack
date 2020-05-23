#pragma once
#include "LinkedList.h"
#include "Sequence.h"
#include "ListSequence.h"
#include <exception>

using namespace std;

struct my_exception_ : public exception {
    [[nodiscard]] const char * what () const noexcept override {
        return "Stack is empty";
    }
};

template <typename T>
class stack {
private:
    list_sequence<T>* items;
public:
    explicit stack(list_sequence<T>* items)
    {
        this->items = items;
    }
public:
    T get(int index) {
        if (this->items->get_length() <= 0)
            throw my_exception_();
        return this->items->get(index);
    }

    stack<T>* concat(stack<T>* other) {
        auto *combined_list = new linked_list<T>();

        for(int i = 0; i < other->get_size(); i++)
            combined_list->append(other->get(i));
        for(int j = 0; j < this->items->get_length(); j++)
            combined_list->append(this->get(j));
        auto *combined_sequence = new list_sequence(combined_list);
        auto *combined_stack = new stack(combined_sequence);
        return combined_stack;
    }

    stack<T>* get_sub_stack(int start, int end) {
        auto new_sub_stack = new stack(this->items->get_subsequence(start, end));
        return new_sub_stack;
    }

    int get_size()
    {
        return this->items->get_length();
    }

    T pop()
    {
        if (this->items->get_length() <= 0)
            throw my_exception_();
        auto item = this->items->get_first();
        this->items->remove_at(0);
        return item;
    }

    stack<T>* map(T function(T future_output)) {
        if (this->items->get_length() <= 0)
            throw my_exception_();

        auto new_list = new linked_list<T>();
        if (this->items->get_length() == 1) {
            new_list->append(function(this->items->get(0)));
        }
        else {
            for (int i = 0; i < this->items->get_length(); i++) {
                new_list->prepend(function(this->items->get(i)));
            }
        }
        auto new_sequence = new list_sequence(new_list);
        auto new_stack = new stack(new_sequence);
        return new_stack;
    }

    stack <T>* where(bool function(T something)) {
        if (this->items->get_length() <= 0)
            throw my_exception_();

        auto new_list = new linked_list<T>();
        int j = 0;
        for (int i = 0; i < this->items->get_length(); ++i) {
            if (function(this->items->get(i))) {
                new_list->prepend(this->items->get(i));
                j++;
            }
        }
        auto new_sequence = new list_sequence(new_list);
        auto new_stack = new stack(new_sequence);
        return new_stack;
    }

    T reduce(T function(T first, T second), T constant) {
        if (this->items->get_length() <= 0)
            throw my_exception_();

        T future_output = function(this->items->get(0), constant);
        for (int i = 1; i < this->items->get_length(); ++i) {
            future_output = function(this->items->get(i), future_output);
        }
        return future_output;
    }
public:
    void push(T item)
    {
        this->items->append(item);
    }
};
