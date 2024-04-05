#include <iostream>
#include <stdexcept>
using namespace std;

#define MAX 100

template<typename T>
class List {
protected:
    T arr[MAX];
    int beg;
    int end;
    int size;

public:
    List(int size = 10) {
        beg = -1;
        end = 0;
        this->size = size;
        cout << "List()" << endl;
    }

    ~List() {
        cout << "~List()" << endl;
    }

    // Operations on List:
    void insertbeg(T key);
    void insertend(T key);
    void deletebeg();
    void deleteend();
    bool isFull();
    bool isEmpty();
    T getbeg();
    T getend();
    virtual void display() = 0;
};

template<typename T>
bool List<T>::isFull() {
    return ((beg == 0 && end == size - 1) || beg == end + 1);
}

template<typename T>
bool List<T>::isEmpty() {
    return (beg == -1);
}

template<typename T>
void List<T>::insertbeg(T key) {
    if (isFull()) {
        throw overflow_error("Overflow");
    }

    if (beg == -1) {
        beg = 0;
        end = 0;
    } else if (beg == 0)
        beg = size - 1;
    else
        beg = beg - 1;

    arr[beg] = key;
}

template<typename T>
void List<T>::insertend(T key) {
    if (isFull()) {
        throw overflow_error("Overflow");
    }

    if (beg == -1) {
        beg = 0;
        end = 0;
    } else if (end == size - 1)
        end = 0;
    else
        end = end + 1;

    arr[end] = key;
}

template<typename T>
void List<T>::deletebeg() {
    if (isEmpty()) {
        throw underflow_error("Queue Underflow");
    }

    if (beg == end) {
        beg = -1;
        end = -1;
    } else if (beg == size - 1)
        beg = 0;
    else
        beg = beg + 1;
}

template<typename T>
void List<T>::deleteend() {
    if (isEmpty()) {
        throw underflow_error("Underflow");
    }

    if (beg == end) {
        beg = -1;
        end = -1;
    } else if (end == 0)
        end = size - 1;
    else
        end = end - 1;
}

template<typename T>
T List<T>::getbeg() {
    if (isEmpty()) {
        throw underflow_error("Underflow");
    }
    return arr[beg];
}

template<typename T>
T List<T>::getend() {
    if (isEmpty() || end < 0) {
        throw underflow_error("Underflow");
    }
    return arr[end];
}

template<typename T>
void List<T>::display() {
    if (beg <= end)
        for (int i = beg; i <= end; i++)
            cout << arr[i] << "   ";
    else {
        for (int i = beg; i < size; i++)
            cout << arr[i] << "   ";
        for (int i = 0; i <= end; i++)
            cout << arr[i] << "   ";
    }
    cout << endl;
}

template<typename T>
class Stack : private List<T> {
    int top;
public:
    Stack(int x = 10) : List<T>(x) {
        top = List<T>::end;
        cout << "Stack()" << endl;
    }

    ~Stack() {
        cout << "~Stack()" << endl;
    }

    void push(T key) {
        List<T>::insertbeg(key);
        cout << endl << "After push : ";
        List<T>::display();
    }

    void pop() {
        List<T>::deletebeg();
        cout << endl << "After pop : ";
        List<T>::display();
    }

    T getTop() {
        return (List<T>::getend());
    }

    void display() {
        List<T>::display();
    }

};

template<typename T>
class Queue : protected List<T> {
public:
    Queue(int x = 10) : List<T>(x) {
        cout << "Queue()" << endl;
    }

    ~Queue() {
        cout << "~Queue()" << endl;
    }

    void ins(T key) {
        List<T>::insertend(key);
        cout << endl << "After Insert : ";
        List<T>::display();
    }

    void del() {
        List<T>::deletebeg();
        cout << endl << "After Delete : ";
        List<T>::display();
    }

    void display() {
        List<T>::display();
    }

};

template<typename T>
class DeQue : public Queue<T> {
public:
    DeQue(int x = 10) : Queue<T>(x) {
        cout << "DeQue()" << endl;
    }

    ~DeQue() {
        cout << "~DeQue()" << endl;
    }

    using Queue<T>::insertbeg;
    void ins(T key) {
        List<T>::insertend(key);
        cout << endl << "After Insert : ";
        List<T>::display();
    }

    void del() {
        List<T>::deletebeg();
        cout << endl << "After Delete : ";
        List<T>::display();
    }

    void display() {
        List<T>::display();
    }

};

int main() {
    try {
        Stack<int> s;
        s.push('a');
        s.push('b');
        s.push('c');
        s.pop();

        Queue<int> q;
        q.ins(2);
        q.ins(23);
        q.ins(12);
        q.del();

        DeQue<int> d;
        d.insertbeg(2);
        d.ins(23);
        d.ins(12);
        d.del();
    } catch (exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
