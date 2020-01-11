#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 55;

long long dp[2][N][N][18 * N];

void add(long long & var, long long val) {
	var += val;
	if (var >= mod)
		var -= mod;
}

class ClassRankings {
public:
	int countWays(vector <int> amt, vector <int> lo, vector <int> hi) {
		vector<int> vx;
		int a = amt[0], b = amt[1], c = amt[2];
		int tot = a + b + c;
		for (int i = 0; i < 3; ++i) {
			for (int j = lo[i]; j <= hi[i] && j <= lo[i] + tot; ++j)
				vx.emplace_back(j);
			for (int j = hi[i]; j >= lo[i] && j >= hi[i] - tot; --j)
				vx.emplace_back(j);
		}
		sort(vx.begin(), vx.end());
		vx.erase(unique(vx.begin(), vx.end()), vx.end());
		for (int i = 0; i < 3; ++i) {
			lo[i] = lower_bound(vx.begin(), vx.end(), lo[i]) - vx.begin();
			hi[i] = lower_bound(vx.begin(), vx.end(), hi[i]) - vx.begin();
		}
		dp[0][0][0][0] = 1;
		int cur = 0, pre = 1;
		for (int i = 0; i <= a; ++i) {
			swap(cur, pre);
			memset(dp[cur], 0, sizeof dp[cur]);
			for (int j = 0; j <= b; ++j) {
				for (int k = 0; k <= c; ++k) {
					for (int z = 0; z < (int)vx.size(); ++z) {
						long long now = dp[pre][j][k][z];
						if (now == 0) continue;
						if (i + 1 <= a && z <= hi[0]) {
							add(dp[cur][j][k][max(z, lo[0]) + 1], now);
						}
						if (j + 1 <= b && z <= hi[1]) {
							add(dp[pre][j+1][k][max(z, lo[1]) + 1], now);
						}
						if (k + 1 <= c && z <= hi[2]) {
							add(dp[pre][j][k+1][max(z, lo[2]) + 1], now);
						}
					}
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i <= (int)vx.size(); ++i)
			add(ans, dp[pre][b][c][i]);
		ans %= mod;
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
		cout << "Testing ClassRankings (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1578763386;
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
		ClassRankings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int amt[] = {1,1,1};
				int lo[] = {1,1,1};
				int hi[] = {100,100,100};
				_expected = 6;
				_received = _obj.countWays(vector <int>(amt, amt+sizeof(amt)/sizeof(int)), vector <int>(lo, lo+sizeof(lo)/sizeof(int)), vector <int>(hi, hi+sizeof(hi)/sizeof(int))); break;
			}
			case 1:
			{
				int amt[] = {1,1,1};
				int lo[] = {1,1,1};
				int hi[] = {1,1,1};
				_expected = 0;
				_received = _obj.countWays(vector <int>(amt, amt+sizeof(amt)/sizeof(int)), vector <int>(lo, lo+sizeof(lo)/sizeof(int)), vector <int>(hi, hi+sizeof(hi)/sizeof(int))); break;
			}
			case 2:
			{
				int amt[] = {2,1,3};
				int lo[] = {5,1,2};
				int hi[] = {6,1,4};
				_expected = 1;
				_received = _obj.countWays(vector <int>(amt, amt+sizeof(amt)/sizeof(int)), vector <int>(lo, lo+sizeof(lo)/sizeof(int)), vector <int>(hi, hi+sizeof(hi)/sizeof(int))); break;
			}
			case 3:
			{
				int amt[] = {2,4,3};
				int lo[] = {1,4,8};
				int hi[] = {6,10,12};
				_expected = 15;
				_received = _obj.countWays(vector <int>(amt, amt+sizeof(amt)/sizeof(int)), vector <int>(lo, lo+sizeof(lo)/sizeof(int)), vector <int>(hi, hi+sizeof(hi)/sizeof(int))); break;
			}
			case 4:
			{
				int amt[] = {50,50,50};
				int lo[] = {1,1,1};
				int hi[] = {150,150,150};
				_expected = 824706821;
				_received = _obj.countWays(vector <int>(amt, amt+sizeof(amt)/sizeof(int)), vector <int>(lo, lo+sizeof(lo)/sizeof(int)), vector <int>(hi, hi+sizeof(hi)/sizeof(int))); break;
			}
			/*case 5:
			{
				int amt[] = ;
				int lo[] = ;
				int hi[] = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(amt, amt+sizeof(amt)/sizeof(int)), vector <int>(lo, lo+sizeof(lo)/sizeof(int)), vector <int>(hi, hi+sizeof(hi)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int amt[] = ;
				int lo[] = ;
				int hi[] = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(amt, amt+sizeof(amt)/sizeof(int)), vector <int>(lo, lo+sizeof(lo)/sizeof(int)), vector <int>(hi, hi+sizeof(hi)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int amt[] = ;
				int lo[] = ;
				int hi[] = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(amt, amt+sizeof(amt)/sizeof(int)), vector <int>(lo, lo+sizeof(lo)/sizeof(int)), vector <int>(hi, hi+sizeof(hi)/sizeof(int))); break;
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
