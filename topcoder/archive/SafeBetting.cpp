#include <bits/stdc++.h>

using namespace std;

class SafeBetting {
public:
	int minRounds(int a, int b, int c) {
		int d = c-b;
		if (d <= 0)
			return 0;
		int e = b-a, ans = 0;
		if (e <= 0)
			return -1;
		d = c-a;
		while (e < d) {
			e *= 2;
			ans++;
		}		
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
		cout << "Testing SafeBetting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486878882;
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
		SafeBetting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 15;
				int b = 20;
				int c = 48;
				_expected = 3;
				_received = _obj.minRounds(a, b, c); break;
			}
			case 1:
			{
				int a = 10;
				int b = 400;
				int c = 560;
				_expected = 1;
				_received = _obj.minRounds(a, b, c); break;
			}
			case 2:
			{
				int a = 5;
				int b = 7;
				int c = 21;
				_expected = 3;
				_received = _obj.minRounds(a, b, c); break;
			}
			case 3:
			{
				int a = 5;
				int b = 7;
				int c = 22;
				_expected = 4;
				_received = _obj.minRounds(a, b, c); break;
			}
			case 4:
			{
				int a = 17;
				int b = 30;
				int c = 1000;
				_expected = 7;
				_received = _obj.minRounds(a, b, c); break;
			}
			/*case 5:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = ;
				_received = _obj.minRounds(a, b, c); break;
			}*/
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = ;
				_received = _obj.minRounds(a, b, c); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = ;
				_received = _obj.minRounds(a, b, c); break;
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
