#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_HEAP_SIZE = 50;
int H[MAX_HEAP_SIZE];
int heapSize = -1;

int parent(int i)
{
    return (i - 1) / 2;
}

int leftChild(int i)
{
    return ((2 * i) + 1);
}

int rightChild(int i)
{
    return ((2 * i) + 2);
}

void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i])
    {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i)
{
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex])
    {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex])
    {
        maxIndex = r;
    }
    if (i != maxIndex)
    {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p)
{
    if (heapSize + 1 >= MAX_HEAP_SIZE)
    {
        cout << "Heap overflow, cannot insert more elements\n";
        return;
    }
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax()
{
    if (heapSize == -1)
    {
        cout << "Heap is empty\n";
        return -1;
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;
    if (p > oldp)
    {
        shiftUp(i);
    }
    else
    {
        shiftDown(i);
    }
}

int getMax()
{
    if (heapSize == -1)
    {
        cout << "Heap is empty\n";
        return -1;
    }
    return H[0];
}

void remove(int i)
{
    if (heapSize == -1)
    {
        cout << "Heap is empty\n";
        return;
    }
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main()
{
    int n;
    cout << "Enter the number of elements in the heap: ";
    cin >> n;

    if (n > MAX_HEAP_SIZE)
    {
        cout << "Number of elements exceeds maximum heap size (" << MAX_HEAP_SIZE << ")\n";
        return true;
    }

    cout << "Enter the elements of the heap: ";
    for (int i = 0; i < n; ++i)
    {
        int element;
        cin >> element;
        insert(element);
    }

    cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i)
    {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority: " << extractMax() << "\n";

    cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i)
    {
        cout << H[i] << " ";
    }
    cout << "\n";

    // Ubah prioritas elemen ke-2 (index 1) menjadi 80
    if (n > 2)
    {
        changePriority(2, 80);
        cout << "Priority queue after priority change: ";
        for (int i = 0; i <= heapSize; ++i)
        {
            cout << H[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "Not enough elements to change priority\n";
    }

    // Hapus elemen ke-3 (index 2)
    if (n > 3)
    {
        remove(3);
        cout << "Priority queue after removing the element: ";
        for (int i = 0; i <= heapSize; ++i)
        {
            cout << H[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "Not enough elements to remove\n";
    }

    return 0;
}
