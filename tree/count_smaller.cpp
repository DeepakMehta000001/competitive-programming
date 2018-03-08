//Problem - https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
//Nature - BIT
//Level - Medium, Tricky.

#include<bits/stdc++.h>
using namespace std;

  int BST(map<long long,int> &idx, map<long long,pair<int,int> > &bst,int n){
    if(bst.size()==0){
        bst[0]={0,1};
        idx[0] =  n;
        idx[1] = -1;
        idx[2] = -1;
        return 0;
    }
    int i=0;
    int cnt=0;
    while(true){
        if(idx[i]==n){
            cnt+=bst[i].first;
            bst[i].second++;
            break;
        }else if(n > idx[i]){
            cnt += bst[i].first+bst[i].second;
            i = (i*2) + 2;
        }else{
            bst[i].first++;
            i = (i*2) + 1;
        }
        if(idx[i]==-1){
            idx[i]=n;
            bst[i]={0,1};
            idx[i*2+1]=-1;
            idx[i*2+2]=-1;
            break;
        }
    }
    
    return cnt;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);//[5,2,6,1];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    vector<int> res = countSmaller(arr);
    for(int i=0;i<arr.size();++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}