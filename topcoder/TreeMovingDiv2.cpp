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
		dfs(id, u);
	}
}

void upd(int id, int v) {
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
	long long res = depth[id][u] + depth[id][v] - 2 * depth[id][w];
	res %= mod;
	if (res < 0) res += mod;
	return res; 
}

class TreeMovingDiv2 {
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
		cout << "Testing TreeMovingDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1490441521;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeMovingDiv2 _obj;
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
				int c[] = {3, 5};
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
				int n = 2;
				int roots[] = {1, 0, 0};
				int a[] = {122064284, 9662111, 120616497};
				int b[] = {20137061, 408976122, 494878172};
				int c[] = {242061783, 603049107, 805670429};
				_expected = 1;
				_received = _obj.count(n, vector <int>(roots, roots+sizeof(roots)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 15;
				int roots[] = {11, 3, 13, 5, 0, 3, 0, 8, 9, 4, 9, 7, 5, 12, 12, 11, 12, 2, 6, 5, 13, 13, 11, 8, 14, 9, 2, 0, 3, 11, 10, 12, 10, 11, 11, 12, 13, 7, 12, 11, 2, 14, 8, 3, 6, 6, 4, 13, 5, 8};
				int a[] = {983816220, 620877501, 728957664, 719453482, 891241034, 959047323, 459235325, 188837384, 749336264, 40650017, 404049008, 121578182, 640967952, 444329307, 181115164, 697849277, 12923013, 711014676, 308063158, 403714366, 341206103, 674610097, 743172147, 27978413, 95548595, 93823839, 844476902, 863583697, 568069127, 618319911, 659846531, 341309147, 735202433, 531047579, 967335611, 311192666, 753647731, 36420180, 609571991, 208600401, 915548304, 926479460, 672275772, 545217041, 864561330, 32472050, 852336473, 144521601, 383750815, 616511468};
				int b[] = {715457951, 308091233, 686233659, 523365634, 260145657, 96581518, 754153775, 622990522, 78662953, 689973864, 609423534, 534351235, 56822117, 899080526, 236413795, 747521954, 249656307, 790813221, 238598034, 203856426, 170015231, 791645278, 991710627, 747864180, 331241135, 416320805, 820623220, 811261319, 154661650, 914880513, 270905767, 954448019, 261442212, 954262444, 293791600, 493225233, 67542211, 911866345, 567575019, 95716070, 410883122, 337767450, 375732581, 616839717, 416849487, 140196829, 200763187, 51759408, 992789421, 882490836};
				int c[] = {650915191, 363659051, 226659197, 706291662, 748630395, 163284394, 663006670, 2890697, 639793395, 728890798, 570088430, 967259303, 101778889, 249725396, 968816738, 276471315, 905010209, 467925249, 798793109, 857289233, 494026470, 476417587, 98570430, 596160845, 211373787, 188742439, 364805067, 757845257, 317224756, 74104796, 455729968, 78933290, 769895010, 476555278, 45379277, 957039727, 395817921, 447349376, 629724490, 287334171, 227424105, 603337884, 467060652, 254067677, 237332026, 976429932, 93075762, 960441433, 132935737, 671265490};
				_expected = 755767349;
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
