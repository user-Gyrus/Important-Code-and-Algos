//The dutch national flag algorithm consists of three pointers, low, mid high
// the portion from 0th index to low-1 consists of only 0s
//the portion of low to mid-1 consists of only 1s
//the portion between mid to high-1 will consisted unsorted numbers
// from high to end will consist of only 2s

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

//time complexity - O(N)
//space complexity - O(1)