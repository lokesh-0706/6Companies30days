#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    int maxProfit(int K, int N, int A[]) 
    {
        int t[K+1][N];
        for(int i=0;i<=K;i++)
        {
            t[i][0]=0;
        }
        for(int i=0;i<N;i++)
        {
            t[0][i]=0;
        }
        for(int i=1;i<=K;i++)
        {
            int prev=INT_MIN;
            for(int j=1;j<N;j++) 
            {
                prev=max(prev,t[i-1][j-1]-A[j-1]);
                t[i][j]=max(t[i][j-1],prev+A[j]);
            }
        }
        return t[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
} 