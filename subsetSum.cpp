// subset queries with solution generation
// if we change the rec() param from currSum to sumLeft and start the function with rec(0, target), we can use the same code for subset sum for multiple queries 
// this would help us use only one dp array throughout i.e we will not need to flush the memo table for every query


#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int n;
int target;
vector<int> a;
vector<int> sol;
vector<vector<int>> dp;

void disp(vector<int> a){
    for(int i: a) cout << i << " ";
    cout << '\n';
}

int rec(int level, int currSum){
    if(currSum > target) return 0;

    if(level == n) {
        if(currSum == target) return 1;
        else return 0;
    }

    int ans = 0;
    if(rec(level + 1, currSum)) ans = 1;
    else if(rec(level + 1, currSum + a[level])) ans = 1;

    return ans;
}

void generate(int level, int currSum){
    if(currSum > target) return;

    if(level == n) {
        return;
    }

    int ans = 0;
    if(rec(level + 1, currSum)) {
        ans = 1;
        generate(level + 1, currSum);
    }
    else if(rec(level + 1, currSum + a[level])){
        ans = 1;
        cout << a[level] << " ";
        generate(level + 1, currSum + a[level]);
    }

    return ;
}

void solve() {
    cin >> n >> target;
    a.resize(n);
    int ma = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    dp.resize(n, vector<int>(ma, -1));
    cout << rec(0, 0) << '\n';
    generate(0, 0);
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