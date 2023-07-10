#if !defined(_SORTING_H_)
#define _SORTING_H_

#include "../ArrayList/ArrayList.h"

#define DEFAULT_SIZE 16

class Sorting
{
public:
    ArrayList *data;
    ArrayList *temp;
    int maxSize;
    double timeElapsed;
    unsigned long loopCounter;
    unsigned long swapCounter;

public:
    Sorting(int maxSize = DEFAULT_SIZE);                        // * done
    ~Sorting();                                                 // * done

    void display();                                             // * done
    void displayTimeElapsed();                                  // * done
    void displayLoopCounter();                                  // * done
    void displaySwapCounter();                                  // * done

    void random();                                              // * done
    void backup();                                              // * done
    void restore();                                             // * done

    // * Sorting alg.
    // * Selection sort
    void selection(bool verbose = false);                       // * done
    // * Insertion sort
    void insertion(bool verbose = false);                       // * done
    // * Bubble sort
    void bubble(bool verbose = false);                          // * done
    // * Shell sort
    void shell(bool verbose = false);                           // * done
    // * Merge sort
    void merge(bool verbose = false);                           // * done
    // * Quick sort
    void quick(bool verbose = false);                           // * done

private:
    // * Selection method
    int findMaxIndex(int n);                                    // * done
    void swap(int i, int j);                                    // * done

    // * Insertion method
    void insert(int n);                                         // * done

    // * Bubble method
    void bubble_(int n);                                        // * done

    // * Shell method
    void selectK(int n, int k);                                 // * done
    int findMinIndexK(int n, int iStart, int k);                // * done

    // * Merge method
    void copyArray(ArrayList *src, ArrayList *dest, int begin, int end);    // * done
    void merge_(ArrayList *data, ArrayList *result, int begin, int end);    // * done

    // * Quick method
    void quick_(int begin, int end);                            // * done 
    int pickPivotIndex(int begin, int end);                     // * done
};

#endif // _SORTING_H_