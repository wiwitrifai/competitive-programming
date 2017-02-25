#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

class UpDownNess {
public:
	int count(int n, int k) {
		long long dp[55][5050];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= k; j++)
				dp[i][j] = 0; 
		}
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				int now = dp[i][j];
				if (now == 0) continue;
				for (int pos = 0; pos <= i; pos++) {
					int new_j = j + pos * (i-pos);
					if (new_j <= k) {
						dp[i+1][new_j] += now;
						if (dp[i+1][new_j] >= mod)
							dp[i+1][new_j] -= mod;
					}
				}
			}
		}
		return dp[n][k];
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
		cout << "Testing UpDownNess (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487994164;
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
		UpDownNess _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 1;
				_expected = 2;
				_received = _obj.count(N, K); break;
			}
			case 1:
			{
				int N = 3;
				int K = 0;
				_expected = 4;
				_received = _obj.count(N, K); break;
			}
			case 2:
			{
				int N = 4;
				int K = 3;
				_expected = 4;
				_received = _obj.count(N, K); break;
			}
			case 3:
			{
				int N = 19;
				int K = 19;
				_expected = 24969216;
				_received = _obj.count(N, K); break;
			}
			case 4:
			{
				int N = 50;
				int K = 2000;
				_expected = 116596757;
				_received = _obj.count(N, K); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.count(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.count(N, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.count(N, K); break;
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
