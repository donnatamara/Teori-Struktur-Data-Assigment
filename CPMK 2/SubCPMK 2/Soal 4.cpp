#include <iostream>

using namespace std;



void merge(int arr[], int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;
  int tempArr[r - l + 1];

  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j]) {
      tempArr[k] = arr[i];
      i++;
    } else {
      tempArr[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i <= mid) {
    tempArr[k] = arr[i];
    k++;
    i++;
  }

  while (j <= r) {
    tempArr[k] = arr[j];
    k++;
    j++;
  }

  for (int i = l; i <= r; i++) {
    arr[i] = tempArr[i - l];
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

void mergeArrays(int A[], int nA, int B[], int nB) {
  // Memastikan A memiliki cukup ruang untuk menampung B
  if (nA + nB > sizeof(A) / sizeof(int)) {
    cout << "Ukuran array A tidak cukup untuk menampung array B" << endl;
    return;
  }

  // Salin elemen B ke akhir A
  for (int i = 0; i < nB; i++) {
    A[nA + i] = B[i];
  }

  // Gabungkan dan urutkan array A
  mergeSort(A, 0, nA + nB - 1);
}

int main() {
  int A[] = {2, 5, 8, 12, 16};
  int nA = sizeof(A) / sizeof(int);
  int B[] = {3, 6, 7, 11, 14};
  int nB = sizeof(B) / sizeof(int);

  mergeArrays(A, nA, B, nB);

  // Tampilkan array A yang sudah digabung dan diurutkan
  for (int i = 0; i < nA + nB; i++) {
    cout << A[i] << " ";
  }

  return 0;
}
