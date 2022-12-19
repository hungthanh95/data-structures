#include <iostream>

using namespace std;


class Stack
{
private:
    int* items;
    int capacity;
    int top;
public:
    Stack(int capacity);
    ~Stack();
    bool isFull();
    bool isEmpty();
    void push(int value);
    int pop(void);
    void printStack();
};

Stack::Stack(int capacity)
{
    this->items = new int[capacity];
    this->capacity = capacity;
    this->top = -1;
}

Stack::~Stack()
{
    delete items;
}

bool Stack::isFull()
{
    return (top >= (capacity - 1));
}

bool Stack::isEmpty()
{
    return (top == -1);
}

void Stack::push(int value)
{
    if (isFull()) {
        return;
    }
    items[++top] = value;
}

int Stack::pop(void)
{
    if(isEmpty()) {
        return -1;
    }
    return items[top--];
}

void Stack::printStack()
{
    for (int i = top; i >= 0; i--)
    {
        cout << "| " << items[i] << " |" << endl;
    } 
}

int main(int, char**) {
    Stack st(5);
    st.isEmpty() ? cout << "Stack empty\n" : cout << "Stack not empty\n";
    st.isFull() ? cout << "Stack is full\n" : cout << "Stack is not full\n";
    
    st.push(2);
    st.push(12);
    st.push(6);
    st.push(5);

    cout << "Stack: "<< endl;
    st.printStack();

    st.pop();
    st.pop();

    cout << "Stack after pop: "<< endl;
    st.printStack();

    st.push(2);
    st.push(12);
    st.push(6);
    st.push(5);

    st.isEmpty() ? cout << "Stack empty\n" : cout << "Stack not empty\n";
    st.isFull() ? cout << "Stack is full\n" : cout << "Stack is not full\n";
    
    cout << "Stack after over push: "<< endl;
    st.printStack();

}
