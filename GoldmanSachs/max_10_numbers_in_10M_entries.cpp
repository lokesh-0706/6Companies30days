#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10000000];
    for(int i=0;i<10000000;i++){
        cin>>arr[i];
    }
    sort(arr,arr+10000000,greater<int>());
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}