// Moore's Voting Algo uses only two variables, count and element
// the element variable store the current number, and count stores the number of times it is repeating
// if at some part of the array, the count becomes 0, it indicates that the chosen element is not the majority
// element, since it gets cancelled by the other elements in the chosen subarray (by -1 for each element)


#include <vector>
#include <iostream>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

//time complexities - O(N) + O(N) (if they that the array may or may not have the majority element)
//space complexity - O(1)