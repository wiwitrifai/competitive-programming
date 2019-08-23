#include <bits/stdc++.h>

using namespace std;

int count(string a, string b) {
	int dp[55][55];
	for (int i = 0; i < 55; i++)
		for (int j = 0; j < 55; j++) 
			dp[i][j] = 1000;
	int n = a.size(), m = b.size();
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i < n && j < m && a[i] == b[j]) {
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
			}
			dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
			dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
			dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + 1);
		}
	}
	return dp[n][m];
}
class RepeatString {
public:
	int minimalModify(string s) {
		int ans = 1000;
		for (int i = 0; i < s.size(); i++)
			ans = min(ans, count(s.substr(0, i), s.substr(i, (int)s.size() - i)));
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
		cout << "Testing RepeatString (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487256797;
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
		RepeatString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "aba";
				_expected = 1;
				_received = _obj.minimalModify(s); break;
			}
			case 1:
			{
				string s = "adam";
				_expected = 1;
				_received = _obj.minimalModify(s); break;
			}
			case 2:
			{
				string s = "x";
				_expected = 1;
				_received = _obj.minimalModify(s); break;
			}
			case 3:
			{
				string s = "aaabbbaaaccc";
				_expected = 3;
				_received = _obj.minimalModify(s); break;
			}
			case 4:
			{
				string s = "repeatstring";
				_expected = 6;
				_received = _obj.minimalModify(s); break;
			}
			case 5:
			{
				string s = "aaaaaaaaaaaaaaaaaaaa";
				_expected = 0;
				_received = _obj.minimalModify(s); break;
			}
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.minimalModify(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.minimalModify(s); break;
			}*/
			/*case 8:
			{
				string s = ;
				_expected = ;
				_received = _obj.minimalModify(s); break;
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
