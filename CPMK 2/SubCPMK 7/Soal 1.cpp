#include <iostream>
#define MAX 5 // Ukuran maksimal antrian

using namespace std;

class Queue
{
private:
    int front, rear, size;
    int queue[MAX];

public:
    Queue()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    bool isFull()
    {
        return (size == MAX);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        if (front == -1)
        {
            front = rear;
        }
        size++;
        cout << value << " enqueued to queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << queue[front] << " dequeued from queue." << endl;
        front = (front + 1) % MAX;
        size--;
        if (size == 0)
        {
            front = rear = -1;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
        return queue[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << queue[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    cout << "Front element is: " << q.peek() << endl;

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}