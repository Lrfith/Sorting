/**************************************
 * ID: 65009138
 * NAME: Ms.Nuttamon Malakan
 * DESCRIPTION: Testing for ArrayList
 **************************************/

#include <iostream>

#include "ArrayList.h"

using namespace std;

int main()
{
    ArrayList list; // call constructor auto
    int choice, element, index;

    do
    {
        // display
        cout << "-------------- CURRENT STATUS --------------" << endl;

        list.display();
        cout << endl;

        // show menu
        cout << "------------------- MENU -------------------" << endl;
        cout << "1: add element to list, add()" << endl;
        cout << "2: remove element from list, remove()" << endl;
        cout << "3: get element from list, get()" << endl;
        cout << "4: set element to list, set()" << endl;
        cout << "5: list size, size()" << endl;
        cout << "6: first index of element, indexOf()" << endl;
        cout << "7: clear list, clear()" << endl;
        cout << "8: find maximum number from list, max()" << endl;
        cout << "9: find minimum number from list, min()" << endl;
        cout << "0: exit" << endl;

        // asking for choice
        cout << endl;
        cout << "---------------- USER CHOICE ---------------" << endl;
        cout << "Enter your choice: "; cin >> choice;
        cout << endl;

        //cout << "------ answer -------" << endl;
        // check user choice
        cout << "--------------- CALL METHODS ---------------" << endl;
        switch (choice)
        {
        case 1: // void add(index, element)
            cout << "Enter index: "; cin >> index;
            cout << "Enter element: "; cin >> element;

            // call function
            list.add(index, element);
            break;

        case 2: // int remove(index)
            cout << "Enter index: "; cin >> index;
            element = list.remove(index);
            cout << "Result element is " << element << endl;
            break;

        case 3: // int get(index)
            cout << "Enter index: "; cin >> index;
            element = list.get(index);
            cout << "Result element is  " << element << endl;
            break;

        case 4: // void set(index, element)
            cout << "Enter index: "; cin >> index;
            cout << "Enter element: "; cin >> element;
            list.set(index, element);
            break;

        case 5: // int size()
            cout << "Result list size is " << list.size() << endl;
            break;

        case 6: // int indexOf(element)
            cout << "Enter element: "; cin >> element;
            index = list.indexOf(element);
            cout << "Result index is " << element << " found at " << index << endl;
            break;

        case 7: // void clear()
            list.clear();
            cout << "List is cleared" << endl;
            break;

        case 8: // int max()
            element = list.max();
            cout << "Result maximum is " << element << endl;
            break;

        case 9: // int max()
            element = list.min();
            cout << "Result minimum is " << element << endl;
            break;

        case 0:
            cout << "-------------------- Bye -------------------" << endl;
            break;
        default:
            cout << "[!!! Wrong choice, try again !!!]" << endl;
        }

        cout << endl;
    } while (choice != 0);

    return 0; // auto call destructor
}
