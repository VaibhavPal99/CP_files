#include <bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #endif
using namespace std;

// #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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

// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
// #else
// #define debug(x)
// #endif




void solve() {
	string s; cin >> s;
	int a; int b; cin >> a >> b;
	int n = sz(s);

	for (int i = 0; i < sz(s); i++) {
		if (s[i] != '0' && s[i] != '1') {
			cout << "INVALID" << nl;
			return;
		}
	}
	int cnt = 0;
	if (a > b) {
		string tmp = s;
		sort(al(s));
		for (int i = 0; i < n; i++) {
			if (s[i] != tmp[i])
				cnt++;
		}

	} else if (a < b) {
		string tmp = s;
		sort(all(s));
		for (int i = 0; i < n; i++) {
			if (s[i] != tmp[i]) {
				cnt++;
			}
		}

	} else {
		string tmp = s;
		sort(al(s));
		int cnt1 = 0; int cnt2 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != tmp[i])
				cnt1++;
		}
		sort(all(s));

		for (int i = 0; i < n; i++) {
			if (s[i] != tmp[i]) {
				cnt2++;
			}
		}
		cnt = min(cnt1, cnt2);
	}

	cout << cnt << nl;
	// cerr << "***********************" << nl;
}

int main() {
	// fastio();
// #ifndef ONLINE_JUDGE
// 	freopen("in.txt", "r", stdin);
// 	freopen("op.txt", "w", stdout);
// 	freopen("er.txt", "w", stderr);
// #endif
	int tt = 1;
	cin >> tt;
	for (int i = 1; i <= tt; i++) {
		solve();
	}
	return 0;
}
