#include <bits/stdc++.h>

using namespace std;

const int N = 333, mod = 1e9 + 7, LN = 10;

vector< int > g[N][N];
pair< int, int > e[N][N];
long long dp[N][N];
long long X[N];
int par[N][LN][N], lv[N][N];
long long depth[N][N];
void dfs(int id, int v) {
	for (int i = 0; i < LN-1; i++) {
		par[id][i+1][v] = par[id][i][par[id][i][v]];
	}
	for (int j : g[id][v]) {
		int u = e[id][j].first + e[id][j].second - v;
		if (u == par[id][0][v]) continue;
		lv[id][u] = lv[id][v] + 1;
		par[id][0][u] = v;
		//cerr << id << " " << v << " " << u << endl;
		dfs(id, u);
	}
}

void upd(int id, int v) {
	//cerr << id << " " << v << " depth " << depth[id][v] << endl;
	for (int j : g[id][v]) {
		int u = e[id][j].first + e[id][j].second - v;
		if (u == par[id][0][v]) continue;
		depth[id][u] = (depth[id][v] + dp[id][j]) % mod;
		upd(id, u);
	}
}
int lca(int id, int u, int v) {
	if (lv[id][u] > lv[id][v]) {
		swap(u, v);
	}
	int diff = lv[id][v] - lv[id][u];
	for (int i = 0; i < LN; i++)
		if (diff & (1<<i))
			v = par[id][i][v];
	if (u == v) 
		return v;
	for (int i = LN-1; i >= 0; i--) {
		if (par[id][i][v] != par[id][i][u])
			v = par[id][i][v], u = par[id][i][u];
	}
	return par[id][0][v];
}
long long dist(int id, int u, int v) {
	int w = lca(id, u, v);
	//cerr << "lca " << id << " " << u << " " << v << " " << w << endl;
	long long res = depth[id][u] + depth[id][v] - 2 * depth[id][w];
	res %= mod;
	if (res < 0) res += mod;
	return res; 
}

class TreeMoving {
public:
	int count(int n, vector <int> roots, vector <int> a, vector <int> b, vector <int> c) {
		int m = roots.size();
		for (int i = 0; i < m; i++) {
			X[0] = c[i];
			for (int k = 1; k < n-1; k++)
			  X[k] = (1LL * a[i] * X[k - 1] + b[i]) % mod;
			for (int j = 0; j < n-1; j++) {
		    int u = (roots[i] + j + 1) % n;
		    int v = (roots[i] + (X[j] % (j + 1))) % n;
		    e[i][j] = make_pair(u, v);
		    g[i][u].push_back(j);
		    g[i][v].push_back(j);
		  }
		}
		for (int i = 0; i < m; i++) {
			par[i][0][0] = 0;
			depth[i][0] = 0;
			lv[i][0] = 0;
			dfs(i, 0);
		}
		long long ans = 0;
		for (int j = 0; j < n-1; j++) {
			for (int i = 0; i < n-1; i++) {
				dp[m-1][i] = 0;
			}
			dp[m-1][j] = 1;
			upd(m-1, 0);
			for (int i = m-2; i >= 0; i--) {
				for (int z = 0; z < n-1; z++) {
					dp[i][z] = dist(i+1, e[i][z].first, e[i][z].second);
				}
				upd(i, 0);
			}
			ans += dist(0, e[m-1][j].first, e[m-1][j].second);
			if (ans >= mod) ans -= mod;
		}
		ans %= mod;
		if (ans < 0) ans += mod;
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
		cout << "Testing TreeMoving (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1490437095;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeMoving _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int roots[] = {0, 2};
				int a[] = {1, 2};
				int b[] = {1, 0};
				int c[] = {2, 3};
				_expected = 2;
				_received = _obj.count(n, vector <int>(roots, roots+sizeof(roots)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 3;
				int roots[] = {0, 0, 1};
				int a[] = {6, 1, 3};
				int b[] = {6, 5, 5};
				int c[] = {2, 5, 9};
				_expected = 2;
				_received = _obj.count(n, vector <int>(roots, roots+sizeof(roots)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 5;
				int roots[] = {0, 1, 1, 1, 2};
				int a[] = {7, 4, 7, 9, 2};
				int b[] = {8, 3, 9, 5, 3};
				int c[] = {6, 0, 1, 5, 9};
				_expected = 22;
				_received = _obj.count(n, vector <int>(roots, roots+sizeof(roots)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 3;
				int roots[] = {0, 0, 1};
				int a[] = {373206610, 937739946, 172315864};
				int b[] = {870770575, 635025870, 765158489};
				int c[] = {915938656, 747443899, 387215442};
				_expected = 2;
				_received = _obj.count(n, vector <int>(roots, roots+sizeof(roots)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 10;
				int roots[] = {0, 1, 0, 4, 0, 2, 1, 8, 5, 5};
				int a[] = {508821715, 481198414, 163209181, 56649169, 276327522, 13486359, 845629232, 482370937, 373100199, 297431939};
				int b[] = {256979012, 884002808, 393825387, 609998779, 816536931, 123064634, 673095376, 18224901, 510687925, 466437174};
				int c[] = {368733721, 596826005, 853637399, 436680590, 369153650, 853574577, 609377415, 903050702, 259325966, 105275092};
				_expected = 17765;
				_received = _obj.count(n, vector <int>(roots, roots+sizeof(roots)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int roots[] = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.count(n, vector <int>(roots, roots+sizeof(roots)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int roots[] = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.count(n, vector <int>(roots, roots+sizeof(roots)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int roots[] = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.count(n, vector <int>(roots, roots+sizeof(roots)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
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
