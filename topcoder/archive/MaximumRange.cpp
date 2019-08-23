#include <bits/stdc++.h>

using namespace std;

class MaximumRange {
public:
	int findMax(string s) {
		int neg, pos;
		neg = pos = 0;
		for (char c : s)
			if (c == '+')
				pos++;
			else
				neg++;
		return max(pos, neg);
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
		cout << "Testing MaximumRange (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1496192405;
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
		MaximumRange _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "+++++++";
				_expected = 7;
				_received = _obj.findMax(s); break;
			}
			case 1:
			{
				string s = "+--+--+";
				_expected = 4;
				_received = _obj.findMax(s); break;
			}
			case 2:
			{
				string s = "++++--------";
				_expected = 8;
				_received = _obj.findMax(s); break;
			}
			case 3:
			{
				string s = "-+-+-+-+-+-+";
				_expected = 6;
				_received = _obj.findMax(s); break;
			}
			case 4:
			{
				string s = "+";
				_expected = 1;
				_received = _obj.findMax(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.findMax(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.findMax(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.findMax(s); break;
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
