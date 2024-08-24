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

int n, m;
vector<vector<int>> v;
vector<vector<bool>> visited;

int dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == 0 || visited[i][j])
        return 0;

    visited[i][j] = true;
    int sum = v[i][j];

    sum += dfs(i, j - 1);
    sum += dfs(i, j + 1);
    sum += dfs(i - 1, j);
    sum += dfs(i + 1, j);

    return sum;
}

void solve() {
    cin >> n >> m;
    v.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    debug(v);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && v[i][j] != 0) {
                int current_sum = dfs(i, j);
                debug(current_sum);
                mx = max(mx, current_sum);
            }
        }
    }
    debug(mx);
    cout << mx << nl;

    cerr << "*****************************" << nl;
}

int main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
