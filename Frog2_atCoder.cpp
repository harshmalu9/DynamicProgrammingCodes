#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int n, k;
int arr[100100];
int dp[100100];

int rec(int level){
    if(level == 0) return 0;

    if(dp[level] != -1) return dp[level];

    int ans = MOD;

    for(int i=1; i<=k; i++){
        if(level - i < 0) break;

        ans = min(ans, abs(arr[level] - arr[level - i]) + rec(level - i));
    }

    return dp[level] = ans;
}

void solve() {
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));

    cout << rec(n-1) << '\n';
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