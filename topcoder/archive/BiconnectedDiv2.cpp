#include <bits/stdc++.h>

using namespace std;

class BiconnectedDiv2 {
public:
	int minimize(vector <int> w1, vector <int> w2) {
		int ret = 0;
		for (int v : w1) ret += v;
		for (int v : w2) ret += v;
		for (int i = 1; i + 1 < w1.size(); i++) {
			if (w1[i] > 0)
				ret -= w1[i];
		}
		return ret;
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
		cout << "Testing BiconnectedDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488008033;
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
		BiconnectedDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int w1[] = {1,2};
				int w2[] = {3};
				_expected = 6;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			case 1:
			{
				int w1[] = {-1,-2,-3};
				int w2[] = {-4,-5};
				_expected = -15;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			case 2:
			{
				int w1[] = {1,100,-3,2};
				int w2[] = {-2,1,4};
				_expected = 3;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			/*case 3:
			{
				int w1[] = ;
				int w2[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int w1[] = ;
				int w2[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int w1[] = ;
				int w2[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
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
