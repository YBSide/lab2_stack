#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
#include <functional>
#include <exception>

using namespace std;

struct my_exception : public exception {
    [[nodiscard]] const char * what () const noexcept override {
        return "You can't use it there. Please use ListSequence";
    }
};

template <typename T>
class array_sequence: public sequence<T> {
private:
    dynamic_array<T>* items;
public:
    array_sequence(T* items, int size) {
        this->items = new dynamic_array<T>(items, size);
    }

public:
    T get_length() const override {
        return this->items->get_size();
    }

    T get_first() const override {
        throw my_exception();
        // выбрасывает исключение
    }

    T get_last() const override {
        throw my_exception();
        // выбрасывает исключение
    }

    T get(const int index) const override {
        return this->items->get(index);
    }

    array_sequence<T>* get_subsequence(const int start, const int end) const override {
        T arr[end-start+1];
        int j=0;
        for (int i=start; i<=end; ++i) {
            arr[j] = this->items->get(i);
            j++;
        }

        auto *subsequence = new array_sequence(arr, end-start+1);

        return subsequence;
    }

public:
    void append(T item) override {
        throw my_exception();
        // выбрасывает исключение
    }

    void prepend(T item) override {
        throw my_exception();
        // выбрасывает исключение
    }

    void insert_at(const int index, T value) override {
        throw my_exception();
        // выбрасывает исключение
    }

    void remove_at(const int index) override {
        throw my_exception();
        // выбрасывает исключение
    }

    void concat(sequence<T>* other) override {
        throw my_exception();
        // искл
    }

};
