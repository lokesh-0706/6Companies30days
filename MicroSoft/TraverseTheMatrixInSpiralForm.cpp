#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) 
    {
        // code here
        int t_r=0,b_r=r-1;
        int l_c=0,r_c=c-1;
        vector<int> v;
        while(t_r<=b_r and l_c<=r_c){
            for(int i=l_c;i<=r_c;i++){
                v.push_back(m[t_r][i]);
            }
            t_r++;
            if(!(t_r<=b_r and l_c<=r_c)){
                break;
            }
            for(int i=t_r;i<=b_r;i++){
                v.push_back(m[i][r_c]);
            }
            r_c--;
            if(!(t_r<=b_r and l_c<=r_c)){
                break;
            }
            for(int i=r_c;i>=l_c;i--){
                v.push_back(m[b_r][i]);
            }
            b_r--;
            if(!(t_r<=b_r and l_c<=r_c)){
                break;
            }
             for(int i=b_r;i>=t_r;i--){
                v.push_back(m[i][l_c]);
            }
            l_c++;
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends