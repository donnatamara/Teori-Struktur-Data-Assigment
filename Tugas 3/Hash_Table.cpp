#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashNode
{
public:
    int key;
    int value;
    HashNode *next;

    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

class HashTable
{
private:
    HashNode **table;

    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    HashTable()
    {
        table = new HashNode *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            table[i] = nullptr;
        }
    }

    void insert(int key, int value)
    {
        int hash = hashFunction(key);
        HashNode *prev = nullptr;
        HashNode *entry = table[hash];

        while (entry != nullptr && entry->key != key)
        {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr)
        {
            entry = new HashNode(key, value);
            if (prev == nullptr)
            {
                table[hash] = entry;
            }
            else
            {
                prev->next = entry;
            }
        }
        else
        {
            entry->value = value;
        }
    }

    int search(int key)
    {
        int hash = hashFunction(key);
        HashNode *entry = table[hash];

        while (entry != nullptr)
        {
            if (entry->key == key)
            {
                return entry->value;
            }
            entry = entry->next;
        }
        return -1; // Mengembalikan -1 jika kunci tidak ditemukan
    }

    void remove(int key)
    {
        int hash = hashFunction(key);
        HashNode *entry = table[hash];
        HashNode *prev = nullptr;

        while (entry != nullptr && entry->key != key)
        {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr)
        {
            cout << "Key not found!" << endl;
            return;
        }

        if (prev == nullptr)
        {
            table[hash] = entry->next;
        }
        else
        {
            prev->next = entry->next;
        }
        delete entry;
        cout << "Key removed!" << endl;
    }

    ~HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashNode *entry = table[i];
            while (entry != nullptr)
            {
                HashNode *prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }
};

int main()
{
    HashTable ht;

    // Menggunakan pointer ke metode anggota
    auto insert = [&ht](int key, int value)
    { ht.insert(key, value); };
    auto search = [&ht](int key)
    { return ht.search(key); };
    auto remove = [&ht](int key)
    { ht.remove(key); };

    insert(1, 50);
    insert(2, 60);
    insert(77, 50);

    cout << "Value for key 1: " << search(1) << endl;
    cout << "Value for key 2: " << search(2) << endl;
    cout << "Value for key 77: " << search(77) << endl;

    remove(2);

    cout << "Value for key 2: " << search(1) << endl;

    return 0;
}
