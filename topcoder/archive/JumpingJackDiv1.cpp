#include <bits/stdc++.h>

using namespace std;

class JumpingJackDiv1 {
public:
	int getLocationOfJack(int dist, int k, int x) {
		int cnt = x - (x / k);
		return dist * cnt;
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
		cout << "Testing JumpingJackDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1527318051;
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
		JumpingJackDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dist = 2;
				int k = 2;
				int x = 0;
				_expected = 0;
				_received = _obj.getLocationOfJack(dist, k, x); break;
			}
			case 1:
			{
				int dist = 2;
				int k = 2;
				int x = 1;
				_expected = 2;
				_received = _obj.getLocationOfJack(dist, k, x); break;
			}
			case 2:
			{
				int dist = 2;
				int k = 2;
				int x = 2;
				_expected = 2;
				_received = _obj.getLocationOfJack(dist, k, x); break;
			}
			case 3:
			{
				int dist = 2;
				int k = 2;
				int x = 3;
				_expected = 4;
				_received = _obj.getLocationOfJack(dist, k, x); break;
			}
			case 4:
			{
				int dist = 2;
				int k = 2;
				int x = 4;
				_expected = 4;
				_received = _obj.getLocationOfJack(dist, k, x); break;
			}
			case 5:
			{
				int dist = 3;
				int k = 7;
				int x = 10;
				_expected = 27;
				_received = _obj.getLocationOfJack(dist, k, x); break;
			}
			case 6:
			{
				int dist = 5;
				int k = 2;
				int x = 10;
				_expected = 25;
				_received = _obj.getLocationOfJack(dist, k, x); break;
			}
			/*case 7:
			{
				int dist = ;
				int k = ;
				int x = ;
				_expected = ;
				_received = _obj.getLocationOfJack(dist, k, x); break;
			}*/
			/*case 8:
			{
				int dist = ;
				int k = ;
				int x = ;
				_expected = ;
				_received = _obj.getLocationOfJack(dist, k, x); break;
			}*/
			/*case 9:
			{
				int dist = ;
				int k = ;
				int x = ;
				_expected = ;
				_received = _obj.getLocationOfJack(dist, k, x); break;
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
