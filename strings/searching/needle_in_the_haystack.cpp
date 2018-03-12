//Problem - http://www.spoj.com/problems/NHAY/
//Type - Strings, sliding window, Hashing. 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

const int MAXN = (int) 1e6;
const int B = 37;
ull hsh[MAXN + 1], pw[MAXN + 1];
inline ull get(int l, int r) {
    return hsh[r] - hsh[l - 1];
}


int M,N;
string pat,txt;
bool hasRes=false;

/*
//Simplest Window Approach
void solve(){
    for(int i=0;i<=N-M;++i){
        int idx=0;
        bool mark=true;
        for(int j=i;j<i+M;++j){
            if(txt[j]!=pat[idx++]){
                mark=false;
                break;
            }
        }
        if(mark){
            cout<<i<<endl;
            hasRes=true;
        }
    }
    
}
*/

//Using Hashing for faster comparison. 

void solveHash(){
    ull val = 0;
    for(int i=M-1;i>=0;--i){
        val = val * B + pat[i] - 'a' + 1;
    }

    int sz = 0;
    for(int i = 0; i < N; i++) {
        hsh[sz + 1] = hsh[sz] + pw[sz] * (txt[i] - 'a' + 1);
        sz++;
        if(sz >= M && val * pw[sz - M] == get(sz - M + 1, sz)) {
            cout<<sz-M<<endl;
            hasRes=true;
        }
    }
}

int main(){
    pw[0] = 1;
    for(int i = 1; i <= MAXN; i++) {
        pw[i] = pw[i - 1] * B;
    }
    while(scanf("%d", &M) !=EOF){
        cin>>pat;
        cin>>txt;
        N = txt.length();
        hasRes=false;
        //solve();
        solveHash();
        if(!hasRes){
            cout<<""<<endl;
        }
    }
    return 0;
}