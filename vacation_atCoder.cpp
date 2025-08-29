#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<vector<int>> arr;
vector<int> a, b, c, e;
vector<vector<int>> dp;

int rec(int level, int avoid){
    if(level == n) return 0;
    
    if(dp[level][avoid] != -1) return dp[level][avoid];

    int ans = 0;
    if(avoid == 0){
        ans = max(ans, arr[1][level] + rec(level + 1, 1));
        ans = max(ans, arr[2][level] + rec(level + 1, 2));
        ans = max(ans, arr[3][level] + rec(level + 1, 3));
    }
    else if(avoid == 1){
        ans = max(ans, arr[2][level] + rec(level + 1, 2));
        ans = max(ans, arr[3][level] + rec(level + 1, 3));
    }
    else if(avoid == 2){
        ans = max(ans, arr[1][level] + rec(level + 1, 1));
        ans = max(ans, arr[3][level] + rec(level + 1, 3));
    }
    else{
        ans = max(ans, arr[1][level] + rec(level + 1, 1));
        ans = max(ans, arr[2][level] + rec(level + 1, 2));
    }

    return dp[level][avoid] = ans;
}

void solve() {
    cin >> n;
    e.resize(n+1, 0);
    a.resize(n+1);
    b.resize(n+1);
    c.resize(n+1);
    for(int i=0; i<n; i++) cin >> a[i] >> b[i] >> c[i];
    arr.push_back(e);
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    dp.resize(n+1, vector<int> (4, -1));

    cout << rec(0, 0) << '\n';
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