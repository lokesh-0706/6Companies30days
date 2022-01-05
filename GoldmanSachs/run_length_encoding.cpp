#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src){
   string str = "";
   int i=0, j=0;
   int n = src.length();
   
   while(i<n){
       while(src[i] == src[j] and j<n){
           j++;
       }
       
       str.push_back(src[i]);
       str += to_string(j-i);
       
       i = j;
   }
   return str;
   
}  