#include <bits/stdc++.h>

using namespace std;

class TriangleFree {
public:
	long long count(int n, vector <int> x, vector <int> y) {
		
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
		cout << "Testing TriangleFree (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488083199;
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
		TriangleFree _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int x[] = {0,1,2,3};
				int y[] = {1,2,0,2};
				_expected = 14LL;
				_received = _obj.count(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				int x[] = {0,0,0,0,1,1,1,2,2,3};
				int y[] = {1,2,3,4,2,3,4,3,4,4};
				_expected = 16LL;
				_received = _obj.count(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 6;
				int x[] = {0,0,1,1,1,3,1,2,2,4};
				int y[] = {1,2,2,3,4,4,5,4,5,5};
				_expected = 40LL;
				_received = _obj.count(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 60;
				int x[] = {10,20,30};
				int y[] = {20,30,10};
				_expected = 1008806316530991104LL;
				_received = _obj.count(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 60;
				int x[] = {0,0,1,0,0,3,0,0,5,0,0,7,0,0,9,0,0,11,0,0,13,0,0,15,0,0,17,0,0,19,0,0,21,0,0,23,0,0,25,0,0,27,0,0,29,5,2,23,5,20,27,26,22,19,18,13,15,12,7,9};
				int y[] = {1,2,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,12,13,14,14,15,16,16,17,18,18,19,20,20,21,22,22,23,24,24,25,26,26,27,28,28,29,30,30,1,12,27,22,1,14,5,27,27,15,15,29,7,6,3};
				_expected = 578333426763956224LL;
				_received = _obj.count(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				_expected = LL;
				_received = _obj.count(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				_expected = LL;
				_received = _obj.count(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				_expected = LL;
				_received = _obj.count(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
