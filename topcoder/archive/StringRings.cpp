#include <bits/stdc++.h>

using namespace std;

class StringRings {
public:
	double expectedRings(int A, int B) {
		long double ans = 0;
		for (int i = 1; i <= A; ++i) {
			ans += (long double)1.0 / (2 * i - 1);
		}
		for (int i = 1; i <= B; ++i) {
			int cnt = i + 2 * A;
			ans += (long double)1.0 / cnt;
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
		cout << "Testing StringRings (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1579955611;
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
		StringRings _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 0;
				int B = 1;
				_expected = 1.0;
				_received = _obj.expectedRings(A, B); break;
			}
			case 1:
			{
				int A = 1;
				int B = 0;
				_expected = 1.0;
				_received = _obj.expectedRings(A, B); break;
			}
			case 2:
			{
				int A = 1;
				int B = 2;
				_expected = 1.5833333333333333;
				_received = _obj.expectedRings(A, B); break;
			}
			case 3:
			{
				int A = 0;
				int B = 0;
				_expected = 0.0;
				_received = _obj.expectedRings(A, B); break;
			}
			case 4:
			{
				int A = 2;
				int B = 3;
				_expected = 1.8428571428571427;
				_received = _obj.expectedRings(A, B); break;
			}
			case 5:
			{
				int A = 2;
				int B = 0;
				_expected = 1.3333333333333333;
				_received = _obj.expectedRings(A, B); break;
			}
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.expectedRings(A, B); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.expectedRings(A, B); break;
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
