#include <bits/stdc++.h>

using namespace std;

class SwapAndArithmetic {
public:
	string able(vector <int> x) {
		sort(x.begin(), x.end());
		if (x.size() <= 1)
			return "Possible";
		int d = x[1] - x[0];
		for (int i = 2; i < x.size(); i++) if (x[i] - x[i-1] != d)
			return "Impossible";
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
		cout << "Testing SwapAndArithmetic (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483049608;
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
		SwapAndArithmetic _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {3,1,2};
				_expected = "Possible";
				_received = _obj.able(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1,2,4};
				_expected = "Impossible";
				_received = _obj.able(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1,1,1,1,1,1};
				_expected = "Possible";
				_received = _obj.able(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {1000,704,1};
				_expected = "Impossible";
				_received = _obj.able(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {7,3,11,5,1,9};
				_expected = "Possible";
				_received = _obj.able(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 5:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.able(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.able(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.able(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
