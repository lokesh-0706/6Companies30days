#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

bool check(vector<int> a,int s,int k)
{
    int ans=0,n=a.size();
    for(int i=0;i<k-1;i++)
        ans+=a[i];
    for(int i=k-1;i<n;i++)
    {
        ans+=a[i];
        if(ans>=s)
            return true;
        ans-=a[i-k+1];
    }
    return false;
}

int minSubArrayLen(int s, vector<int>& a) {
    int i,n=a.size(),ans=INT_MAX,low=1,high=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(check(a,s,mid))
        {
            ans=min(ans,mid);
            high=mid-1;
        }
        else
            low=mid+1;
    }
    if(ans==INT_MAX)
        return 0;
    return ans;
    
}
};