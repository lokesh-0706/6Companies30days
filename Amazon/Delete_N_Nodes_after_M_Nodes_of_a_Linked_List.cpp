#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

 // } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
void linkdelete(struct Node* head, int M, int N)
    {
        //Add code here   
        Node* temp=head;
        int a=M,b=N;
        Node* temp1;
        while(temp->next!=NULL)
        {
            for(int i=1;i<a;i++)
            {
                if(temp!=NULL)
                    temp=temp->next;
            }
            if(temp==NULL)
            {
                return;
            }
            temp1=temp;
            for(int i=0;i<=b;i++)
            {
                if(temp1!=NULL)
                {
                    temp1=temp1->next;
                }
            }
            if(temp1==NULL)
            {
                temp->next=NULL;
                return;
            }
            
            temp->next=temp1;
            temp=temp1;
        }}
};



// { Driver Code Starts.
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}