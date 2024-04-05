// C++ implementation of De-queue using circular array 
#include<iostream> 
using namespace std; 
  
// Maximum size of array or Listue 
#define MAX 100 
  
// A structure to represent a List 
class List 
{ 
    protected : int  arr[MAX]; 
    int  beg; 
    int  end; 
    int  size; 
public : 
    List(int size=10) 
    { 
        beg = -1; 
        end = 0; 
        this->size = size;
        cout<<"List()"<<endl; 
    } 
    ~List()
    {
        cout<<"~List()"<<endl;
    }
  
    // Operations on List: 
    void  insertbeg(int key); 
    void  insertend(int key); 
    void  deletebeg(); 
    void  deleteend(); 
    bool  isFull(); 
    bool  isEmpty(); 
    int  getbeg(); 
    int  getend(); 
    virtual void display()=0;
}; 
  
// Checks whether List is full or not. 
bool List::isFull() 
{ 
    return ((beg == 0 && end == size-1)|| 
            beg == end+1); 
} 
  
// Checks whether List is empty or not. 
bool List::isEmpty () 
{ 
    return (beg == -1); 
} 
  
// Inserts an element at beg 
void List::insertbeg(int key) 
{ 
    // check whether List if  full or not 
    if (isFull()) 
    { 
        cout << "Overflow\n" << endl; 
        return; 
    } 
  
    // If queue is initially empty 
    if (beg == -1) 
    { 
        beg = 0; 
        end = 0; 
    } 
  
    // beg is at first position of queue 
    else if (beg == 0) 
        beg = size - 1 ; 
  
    else // decrement beg end by '1' 
        beg = beg-1; 
  
    // insert current element into List 
    arr[beg] = key ; 
} 
  
// function to inset element at end end 
// of List. 
void List ::insertend(int key) 
{ 
    if (isFull()) 
    { 
        cout << " Overflow\n " << endl; 
        return; 
    } 
  
    // If queue is initially empty 
    if (beg == -1) 
    { 
        beg = 0; 
        end = 0; 
    } 
  
    // end is at last position of queue 
    else if (end == size-1) 
        end = 0; 
  
    // increment end end by '1' 
    else
        end = end+1; 
  
    // insert current element into List 
    arr[end] = key ; 
} 
  
// Deletes element at beg end of List 
void List ::deletebeg() 
{ 
    // check whether List is empty or not 
    if (isEmpty()) 
    { 
        cout << "Queue Underflow\n" << endl; 
        return ; 
    } 
  
    // List has only one element 
    if (beg == end) 
    { 
        beg = -1; 
        end = -1; 
    } 
    else
        // back to initial position 
        if (beg == size -1) 
            beg = 0; 
  
        else // increment beg by '1' to remove current 
            // beg value from List 
            beg = beg+1; 
} 
  
// Delete element at end end of List 
void List::deleteend() 
{ 
    if (isEmpty()) 
    { 
        cout << " Underflow\n" << endl ; 
        return ; 
    } 
  
    // List has only one element 
    if (beg == end) 
    { 
        beg = -1; 
        end = -1; 
    } 
    else if (end == 0) 
        end = size-1; 
    else
        end = end-1; 
} 
  
// Returns beg element of List 
int List::getbeg() 
{ 
    // check whether List is empty or not 
    if (isEmpty()) 
    { 
        cout << " Underflow\n" << endl; 
        return -1 ; 
    } 
    return arr[beg]; 
} 
  
// function return end element of List 
int List::getend() 
{ 
    // check whether List is empty or not 
    if(isEmpty() || end < 0) 
    { 
        cout << " Underflow\n" << endl; 
        return -1 ; 
    } 
    return arr[end]; 
} 

// function displays elements of the List 
void List::display()
{
    if(beg<=end)
        for(int i=beg;i<=end;i++)
             cout<<arr[i]<<"   "; 
    else
    {
        for(int i=beg;i<size;i++)
             cout<<arr[i]<<"   ";
        for(int i=0;i<=end;i++)
             cout<<arr[i]<<"   ";
    }
    cout<<endl;
}

//==================================================
class Stack : private List
{
    int top;
    public:
        Stack(int x=10): List(x)
        {
            top=List::end;
            cout<<"~Stack()"<<endl;
        }
        ~Stack()
        {
            cout<<"~Stack()"<<endl;
        }
        // Operations on Stack: 
    //void  insertbeg(int key); 
    void  push(int key)
    {
        List::insertbeg(key);
        cout<<endl<<"After push : ";
        List::display();
    }

    //void  deletebeg(); 
    void pop()
    {
        List::deleteend();
        cout<<endl<<"After pop : ";
        List::display();
    }

    //bool  isFull(); 
    //bool  isEmpty(); 
    //int  getbeg(); 

    int  getTop()
    {
        return(List::getend());
    } 

    void display()
    {
        List::display();
    }

};

//==================================================
class Queue : protected List
{
    public:
        Queue(int x=10): List(x)
        {
            cout<<"~Queue()"<<endl;
        }
        ~Queue()
        {
            cout<<"~Queue()"<<endl;
        }
        // Operations on Queue: 
    //void  insertbeg(int key); 
    void  ins(int key)
    {
        List::insertend(key);
        cout<<endl<<"After Insert : ";
        List::display();
    }

    //void  deletebeg(); 
    void del()
    {
        List::deletebeg();
        cout<<endl<<"After Delete : ";
        List::display();
    }

    //bool  isFull(); 
    //bool  isEmpty(); 
    //int  getbeg(); 
    //int  getTop()
    
    void display()
    {
        List::display();
    }

};
//=================================================

class DeQue : public Queue
{
    public:
        DeQue(int x=10): Queue(x)
        {
            cout<<"~DeQue()"<<endl;
        }
        ~DeQue()
        {
            cout<<"~DeQue()"<<endl;
        }
        // Operations on DeQue: 

    using Queue::insertbeg; 
    void  ins(int key)
    {
        List::insertend(key);
        cout<<endl<<"After Insert : ";
        List::display();
    }

    //void  deletebeg(); 
    void del()
    {
        List::deletebeg();
        cout<<endl<<"After Delete : ";
        List::display();
    }

    //bool  isFull(); 
    //bool  isEmpty(); 
    //int  getbeg(); 
    //int  getTop()
    

    void display()
    {
        List::display();
    }

};
//=================================================


// Driver program to test above function 
int main() 
{ 
    /*List dq(5); 
    cout << "Insert element at end end  : 5 \n"; 
    dq.insertend(5); 
  
    cout << "insert element at end end : 10 \n"; 
    dq.insertend(10); 
  
   // cout << "get end element " << " "
     //    << dq.getend() << endl; 
  
    dq.deleteend(); 
   // cout << "After delete end element new end"
       //  << " become " << dq.getend() << endl; 
  
    cout << "inserting element at beg end \n"; 
    dq.insertbeg(15); 
  
    //cout << "get beg element " << " "
      //   << dq.getbeg() << endl; 
  
    dq.deletebeg(); 
  
    //cout << "After delete beg element new "
      // << "beg become " << dq.getbeg() << endl; 
*/
    //List a;

    Stack  s;

    s.push(2);
    s.push(23);
    s.push(12);
    s.pop();

   // s.insertbeg(5);

   Queue q;

    q.ins(2);
    q.ins(23);
    q.ins(12);
    q.del();

   DeQue d;

    d.insertbeg(2);
    d.ins(23);
    d.ins(12);
    d.del();

    return 0; 
} 
