//Binary search is only applicable in a sorted search space
//algorithm
// 1. Find the middle element of the array
// 2. Compare the middle element with the target element
// 3. If the target element is equal to the middle element, return the index of the middle element
// 4. If the target element is less than the middle element, repeat the search on the sub-array to the left of the middle element
// 5. If the target element is greater than the middle element, repeat the search on the sub-array to the right of the middle element
// 6. If the sub-array is empty, the target element is not in the array
// 7. Repeat the process until the target element is found or the sub-array is empty
// Time complexity: O(log n)
// Space complexity: O(1)
//in cpp 
#include <iostream>
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int index = binarySearch(arr, target);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }
    return 0;
}
// Output   
// Element found at index 4
// Time complexity: O(log n)
// Space complexity: O(1)
// The binarySearch function takes an array arr and a target element as input and returns the index of the target element in the array. If the target element is not found, the function returns -1. The function uses a while loop to repeatedly divide the search space in half until the target element is found or the search space is empty. The time complexity of the binary search algorithm is O(log n), where n is the number of elements in the array. The space complexity of the algorithm is O(1) since it uses a constant amount of extra space.
//upper and lower bound in binary search
//algorithm
// 1. Find the lower bound of the target element in the array
// 2. Find the upper bound of the target element in the array
// 3. Return the range of indices containing the target element
// Time complexity: O(log n)
// Space complexity: O(1)
//in cpp both functions
// int lowerBound(vector<int>& arr, int target) {
//     int left = 0;
//     int right = arr.size() - 1;
//     int result = -1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (arr[mid] >= target) {
//             result = mid;
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }
//     return result;
// }
// int upperBound(vector<int>& arr, int target) {
//     int left = 0;
//     int right = arr.size() - 1;
//     int result = -1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (arr[mid] <= target) {
//             result = mid;
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }
//     return result;
// }
// int main() {
//     vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int target = 2;
//     int lower = lowerBound(arr, target);
//     int upper = upperBound(arr, target);
//     if (lower != -1 && upper != -1) {
//         cout << "Element found in the range [" << lower << ", " << upper << "]" << endl;
//     } else {
//         cout << "Element not found in the array" << endl;
//     }
//     return 0;
// }

class Solution {
  public:
//
    int findFloor(vector<int>& arr, int k) {
        int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] >= k) {
            // lower bound found:
            return i;
        }
    }
    return -1;
}
        // Your code here
    
};
