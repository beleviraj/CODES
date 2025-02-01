#include <iostream>
using namespace std;

template<typename T>
int linearSearch(const T arr[], int size, T key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    const int size = 5;

    int intArr[size];
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> intArr[i];
    }
    int intKey;
    cout << "Enter the integer you want to search: ";
    cin >> intKey;
    int x = linearSearch(intArr, size, intKey);
    if (x != 0) {
        cout << "Integer found in the array at : " << x << endl;
    } else {
        cout << "Integer not found in the array." << endl;
    }

    float floatArr[size];
    cout << "Enter " << size << " floating-point numbers: " << endl;
    for (int i = 0; i < size; ++i) {
        cin >> floatArr[i];
    }
    float floatKey;
    cout << "Enter the floating-point number you want to search: ";
    cin >> floatKey;
    int y = linearSearch(floatArr, size, floatKey);
    if (y != 0) {
        cout << "Floating-point number found in the array at : " << y << endl;
    } else {
        cout << "Floating-point number not found in the array." << endl;
    }

    char charArr[size];
    cout << "Enter " << size << " characters:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> charArr[i];
    }
    char charKey;
    cout << "Enter the character you want to search: ";
    cin >> charKey;
    int z = linearSearch(charArr, size, charKey);
    if (z != 0) {
        cout << "Character found in the array at :" << z << endl;
    } else {
        cout << "Character not found in the array." << endl;
    }

    return 0;
}
