#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, inf = 1e7;
vector< int > cv, ce;
vector< int > child[N];
int dp[N][2];
void dfs(int v) {
	int all = 0;
	for (int u : child[v]) {
		dfs(u, v);
		all += dp[u][0];
	}
	dp[v][0] = all + 2 * cv[v] + (v ? ce[v-1] : 0);
	dp[v][1] = all + cv[v];
	for (int u : child[v]) {
		dp[v][0] = min(dp[v][0], all - dp[u][0] + dp[u][1] + (v ? ce[v-1] : 0) + cv[v]);
		dp[v][1] = min(dp[v][1], all - dp[u][0] + dp[u][1]);
	}
	for (int u : child[v]) {
		for (int w : child[v]) if (w != u) {
			int cost = all - dp[u][0] + dp[u][1] - dp[w][0] + dp[w][1] + (v ? ce[v-1] : 0);
			dp[v][0] = min(dp[v][0], cost);
		}
	}
}

class TreeAndCycle {
public:
	int minimize(vector <int> costV, vector <int> pre, vector <int> costE) {
		int n = costV.size();
		cv = costV;
		ce = costE;
		for (int i = 0; i < n-1; i++) {
			child[pre[i]].emplace_back(i+1);
		}
		dfs(0);
		return dp[0][0];
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
		cout << "Testing TreeAndCycle (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488009626;
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
		TreeAndCycle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int costV[] = {7,2,5,8};
				int pre[] = {0,1,2};
				int costE[] = {6,4,3};
				_expected = 15;
				_received = _obj.minimize(vector <int>(costV, costV+sizeof(costV)/sizeof(int)), vector <int>(pre, pre+sizeof(pre)/sizeof(int)), vector <int>(costE, costE+sizeof(costE)/sizeof(int))); break;
			}
			case 1:
			{
				int costV[] = {100,5,9,8};
				int pre[] = {0,0,0};
				int costE[] = {6,2,2};
				_expected = 32;
				_received = _obj.minimize(vector <int>(costV, costV+sizeof(costV)/sizeof(int)), vector <int>(pre, pre+sizeof(pre)/sizeof(int)), vector <int>(costE, costE+sizeof(costE)/sizeof(int))); break;
			}
			case 2:
			{
				int costV[] = {10,20,30,40,50,60,70,80,90};
				int pre[] = {0,1,2,2,3,4,5,7};
				int costE[] = {5,15,25,35,45,55,65,75};
				_expected = 205;
				_received = _obj.minimize(vector <int>(costV, costV+sizeof(costV)/sizeof(int)), vector <int>(pre, pre+sizeof(pre)/sizeof(int)), vector <int>(costE, costE+sizeof(costE)/sizeof(int))); break;
			}
			/*case 3:
			{
				int costV[] = ;
				int pre[] = ;
				int costE[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(costV, costV+sizeof(costV)/sizeof(int)), vector <int>(pre, pre+sizeof(pre)/sizeof(int)), vector <int>(costE, costE+sizeof(costE)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int costV[] = ;
				int pre[] = ;
				int costE[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(costV, costV+sizeof(costV)/sizeof(int)), vector <int>(pre, pre+sizeof(pre)/sizeof(int)), vector <int>(costE, costE+sizeof(costE)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int costV[] = ;
				int pre[] = ;
				int costE[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(costV, costV+sizeof(costV)/sizeof(int)), vector <int>(pre, pre+sizeof(pre)/sizeof(int)), vector <int>(costE, costE+sizeof(costE)/sizeof(int))); break;
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
