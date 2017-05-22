#include <bits/stdc++.h>

using namespace std;

class FoxAndCake2 {
public:
	string isPossible(int c, int s) {
		if (c > s) swap(c, s);
		if (c == 1) return "Impossible";
		if (c == 2) return s & 1 ? "Impossible" : "Possible";
		if (c == 3) return s % 3 ? "Impossible" : "Possible";
		if (c == 4) return s & 1 ? "Impossible" : "Possible";
		if (c == 5) return s == 6 ? "Impossible" : "Possible";
		if (c == 6) return s % 3 && s % 2 ? "Impossible" : "Possible";
		return "Possible";
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
		cout << "Testing FoxAndCake2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495296030;
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
		FoxAndCake2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int c = 74;
				int s = 109;
				_expected = "Possible";
				_received = _obj.isPossible(c, s); break;
			}
			case 1:
			{
				int c = 1000000000;
				int s = 1000000000;
				_expected = "Possible";
				_received = _obj.isPossible(c, s); break;
			}
			case 2:
			{
				int c = 1;
				int s = 58;
				_expected = "Impossible";
				_received = _obj.isPossible(c, s); break;
			}
			/*case 3:
			{
				int c = ;
				int s = ;
				_expected = ;
				_received = _obj.isPossible(c, s); break;
			}*/
			/*case 4:
			{
				int c = ;
				int s = ;
				_expected = ;
				_received = _obj.isPossible(c, s); break;
			}*/
			/*case 5:
			{
				int c = ;
				int s = ;
				_expected = ;
				_received = _obj.isPossible(c, s); break;
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
