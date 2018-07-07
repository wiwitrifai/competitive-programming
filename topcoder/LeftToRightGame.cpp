#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int dp[N][N][2];
int c[N][10];
int d;

int solve(int len, int val, int p) {
	if (len == 0)
		return val != 0;
	int & ret = dp[len][val][p];
	if (ret != -1) return ret;
	if (p) {
		ret = 0;
		for (int j = 0; j < 10; ++j) {
			if (solve(len-1, (val + c[len][j]) % d, !p)) {
				ret = 1; 
				break;
			}
		}
	}
	else {
		ret = 1;
		for (int j = 0; j < 10; ++j) {
			if (!solve(len-1, (val + c[len][j]) % d, !p)) {
				ret = 0;
				break;
			}
		}
	}
	// cerr << len << " " << val << " " << p << " = " << ret << endl;
	return ret;
}

class LeftToRightGame {
public:
	string whoWins(int length, int divisor) {
		memset(dp, -1, sizeof dp);		
		d = divisor;
		for (int i = 0; i < 10; ++i) {
			c[1][i] = i;
		}
		for (int i = 2; i <= length; ++i) {
			for (int j = 0; j < 10; ++j)
				c[i][j] = c[i-1][j] * 10 % divisor;
		}
		for (int i = 1; i < 10; ++i) {
			if (solve(length-1, c[length][i] % divisor, 0))
				return "Alice";
		}
		return "Bob";
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
		cout << "Testing LeftToRightGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1530979206;
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
		LeftToRightGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 4;
				int divisor = 10;
				_expected = "Bob";
				_received = _obj.whoWins(length, divisor); break;
			}
			case 1:
			{
				int length = 3;
				int divisor = 1000;
				_expected = "Alice";
				_received = _obj.whoWins(length, divisor); break;
			}
			case 2:
			{
				int length = 2;
				int divisor = 3;
				_expected = "Bob";
				_received = _obj.whoWins(length, divisor); break;
			}
			case 3:
			{
				int length = 147;
				int divisor = 47;
				_expected = "Alice";
				_received = _obj.whoWins(length, divisor); break;
			}
			/*case 4:
			{
				int length = ;
				int divisor = ;
				_expected = ;
				_received = _obj.whoWins(length, divisor); break;
			}*/
			/*case 5:
			{
				int length = ;
				int divisor = ;
				_expected = ;
				_received = _obj.whoWins(length, divisor); break;
			}*/
			/*case 6:
			{
				int length = ;
				int divisor = ;
				_expected = ;
				_received = _obj.whoWins(length, divisor); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
