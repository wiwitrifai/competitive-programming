#include <bits/stdc++.h>

using namespace std;

class SlightlyBigger {
public:
	double getProbability(int maxDiff, int ifNear, int ifFar, int query) {
		
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
		cout << "Testing SlightlyBigger (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1559662809;
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
		SlightlyBigger _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int maxDiff = 1;
				int ifNear = 1;
				int ifFar = 1;
				int query = 1;
				_expected = 0.3333333333333334;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}
			case 1:
			{
				int maxDiff = 1;
				int ifNear = 1;
				int ifFar = 1;
				int query = 470;
				_expected = 0.0;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}
			case 2:
			{
				int maxDiff = 1;
				int ifNear = 1;
				int ifFar = 2;
				int query = 1;
				_expected = 0.25;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}
			case 3:
			{
				int maxDiff = 3;
				int ifNear = 4;
				int ifFar = 7;
				int query = 3;
				_expected = 0.08005718370264478;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}
			/*case 4:
			{
				int maxDiff = ;
				int ifNear = ;
				int ifFar = ;
				int query = ;
				_expected = ;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}*/
			/*case 5:
			{
				int maxDiff = ;
				int ifNear = ;
				int ifFar = ;
				int query = ;
				_expected = ;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}*/
			/*case 6:
			{
				int maxDiff = ;
				int ifNear = ;
				int ifFar = ;
				int query = ;
				_expected = ;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
