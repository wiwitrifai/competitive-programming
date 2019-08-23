#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

bool cmp(int a, char c, int b) {
	if (c == '=')
		return a == b;
	if (c == '<')
		return a < b;
	if (c == '>')
		return a > b;
	if (c == '!')
		return a != b;
	assert(false);
}

string s;
int dp[N][10];
int can(int n, int d) {
	if (n >= s.size())
		return 1;
	int & ret = dp[n][d];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int j = 0; j < 10; ++j) {
		if (!cmp(d, s[n], j)) continue;
		if (can(n+1, j)) {
			return ret = 1;
		}
	}
	return ret;
}

string get(int n, int d) {
	string ret = "0";
	ret[0] += d;
	if (n >= s.size())
		return ret;
	for (int j = 0; j < 10; ++j) {
		if (!cmp(d, s[n], j)) continue;
		if (can(n+1, j)) {
			return ret + get(n+1, j);
		}
	}
	assert(false);
}

class ReconstructNumber {
public:
	string smallest(string comparisons) {
		s = comparisons;
		memset(dp, -1, sizeof dp);
		for (int d = 1; d < 10; ++d) {
			if (can(0, d)) {
				return get(0, d);
			}
		}
		return "";
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
		cout << "Testing ReconstructNumber (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1551873780;
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
		ReconstructNumber _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string comparisons = ">=!<";
				_expected = "10012";
				_received = _obj.smallest(comparisons); break;
			}
			case 1:
			{
				string comparisons = "====!====";
				_expected = "1111100000";
				_received = _obj.smallest(comparisons); break;
			}
			case 2:
			{
				string comparisons = "";
				_expected = "1";
				_received = _obj.smallest(comparisons); break;
			}
			case 3:
			{
				string comparisons = ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
				_expected = "";
				_received = _obj.smallest(comparisons); break;
			}
			case 4:
			{
				string comparisons = "><<>><=<=>=>";
				_expected = "1012101122110";
				_received = _obj.smallest(comparisons); break;
			}
			/*case 5:
			{
				string comparisons = ;
				_expected = ;
				_received = _obj.smallest(comparisons); break;
			}*/
			/*case 6:
			{
				string comparisons = ;
				_expected = ;
				_received = _obj.smallest(comparisons); break;
			}*/
			/*case 7:
			{
				string comparisons = ;
				_expected = ;
				_received = _obj.smallest(comparisons); break;
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
