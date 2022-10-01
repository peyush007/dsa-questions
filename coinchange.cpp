

//https://practice.geeksforgeeks.org/problems/coin-change2448/1?page=1&curated[]=8&sortBy=submissions


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        long long int a[sum+1];
        for(int i=0;i<=sum;i++)
        {
            a[i] = 0;
        }
        a[0] = 1;
        for(int j=0;j<N;j++)
        {
            for(int i=coins[j];i<=sum;i++)
            {
                a[i] = a[i] + a[i-coins[j]];
            }
        }
        return a[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends