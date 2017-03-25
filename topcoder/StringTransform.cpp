#include <bits/stdc++.h>

using namespace std;

class StringTransform {
public:
	string isPossible(string s, string t) {
		bool ok = 1;
		int n = s.size();
		for (int i = n-1; i >= 0; i--) {
			if (s[i] != t[i]) {
				ok = 0;
				for (int j = 0; j < i; j++)
					if (s[j] == t[i]){
						ok = 1;
						break;
					}
				if (!ok)
					return "Impossible";
			}
		}
		return ok ? "Possible" : "Impossible";
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
		cout << "Testing StringTransform (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1490441331;
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
		StringTransform _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "abc";
				string t = "aba";
				_expected = "Possible";
				_received = _obj.isPossible(s, t); break;
			}
			case 1:
			{
				string s = "abc";
				string t = "bbc";
				_expected = "Impossible";
				_received = _obj.isPossible(s, t); break;
			}
			case 2:
			{
				string s = "topcoder";
				string t = "topcoder";
				_expected = "Possible";
				_received = _obj.isPossible(s, t); break;
			}
			case 3:
			{
				string s = "rdmcxnnbbe";
				string t = "rdrrxrnxbe";
				_expected = "Possible";
				_received = _obj.isPossible(s, t); break;
			}
			case 4:
			{
				string s = "rdmcxnnbbe";
				string t = "rdqrxrnxbe";
				_expected = "Impossible";
				_received = _obj.isPossible(s, t); break;
			}
			/*case 5:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.isPossible(s, t); break;
			}*/
			/*case 6:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.isPossible(s, t); break;
			}*/
			/*case 7:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.isPossible(s, t); break;
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
