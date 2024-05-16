#include <iostream>
#include <string>

using namespace std;

int binarySearch(string arr[], const string& target, int left, int right) {
    if (left > right) {
        return -1; // Target tidak ditemukan
    }

    int mid = left + (right - left) / 2;

    // Jika elemen tengah adalah string kosong, cari elemen non-kosong terdekat
    int midLeft = mid, midRight = mid;
    while (arr[midLeft] == "" && arr[midRight] == "") {
        if (midLeft > left) midLeft--;
        if (midRight < right) midRight++;
        if (midLeft == left && midRight == right) return -1; // Semua elemen kosong
    }

    if (arr[midLeft] != "") {
        mid = midLeft;
    } else {
        mid = midRight;
    }

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearch(arr, target, mid + 1, right);
    } else {
        return binarySearch(arr, target, left, mid - 1);
    }
}

int search(string arr[], int size, const string& target) {
    if (size == 0 || target == "") {
        return -1; // Jika array kosong atau target adalah string kosong
    }
    return binarySearch(arr, target, 0, size - 1);
}

int main() {
    string arr[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    int size = sizeof(arr) / sizeof(arr[0]);
    string target = "ball";

    int index = search(arr, size, target);
    if (index != -1) {
        cout << "Kata '" << target << "' ditemukan pada indeks " << index << "." << endl;
    } else {
        cout << "Kata '" << target << "' tidak ditemukan dalam array." << endl;
    }

    return 0;
}
