#include "Sorting.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Sorting::Sorting(int maxSize)
{
    // this->maxSize = 16
    this->maxSize = maxSize;
    // create new ArrayList
    data = new ArrayList(this->maxSize);
    temp = new ArrayList(this->maxSize);

    // initializes two(data, temp) arrays
    for (int i = 0; i < this->maxSize; i++)
    {
        data->add(i, 0);
        temp->add(i, 0);
    }
    // for random data
    srand(time(NULL));
}

Sorting::~Sorting()
{
    delete data;
    delete temp;
}

void Sorting::display()
{
    // * data: {e0, e1 , ... , en-1}
    cout << "Data: {";
    if (maxSize <= 0)
        cout << "}" << endl;
    else
    {
        for (int i = 0; i < maxSize; i++)
        {
            printf("%2d", data->get(i));
            if (i < maxSize - 1)
                cout << ", ";
            else
                cout << "}" << endl;
        }
    }
}

void Sorting::displayTimeElapsed()
{
    // cout << "Time: " << timeElapsed << " second" << endl;
    printf("Time: %f second\n", timeElapsed);
}

void Sorting::displayLoopCounter()
{
    cout << "Loop: " << loopCounter << " times" << endl;
}

void Sorting::displaySwapCounter()
{
    cout << "Swap: " << swapCounter << " times" << endl;
}

void Sorting::random()
{
    // sets a random value between 0 - 99 at index of 'data'
    for (int i = 0; i < maxSize; i++)
        data->set(i, rand() % 100);
}

void Sorting::backup()
{
    // copies the values from the "data" array to the "temp" array
    for (int i = 0; i < maxSize; i++)
        temp->set(i, data->get(i));
}

void Sorting::restore()
{
    // copies the values from the "temp" array to the "data" array
    for (int i = 0; i < maxSize; i++)
        data->set(i, temp->get(i));
}

void Sorting::selection(bool verbose)
{
    timeElapsed = 0.0;
    swapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // set number of element [n, n-1, ..., 2]
    for (int nElement = maxSize; nElement > 1; nElement--)
    {
        // find index of maximum value
        int maxIndex = findMaxIndex(nElement);

        // swap value at index iMax and count - 1
        swap(maxIndex, nElement - 1);

        if (verbose)
            display();
    }
    clock_t end = clock();
    timeElapsed = (end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::insertion(bool verbose)
{
    timeElapsed = 0.0;
    swapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // set number of element [2, 3, ..., n]
    for (int nData = 2; nData <= maxSize; nData++)
    {
        // do insertion only for nData elements
        insert(nData);

        if (verbose)
            display();
    }
    clock_t end = clock();
    timeElapsed = (end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::bubble(bool verbose)
{
    timeElapsed = 0.0;
    swapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // set number of element [n, n-1, ..., 2]
    for (int nData = maxSize; nData > 1; nData--)
    {
        // do bubble only for nData elements
        bubble_(nData);

        if (verbose)
            display();
    }
    clock_t end = clock();
    timeElapsed = (end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::shell(bool verbose)
{
    timeElapsed = 0.0;
    swapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // do shell for k = [n/2, n/4, ..., 1]
    for (int k = maxSize / 2; k >= 1; k = k / 2)
    {
        selectK(maxSize, k);

        if (verbose)
            display();
    }
    clock_t end = clock();
    timeElapsed = (end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::merge(bool verbose)
{
    timeElapsed = 0.0;
    swapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();

    ArrayList *tempData = new ArrayList(maxSize);
    for (int i = 0; i < maxSize ; i++) tempData->add(i, 0);

    copyArray(data, tempData, 0, maxSize - 1);

    merge_(tempData, data, 0, maxSize - 1);

    delete tempData;

    if (verbose)
        display();

    clock_t end = clock();
    timeElapsed = (end - begin) / (double)CLOCKS_PER_SEC;
}

void Sorting::quick(bool verbose)
{
    timeElapsed = 0.0;
    swapCounter = 0;
    loopCounter = 0;

    clock_t begin = clock();
    // perform recursive quick sort
    quick_(0, maxSize - 1);
    if (verbose)
        display();

    clock_t end = clock();
    timeElapsed = (end - begin) / (double)CLOCKS_PER_SEC;
}

int Sorting::findMaxIndex(int n)
{
    // first set max index at zero position
    int maxIndex = 0;

    // scan for index of maximum value
    for (int i = 1; i < n; i++)
    {
        if (data->get(maxIndex) < data->get(i))
            maxIndex = i;
        loopCounter++;
    }

    // return index of maximum value
    return maxIndex;
}

void Sorting::swap(int i, int j)
{
    //  swap as triangle copy
    int temp = data->get(i);
    data->set(i, data->get(j));
    data->set(j, temp);

    swapCounter++;
}

void Sorting::insert(int n)
{
    // pick insert data at index n - 1
    int insertData = data->get(n - 1);

    // set insert index to n - 2
    int insertPos = n - 2;

    // check insertion condition
    while (insertPos >= 0 && data->get(insertPos) > insertData)
    {
        swap(insertPos, insertPos + 1);
        insertPos--;

        loopCounter++;
    }
}

void Sorting::bubble_(int n)
{
    // do bubble for n elements
    for (int i = 0; i < n - 1; i++)
    {
        // check condition for swapping
        if (data->get(i) > data->get(i + 1))
            swap(i, i + 1);

        loopCounter++;
    }
}

void Sorting::selectK(int n, int k)
{
    // do insertion for n element with k displacement
    for (int i = 0; i < k; i++)
    {
        // do selection sort with k displacement
        for (int j = i; j < n; j = j + k)
        {
            int iMin = findMinIndexK(n, j, k);
            swap(j, iMin);
        }
    }
}

int Sorting::findMinIndexK(int n, int iStart, int k)
{
    // first set min index at first index
    int minIndex = iStart;
    // scan for index fo minimum value
    for (int i = iStart + k; i < n; i = i + k)
    {
        if (data->get(i) < data->get(minIndex))
            minIndex = i;

        loopCounter++;
    }

    // return index of minimum value
    return minIndex;
}

void Sorting::copyArray(ArrayList *src, ArrayList *dest, int begin, int end)
{
    for (int i = begin; i <= end; i++)
        dest->set(i, src->get(i));
}

void Sorting::merge_(ArrayList *data, ArrayList *result, int begin, int end)
{
    // check number of data
    if (end - begin <= 0) return;
    // continue divide data
    int half = (begin + end) / 2;
    merge_(data, result, begin, half);
    merge_(data, result, half + 1, end);

    // merge sort
    int i = begin;
    int j = half + 1;
    for (int k = begin; k <= end; k++)
    {
        if (i > half)
            result->set(k, data->get(j++));     // remain only j data, select d[j]
        else if (j > end)
            result->set(k, data->get(i++));     // remain only i data, select d[i]
        else if (data->get(i) > data->get(j))
            result->set(k, data->get(j++));     // d[i] > d[j], select d[i]
        else
            result->set(k, data->get(i++));     // d[i] <= d[j], select d[i]
        
        loopCounter ++;
    }
    // update result to data before return
    copyArray(result, data, begin, end);
}

void Sorting::quick_(int begin, int end)
{
    // check index
    if (end - begin <= 0)
        return;

    // pick pivot index
    int iPivot = pickPivotIndex(begin, end);

    // swap between index of pivot and last data
    swap(iPivot, end);

    // partition to two data sets
    int i = begin, j = end - 1;
    while (i <= j)
    {
        while (i <= j && data->get(i) < data->get(end))
            i++;
        while (i <= j && data->get(j) >= data->get(end))
            j--;
        if (i < j)
            swap(i, j);

        loopCounter++;
    }
    // swap i and end (pivot)
    swap(i, end);

    // perform quick sort in two data sets, recursively
    quick_(begin, i - 1);
    quick_(i + 1, end);
}

int Sorting::pickPivotIndex(int begin, int end)
{
    // calculate middle position
    int mid = (begin + end) / 2;

    // re-assign variables (easy to call), like a, b and c
    int a = data->get(begin), b = data->get(mid), c = data->get(end);

    // check for middle conditions
    if ((a >= b && b >= c) || (a <= b && b <= c))
        return mid;
    else if ((b >= c && c >= a) || (b <= c && c <= a))
        return end;
    else if ((c >= a && a >= b) || (c <= a && a <= b))
        return begin;

    // un-reachable code, just for warning avoidance
    return mid;
}
