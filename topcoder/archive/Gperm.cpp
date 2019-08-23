#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8, n = 50;
int dp[1 << 20];
int val[55];

class Gperm {
public:
	int countfee(vector <int> x, vector <int> y) {
		int m = x.size();
		memset(val, 0, sizeof val);
		for (int i = 0; i < m; i++) {
			val[x[i]] |= (1<<i);
			val[y[i]] |= (1<<i);
		}
		int mmask = 1 << m;
		for (int i = 0; i < mmask; i++) dp[i] = inf;
		dp[mmask - 1] = 0;
		for (int mask = mmask -1; ~mask; mask--) {
			dp[mask] += __builtin_popcount(mask);
			for (int i = 0; i < m; i++) if (mask & (1<<i)) {
				int to = mask ^ (val[x[i]] & mask);
				dp[to] = min(dp[to], dp[mask]);
				to = mask ^ (val[y[i]] & mask);
				dp[to] = min(dp[to], dp[mask]);
			}
		}
		return dp[0];
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
		cout << "Testing Gperm (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487342133;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Gperm _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0};
				int y[] = {1};
				_expected = 1;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,1};
				int y[] = {1,2};
				_expected = 2;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {4,7,7};
				int y[] = {7,4,4};
				_expected = 3;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0,0,1};
				int y[] = {1,2,2};
				_expected = 4;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {7,8,9};
				int y[] = {4,5,6};
				_expected = 6;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28};
				int y[] = {45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27};
				_expected = 53;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.countfee(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
