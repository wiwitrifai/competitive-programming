#include <bits/stdc++.h>

using namespace std;

class TriangleMaking {
public:
	int maxPerimeter(int a, int b, int c) {
		int x[3];
		x[0] = a, x[1] = b, x[2] = c;
		sort(x, x+3);
		x[2] = min(x[2], x[0] + x[1] -1);
		return x[0]+x[1]+x[2];		
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
		cout << "Testing TriangleMaking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487302164;
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
		TriangleMaking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 2;
				int c = 3;
				_expected = 5;
				_received = _obj.maxPerimeter(a, b, c); break;
			}
			case 1:
			{
				int a = 2;
				int b = 2;
				int c = 2;
				_expected = 6;
				_received = _obj.maxPerimeter(a, b, c); break;
			}
			case 2:
			{
				int a = 1;
				int b = 100;
				int c = 1;
				_expected = 3;
				_received = _obj.maxPerimeter(a, b, c); break;
			}
			case 3:
			{
				int a = 41;
				int b = 64;
				int c = 16;
				_expected = 113;
				_received = _obj.maxPerimeter(a, b, c); break;
			}
			/*case 4:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = ;
				_received = _obj.maxPerimeter(a, b, c); break;
			}*/
			/*case 5:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = ;
				_received = _obj.maxPerimeter(a, b, c); break;
			}*/
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = ;
				_received = _obj.maxPerimeter(a, b, c); break;
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
