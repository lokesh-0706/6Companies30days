#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string s1, string s2) 
    {
        if(s1+s2==s2+s1)
        {
            int n= __gcd( s1.length() , s2.length() );
            return s1.substr(0,n);
        }
        return "";
    }
};