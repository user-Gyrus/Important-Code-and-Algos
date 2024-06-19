//Kadane's Algorithm is an approach to find the maximum sum from a subarray in the given array
//It completes the solution in one just pass

//if you want to store the subarray too, use three variables, start = 0, ansStart = -1, ansEnd = -1
//update the start variable with the index for which sum == 0. Then if the current sum is greater than the maxSum
//we will update the ansStart = start, and ansEnd = i
//then traverse again from ansStart to ansEnd and store it in a vector

#include <iostream>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

//Time complexity - O(N)
//Space Complexity - O(1)