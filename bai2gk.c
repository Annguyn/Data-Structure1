#include <iostream>
using namespace std;

// Hàm kiểm tra xem phần tử thứ k lớn hơn x hay không trong heap
bool isKthLargestGreaterThanX(int arr[], int n, int k, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            count++;
            if (count == k) {
                return true;
            }
        }
    }
    return false;
}

// Hàm main để kiểm tra
int main() {
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3, x = 35;
    if (isKthLargestGreaterThanX(arr, n, k, x)) {
        cout << "Phan tu thu " << k << " lon hon " << x << endl;
    }
    else {
        cout << "Phan tu thu " << k << " khong lon hon " << x << endl;
    }
    return 0;
}
