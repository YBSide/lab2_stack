#pragma once
#include <iostream>

using namespace std;

struct human {
    string first_name;
    string middle_name;
    string last_name;
    string identification;
};

string interface_function_1() {
    string a;

    while (a != "YES" || a != "NO" || a != "n" || a != "y" || a != "N" || a != "Y") {
        cin >> a;

        if (a == "YES" || a == "Y" || a == "y")
            return "1";

        if (a == "NO" || a == "N" || a == "n")
            return "0";

        cout << "Incorrect answer! Please, use YES(y) or NO(n)" << endl;

    }
    return "00";
}

string interface_function_2() {
    string a;
    cout << "Select element type: (1)teacher, (2)student, (3)function" << endl;
    while (a != "1" || a != "2" || a != "3") {
        cin >> a;

        if (a == "1")
            return "1";
        if (a == "2")
            return "2";
        if (a == "3")
            return "3";

        cout << "Incorrect answer! Please, put 1, 2 or 3" << endl;
    }
    return "00";
}

struct human interface_function_3() {
    string first_name;
    string middle_name;
    string last_name;
    string identification;
    struct human human;
    cout << "Write first name" << endl;
    cin >> first_name;
    cout << "Write middle name" << endl;
    cin >> middle_name;
    cout << "Write last name" << endl;
    cin >> last_name;
    cout << "Write identification" << endl;
    cin >> identification;
    human.first_name = first_name;
    human.middle_name = middle_name;
    human.last_name = last_name;
    human.identification = identification;
    return human;
}

string interface_function_4() {
    string a;
    cout << "What do you want to do with stack: (1)push, (2)pop, (3)see stack or (4)exit from program" << endl;
    while (a != "1" || a != "2" || a != "3" || a != "4") {
        cin >> a;

        if (a == "1")
            return "1";
        if (a == "2")
            return "2";
        if (a == "3")
            return "3";
        if (a == "4")
            return "4";

        cout << "Incorrect answer! Please, put 1, 2, 3 or 4" << endl;
    }
    return "00";
}

