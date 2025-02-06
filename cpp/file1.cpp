#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int size = 0;
    cout << "Enter array size: " << endl;
    cin >> size;

    int arr[size];
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);
    cout << "Sorted array: " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}