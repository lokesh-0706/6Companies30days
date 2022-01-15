#include<bits/stdc++.h>
using namespace std;

 
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> indeg(N,0);
	    vector<vector<int>>mp(N);
	    for( auto p : pre){
	        indeg[p.first] ++;
	        mp[p.second].push_back(p.first);
	    }
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        if(indeg[i]==0){
	            indeg[i]==-1;
	            q.push(i);
	        }
	    }
	    while(q.size()){
	        int u = q.front();
	        q.pop();
	        for(auto v : mp[u]){
	            if(indeg[v]==-1)continue;
	            indeg[v]--;
	            if(indeg[v]==0){
	                indeg[v]=-1;
	                q.push(v);
	            }
	        }
	    }
	    for(int i=0;i<N;i++)if(indeg[i]>0)return false;
	    return true;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prereq;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prereq.push_back(make_pair(x, y));
        }
       
        Solution ob;
        if (ob.isPossible(N, prereq))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
} 