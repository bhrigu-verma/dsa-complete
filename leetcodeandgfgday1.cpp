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