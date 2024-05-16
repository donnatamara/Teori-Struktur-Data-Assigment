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