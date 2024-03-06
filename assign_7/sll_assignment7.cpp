#include <iostream>
using namespace std;

class sllnode
{
public:
    int val;
    sllnode *next;

    sllnode(int x = -1, sllnode *p = NULL)
    {
        val = x;
        next = p;
    }

    ~sllnode()
    {
        val = -1;
        next = NULL;
    }
};

class sll
{
    sllnode *sllHead;
    int nodeCnt;

public:
    sll(sllnode *p = NULL)
    {
        cout << "constructing sll " << endl;
        sllHead = p;
        nodeCnt = 0;
    }

    ~sll()
    {
        cout << "destroying sll " << endl;
        while (sllHead != NULL)
        {
            sllnode *temp = sllHead;
            sllHead = sllHead->next;
            delete temp;
        }
        nodeCnt = 0;
    }

    sll(const sll &rhs);

    int sllAddBeg(int x);
    int sllDelBeg();
    int sllGetElement(int x);
    void sllDisplay();
};

sll::sll(const sll &rhs)
{
    cout << "constructing sll using copy constructor ";
    nodeCnt = rhs.nodeCnt;

    if (rhs.sllHead == NULL)
    {
        sllHead = NULL;
        return;
    }

    sllnode *rhstemp = rhs.sllHead;
    sllnode *lhstemp;

    for (int i = 0; i < nodeCnt; i++)
    {
        if (rhstemp == rhs.sllHead)
        {
            sllHead = new sllnode(rhstemp->val, NULL);
            lhstemp = sllHead;
            rhstemp = rhstemp->next;
        }
        else
        {
            lhstemp->next = new sllnode(rhstemp->val, NULL);
            rhstemp = rhstemp->next;
            lhstemp = lhstemp->next;
        }
    }
}

int sll::sllAddBeg(int x)
{
    sllnode *newNode = new sllnode(x, sllHead);
    sllHead = newNode;
    nodeCnt++;
    return 1; // assuming success
}

int sll::sllDelBeg()
{
    if (sllHead == NULL)
        return -1; // nothing to delete

    sllnode *temp = sllHead;
    int deletedValue = temp->val;
    sllHead = sllHead->next;
    delete temp;
    nodeCnt--;

    return deletedValue;
}

int sll::sllGetElement(int x)
{
    if (x <= 0 || x > nodeCnt)
        return -1; // invalid index

    sllnode *temp = sllHead;
    for (int i = 1; i < x; i++)
        temp = temp->next;

    return temp->val;
}

void sll::sllDisplay()
{
    sllnode *temp = sllHead;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    sll a;

    a.sllAddBeg(2);
    a.sllAddBeg(20);
    a.sllAddBeg(12);
    a.sllDisplay();

    a.sllDelBeg();
    a.sllDelBeg();
    a.sllDisplay();

    return 0;
}
