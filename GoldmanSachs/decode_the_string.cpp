#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        vector<char>st;
        for(int i=0;i<s.length();i++)
        {
            if (s[i] == ']') {
            string temp;
            while (!st.empty() && st.front() != '[') {
                temp = st.front() + temp;
                st.erase(st.begin());
            }
            st.erase(st.begin());
            string num;
            while (!st.empty() && isdigit(st.front())) {
                num = st.front() + num;
                st.erase(st.begin());
            }
            int n = stoi(num);
            string r;
            for (int j = 0; j < n; j++)
                r+= temp;
            for (char ch : r)
                st.insert(st.begin(),ch);
        }
        else
            st.insert(st.begin(),s[i]);
    }
    string ans="";
    while (!st.empty()) {
        ans= st.front() + ans;
        st.erase(st.begin());
    }
    return ans;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
} 