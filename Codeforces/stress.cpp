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
#define fr(x, a, b) for (int x = a; x < b; x++)
#define vi vector<int>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif



int correct_solution(int n, int l, int r, vector <int> v)
{
  int ans = 0;
  int sm = 0;
  int st = 0;
  int i = 0;
  while (i < n)

  {
    sm += v[i];
    while (sm > r && st <= i)
    {
      sm -= v[st++];
    }
    if (sm >= l && sm <= r)
    {
      ans++;
      sm = 0;
      st = i + 1;
    }
    i++;
  }

  return ans;
}

int my_solution(int n, int l, int r, vector <int> v) {
  ll cnt = 0;
  ll sum = 0;

  for (int i = 0; i < n; i++) {

    if (v[i] >= l && v[i] <= r) {
      cnt++;
      sum = 0;
    }
    else {
      if (sum > r) {
        sum = 0;
      }
      sum += v[i];
      if (sum >= l && sum <= r) {
        cnt++;
        sum = 0;
      }
    }
  }

  return cnt;
}
int main()
{
  fastio();
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("Error.txt", "w", stderr);
#endif

  // int t;
  // cin >> t;
  // for (int i = 1; i <= t; i++) {
  //   solve(i);
  // }
  srand(time(NULL));
  int cnt = 1;
  while (cnt <= 1000) {

    int n = rand() % 100000 + 1;
    int l = rand() % 100000 + 1;
    int r = rand() % 100000 + 1;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = rand() % 1000000000 + 1;
    }
    int correct = correct_solution(n, l, r, v);
    debug(correct);
    int myans = my_solution(n, l, r, v);
    debug(myans);
    if (correct != myans) {
      cout << n << " " << l << " " << r << nl;
      for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
      }
      cout << nl;
      break;
    }

    cnt++;
  }

}