/********************************************************************************************
 * ID: 65009138
 * NAME: Ms.Nuttamon Malakan
 * DESCRIPTION: Sorting Algorithms contain Selection, Insertion, Bubble, Shell, Merge, Quick
 ********************************************************************************************/

#include <iostream>

#include "Sorting.h"

using namespace std;
int main()
{
    
    int n;
    cout << "Enter number of element: "; cin >> n;
    Sorting sort(n);
    sort.random();
    sort.backup();
    // int n = 7; // Number of elements
    // Sorting sort(n);
    
    // Set the elements manually
    // sort.data->set(0, 29);
    // sort.data->set(1, 57);
    // sort.data->set(2, 34);
    // sort.data->set(3, 5);
    // sort.data->set(4, 22);
    // sort.data->set(5, 39);
    // sort.data->set(6, 91);
    // sort.backup(); // unforget to change header to public
    int choice;

    do
    {

        // show menu
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "------------------------------ >>> MENU <<< -----------------------------" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "1: Selection sort\n";
        cout << "2: Insertion sort\n";
        cout << "3: Bubble sort\n";
        cout << "4: Shell sort\n";
        cout << "5: Merge sort\n";
        cout << "6: Quick sort\n";
        cout << "0: Exit";

        // asking for choice
        cout << endl;
        cout << "-------------------------- >>> USER CHOICE <<< --------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        // check user choice
        cout << "-------------------------- >>> CALL METHODS <<< -------------------------" << endl;
        switch (choice)
        {

        case 1:
            // * selection sort (case 1)
            cout << "[SELECTION]" << endl;
            sort.restore();
            if (n <= 16) sort.display();
            sort.selection(n <= 10);
            if (n <= 16) sort.display();
            sort.displaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElapsed();

            break;
        case 2:
            // * insertion sort (case 2)
            cout << "[INSERTION]" << endl;
            sort.restore();
            if (n <= 16) sort.display();
            sort.insertion(n <= 10);
            if (n <= 16) sort.display();
            sort.displaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElapsed();

            break;
        case 3:
            // * bubble sort (case 3)
            cout << "[BUBBLE]" << endl;
            sort.restore();
            if (n <= 16) sort.display();
            sort.bubble(n <= 10);
            if (n <= 16) sort.display();
            sort.displaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElapsed();

            break;
        case 4:
            // * shell sort (case 4)
            cout << "[SHELL]" << endl;
            sort.restore();
            if (n <= 16) sort.display();
            sort.shell(n <= 10);
            if (n <= 16) sort.display();
            sort.displaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElapsed();
            break;
        case 5:
            // * merge sort (case 5)
            cout << "[MERGE]" << endl;
            sort.restore();
            if (n <= 16) sort.display();
            sort.merge(n <= 10);
            if (n <= 16) sort.display();
            sort.displaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElapsed();
            break;
        case 6:
            // * quick sort (case 6)
            cout << "[QUICK]" << endl;
            sort.restore();
            if (n <= 16) sort.display();
            sort.quick(n <= 10);
            if (n <= 16) sort.display();
            sort.displaySwapCounter();
            sort.displayLoopCounter();
            sort.displayTimeElapsed();
            break;
        case 0:
            cout << "------------------------------- >>> Bye <<< -----------------------------" << endl;
            break;
        default:
            cout << "[!!! Wrong choice, try again !!!]" << endl;
        }

    } while (choice != 0);

    return 0;
}