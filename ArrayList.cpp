#include "ArrayList.h"

#include <iostream>
using namespace std;

ArrayList::ArrayList(int maxSize)
{
    // create array with maxSize elements
    L = new int[maxSize];

    // set maximum size to maxSize
    this->maxSize = maxSize;

    // set current size to zero
    curSize = 0;

    // cout << "CONSTRUCTOR" << endl;
}

ArrayList::~ArrayList()
{
    // destroy list
    delete[] L;

    // cout << "DESTRUCTOR" << endl;
}

int ArrayList::size()
{
    // get current size
    return curSize;
}

int ArrayList::indexOf(int e)
{
    // check empty list
    if (curSize <= 0){
        cout << "[Error]: List is empty!" << endl;
        return -1;
    }

    // linear search, scan form 0 to curSize -1
    for (int i = 0; i <= curSize - 1; i++)
        if (L[i] == e)
            return i;

    // not found
    cout << "[Error]: element not found" << endl;
    return -1;
}

int ArrayList::get(int i)
{
    // check empty list
    if (curSize == 0){
        cout << "[Error]: Empty list" << endl;
        return -1;
    }
    // check lower bound
    if (i < 0){
        cout << "[Error]: i is under lower bound" << endl;
        return -1;
    }
    // check upper bound
    else if (i > curSize - 1){
        cout << "[Error]: i is over upper bound" << endl;
        return -1;
    }

    return L[i];
}

void ArrayList::set(int i, int e)
{
    // check lower bound
    if (i < 0){
        cout << "[Warning]: i is lower bound can't set to this element" << endl;
    }
    // check upper bound
    else if (i >= curSize){
        cout << "[Warning]: i is over upper bound can't set to this element " << endl;
    }
    else {
        L[i] = e;
    }
}

int ArrayList::remove(int i)
{
    // check Empty list
    if (curSize <= 0){
        cout << "[Error]: list is empty" << endl;
        return -1;
    }
    // check lower bound
    if (i < 0){
        cout << "[Error]: i is lower bound can't remove this element" << endl;
        return -1;
    }
    // check upper bound
    else if (i > curSize - 1){
        cout << "[Error]: i is over upper bound can't remove this element" << endl;
        return -1;
    }

    int remove = L[i];
    for (int j = i + 1; j <= curSize - 1; j++)
        L[j - 1] = L[j];

    curSize--;
    return remove;
}

void ArrayList::add(int i, int e)
{
    // check list is full ?
    if (curSize == maxSize){
        cout << "[Error]: List is full" << endl;
        return;
    }

    // check lower bound (warning)
    if (i < 0){
        cout << "[Warning]: i is under lower bound, i change to 0" << endl;
        i = 0;
    }
    // check upper bound (warning)
    else if (i > curSize){
        cout << "[Warning]: i is over upper bound, i change to " << curSize << endl;
        i = curSize;
    }

    /// shift right (from maxSize-1 down to curSize)
    for (int j = curSize - 1; j >= i; j--)
        L[j + 1] = L[j];

    // put e to element i
    L[i] = e;

    // increment current size
    curSize++;
}

void ArrayList::display()
{
    cout << "L: {";
    if (curSize == 0)
        cout << "}, ";
    else{
        for (int i = 0; i < curSize; i++){
            cout << L[i];
            if (i < curSize - 1)
                cout << ", ";
            else
                cout << "}" << endl;
        }
    }
    cout << "size: " << curSize << "/" << maxSize << endl;
}

void ArrayList::clear()
{
    // set current list size to zero
    curSize = 0;
}

int ArrayList::max() // linear search
{
    // check empty list
    if (curSize == 0){
        cout << "[Error]: list is empty" << endl;
        return -1;
    }

    int max = L[0]; // set first element of the array is max
    for (int i = 1; i <= curSize - 1; i++){
        if (L[i] > max) // check if L[i] maximum greater than max
            max = L[i]; // let max = L[i]
    }

    return max;
}

int ArrayList::min() // linear search
{
    // check empty list
    if (curSize <= 0){
        cout << "[Error]: list is empty" << endl;
        return -1;
    }

    int min = L[0]; // set first element of the array is min

    // if have element more than one
    for (int i = 1; i <= curSize - 1; i++){
        if (L[i] < min) // if L[i] minimum less than min = L[0];
            min = L[i]; // let min = L[i]
    }

    return min;
}


