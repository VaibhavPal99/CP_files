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



int correct_solution(int n, vector <int> v)
{
  int t = 0;  // Initialize turn count to 0
  for (int i = 0; i < n; i++) {
    while (v[i] > 0) {
      t++;  // Increment the turn before attack
      if (t % 3 == 0) {
        v[i] -= 3;  // Attack with -3 on every 3rd turn
      } else {
        v[i] -= 1;  // Otherwise attack with -1
      }
    }
  }
  return t;
}

int my_solution(int n, vector <int> v) {
  //  int n;
  // cin >> n;
  // vector<ll> v(n);
  // for (int i = 0; i < n; i++) cin >> v[i];

  ll t = 0;
  ll tmp = 0;

  for (int i = 0; i < n; i++) {
    if (tmp == 1) {             // this section is used to even out the operation
      // difference that was caused by previous value of v[i]
      //if tmp==1 then previous v[i] has used 1 operation extra
      //hence we perform two more operations(as per requirement)
      // to round off the calculation of operations
      v[i] -= tmp;
      t++;
      if (v[i] > 0) {
        v[i] -= 3;
        t++;
      }
    } else if (tmp == 2) {
      v[i] -= 3;
      t++;
    }                           //this section ends here

    if (v[i] <= 0)
      continue;

    ll quo = v[i] / 5;  //total operations b/w any two multiples of 3 is 5, so dividing by it seems fine
    ll val = v[i] % 5; //this is used to calculate extra operations
    debug(quo); debug(val);

    if (val == 0)
      tmp = 0;
    else if (val == 1)
      tmp = 1;
    else if (val == 2)
      tmp = 2;
    else if (val >= 3)
      tmp = 3;

    debug(tmp);

    t += quo * 3;
    t += tmp;
    if (tmp == 3) tmp = 0;
  }

  debug(t);
  return t;
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

    int n = rand() % 3 + 1;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = rand() % 10 + 1;
    }
    int correct = correct_solution(n, v);
    debug(correct);
    int myans = my_solution(n, v);
    debug(myans);
    if (correct != myans) {
      cout << n << nl;
      for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
      }
      cout << nl;
      break;
    }

    cnt++;
  }

}