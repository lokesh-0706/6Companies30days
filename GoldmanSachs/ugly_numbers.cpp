#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
    ull getNthUglyNo(int n) {
    	   set <long long int> s;
    	   s.insert(1);
    	   n--;
    	   while(n--){
    	        auto val = s.begin();
    	        long long int a = *val;
    	        s.erase(val);
    	        s.insert(a*2);
    	        s.insert(a*3);
    	        s.insert(a*5);
    	    } 
            auto it= *s.begin();
            return it;
    	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}