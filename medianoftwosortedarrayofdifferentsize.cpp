//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        if(array1.size()>array2.size())
            return MedianOfArrays(array2,array1);
        int k = (array1.size()+array2.size()+1)/2;
        int n = array1.size();
        int m = array2.size();
        int l = max(0,k-m);
        int h = min(n,k);
        while(l<=h){
            int count = l+(h-l)/2;
            int l1 = count>0?array1[count-1]:INT_MIN;
            int l2 = (k - count-1)>=0?array2[k - count-1]:INT_MIN;
            int r1 = (count)<n?array1[count]:INT_MAX;
            int r2 = (k-count)<m?array2[k - count]:INT_MAX;
            if(l1<=r2 && l2<=r1){
                if((m+n)%2!=0)
                    return max(l1,l2);
                else 
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2)
            h = count-1;
            else
            l = count+1;
        }
        return 0;
        

    
        
        
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends