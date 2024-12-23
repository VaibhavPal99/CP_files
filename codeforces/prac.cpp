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

bool func(vector<int>& numbers, int targetSum, vector<int>& result) {
    int n = sz(numbers);
    int totalCombinations = (1 << n);

    for (int mask = 0; mask < totalCombinations; ++mask) {
        vector<int> subset;
        int currentSum = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.pb(numbers[i]);
                currentSum += numbers[i];
            }
        }

        if (currentSum == targetSum) {
            result = subset;
            return true;
        }
    }

    return false;
}

void solve() {

    string s; cin >> s;
    ll sum = 0;
    for (int i = 0; i < sz(s); i++) {
        sum += (s[i] - '0');
    }
    debug(sum);

    ll rem = sum % 9;

    if (rem == 0) {
        cout << "Yes" << nl;
        return;
    }
    debug(rem);
    ll diff = 9 - rem;
    debug(diff);
    vector<int>a;
    ll final = 0;
    for (int i = 0; i < sz(s); i++) {
        int val = s[i] - '0';
        if (val == 2) {
            final += val;
            a.pb(val);
        }
        if (val == 3) {
            final += 6;
            a.pb(6);
        }
    }

    sort(all(a));
    debug(a);
    int i = diff;
    while (i <= final) {
        vector<int> result;
        if (func(a, i, result)) {
            cout << "Yes" << nl;
            return;
        }
        i += 9;
    }

    cout << "No" << nl;





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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
