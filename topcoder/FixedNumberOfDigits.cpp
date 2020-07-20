#include <bits/stdc++.h>

using namespace std;

class FixedNumberOfDigits {
public:
	long long sum(int start, int step, long long numberOfDigits) {
		long long ten = 10;
		long long now = start;
		int dig = 1;
		while (ten <= now) {
			ten *= 10;
			++dig;
		}
		while (numberOfDigits > 0) {
			long long last = ten - 1;
			long long cnt = (last - now) / step + 1;
			if (cnt * dig >= numberOfDigits) {
				long long x = (numberOfDigits + dig - 1) / dig - 1;
				now += step * x;
				numberOfDigits -= x * dig;
				int sisa = dig - numberOfDigits;
				for (int i = 0; i < sisa; ++i)
					now /= 10;
				return now;
			} else {
				numberOfDigits -= cnt * dig;
				++dig;
				ten *= 10;
				now += cnt * step;
			}
		}
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
		cout << "Testing FixedNumberOfDigits (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1595088311;
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
		FixedNumberOfDigits _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int start = 47;
				int step = 10;
				long long numberOfDigits = 7LL;
				_expected = 7LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			case 1:
			{
				int start = 98;
				int step = 1;
				long long numberOfDigits = 10LL;
				_expected = 101LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			case 2:
			{
				int start = 0;
				int step = 1;
				long long numberOfDigits = 7LL;
				_expected = 6LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			case 3:
			{
				int start = 123456789;
				int step = 10;
				long long numberOfDigits = 5LL;
				_expected = 12345LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			case 4:
			{
				int start = 123456789;
				int step = 10;
				long long numberOfDigits = 17LL;
				_expected = 12345679LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}
			/*case 5:
			{
				int start = ;
				int step = ;
				long long numberOfDigits = LL;
				_expected = LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}*/
			/*case 6:
			{
				int start = ;
				int step = ;
				long long numberOfDigits = LL;
				_expected = LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
			}*/
			/*case 7:
			{
				int start = ;
				int step = ;
				long long numberOfDigits = LL;
				_expected = LL;
				_received = _obj.sum(start, step, numberOfDigits); break;
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
