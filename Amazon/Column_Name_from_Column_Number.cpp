#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string x;
        int a=0;
        while(n>0){
            a = n%26 -1;
            if(a==-1){
                a=25;
                n=n-26;
            }
            x+='A'+(a);
            n=n/26;
        }
        reverse(x.begin(), x.end());
        return x;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}