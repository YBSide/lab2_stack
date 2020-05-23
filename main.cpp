#include <iostream>
#include "Stack.h"
#include "LinkedList.h"
#include "ListSequence.h"
#include "Interface.h"
#include "Tests.h"
using namespace std;

int main() {
    cout << "Do you want to run tests? (YES(y) or NO(n))" << endl;
    string answer = interface_function_1();
    if (answer == "1")
        tests();

    cout << "Do you want to use this program by yourself? (YES(y) or NO(n))" << endl;
    answer = interface_function_1();
    if (answer == "0") {
        cout << "Goodbye! Have a nice day/night!" << endl;
        return 0;
    }

    auto your_list = new linked_list<struct human>();

    int num_of_elements;
    cout << "Write number of elements" << endl;
    cin >> num_of_elements;
    for (int i = 0; i < num_of_elements; i++) {
        cout << i+1 << ")";
        your_list->prepend(interface_function_3());
    }
    auto your_sequence = new list_sequence<struct human>(your_list);
    auto your_stack = new stack<struct human>(your_sequence);
    answer = interface_function_4();

    while (answer != "4") {

        if (answer == "1") {
            your_stack->push(interface_function_3());
        }

        if (answer == "2")
            auto tmp = your_stack->pop();

        if (answer == "3") {
            for (int i = 0; i < your_stack->get_size(); ++i) {
                auto tmp = your_stack->get(i);
                cout << i+1 << ")" << tmp.first_name << " " << tmp.middle_name << " " << tmp.last_name << " " << tmp.identification << endl;
            }
        }

        answer = interface_function_4();
    }

    cout << "Goodbye! Have a nice day/night!";


    return 0;
}
