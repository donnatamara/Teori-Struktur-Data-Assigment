#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(arr[i], arr[minIndex]);
    }
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Array sebelum diurutkan: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  selectionSort(arr, n);

  cout << "\nArray setelah diurutkan: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}