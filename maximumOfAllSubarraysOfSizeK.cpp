/*
Maximum of all subarrays of size k
Medium Accuracy: 26.04% Submissions: 295K+ Points: 4

Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
Example 2:

Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13
Output: 
10 10 10 15 15 90 90
Explanation: 
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10
3rd contiguous subarray = {10 7 9 4}, Max = 10
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, 
Max = 15
6th contiguous subarray = {4 15 12 90},
Max = 90
7th contiguous subarray = {15 12 90 13}, 
Max = 90
Your Task:  
You dont need to read input or print anything. Complete the function max_of_subarrays() which takes the array, N and K as input parameters and returns a list of integers denoting the maximum of every contiguous subarray of size K.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(k)

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ N
0 ≤ arr[i] ≤ 107
*/

//This approach has the time complexity O(N*k)


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
 
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        int i=0,temp=i,j=(i+k)-1,maxval=arr[temp]; /*maintaining 2 pointers i.e. i at the start of the window
                                                and j at the end of the window and temp to find max through
                                                the window*/
        temp=temp+1;
        
        vector<int>v;
        
        while(i<n && j<n){
            if((temp)<=j){
                maxval=max(maxval,arr[temp]);
                temp=temp+1;
            }
            else{
               v.push_back(maxval);
               i=i+1;
               j=j+1;
               temp=i;
               maxval=arr[temp];
               temp=temp+1;
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

/*
Output Window

Runtime Error 
Test Cases Passed: 
67 /166
Time Limit Exceeded

Your program took more time than expected.Expected Time Limit : 1.46sec
Hint : Please optimize your code and submit again.

Geek Tip:
Your code is taking more time than expected. Reduce its time complexity by optimising your code.
You can access the hint section to get an idea about what is expected of you.
Please note that this will impact your score.*/
