// User function template for C++
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