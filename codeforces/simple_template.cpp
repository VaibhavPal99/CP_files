#include <bits/stdc++.h>
using namespace std;

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

void solve() {
	int n; cin >> n;
	vector<vector<pair<int, int>>> v(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;

		for (int j = 0; j < x; j++) {
			int a; int b;
			cin >> a >> b;
			v[i].pb(mp(a, b));
		}

	}
	debug(v);
	vector<vector<int>> side(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz(v[i]) - 1; j++) {
			int a = abs(v[i][j].ff - v[i][j + 1].ff);
			int b = abs(v[i][j].ss - v[i][j + 1].ss);
			int ans = a * a + b * b;
			side[i].pb(ans);
		}
		int s = abs(v[i][0].ff - v[i][sz(v[i]) - 1].ff);
		int t = abs(v[i][0].ff - v[i][sz(v[i]) - 1].ss);
		int val = s * s + t * t;
		side[i].pb(val);
	}

	debug(side);
	int x = -1; int y = -1;
	int final = 0;

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {
			if (sz(side[i]) != sz(side[j])) {
				continue;
			}

			for (int k = 0; k < sz(side[i]); k++) {
				int f = 1;
				for (int  l = 0; l < sz(side[i]); l++) {
					if (side[i][l] != side[j][(l + k) % sz(side[i])]) {
						f = 0;
						break;
					}
				}
				if (f) {
					x = i + 1;
					y = j + 1;
					final = 1;
				}
				if (final) break;

			}
			if (final) break;
		}
		if (final) break;
	}
	debug(x); debug(y);
	cout << x << " " << y << nl;
}

int main() {

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}