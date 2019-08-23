#include <bits/stdc++.h>

using namespace std;

class Chains3 {
public:
	string validate(vector <int> c) {
		int n = c.size();
		int l = c[0], r = c[0];
		for (int i = 1; i < n; ++i) {
			if (c[i] >= l && c[i] <= r)
				return "invalid " + to_string(i+1);
			l = min(l, c[i]);
			r = max(r, c[i]);
		}
		l = r = c[0];
		if (r >= n)
			return "valid 1";
		for (int i = 1; i < n; ++i) {
			l = min(l, c[i]);
			r = max(r, c[i]);
			if (r >= n)
				return "valid " + to_string(i+1);
			if (r-l+1 > i+1)
				return "valid " + to_string(i+1);
		}
		return "maximal " + to_string(n);
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
		cout << "Testing Chains3 (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1545963706;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Chains3 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int c[] = {1, 0};
				_expected = "maximal 2";
				_received = _obj.validate(vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int c[] = {4, 5, 6, 2, 1, 9, 0};
				_expected = "valid 4";
				_received = _obj.validate(vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int c[] = {4, 5, 6, 2, 1, 3, 0};
				_expected = "invalid 6";
				_received = _obj.validate(vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int c[] = {4, 5, 4, 2, 1, 3, 0};
				_expected = "invalid 3";
				_received = _obj.validate(vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 4:
			{
				int c[] = ;
				_expected = ;
				_received = _obj.validate(vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int c[] = ;
				_expected = ;
				_received = _obj.validate(vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int c[] = ;
				_expected = ;
				_received = _obj.validate(vector <int>(c, c+sizeof(c)/sizeof(int))); break;
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
