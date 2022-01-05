#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
    int CountWays(string str){
        int len=str.length();
        int arr[len+1];
        int mod = 1e9 + 7;
        arr[0]=1;
        arr[1]=1;
       
        if(len==1 && str[0]!='0'){
            return 1;    
        }
        
        if(str[0]=='0'){
            return 0;    
        }
        
        
        for(int i=2;i<=len;i++)
        {
            arr[i]=0;
            
            if(str[i-1]>'0'){
                arr[i] = arr[i-1];                
            }

            if(str[i-2]=='1' || str[i-2]=='2' && str[i-1]<'7'){
                arr[i] = (arr[i]+arr[i-2])%mod;                
            }

        }
        return arr[len];
    }


};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
} 