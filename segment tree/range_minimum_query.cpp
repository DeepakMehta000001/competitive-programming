
//Problem - Range Minimum Query
//Nature - Segment Tree
    
#include<bits/stdc++.h>
using namespace std;
#define NAX 16
int n = 6; 
int arr[6]={-1,3,4,0,2,1};
int segTree[NAX];

void build(int l,int h,int p){
    if(h==l){
        segTree[p]=arr[l];
        return;
    }
    int mid = (l+h)/2; 
    build(l,mid,2*p+1);
    build(mid+1,h,2*p+2);
    segTree[p] = min(segTree[2*p+1],segTree[2*p+2]);
}


int query(int ql,int qh,int l,int h, int p){
        if(ql<=l && qh>=h)
            return segTree[p];
        if(ql>h || qh<l)
            return INT_MAX;
        int mid = (l+h)/2;
        return min(query(ql,qh,l,mid,p*2+1),query(ql,qh,mid+1,h,p*2+2));
}


int main(){
    //memset(segTree,0,sizeof(segTree));
    fill(segTree,segTree+NAX,INT_MAX);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    build(0,n-1,0);
    cout<<"lowest between 1,3 is "<<query(1,3,0,n-1,0)<<endl;
    cout<<"lowest between 0,2 is "<<query(0,2,0,n-1,0)<<endl;
    cout<<"lowest between 1,2 is "<<query(1,2,0,n-1,0)<<endl;
    return 0;
}

