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




void solve()
{
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x != 0)
      v.pb(x);
  }
  ll c = 0;

  for (int i = 0; i < sz(v) - 1; i++) {
    if (c >= 0 && v[i] >= 0) {
      c += v[i];
    } else if (c >= 0 && v[i] < 0) {
      if (c > v[i] * (-1))
        c += v[i];
      else {
        if (v[i + 1] < 0) {
          c += v[i];
        } else {
          c += v[i];
          c = abs(c);
        }
      }
    } else if (c <= 0 && v[i] <= 0) {
      if (v[i + 1] > 0) {
        c += v[i];
        c = abs(c);
      } else {
        c += v[i];
      }
    } else {
      if (c * (-1) < v[i])
        c += v[i];
      else {
        if (v[i + 1] < 0) {
          c += v[i];
        } else {
          c += v[i];
          c = abs(c);
        }
      }
    }
  }
  c += v[sz(v) - 1];
  c = abs(c);
  debug(c);
  cout << c << nl;


  cerr << "*****************************" << nl;
}
int main()
{
  fastio();
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("Error.txt", "w", stderr);
#endif

  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }

}