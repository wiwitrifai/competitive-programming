#include <bits/stdc++.h>

using namespace std;

class TokenDoublingGame {
public:
	int expectation(int N) {
		
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
		cout << "Testing TokenDoublingGame (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1551874488;
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
		TokenDoublingGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				_expected = 1;
				_received = _obj.expectation(N); break;
			}
			case 1:
			{
				int N = 2;
				_expected = 333333339;
				_received = _obj.expectation(N); break;
			}
			case 2:
			{
				int N = 13;
				_expected = 444154848;
				_received = _obj.expectation(N); break;
			}
			/*case 3:
			{
				int N = ;
				_expected = ;
				_received = _obj.expectation(N); break;
			}*/
			/*case 4:
			{
				int N = ;
				_expected = ;
				_received = _obj.expectation(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.expectation(N); break;
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
