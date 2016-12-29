#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
long long dp[2][105], tmp[2][105];
class ModEquationEasy {
public:
	int count(int n, int K, int v) {
		int c = 0, b = !c;
		for (int i = 0; i < K; i++) {
			tmp[c][i] = 1;
			dp[c][i] = 0;
		}
		dp[c][1] = 1;
		while (n) {
			c ^= 1;
			b = !c;
			for (int i = 0; i < K; i++)
				dp[c][i] = tmp[c][i] = 0;
			if (n & 1) {
				for (int i = 0; i < K; i++)
					for (int j = 0; j < K; j++) {
						int x = (i * j) % K;
						dp[c][x] += (dp[b][i] * tmp[b][j]) % mod;
						if (dp[c][x] >= mod)
							dp[c][x] -= mod;
					}
			}
			else
				for (int i = 0; i < K; i++)
					dp[c][i] = dp[b][i];
			for (int i = 0; i < K; i++)
				for (int j = 0; j < K; j++) {
					int x = (i * j) % K;
					tmp[c][x] += (tmp[b][i] * tmp[b][j]) % mod;
					if (tmp[c][x] >= mod)
						tmp[c][x] -= mod;
				}
			n >>= 1;
		}
		int ret = dp[c][v % K] % mod;
		if (ret < 0)
			ret += mod;
		return ret;
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
		cout << "Testing ModEquationEasy (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483050574;
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
		ModEquationEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int K = 4;
				int v = 1;
				_expected = 2;
				_received = _obj.count(n, K, v); break;
			}
			case 1:
			{
				int n = 2;
				int K = 4;
				int v = 0;
				_expected = 8;
				_received = _obj.count(n, K, v); break;
			}
			case 2:
			{
				int n = 2;
				int K = 4;
				int v = 2;
				_expected = 4;
				_received = _obj.count(n, K, v); break;
			}
			case 3:
			{
				int n = 3;
				int K = 7;
				int v = 5;
				_expected = 36;
				_received = _obj.count(n, K, v); break;
			}
			case 4:
			{
				int n = 10;
				int K = 100;
				int v = 50;
				_expected = 683036071;
				_received = _obj.count(n, K, v); break;
			}
			case 5:
			{
				int n = 1;
				int K = 2;
				int v = 0;
				_expected = 1;
				_received = _obj.count(n, K, v); break;
			}
			/*case 6:
			{
				int n = ;
				int K = ;
				int v = ;
				_expected = ;
				_received = _obj.count(n, K, v); break;
			}*/
			/*case 7:
			{
				int n = ;
				int K = ;
				int v = ;
				_expected = ;
				_received = _obj.count(n, K, v); break;
			}*/
			/*case 8:
			{
				int n = ;
				int K = ;
				int v = ;
				_expected = ;
				_received = _obj.count(n, K, v); break;
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
