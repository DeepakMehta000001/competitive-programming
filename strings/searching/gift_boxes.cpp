//Problem- https://www.hackerrank.com/contests/womens-codesprint-5/challenges/gift-boxes/problem
//Type - Strings , Hashing. 

#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long

using namespace std;

const int MAXN = (int) 1e6;
const int B = 37;

ull hsh[MAXN + 1], pw[MAXN + 1];

string a, b;

inline ull get(int l, int r) {
    return hsh[r] - hsh[l - 1];
}

int main() {
    int i, t;
    ios::sync_with_stdio(false);
    pw[0] = 1;
    for(i = 1; i <= MAXN; i++) {
        pw[i] = pw[i - 1] * B;
    }
    cin >> t;
    while(t > 0) {
        t--;
        cin >> a >> b;
        ull val = 0;
        for(i = (int) a.size() - 1; i >= 0; i--) {
            val = val * B + a[i] - 'a' + 1;
        }
        int ans = 0;
        int sz = 0;
        for(i = 0; i < b.size(); i++) {
            hsh[sz + 1] = hsh[sz] + pw[sz] * (b[i] - 'a' + 1);
            sz++;
            if(sz >= a.size() && val * pw[sz - a.size()] == get(sz - a.size() + 1, sz)) {
                sz -= a.size();
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
    