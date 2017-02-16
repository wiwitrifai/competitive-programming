#include <bits/stdc++.h>

using namespace std;

int solve(string a, string b) {
	int n = a.size(), m = b.size();
	int dp[55][55];
	memset(dp, 0, sizeof dp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (a[i] == b[j]));
			dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1])); 
		}
	}
	return dp[n][m];
}

class RepeatStringEasy {
public:
	int maximalLength(string s) {
		int ans = 0;
		for (int i = 1; i < s.size(); i++) {
			ans = max(ans, 2 * solve(s.substr(0, i), s.substr(i, (int)s.size()))); 
		}
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
		cout << "Testing RepeatStringEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487254512;
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
		RepeatStringEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "frankfurt";
				_expected = 4;
				_received = _obj.maximalLength(s); break;
			}
			case 1:
			{
				string s = "single";
				_expected = 0;
				_received = _obj.maximalLength(s); break;
			}
			case 2:
			{
				string s = "singing";
				_expected = 6;
				_received = _obj.maximalLength(s); break;
			}
			case 3:
			{
				string s = "aababbababbabbbbabbabb";
				_expected = 18;
				_received = _obj.maximalLength(s); break;
			}
			case 4:
			{
				string s = "x";
				_expected = 0;
				_received = _obj.maximalLength(s); break;
			}
			case 5:
			{
				string s = "fdljhcadorufenakncbefvlbqnabdaaijilalraparjcew";
				_expected = 16;
				_received = _obj.maximalLength(s); break;
			}
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.maximalLength(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.maximalLength(s); break;
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
