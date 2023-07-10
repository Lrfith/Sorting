#if !defined(_ARRAYLIST_H_)
#define _ARRAYLIST_H_

#define DEFAULT_MAX_SIZE 5

class ArrayList
{

private:         // data
    int *L;      // list data
    int maxSize; // maximum size
    int curSize; // current size

public:                     // method
    ArrayList(int maxSize = DEFAULT_MAX_SIZE); // constructor
    ~ArrayList();           // destructor
    
    int size();                 // done
    int indexOf(int e);         // done
    int get(int i);             // done
    void set(int i, int e);     // done
    int remove(int i);          // done
    void add(int i, int e);     // done
    void display();             // done
    
    void clear();               // done
    int max();                  // done
    int min();                  // done

    //int removeN(int i, int j);
};

#endif // _ARRAYLIST_H_