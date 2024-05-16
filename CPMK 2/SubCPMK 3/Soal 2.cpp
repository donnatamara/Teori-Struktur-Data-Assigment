#include <iostream>
using namespace std;

// Fungsi untuk melakukan binary search
int binarySearch(int arr[], int size, int target)
{
  int left = 0;
  int right = size - 1;

  while (left <= right)
  {
    int middle = left + (right - left) / 2; // Menghindari overflow

    // Jika elemen di tengah adalah target
    if (arr[middle] == target)
    {
      return middle;
    }

    // Jika target lebih besar, abaikan bagian kiri
    if (arr[middle] < target)
    {
      left = middle + 1;
    }
    // Jika target lebih kecil, abaikan bagian kanan
    else
    {
      right = middle - 1;
    }
  }

  // Jika target tidak ditemukan
  return -1;
}

int main()
{
  int arr[] = {2, 3, 4, 10, 40};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 10;
  int result = binarySearch(arr, size, target);

  if (result != -1)
  {
    cout << "Elemen ditemukan pada indeks: " << result << endl;
  }
  else
  {
    cout << "Elemen tidak ditemukan" << endl;
  }

  return 0;
}
