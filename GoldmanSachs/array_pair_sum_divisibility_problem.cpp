#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        vector<int> v;
        if(nums.size()%2!=0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]%k);
        }
        int arr[k]={0};
        for(int i=0;i<v.size();i++){
            arr[v[i]]++;
        }
        for(int i=1;i<k;i++){
            if(arr[i]!=arr[k-i]){
                return 0;
            }
        }
        if(k%2==0){
            if(arr[k/2]%2!=0){
                return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} 