//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool check(Node* root,vector<int> bn){
        if(!root) return false;
        if(bn[root->data] == -1) return false;
        return true;
    }
  
    void pushTarget(Node* root,int target,queue<Node*> &q){
        if(!root) return;
        if(root->data == target){
            q.push(root);
            return;
        }
        pushTarget(root->left,target,q);
        pushTarget(root->right,target,q);
    }
    
    void assignParent(Node* child,Node* par,vector<Node*>&parent){
        if(!child) return;
        parent[child->data] = par;
    }
    
    void dfs(Node* root,vector<Node*> &parent){
        if(!root) return;
        assignParent(root->left,root,parent);
        assignParent(root->right,root,parent);
        dfs(root->left,parent);
        dfs(root->right,parent);
    }
  
    int minTime(Node* root, int target){
        vector<Node*> parent(100001);
        dfs(root,parent);
        
        queue<Node*> q;
        pushTarget(root,target,q);
        
        vector<int> burnedNode(100001);
        int t = -1;
        while(!q.empty()){
            int size = q.size();
            t++;
            while(size--){
                auto top = q.front();
                q.pop();
                burnedNode[top->data] = -1;
                
                if(check(top->left,burnedNode)) 
                    q.push(top->left);
                    
                if(check(top->right,burnedNode)) 
                    q.push(top->right);
                    
                if(check(parent[top->data],burnedNode))
                    q.push(parent[top->data]);
            }
        }
        
        return t;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}