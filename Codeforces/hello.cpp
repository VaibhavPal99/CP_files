#include <bits/stdc++.h>
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void solve()
{
	string num;
	// string name;
	cin >> num;
	string temp = num;
	int sum = 0;
	int i = 1;
	while (1)
	{
		sum = sum + temp[i];
		if (i == sz(temp) - 1)
		{
			temp = sum;
		}
		if (sum < 10)
			break;
	}
	cout << sum << nl;


}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

}