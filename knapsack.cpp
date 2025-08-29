#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<int> w, v;
int W;
vector<vector<int>> dp;


int rec(int l, int wl){
    if(l == n) return 0;

    if(dp[l][wl] != -1) return dp[l][wl];

    int ans = rec(l+1, wl);
    if(wl >= w[l]){
        ans = max(ans, rec(l+1, wl - w[l]) + v[l]);
    }
    return dp[l][wl] = ans;
}

void solve() {
    cin >> n;
    cin >> W;
    w.resize(n);    
    v.resize(n);    
    for(int i=0; i<n; i++) cin >> w[i] >> v[i];
    // for(int i=0; i<n; i++) cin >> v[i];
    dp.resize(n+1, vector<int>(W+1, -1));

    cout << rec(0, W) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int _t = 1;
    // cin >> _t;
    while(_t--) {
        solve();
    }

    return 0;
}