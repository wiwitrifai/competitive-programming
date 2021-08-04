#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
	long long r = 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1)
			r = r * b % mod;
	return r;
}

vector<int> g[N];
int far[N];

void dfs(int v, int par = -1) {
	far[v] = 0;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		far[v] = max(far[v], far[u] + 1);
	}
}

struct TreeTokens {
	int placeMax(int N, int G, int L, int seed) {
		for (int i = 0; i < N; ++i)
			g[i].clear();
		long long state = seed;
		long long mask = (1LL << 31) - 1;
		for (int i = 1; i < N; ++i) {
			state = (state * 1103515245LL + 12345LL) & mask;
			int tmp = (state / 1000) % L;
			int p = max(0, i - 1 - tmp);
			g[p].push_back(i);
			g[i].push_back(p);
		}
		dfs(G);
		long long ans = 0;
		int tot = 0;
		for (int i = 0; i < N; ++i) {
			if (i == G) continue;
			ans = (ans + powmod(2, far[i])) % mod;
			tot += far[i];
		}
		if (ans < 0)
			ans += mod;
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing TreeTokens (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1628076683;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeTokens _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int G = 0;
				int L = 1000000;
				int seed = 1234567;
				_expected = 4;
				_received = _obj.placeMax(N, G, L, seed); break;
			}
			case 1:
			{
				int N = 5;
				int G = 4;
				int L = 1;
				int seed = 1234567;
				_expected = 15;
				_received = _obj.placeMax(N, G, L, seed); break;
			}
			case 2:
			{
				int N = 4;
				int G = 0;
				int L = 2;
				int seed = 4742;
				_expected = 4;
				_received = _obj.placeMax(N, G, L, seed); break;
			}
			case 3:
			{
				int N = 7;
				int G = 5;
				int L = 3;
				int seed = 47;
				_expected = 17;
				_received = _obj.placeMax(N, G, L, seed); break;
			}
			case 4:
			{
				int N = 100000;
				int G = 0;
				int L = 1;
				int seed = 2131;
				_expected = 303861759;
				_received = _obj.placeMax(N, G, L, seed); break;
			}
			/*case 5:
			{
				int N = ;
				int G = ;
				int L = ;
				int seed = ;
				_expected = ;
				_received = _obj.placeMax(N, G, L, seed); break;
			}*/
			/*case 6:
			{
				int N = ;
				int G = ;
				int L = ;
				int seed = ;
				_expected = ;
				_received = _obj.placeMax(N, G, L, seed); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
