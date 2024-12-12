// User function template for C++
//qn -Second Largest
// Difficulty: EasyAccuracy: 26.72%Submissions: 871K+Points: 2
// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

// Note: The second largest element should not be equal to the largest element.
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        //get the se   
        int maxi=0;
    int n=arr.size();
    for(int i=0;i<=n-1;i++){
        //mini ko upgrade karte chalo
        if(arr[i]>arr[maxi]) 
        {maxi=i;}
    }
    
    int secondmaxi = -1;
    for (int i = 0; i < n; i++) {
            if (arr[i] < arr[maxi]) { // Check for elements smaller than the largest
                if (secondmaxi == -1 || arr[i] > arr[secondmaxi]) {
                    secondmaxi = i; // Update index of the second largest
                }
            }
            
        }return secondmaxi == -1 ? -1 : arr[secondmaxi]; 
    }
};
//2 qn - Maximum Sum Subarray of Size 3
// Maximum Sum Subarray of Size 3   
// Difficulty: EasyAccuracy: 50.0%Submissions: 100k+Points: 2
// Given an array arr[] of size N, the task is to find the sum of the maximum sum subarray of size 3.
class Solution {
    public:
    // Function returns the maximum sum
    // of subarray of size 3
    int maxSum(vector<int> &arr) {
        int n = arr.size();

        // If the array has less than 3 elements
        if (n < 3) {
            return -1;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n - 2; i++) {
            int sum = arr[i] + arr[i + 1] + arr[i + 2];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

// 3 qn - Remove Duplicates from Sorted Array
// Remove Duplicates from Sorted Array
// Difficulty: EasyAccuracy: 40.0%Submissions: 100k+Points: 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        int j;
        for(int j =0;j<nums.size();j++){
            if (nums[j]!=nums[i]){

                nums[i+1]=nums[j];
                i=i+1;
                //swap and increase the i ka counter 
            }
           
        } return i+1 ;// we need to return the size and its zero based indexing so return i +1

    }
};

// 4 qn - Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i; 
        //find the size of array 
        //compare each of the sum with the target 
        //now the qn is how 
        int n =nums.size();
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<n;j++){
                if (nums[i]+nums[j]==target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};
// change string to integer

#include <iostream>
#include <string>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int i = 0; // Pointer to traverse the string
    int n = s.size();
    long result = 0; // Use long to detect overflow
    int sign = 1; // Default sign is positive

    // Step 1: Ignore leading whitespace
    while (i < n && s[i] == ' ') i++;

    // Step 2: Check for sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Parse digits and build the number
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0'); // Convert char to int
        if (result * sign >= INT_MAX) return INT_MAX; // Handle overflow
        if (result * sign <= INT_MIN) return INT_MIN; // Handle underflow
        i++;
    }

    // Step 4: Return the final result
    return static_cast<int>(result * sign);
}

//rotate array 
//yhan pe 3 types of variations aati hai n one is ki roatte by 1 place other is roate right and left by
// k places now here is the code for rotate by 1 place
// Rotate Array by One Place
// Difficulty: EasyAccuracy: 50.0%Submissions: 100k+Points: 2
// Given an array arr[] of N elements. The task is to rotate the array by one place in the clock-wise direction.
// Example 1:
// Input:
// N = 5
// arr[] = {1, 2, 3, 4, 5}
#include <iostream>
using namespace std;

void Rotatetoleft(int arr[], int n, int k) {
    k = k % n;  // Handle cases where k >= n
    int temp[k];

    // Step 1: Store first k elements in temp
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    // Step 2: Shift remaining elements to the left
    for (int i = 0; i < n - k; i++) {
        arr[i] = arr[i + k];
    }

    // Step 3: Place temp elements at the end
    for (int i = n - k; i < n; i++) {
        arr[i] = temp[i - n + k];
    }
}

void Rotatetoright(int arr[], int n, int k) {
    k = k % n;  // Handle cases where k >= n
    int temp[k];

    // Step 1: Store last k elements in temp
    for (int i = n - k; i < n; i++) {
        temp[i - n + k] = arr[i];
    }

    // Step 2: Shift remaining elements to the right
    for (int i = n - k - 1; i >= 0; i--) {
        arr[i + k] = arr[i];
    }

    // Step 3: Place temp elements at the start
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7, k = 2;

    // Test right rotation
    Rotatetoright(arr, n, k);
    cout << "After Rotating the elements to right: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reset array for left rotation test
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};

    // Test left rotation
    Rotatetoleft(arr2, n, k);
    cout << "After Rotating the elements to left: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}
//2nd method - better n optimal approach
//Approach 2: Using Reversal Algorithm
//This is a space-efficient solution with O(1) extra space. It works by reversing portions of the array to achieve the rotation.

// Algorithm:
// 1. Reverse the first k elements of the array.
// 2. Reverse the remaining n - k elements of the array.
// 3. Reverse the entire array to obtain the final result.
// Implementation:
// Let's implement the above approach in code:
cpp
#include <iostream>
using namespace std;
// Function to reverse the array from index start to end
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
// Function to rotate the array to the right by k places
void rotateRight(int arr[], int n, int k) {
    k = k % n; // Handle cases where k >= n
    reverse(arr, 0, n - k - 1); // Reverse the first n - k elements
    reverse(arr, n - k, n - 1); // Reverse the remaining k elements
    reverse(arr, 0, n - 1); // Reverse the entire array
}
//function to rotate left

void rotateLeft(int arr[], int n, int k) {
    k = k % n; // Handle cases where k >= n
    reverse(arr, 0, k - 1); // Reverse the first k elements
    reverse(arr, k, n - 1); // Reverse the remaining n - k elements
    reverse(arr, 0, n - 1); // Reverse the entire array
}




//2 sum problem 

// Certainly! Let's break down the implementation and provide a detailed explanation of how the code works:

// Problem Statement
// Given an array arr of integers of size n and an integer target, determine if there exist two distinct elements in the array such that t
// heir sum equals target. If such a pair exists, return "YES"; otherwise, return "NO".
// Create an unordered map mpp to store the numbers seen so far in the array and their corresponding indices. This helps in efficiently checking for the complement of a number in constant time, on average.
// Iterate Through the Array:

// For each element num in the array:
// Compute moreNeeded = target - num, which is the value required to reach the target sum with num.
// Check if moreNeeded exists in the unordered map mpp.
// If it exists, it means a previous number moreNeeded and the current number num together add up to the target. Therefore, return "YES".
// If moreNeeded is not found, store the current number num in mpp with its index as the value. This allows us to efficiently check for its complement in subsequent iterations.
// Return "NO" if No Pair Found:

// If the loop completes and no valid pair is found, return "NO".
// Time Complexity Analysis
// The time complexity of this solution is O(n), where n is the size of the input array arr. This is because we iterate through the array once and perform constant-time operations for each element.
string twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp; // Hash map to store array elements and their indices

    for (int i = 0; i < n; i++) {
        int num = arr[i];          // Current number in the array
        int moreNeeded = target - num; // Complement needed to reach the target

        // Check if the complement exists in the hash map
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES"; // Pair found, return "YES"
        }

        // Otherwise, add the current number to the hash map
        mpp[num] = i;
    }

    // If no pair is found, return "NO"
    return "NO";
}