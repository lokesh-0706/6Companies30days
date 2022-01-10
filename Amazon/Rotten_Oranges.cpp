#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        int x=1;
        int cnt=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        cnt++;    
                    }
                }
            }
        if(cnt==0){
            return 0;
        }
        while(x<=n*m){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    if(i+1<=m-1 and grid[i+1][j]==1){
                        grid[i+1][j]=3;
                    }
                    if(i-1>=0 and grid[i-1][j]==1){
                        grid[i-1][j]=3;
                    }
                    if(j+1<=n-1 and grid[i][j+1]==1){
                        grid[i][j+1]=3;
                    }
                    if(j-1>=0 and grid[i][j-1]==1){
                        grid[i][j-1]=3;
                    }                    
                    
                }
            }
        }
        cnt=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        cnt++;    
                    }
                    if(grid[i][j]==3){
                        grid[i][j]=2;
                    }
                }
            }
            if(cnt==0){
                return x;
            }
            x++;
        }

        return -1;
        
    }
};