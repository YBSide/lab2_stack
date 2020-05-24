#pragma once
#include <iostream>
#include "Stack.h"
#include "LinkedList.h"
#include "ListSequence.h"
#include "Interface.h"

bool some_function_for_where(struct human something) {
    return something.first_name.length() == 5;
}

struct human some_function_for_map(struct human something) {
    something.first_name += "map";
    something.middle_name += "map";
    something.last_name += "map";
    something.identification += "map";
    return something;
}

struct human some_function_for_reduce (struct human first, struct human second) {
    struct human output;
    output.first_name = first.first_name + second.first_name;
    output.middle_name = first.middle_name + second.middle_name;
    output.last_name = first.last_name + second.last_name;
    output.identification = first.identification + "_" + second.identification;
    return output;
}

int inc1_test() {
    return 1;
}

int inc2_test() {
    return 2;
}

int inc3_test() {
    return 3;
}

void tests() {
    struct human first;
    first.first_name = "Rob";
    first.middle_name = "Robinson";
    first.last_name = "Vladimirovich";
    first.identification = "1";
    struct human second;
    second.first_name = "John";
    second.middle_name = "Cenaloa";
    second.last_name = "Olegovich";
    second.identification = "22";
    struct human third;
    third.first_name = "Pavel";
    third.middle_name = "Sidorenko";
    third.last_name = "Felixsovich";
    third.identification = "333";

    struct human group[3] = {first, second, third};
    auto test_human_input_1 = new linked_list<struct human>(group, 3);
    auto test_human_input_2 = new list_sequence<struct human>(test_human_input_1);
    auto test_human_input_3 = new stack<struct human>(test_human_input_2);

    struct human for_concat;
    for_concat.first_name = "Primer";
    for_concat.middle_name = "Primerin";
    for_concat.last_name = "Primerovich";
    for_concat.identification = "p71M3r0v164";

    struct human for_concat_[1] = {for_concat};
    auto test_human_input_11 = new linked_list<struct human>(for_concat_, 1);
    auto test_human_input_22 = new list_sequence<struct human>(test_human_input_11);
    auto test_human_input_33 = new stack<struct human>(test_human_input_22);

    struct human for_push;
    for_push.first_name = "Andrey";
    for_push.middle_name = "Bolshoy";
    for_push.last_name = "Malenkovich";
    for_push.identification = "123asd234";

    struct human for_reduce;
    for_reduce.first_name = "Example";
    for_reduce.middle_name = "Examplin";
    for_reduce.last_name = "Examplovich";
    for_reduce.identification = "Ex4Mp13";

    int(*f[3])() = {&inc1_test, &inc2_test, &inc3_test};
    auto test_function_input_1 = new linked_list<int (*)()>(f, 3);
    auto test_function_input_2 = new list_sequence<int (*)()>(test_function_input_1);
    auto test_function_input_3 = new stack<int (*)()>(test_function_input_2);

    if (test_human_input_3->get_size() == 3)
        cout << "Test 1 passed" << endl;
    else
        cout << "Test 1 failed" << endl;

    test_human_input_3->push(for_push);
    if (test_human_input_3->get_size() == 4 && test_human_input_3->get(0).first_name == "Andrey")
        cout << "Test 2 passed" << endl;
    else
        cout << "Test 2 failed" << endl;

    if (test_human_input_3->pop().middle_name == "Bolshoy" && test_human_input_3->get_size() == 3)
        cout << "Test 3 passed" << endl;
    else
        cout << "Test 3 failed" << endl;

    auto combined_stack = test_human_input_3->concat(test_human_input_33);
    if (combined_stack->get(3).last_name == "Primerovich" && combined_stack->get_size() == 4)
        cout << "Test 4 passed" << endl;
    else
        cout << "Test 4 failed" << endl;

    auto sub_stack = combined_stack->get_sub_stack(1, 2);
    if (sub_stack->get(0).first_name == "John" && sub_stack->get(1).first_name == "Rob" && sub_stack->get_size() == 2)
        cout << "Test 5 passed" << endl;
    else
        cout << "Test 5 failed" << endl;

    auto where_stack = test_human_input_3->where(some_function_for_where);
    if (where_stack->get(0).first_name == "Pavel" && where_stack->get_size() == 1)
        cout << "Test 6 passed" << endl;
    else
        cout << "Test 6 failed" << endl;

    auto map_stack = test_human_input_3->map(some_function_for_map);
    if (map_stack->get(0).first_name == "Robmap" && map_stack->get(2).identification == "333map")
        cout << "Test 7 passed" << endl;
    else
        cout << "Test 7 failed" << endl;

    auto reduced_stack = test_human_input_3->reduce(some_function_for_reduce, for_reduce);
    if (reduced_stack.first_name == "PavelJohnRobExample")
        cout << "Test 8 passed" << endl;
    else
        cout << "Test 8 failed" << endl;

    if (test_function_input_3->get(0)() == 1 || test_function_input_3->get(1)() == 1 || test_function_input_3->get(2)() == 1)
        cout << "Test 9 passed" << endl;
    else
        cout << "Test 9 failed" << endl;
}
