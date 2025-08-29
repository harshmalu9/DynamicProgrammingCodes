#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int r, c; //total
int arr[1001][1001];
int dp[1001][1001];
bool done[1001][1001]; //what if the COMPUTED value of the state is -1
int n, m; //destination

int rec(int cr, int cc){ // cr = current row, cc = current column
    if(cr < 0 or cc < 0) return -MOD;

    if(cr == 0 and cc == 0) return arr[0][0];

    if(done[cr][cc]) return dp[cr][cc];

    int ans = -MOD; // SINCE IT IS A MAXIMIZATION PROBLEM, ALWAYS RETURN -INFI
    if(cr != 0) ans = max(ans, arr[cr][cc] + rec(cr - 1, cc));
    if(cc != 0) ans = max(ans, arr[cr][cc] + rec(cr, cc - 1));

    // THIS IS HOW WE CAN USE RPUNING IN MAXIMIZATION PROBLEMS
    // int ans = arr[cr][cc];
    // ans = max(ans + rec(cr - 1, cc), ans + rec(cr, cc - 1));

    done[cr][cc] = true;
    return dp[cr][cc] = ans;
}

void solve() {
    cin >> r >> c >> n >> m;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << rec(n, m) << '\n';
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