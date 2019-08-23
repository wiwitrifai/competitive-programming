#include <bits/stdc++.h>

using namespace std;

class LastDigit {
public:
	long long findX(long long S) {
		long long a[30];
		a[0] = 1;
		for (int i = 0; i <= 18 && a[i] <= S; i++) {
			a[i+1] = a[i] * 10 + 1;
			long long ans = 0, now = S;
			for (int j = i; j >= 0; j--) {
				int x = now / a[j];
				if (x > 9) x = 9;
				ans = ans * 10 + x;
				now -= a[j] * x;
			}
			if (!now)
				return ans;
		}
		return -1;
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
		cout << "Testing LastDigit (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487107683;
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
		LastDigit _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long S = 564LL;
				_expected = 509LL;
				_received = _obj.findX(S); break;
			}
			case 1:
			{
				long long S = 565LL;
				_expected = -1LL;
				_received = _obj.findX(S); break;
			}
			case 2:
			{
				long long S = 3000LL;
				_expected = 2701LL;
				_received = _obj.findX(S); break;
			}
			case 3:
			{
				long long S = 137174210616796LL;
				_expected = 123456789555123LL;
				_received = _obj.findX(S); break;
			}
			case 4:
			{
				long long S = 837592744927492746LL;
				_expected = -1LL;
				_received = _obj.findX(S); break;
			}
			case 5:
			{
				long long S = 999999999999999999LL;
				_expected = 900000000000000000LL;
				_received = _obj.findX(S); break;
			}
			/*case 6:
			{
				long long S = LL;
				_expected = LL;
				_received = _obj.findX(S); break;
			}*/
			/*case 7:
			{
				long long S = LL;
				_expected = LL;
				_received = _obj.findX(S); break;
			}*/
			/*case 8:
			{
				long long S = LL;
				_expected = LL;
				_received = _obj.findX(S); break;
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
