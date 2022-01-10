#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int a[n],b[n];
        int cnt=0;
        a[n-1]=-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                cnt++;
                a[i]=cnt;
            }
            else{
                a[i]=0;
                cnt=0;
            }
        }
        cnt=0;
        cout<<endl;
        for(int i=n-1;i>0;i--){
            if(arr[i]<arr[i-1]){
                cnt++;
                b[i]=cnt;
            }
            else{
                b[i]=0;
                cnt=0;
            }
        }    
        b[0]=-1;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(a[i]==0 and b[i]==0){
                if(a[i-1]!=0 and b[i+1]!=0)
                maxi= max(maxi,a[i-1]+b[i+1]+1);
            }
        }
    return maxi;
    }
    
};