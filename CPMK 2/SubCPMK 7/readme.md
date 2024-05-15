# <h1 align="center"> CPMK 2 – SubCPMK 7 </h1>

<p align="center">Donna Nur Tamara</p>

## Soal

### 1. Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! 

```C++
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
```

### 2. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1) mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2) memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat.

```C++
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Animal
{
public:
    string name;
    int order; // Waktu masuk ke selter

    Animal(string n, int o) : name(n), order(o) {}
};

class AnimalShelter
{
private:
    queue<Animal *> cats;
    queue<Animal *> dogs;
    int order; // Penanda waktu masuk

public:
    AnimalShelter() : order(0) {}

    void enqueue(string name, string type)
    {
        Animal *animal = new Animal(name, order++);
        if (type == "cat")
        {
            cats.push(animal);
        }
        else if (type == "dog")
        {
            dogs.push(animal);
        }
        else
        {
            cout << "Tipe hewan tidak valid." << endl;
            delete animal;
        }
    }

    Animal *dequeueAny()
    {
        if (cats.empty() && dogs.empty())
        {
            cout << "Selter kosong." << endl;
            return nullptr;
        }
        else if (cats.empty())
        {
            return dequeueDog();
        }
        else if (dogs.empty())
        {
            return dequeueCat();
        }
        else
        {
            if (cats.front()->order < dogs.front()->order)
            {
                return dequeueCat();
            }
            else
            {
                return dequeueDog();
            }
        }
    }

    Animal *dequeueCat()
    {
        if (cats.empty())
        {
            cout << "Tidak ada kucing yang tersedia." << endl;
            return nullptr;
        }
        else
        {
            Animal *cat = cats.front();
            cats.pop();
            return cat;
        }
    }

    Animal *dequeueDog()
    {
        if (dogs.empty())
        {
            cout << "Tidak ada anjing yang tersedia." << endl;
            return nullptr;
        }
        else
        {
            Animal *dog = dogs.front();
            dogs.pop();
            return dog;
        }
    }
};

int main()
{
    AnimalShelter shelter;
    shelter.enqueue("Meow", "cat");
    shelter.enqueue("Woof", "dog");
    shelter.enqueue("Purr", "cat");
    shelter.enqueue("Bark", "dog");

    Animal *adopted = shelter.dequeueAny();
    if (adopted != nullptr)
    {
        cout << "Hewan yang diadopsi: " << adopted->name << endl;
        delete adopted;
    }

    Animal *adoptedCat = shelter.dequeueCat();
    if (adoptedCat != nullptr)
    {
        cout << "Kucing yang diadopsi: " << adoptedCat->name << endl;
        delete adoptedCat;
    }

    Animal *adoptedDog = shelter.dequeueDog();
    if (adoptedDog != nullptr)
    {
        cout << "Anjing yang diadopsi: " << adoptedDog->name << endl;
        delete adoptedDog;
    }

    return 0;
}
```
