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




void solve() {
	int n; int m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	debug(v);
	int k; cin >> k;
	vector<vector<int>> dp(n, vector<int> (m));
	dp[0][0] = 0;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0 && v[i][j] >= v[i - 1][j])
				dp[i][j] += dp[i - 1][j] + 1;
			if (j > 0 && v[i][j] >= v[i][j - 1])
				dp[i][j] += dp[i][j - 1] + 1;
		}
	}
	debug(dp);
	vector<pair<int, int>> a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j] == k) {
				a.pb({i, j});
			}
		}
	}
	debug(a);
	cerr << "***********************" << nl;
}

int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
	freopen("er.txt", "w", stderr);
#endif
	int tt = 1;
	cin >> tt;
	for (int i = 1; i <= tt; i++) {
		solve();
	}
	return 0;
}
