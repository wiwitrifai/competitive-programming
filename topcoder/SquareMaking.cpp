#include <bits/stdc++.h>

using namespace std;

class SquareMaking {
public:
	int getMinimalPrice(int a, int b, int c, int d) {
		int v[] = {a, b, c, d};
		sort(v, v+4);
		int ans = v[1]-v[0] + v[2]-v[1] + v[3]-v[1];
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
		cout << "Testing SquareMaking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1490441187;
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
		SquareMaking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 5;
				int b = 6;
				int c = 5;
				int d = 5;
				_expected = 1;
				_received = _obj.getMinimalPrice(a, b, c, d); break;
			}
			case 1:
			{
				int a = 4;
				int b = 1;
				int c = 5;
				int d = 4;
				_expected = 4;
				_received = _obj.getMinimalPrice(a, b, c, d); break;
			}
			case 2:
			{
				int a = 2017;
				int b = 2017;
				int c = 2017;
				int d = 2017;
				_expected = 0;
				_received = _obj.getMinimalPrice(a, b, c, d); break;
			}
			case 3:
			{
				int a = 705451;
				int b = 751563;
				int c = 608515;
				int d = 994713;
				_expected = 432310;
				_received = _obj.getMinimalPrice(a, b, c, d); break;
			}
			/*case 4:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.getMinimalPrice(a, b, c, d); break;
			}*/
			/*case 5:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.getMinimalPrice(a, b, c, d); break;
			}*/
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.getMinimalPrice(a, b, c, d); break;
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
