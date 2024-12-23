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

    vector<tuple<char, char, int, int>> data;

    char s1, s2;
    int val1, val2;


    while (cin >> s1 >> s2 >> val1 >> val2) {
        data.push_back(make_tuple(s1, s2, val1, val2));
    }

    // for (int i = 0; i < sz(data); i++) {
    //     auto [x1, y1, v1, v2 ] = data[i];
    //     cerr << x1 << " " << y1 << " " << v1 << " " << v2 << nl;
    // }
    set<char> st;
    int n = sz(data);
    for (int i = 0; i < n; i++) {
        auto [x1, y1, v1, v2 ] = data[i];
        st.insert(x1); st.insert(y1);
    }
    // debug(st);

    // sort(all(data));
    // for (int i = 0; i < sz(data); i++) {
    //     auto [x1, y1, v1, v2 ] = data[i];
    //     cerr << x1 << " " << y1 << " " << v1 << " " << v2 << nl;
    // }
    string tmp = "";
    vector<pair<char, char>> v;
    for (auto it : st) {
        tmp += it;
    }
    // debug(tmp);
    for (int i = 0; i < sz(tmp) - 1; i++) {
        v.pb({tmp[i], tmp[i + 1]});
    }
    v.pb({tmp[sz(tmp) - 1], tmp[0]});
    // debug(v);
    string ans = "";

    for (int i = 0; i < sz(v); i++) {
        for (int j = 0; j < n; j++) {
            auto [x1, y1, v1, v2 ] = data[j];
            // debug(v[i].ff); debug(v[i].ss); debug(x1); debug(y1);
            if (v[i].ff == x1 && v[i].ss == y1) {
                // debug(v1);
                ans += v1 + '0';
                break;
            }

        }
    }
    // debug(ans);
    int ok = 1;
    int f = 0;

    for (int i = 0; i < n; i++) {
        auto [x1, y1, v1, v2 ] = data[i];
        if (v[sz(v) - 1].ff == x1 && v1 == 1 && v2 == 1) {
            if (v[sz(v) - 1].ss == y1)
                f = 1;
            ans[sz(ans) - 1] = v1 + '0';
        }
    }

    for (int i = 0; i < n; i++) {
        auto [x1, y1, v1, v2 ] = data[i];
        if (v[sz(v) - 1].ff == x1 && v[sz(v) - 1].ss == y1) {
            if (v2 == 0 && f == 0)
                ok = 0;
        }
    }
    // debug(ans);
    cout << ans << nl;
    if (ok) {
        cout << "Non Overlapping Sequence Detector";
    } else {
        cout << "Overlapping Sequence Detector";
    }





    // cerr << "***************************" << nl;
}

int main() {
    // fastio();
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
//     freopen("er.txt", "w", stderr);
// #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
