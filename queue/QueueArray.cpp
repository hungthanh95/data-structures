#include <iostream>

using namespace std;


class QueueArray
{
private:
    int* items;
    int capacity;
    int front;
    int rear;
public:
    QueueArray(int capacity);
    ~QueueArray();
    bool isFull();
    bool isEmpty();
    void enqueue(int value);
    int dequeue();
    void reset();
    void printQueue();
};

QueueArray::QueueArray(int capacity)
{
    items = new int[capacity];
    this->capacity = capacity;
    this->front = -1;
    this->rear = -1;
}

QueueArray::~QueueArray()
{
    delete items;
}

bool QueueArray::isFull()
{
    if ((rear == front) && (rear == (capacity - 1))) reset();
    return ((rear == (capacity - 1)) && (front != rear));
}

bool QueueArray::isEmpty()
{
    if ((rear == front) && (rear == (capacity - 1))) reset();
    return front == rear;
}

void QueueArray::enqueue(int value)
{
    if (isFull()) return;
    items[++rear] = value;
}

int QueueArray::dequeue()
{
    if (isEmpty()) return -1;
    return items[front++];
}

void QueueArray::reset()
{
    for (int i = 0; i < capacity; i++)
    {
        items[i] = 0;
    }
    front = rear = -1;
}

void QueueArray::printQueue()
{
    if (isEmpty()) return;
    for (int i = rear; i >= front; i--)
    {
        cout << "| " << items[i] << " |" << endl;
    } 
}


int main(int, char**) {
    QueueArray queue(5);
    queue.isEmpty() ? cout << "queue empty\n" : cout << "queue not empty\n";
    queue.isFull() ? cout << "queue is full\n" : cout << "queue is not full\n";

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);

    cout << "Queue: "<< endl;
    queue.printQueue();
    queue.isEmpty() ? cout << "queue empty\n" : cout << "queue not empty\n";
    queue.isFull() ? cout << "queue is full\n" : cout << "queue is not full\n";

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    cout << "Queue: "<< endl;
    queue.printQueue();
    queue.isEmpty() ? cout << "queue empty\n" : cout << "queue not empty\n";
    queue.isFull() ? cout << "queue is full\n" : cout << "queue is not full\n";

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    cout << "Queue: "<< endl;
    queue.printQueue();
    queue.isEmpty() ? cout << "queue empty\n" : cout << "queue not empty\n";
    queue.isFull() ? cout << "queue is full\n" : cout << "queue is not full\n";
    
    return 0;
}
