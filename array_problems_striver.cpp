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
//cpp
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



//Find the Majority Element that occurs more than N/2 times

//brute force



#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}


//Optimal Approach
//The brute force approach has a time complexity of O(n^2) due to the nested loops. We can optimize this
// by using the Boyer-Moore Voting Algorithm, which has a time complexity of O(n) and constant space complexity.
// The algorithm works by maintaining a candidate majority element and a count of its occurrences.
// If the current element is the same as the candidate, we increment the count; otherwise, we decrement the count.
// If the count becomes zero, we update the candidate to the current element and reset the count to 1.
// After traversing the array, the candidate will be the majority element.
// We perform a second pass to verify if the candidate occurs more than n/2 times.
// If it does, we return the candidate; otherwise, we return -1.
// Let's implement this optimized approach in code:



#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }

    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}



//Kadane's Algorithm : Maximum Subarray Sum in an Array
//The Kadane's algorithm is a dynamic programming technique used to find the maximum subarray sum in an array.
// It works by maintaining two variables: maxSum and currentSum. The maxSum variable stores the maximum subarray sum found so far,
// while the currentSum variable stores the sum of the current subarray being considered.
// The algorithm iterates through the array, updating the currentSum by adding the current element and resetting it to zero if it becomes negative.
// At each step, it compares the currentSum with the maxSum and updates the maxSum if the currentSum is greater.
// The final maxSum value represents the maximum subarray sum in the array.
// Let's implement the Kadane's algorithm in code:
//The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray 
//with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.


#include <bits/stdc++.h>
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


//majority element greater than n/2 ki occurence


// 1. Brute Force Approach**
//  Algorithm/Steps:
// 1. Traverse the array using two nested loops:
//    - Outer loop selects an element.
//    - Inner loop counts the frequency of the selected element.
// 2. For each element, check if its frequency is greater than \( N/2 \).
// 3. If found, return the element.
// 4. If no majority element is found, return -1.

int majorityElement(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] == v[i]) {
                count++;
            }
        }
        if (count > n / 2) return v[i];
    }
    return -1;
}

// #### Complexity:
// - **Time Complexity**: \( O(N^2) \)
//   - Outer loop runs \( N \) times, and the inner loop also runs \( N \) times.
// - Space Complexity: \( O(1) \) 
  - No extra data structures are used.

2. Using a Hash Map (Better Approach)**
 Algorithm/Steps:
1. Use a hash map (or frequency array) to count occurrences of each element.
2. Traverse the array and update the hash map with counts.
3. While updating, check if any element’s count exceeds \( N/2 \). If yes, return the element.

int majorityElement(vector<int> v) {
    int n = v.size();
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[v[i]]++;
        if (freq[v[i]] > n / 2) return v[i];
    }
    return -1;
}
```

#### Complexity:
Time Complexity**: \( O(N) \) (with unordered_map) or \( O(N \log N) \) (with map).
Hash map operations are \( O(1) \) on average, but insertion takes \( O(\log N) \) in worst cases.
space Complexity**: \( O(N) \) 
Space used by the hash map.

 Insights:
 This approach reduces time complexity by leveraging a data structure to store counts.
 Suitable for most cases but uses extra memory.


3. Sorting-Based Approach**
 Algorithm/Steps:
1. Sort the array.
2. The majority element must be present at index \( N/2 \) (because it occurs more than \( N/2 \) times and dominates the sorted array).
3. Return the element at \( N/2 \).


int majorityElement(vector<int> v) {
    sort(v.begin(), v.end());
    return v[v.size() / 2];
}
```

Time Complexity ( O(N \log N) \)
Sorting the array dominates the runtime.
Space Complexity: \( O(1) \) (if in-place sorting is used).

#### Insights:
- This approach doesn’t require extra memory (besides sorting).
- While not optimal, it’s simple and leverages the properties of sorted arrays.

---

### **4. Moore’s Voting Algorithm (Optimal Approach)**
#### Algorithm/Steps:
1. **Candidate Selection**:
   - Use a variable (`count`) to track balance and another (`element`) to store the potential majority element.
   - Traverse the array:
     - If `count` is 0, set the current element as the candidate (`element`) and reset `count` to 1.
     - If the current element matches `element`, increment `count`.
     - Otherwise, decrement `count`.
2. **Verification**:
   - Traverse the array again to count occurrences of `element`.
   - Return `element` if its count exceeds \( N/2 \), otherwise return -1.

#### Code:
```cpp
int majorityElement(vector<int> v) {
    int n = v.size();
    int count = 0, element;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            element = v[i];
            count = 1;
        } else if (v[i] == element) {
            count++;
        } else {
            count--;
        }
    }

    // Verify if the candidate is the majority element
    count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == element) count++;
    }
    return (count > n / 2) ? element : -1;
}
```

#### Complexity:
- **Time Complexity**: \( O(N) \)
  - Two traversals: one for candidate selection and another for verification.
- **Space Complexity**: \( O(1) \)
  - No extra data structures are used.

#### Insights:
- This is the most efficient solution.
- It leverages the cancelation effect of non-majority elements.

---

### **5. Divide and Conquer Approach**
#### Algorithm/Steps:
1. Divide the array into two halves.
2. Recursively find the majority element in each half.
3. Merge the results:
   - If both halves agree on the majority element, return it.
   - Otherwise, count each candidate in the whole array and return the one with a count greater than \( N/2 \).

#### Code:
```cpp
int countInRange(vector<int>& v, int num, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (v[i] == num) count++;
    }
    return count;
}

int majorityElementRec(vector<int>& v, int left, int right) {
    if (left == right) return v[left];

    int mid = left + (right - left) / 2;
    int leftMajority = majorityElementRec(v, left, mid);
    int rightMajority = majorityElementRec(v, mid + 1, right);

    if (leftMajority == rightMajority) return leftMajority;

    int leftCount = countInRange(v, leftMajority, left, right);
    int rightCount = countInRange(v, rightMajority, left, right);

    return (leftCount > rightCount) ? leftMajority : rightMajority;
}

int majorityElement(vector<int> v) {
    return majorityElementRec(v, 0, v.size() - 1);
}
```

#### Complexity:
- **Time Complexity**: \( O(N \log N) \)
  - Each recursive step divides the array in half, and merging takes \( O(N) \).
- **Space Complexity**: \( O(\log N) \)
  - Space used by recursion stack.

#### Insights:
- A divide-and-conquer approach, but less practical than Moore’s algorithm.

---

### Comparison of All Approaches:

| Approach                 | Time Complexity       | Space Complexity | Notes                                                                 |
|--------------------------|-----------------------|------------------|----------------------------------------------------------------------|
| Brute Force              | \( O(N^2) \)          | \( O(1) \)       | Simple but inefficient for large arrays.                            |
| Hash Map                 | \( O(N) \) or \( O(N \log N) \) | \( O(N) \)       | Efficient but uses extra space.                                     |
| Sorting                  | \( O(N \log N) \)     | \( O(1) \)       | No extra space, but slower than optimal.                            |
| Moore’s Voting Algorithm | \( O(N) \)            | \( O(1) \)       | Most efficient and widely used for this problem.                    |
| Divide and Conquer       | \( O(N \log N) \)     | \( O(\log N) \)  | Useful as a learning approach but not practical.                    |

---

For competitive programming or real-world applications, **Moore’s Voting Algorithm** is the preferred solution due to its optimal time and space efficiency.


// buy and sell stock problem
// 1. Brute Force Approach**
//  Algorithm/Steps:
// 1. Traverse the array using two nested loops:
//    - Outer loop selects a buy day.
//    - Inner loop selects a sell day after the buy day.
// 2. For each pair of buy and sell days, calculate the profit.
// 3. Update the maximum profit if the current profit is greater.
// 4. Return the maximum profit found.
//code
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int profit = prices[j] - prices[i];
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}

// #### Complexity:
// - **Time Complexity**: \( O(N^2) \)
//   - Nested loops traverse the array.
// - **Space Complexity**: \( O(1) \)
//   - No extra space used.
//optimal approach
// 2. Single Pass Approach**
//  Algorithm/Steps:
// 1. Initialize two variables: `minPrice` to track the minimum price seen so far and `maxProfit` to track the maximum profit.
// 2. Traverse the array:
//    - Update `minPrice` to the minimum of the current price and `minPrice`.
//    - Update `maxProfit` to the maximum of the current profit and the difference between the current price and `minPrice`.
// 3. Return `maxProfit`.
//code
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}
// #### Complexity:
// - **Time Complexity**: \( O(N) \)
//   - Single pass through the array.
// - **Space Complexity**: \( O(1) \)
//   - Constant space used.
// #### Insights:

//best time to buy and sell stock 2
//statement - You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//example
// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// 1. Brute Force Approach**
//  Algorithm/Steps:
// 1. Traverse the array using two nested loops:
//    - Outer loop selects a buy day.
//    - Inner loop selects a sell day after the buy day.
// 2. For each pair of buy and sell days, calculate the profit.
// 3. Update the maximum profit if the current profit is greater.
// 4. Return the maximum profit found.

    