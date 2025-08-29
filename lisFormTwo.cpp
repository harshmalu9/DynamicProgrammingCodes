#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int n;
int arr[10010010];
int dp[10010010];

int rec(int level){
    if(level <= 0) return 1;

    if(dp[level] != -1) return dp[level];

    int ans = 1;
    for(int prev = level -1; prev >= 0; prev--){
        if(arr[prev] < arr[level]) {
            ans = max(ans, 1 + rec(prev));
        }
    }
    return dp[level] = ans;
}

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, rec(i));
    }
    cout << ans << '\n';
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