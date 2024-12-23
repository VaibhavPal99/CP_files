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

   int n; int m; 
   cin>>n>>m;

   vector<int> v(n);
   for(int i=0;i<n;i++){
	   cin>>v[i];
   }

   debug(v);
   for(int i=0;i<n;i++){
	   cout<<v[i]<<" ";
   }
   cout<<nl;


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
