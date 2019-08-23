#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, mod = 1e9;
vector< int > g[N];
int par[N], w[N];

long long sub[N], ans[N], depth[N];
int cnt[N], mid[N];

void dfs(int u) {
	cnt[u] = 1;
	sub[u] = 0;
	depth[u] = u ? depth[par[u]] + w[u] : 0;
	for (int v : g[u]) {
		dfs(v);
		cnt[u] += cnt[v];
		sub[u] += 1LL * w[v] * cnt[v] + sub[v];
	}
}
void dfs2(int u) {
	int bg = -1;
	mid[u] = u;
	ans[u] = sub[u];
	for (int v : g[u]) {
		if (bg == -1 || cnt[bg] < cnt[v])
			bg = v;
		dfs2(v);
	}
	if (bg != -1) {
		int x = mid[bg];
		long long cur = ans[bg] + (cnt[u]-cnt[bg]) * (depth[x] - depth[u]) + sub[u] - sub[bg] - 1LL * cnt[bg] * w[bg];
		if (cur < ans[u]) {
			ans[u] = cur;
			mid[u] = x;
		}
		while (x != u && cnt[u]-cnt[x] > cnt[x]) {
			cur += 1LL * cnt[x] * w[x] - 1LL * (cnt[u]-cnt[x]) * w[x];
			x = par[x];
			if (cur < ans[u]) {
				ans[u] = cur;
				mid[u] = x;
			}
		}
	}
}

class TreeSums {
public:
	long long findSums(int N, int seed, int C, int D) {
		int cur = seed;
		for (int i = 0; i < N; i++)
			g[i].clear();
		for (int i = 0; i < N-1; i++) {
			cur = (cur * 1LL * C + D) % mod;
			par[i+1] = cur % (i+1);
			cur = (cur * 1LL * C + D) % mod;
			w[i+1] = cur % 1000000;
			g[par[i+1]].push_back(i+1);
		}
		dfs(0);
		dfs2(0);
		long long ret = 0;
		for (int i = 0; i < N; i++)
			ret ^= ans[i];
		return ret;
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
		cout << "Testing TreeSums (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489399512;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeSums _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 6;
				int seed = 8;
				int C = 3;
				int D = 13;
				_expected = 856320LL;
				_received = _obj.findSums(N, seed, C, D); break;
			}
			case 1:
			{
				int N = 2;
				int seed = 10;
				int C = 20;
				int D = 30;
				_expected = 4630LL;
				_received = _obj.findSums(N, seed, C, D); break;
			}
			case 2:
			{
				int N = 6;
				int seed = 55;
				int C = 1;
				int D = 18;
				_expected = 22LL;
				_received = _obj.findSums(N, seed, C, D); break;
			}
			case 3:
			{
				int N = 300000;
				int seed = 9192331;
				int C = 992132133;
				int D = 999991231;
				_expected = 438628640790LL;
				_received = _obj.findSums(N, seed, C, D); break;
			}
			/*case 4:
			{
				int N = ;
				int seed = ;
				int C = ;
				int D = ;
				_expected = LL;
				_received = _obj.findSums(N, seed, C, D); break;
			}*/
			/*case 5:
			{
				int N = ;
				int seed = ;
				int C = ;
				int D = ;
				_expected = LL;
				_received = _obj.findSums(N, seed, C, D); break;
			}*/
			/*case 6:
			{
				int N = ;
				int seed = ;
				int C = ;
				int D = ;
				_expected = LL;
				_received = _obj.findSums(N, seed, C, D); break;
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
