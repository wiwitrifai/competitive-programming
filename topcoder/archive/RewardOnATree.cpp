#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

vector<int> nodes[N];
int lv[N], sum[N], dp[N], best[N];

class RewardOnATree {
public:
	int collect(vector <int> parent, vector <int> reward) {
		int n = reward.size();
		for (int i = 0; i < n; i++) {
			nodes[i].clear();
			sum[i] = 0;
		}
		lv[0] = 0;
		nodes[0].push_back(0);
		dp[0] = best[0] = reward[0];
		int ma = 0;
		for (int i = 0; i < parent.size(); i++) {
			lv[i+1] = lv[parent[i]] + 1;
			nodes[lv[i+1]].push_back(i+1);
			ma = max(ma, lv[i+1]);
		}
		// cerr << dp[0] << endl;
		for (int i = 1; i <= ma; i++) {
			sum[i] = 0;
			for (int u : nodes[i])
				sum[i] += max(reward[u], 0);
			for (int u : nodes[i]) {
				// cerr << i << " " << u << " " << dp[u] << " " << dp[parent[u-1]] << " " << sum[i] << endl; 
				dp[u] = dp[parent[u-1]] + sum[i] + min(0, reward[u]);
			}
			if (nodes[i].empty()) continue;
			best[i] = dp[nodes[i][0]];
			for (int u : nodes[i])
				best[i] = max(best[i], dp[u]);
			for (int u : nodes[i]) {
				dp[u] = max(dp[u], best[i] + min(0, reward[u]));
			}
		}
		int ans = dp[0];
		for (int i = 0; i < n; i++)
			ans = max(ans, dp[i]);
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
		cout << "Testing RewardOnATree (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1504899638;
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
		RewardOnATree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {0, 1, 0, 0, 4};
				int reward[] = {1, 3, 2, 1, -1, 2};
				_expected = 9;
				_received = _obj.collect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(reward, reward+sizeof(reward)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {0, 1, 2, 3, 4};
				int reward[] = {1, 2, 3, -2, -1, 2};
				_expected = 6;
				_received = _obj.collect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(reward, reward+sizeof(reward)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0, 1, 2, 3, 4};
				int reward[] = {1, 2, 3, -2, -1, 4};
				_expected = 7;
				_received = _obj.collect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(reward, reward+sizeof(reward)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {};
				int reward[] = {-10000};
				_expected = -10000;
				_received = _obj.collect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(reward, reward+sizeof(reward)/sizeof(int))); break;
			}
			case 4:
			{
				int parent[] = {0, 1, 2, 3, 0, 5, 6, 0, 8, 9};
				int reward[] = {-2, 0, 0, 0, 1, -1, 1, -1, -1, 1, -1};
				_expected = 1;
				_received = _obj.collect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(reward, reward+sizeof(reward)/sizeof(int))); break;
			}
			case 5:
			{
				int parent[] = {0, 1, 2, 3, 4, 5, 5, 3, 8, 9, 2, 11, 12, 13, 
				               12, 11, 16, 1, 18, 19, 20, 21, 21, 20, 19, 25, 
				               18, 27, 28, 29, 28, 27, 0, 33, 34, 35, 34, 33, 38};
				int reward[] = {16, -2745, 504, 1467, 1826, 9191, 9594, -2723, 2120, 
				               7001, -1555, -2476, -1348, -6262, -9114, -973, 1480, 
				               -8002, 918, 1364, 133, 8499, -1503, 8823, 5728, -5209,
				                8342, 1994, 5696, -6712, 1222, -1272, -2434, 4952, 
				               -6979, -115, -9386, -5071, 5102, 2180};
				_expected = 88152;
				_received = _obj.collect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(reward, reward+sizeof(reward)/sizeof(int))); break;
			}
			/*case 6:
			{
				int parent[] = ;
				int reward[] = ;
				_expected = ;
				_received = _obj.collect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(reward, reward+sizeof(reward)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int reward[] = ;
				_expected = ;
				_received = _obj.collect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(reward, reward+sizeof(reward)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int parent[] = ;
				int reward[] = ;
				_expected = ;
				_received = _obj.collect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(reward, reward+sizeof(reward)/sizeof(int))); break;
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
