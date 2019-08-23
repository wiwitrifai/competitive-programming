#include <bits/stdc++.h>

using namespace std;

const int inf = 1e7;

class BiconnectedDiv1 {
public:
	int minimize(vector <int> w1, vector <int> w2) {
		int dp[105][4];
		memset(dp, 0, sizeof dp);
		int n = w1.size() + 1;
		for (int i = 0; i < 4; i++)
			dp[1][i] = inf;
		dp[1][1] = w1[0];
		for (int i = 2; i < n; i++) {
			dp[i][1] = dp[i-1][3] + w1[i-1];
			dp[i][2] = min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3])) + w2[i-2];
			dp[i][3] = min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3])) + w1[i-1] + w2[i-2];
		}
		return dp[n-1][3];
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
		cout << "Testing BiconnectedDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488080945;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BiconnectedDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int w1[] = {1,2};
				int w2[] = {3};
				_expected = 6;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			case 1:
			{
				int w1[] = {3,0,4};
				int w2[] = {1,2};
				_expected = 10;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			case 2:
			{
				int w1[] = {3,3,3,3};
				int w2[] = {3,6,3};
				_expected = 18;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			case 3:
			{
				int w1[] = {7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876};
				int w2[] = {2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920};
				_expected = 46729;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			/*case 4:
			{
				int w1[] = ;
				int w2[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int w1[] = ;
				int w2[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int w1[] = ;
				int w2[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
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
