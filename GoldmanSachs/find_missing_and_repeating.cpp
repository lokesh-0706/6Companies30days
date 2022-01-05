#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
int *findTwoElement(int *arr, int n) {
        // code here
        int missing=0,repeat=0;
        
        sort(arr,arr+n);
       for(int i=0;i<n-1;i++)
       { 
            
           if(arr[i+1]-arr[i]>1)
           {
               missing=arr[i]+1;
               
           }
          
           
       }
       if(arr[0]==2)
           {
               missing=1;
               
           }
            if(arr[n-1]!=n)
           {
               missing=n;
           }
            for(int i=0;i<n-1;i++)
       { 
           if(arr[i]==arr[i+1])
           {
               repeat=arr[i];
           }
       }
       
       int *v = new int[2];
        v[0] = repeat;
        v[1] = missing;
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}