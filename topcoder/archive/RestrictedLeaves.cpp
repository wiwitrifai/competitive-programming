#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7;

vector<int> g[N];
long long dp[N][2][2][2];
long long tmp[2][2][2];

void add(long long & var, long long r) {
	var += r;
	if (var >= mod)
		var -= mod;
}

void dfs(int v) {
	if (g[v].empty()) {
		dp[v][0][0][0] = 1;
		dp[v][1][1][1] = 1;
	}
	bool first = 1;
	for (int u : g[v]) {
		dfs(u);
		if (first) {
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++ j) {
					for (int k = 0; k < 2; ++k) {
						add(dp[v][0][j][k], dp[u][i][j][k]);
						if (!i) 
							add(dp[v][1][j][k], dp[u][i][j][k]);
					}
				}
			}
			first = 0;
		}
		else {
			memset(tmp, 0, sizeof tmp);
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++ j) {
					for (int y = 0; y < 2; ++y) {
						if (j && y) continue;
						for (int k = 0; k < 2; ++k) {
							for (int x = 0; x < 2; ++x) {
								add(tmp[0][x][k], dp[u][i][j][k] * dp[v][0][x][y] % mod);
								if (i == 0) {
									add(tmp[1][x][k], dp[u][i][j][k] * dp[v][1][x][y] % mod);
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++ j) {
					for (int k = 0; k < 2; ++k) {
						dp[v][i][j][k] = tmp[i][j][k];
					}
				}
			}
		}
	}
}

class RestrictedLeaves {
public:
	int count(vector <int> parent) {
		int n = parent.size();
		for (int i = 1; i < n; ++i) {
			g[parent[i]].push_back(i);
		}
		dfs(0);
		long long tot = 0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					if (j && k) continue;
					tot = (tot + dp[0][i][j][k]) % mod;
				}
			}
		}
		return tot;
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
		cout << "Testing RestrictedLeaves (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1583603590;
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
		RestrictedLeaves _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {-1, 0, 0, 0, 0};
				_expected = 8;
				_received = _obj.count(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {-1, 0, 0, 1, 2, 1, 2};
				_expected = 21;
				_received = _obj.count(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {-1, 0, 0, 1, 2, 1, 2, 1, 4, 4};
				_expected = 75;
				_received = _obj.count(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			/*case 3:
			{
				int parent[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int parent[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int parent[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
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
