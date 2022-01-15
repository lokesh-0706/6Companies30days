#include <bits/stdc++.h>
using namespace std;
    vector<vector<int> > fourSum(vector<int> &array, int k) {
        
        int n = array.size();
        sort(array.begin(), array.end());
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n-3; i++) {
            
            if(i > 0 && array[i] == array[i-1])
                continue;
            for(int j = i+1; j < n-2; j++) {
                
                if(j > i+1 && array[j] == array[j-1])
                continue;
                
                int l = j+1, r = n-1;
                while(l < r) {
                    int sum = array[i] + array[j] + array[l] + array[r];
                    if(sum < k) {
                        l++;
                    }
                    else if(sum > k) {
                        r--;
                    }
                    else {
                        ans.push_back({array[i], array[j], array[l], array[r]});
                        while(l+1 < r && array[l+1] == array[l])
                            l++;
                        l++;
                        while(r-1 > l && array[r-1] == array[r])
                            r--;
                        r--;
                    }
                }
                
            }
        }
        return ans;
    }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends