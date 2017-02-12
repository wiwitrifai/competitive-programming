#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int mod = 1e9 + 7;
int n;
vector< int > x, y, d;
map< long long, long long > dp[N][N];
int cross(int a, int b, int p, int q) {
	return a * q - b * p;
}
long long solve(int l, int r, long long mask) {
	if (l > r)
		return 1;
	if (l == r)
		return 1;
	if (dp[l][r].count(mask))
		return dp[l][r][mask];
	long long ret = 0;
	int v = -1;
	for (int i = 0; i < n; i++) if (mask & (1LL << i)) {
		if (v == -1 || y[v] < y[i])
			v = i;
	}
	for (int m = l; m <= r; m++) {
		long long nmask = 0;
		bool ok = 1;
		for (int j = 0; j < n; j++) if (mask & (1LL << j)) {
			if (j == v) continue;
			int cr = cross(x[j]-x[v], y[j]-y[v], d[m]-x[v], -y[v]);
			if (cr > 0)
				nmask |= 1LL << j;
			else if (cr == 0)
				ok = 0;
		}
		if (ok && __builtin_popcountll(nmask) == m-l) {
			long long le = solve(l, m-1, nmask), ri = solve(m+1, r, mask ^ nmask ^ (1LL << v));
			ret = (ret + le * ri) % mod;
		}
	}
	dp[l][r][mask] = ret;
	return ret;
}

class CoastGuard {
public:
	int count(vector <int> D, vector <int> X, vector <int> Y) {
		d = D, x = X, y = Y;
		sort(d.begin(), d.end());
		n = d.size();
		return solve(0, n-1, (1LL<<n)-1);
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
		cout << "Testing CoastGuard (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486964906;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CoastGuard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d[] = {-2, 2};
				int x[] = {0, 1};
				int y[] = {1, 2};
				_expected = 2;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int d[] = {1,2};
				int x[] = {1,2};
				int y[] = {10,10};
				_expected = 1;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int d[] = {-2, 2, 98, 102};
				int x[] = {0, 1, 100, 101};
				int y[] = {1, 2, 1, 2};
				_expected = 4;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int d[] = {1,109,229,294,589,615,741,822,859,1000};
				int x[] = {546,850,287,452,864,874,529,879,818,589};
				int y[] = {414,176,191,15,764,825,204,477,34,460};
				_expected = 400;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int d[] = {-1,0,1};
				int x[] = {0,0,0};
				int y[] = {1,2,3};
				_expected = 2;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int d[] = {0};
				int x[] = {0};
				int y[] = {1};
				_expected = 1;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int d[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int d[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int d[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
