#include "MyLinkedList.h"
#include <iostream>
#include <iomanip>

/////////////////////////  hash table class definition /////////////////////
class hashing
{
    //  private members
    sll *ht;
    int hashfn(int x);

public:
    int htsize;
    hashing(int n = 10);
    ~hashing();
    int searchhs(int x);
    void inserths(int x);
    void display(void);
};

int hashing::hashfn(int x)
{
    return (x % htsize);
}

hashing::hashing(int n)
{
    std::cout << "Hash table constructor" << std::endl;
    ht = new sll[n];
    htsize = n;
}

hashing::~hashing()
{
    std::cout << "Hash table destructor" << std::endl;
    delete[] ht;
}

void hashing::inserths(int x)
{
    int index = hashfn(x);
    ht[index].sllAddBeg(x);
}

int hashing::searchhs(int x)
{
    int index = hashfn(x);
    // You can implement the search logic here based on your requirements.
    // For example, you can search within the linked list at ht[index].
    return -1; // Placeholder, return -1 if not found.
}

void hashing::display(void)
{
    for (int i = 0; i < htsize; ++i)
    {
        std::cout << "Bucket " << i << ": ";
        ht[i].sllDisplay();
    }
}

///////////////////////   END of hash table class definition /////////////////////

int main(void)
{
    hashing h1;

    h1.inserths(15);
    h1.inserths(22);
    h1.inserths(72);
    h1.display();
    h1.display();
    
    return 0;
}
