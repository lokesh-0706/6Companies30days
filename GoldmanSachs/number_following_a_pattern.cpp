#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        stack<int> t;
        string ans ="";
        int num=1;
        for(int i=0;i<S.size();i++){
            char c=S[i];
            if(c=='D'){
                t.push(num++);
                
            }
            else {
                t.push(num++);
                while(!t.empty()){
                    char c1= '0'+t.top();
                    ans.push_back(c1);
                    t.pop();
                    
                }
            }
        }
        t.push(num++);
        while(!t.empty()){
            
            char c1= '0'+t.top();
            ans.push_back(c1);
            t.pop();
                    
                }
        return ans;
        
        
    }
    };



// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 