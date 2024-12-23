#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define al(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void dfs(vector<string> &v, int i, int j, vector<vector<int>> &vis) {

    int n = sz(v);
    int m = sz(v[0]);

    if (i < 0 || i >= n) return;
    if (j < 0 || j >= m) return;

    if (v[i][j] == '#' || vis[i][j] == 1) return;
    vis[i][j] = 1;
    dfs(v, i - 1, j, vis);
    dfs(v, i + 1, j, vis);
    dfs(v, i, j - 1, vis);
    dfs(v, i, j + 1, vis);
}

void solve() {

    int n; int m; cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    debug(v);
    debug(vis);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (v[i][j] == '.' && vis[i][j] == 0) {
                cnt++;
                dfs(v, i, j, vis);
		debug(cnt);
            }
        }
    }

    debug(cnt);
    cout << cnt << nl;

    cerr << "***********************" << nl;
}

int main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
    freopen("er.txt", "w", stderr);
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
