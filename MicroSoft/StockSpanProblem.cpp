#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> st;
       vector<int> ans(n);
       
       for(int i=0;i<n;i++){
           if(!st.empty() && st.top().first > price[i]){
               ans[i] = st.top().second;
           }
           else if(!st.empty() && st.top().first <= price[i]){
               while(!st.empty() && st.top().first <= price[i])
               st.pop();
               
               if(!st.empty())
                 ans[i] = st.top().second;
           }
           st.push({price[i],i+1});
           ans[i] = i-ans[i]+1;
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
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends