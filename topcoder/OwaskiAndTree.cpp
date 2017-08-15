#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

vector< int > g[N];
long long dp[N][3];
vector<int> val;

void solve(int v) {
	dp[v][0] = dp[v][1] = dp[v][2] = 0;
	dp[v][1] = val[v];
	for (int u : g[v]) {
		solve(u);
		long long cur = max(dp[u][1], dp[u][2]);
		dp[v][1] += cur;
		cur = max(cur, dp[u][0]);
		dp[v][0] += cur;
	}
}

class OwaskiAndTree {
public:
	int maximalScore(vector <int> parent, vector <int> pleasure) {
		int n = parent.size() + 1;
		val = pleasure;
		for (int i = 0; i < n; i++)
			g[i].clear();
		for (int i = 0; i < n-1; i++)
			g[parent[i]].push_back(i+1);
		solve(0);
		long long ans = 0;
		for (int i = 0; i < 3; i++)
			ans = max(ans, dp[0][i]);
		return (int)ans;
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
		cout << "Testing OwaskiAndTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1502759823;
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
		OwaskiAndTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
				int pleasure[] = {1, 1, -1, -1, -1, -1, 1, 1, 1, 1};
				_expected = 4;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {0, 0, 1, 2};
				int pleasure[] = {2, 3, 4, -1, -1};
				_expected = 9;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0, 0, 1, 1, 2, 2, 5, 5};
				int pleasure[] = {1, 2, -3, -7, 3, 2, 7, -1, 3};
				_expected = 17;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {0, 1, 1, 1, 0, 3, 1, 3, 4, 4, 3, 6, 8, 0, 12, 12, 11, 7, 7};
				int pleasure[] = {-154011, 249645, 387572, 292156, -798388, 560085, -261135, -812756, 191481, -165204, 81513, -448791, 608073, 354614, -455750, 325999, 227225, -696501, 904692, -297238};
				_expected = 3672275;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 4:
			{
				int parent[] = {};
				int pleasure[] = {-1};
				_expected = 0;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			/*case 5:
			{
				int parent[] = ;
				int pleasure[] = ;
				_expected = ;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int pleasure[] = ;
				_expected = ;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int pleasure[] = ;
				_expected = ;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
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
