#include <bits/stdc++.h>

using namespace std;

class ThueMorseGame {
public:
	string get(int n, int m) {
		if (n <= m) return "Alice";
		if (m == 1) {
			bool ans = 1;
			while (n--) {
				if (__builtin_popcount(n) & 1)
					return ans ? "Bob" : "Alice";
				ans ^= 1;
			}
		}
		int last = 0;
		for (int i = m+1; i <= n; i++) {
			if (__builtin_popcount(i) & 1);
			else if (i-last > m)
				last = i, i += m;
		}
		return (last == n) ? "Bob" : "Alice";
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
		cout << "Testing ThueMorseGame (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487028045;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ThueMorseGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int m = 3;
				_expected = "Alice";
				_received = _obj.get(n, m); break;
			}
			case 1:
			{
				int n = 3;
				int m = 2;
				_expected = "Bob";
				_received = _obj.get(n, m); break;
			}
			case 2:
			{
				int n = 387;
				int m = 22;
				_expected = "Alice";
				_received = _obj.get(n, m); break;
			}
			case 3:
			{
				int n = 499999999;
				int m = 50;
				_expected = "Alice";
				_received = _obj.get(n, m); break;
			}
			case 4:
			{
				int n = 499999975;
				int m = 49;
				_expected = "Bob";
				_received = _obj.get(n, m); break;
			}
			case 5:
			{
				int n = 450000000;
				int m = 1;
				_expected = "Alice";
				_received = _obj.get(n, m); break;
			}
			/*case 6:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.get(n, m); break;
			}*/
			/*case 7:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.get(n, m); break;
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
