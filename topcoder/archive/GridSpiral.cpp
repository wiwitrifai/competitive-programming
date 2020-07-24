#include <bits/stdc++.h>

using namespace std;

class GridSpiral {
public:
	long long arith(long long a, long long b, long long n) {
		long long big = a + b * (n-1);
		long long x = n, y = (a + big);
		if (x & 1)
			y /= 2;
		else
			x /= 2;
		return x * y;
	}
	long long findCell(int D) {
		if ((D & 1) == 0)
			return -1;
		D = (D + 1) / 2;
		if (D <= 4)
			return 0;
		long long ans = 1;
		D -= 5;
		int k = D / 4;
		ans += arith(8, 8, k);
		D -= k * 4;
		for (int i = 0; i < D; ++i) {
			ans += (k * 2 + 1 + (i != 0));
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
		cout << "Testing GridSpiral (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1594385795;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GridSpiral _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int D = 5;
				_expected = 0LL;
				_received = _obj.findCell(D); break;
			}
			case 1:
			{
				int D = 11;
				_expected = 2LL;
				_received = _obj.findCell(D); break;
			}
			case 2:
			{
				int D = 47;
				_expected = 110LL;
				_received = _obj.findCell(D); break;
			}
			case 3:
			{
				int D = 100;
				_expected = -1LL;
				_received = _obj.findCell(D); break;
			}
			case 4:
			{
				int D = 11;
				_expected = 2LL;
				_received = _obj.findCell(D); break;
			}
			case 5:
			{
				int D = 17;
				_expected = 9LL;
				_received = _obj.findCell(D); break;
			}
			/*case 6:
			{
				int D = ;
				_expected = LL;
				_received = _obj.findCell(D); break;
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
