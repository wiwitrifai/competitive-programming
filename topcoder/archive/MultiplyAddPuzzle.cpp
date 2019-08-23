#include <bits/stdc++.h>

using namespace std;


class MultiplyAddPuzzle {
public:
	long long minimalSteps(long long s, long long t, long long a, long long b) {
		if (s == t) return 0;
		if (b == 0) {
			if (t == 0)
				return s != 0;
			if (a == 0)
				return -1;
			if (t >= s && ((t-s) % a) == 0)
				return (t-s)/a;
			if (t % a == 0)
				return t/a + 1;
			return -1;
		}
		if (b == 1) {
			if (a == 0)
				return -1;
			if (t < s)
				return -1;
			if (((t-s) % a) == 0)
				return (t-s)/a;
			return -1;
		}
		if (t < s) return -1;
		if (a == 0) {
			int ans = 0;
			while ((t % b == 0) && t > s) t /= b, ans++;
			if (t == s)
				return ans;
			return -1;
		}
		long long ans = -1;
		for (int i = 0; i < 66; i++) {
			if (s > t) break;
			long long d = t-s;
			if (d % a) {
				if (s > (t+b-1)/b) break;
				s *= b;
				continue;
			}
			long long cur = i;
			d /= a;
			for (int j = 0; j < i; j++) {
				cur += d % b;
				d /= b;
			}
			cur += d;
			if (ans == -1 || ans > cur)
				ans = cur;
			if (s > (t+b-1)/b) break;
			s *= b;
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
		cout << "Testing MultiplyAddPuzzle (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485830018;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MultiplyAddPuzzle _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long s = 10LL;
				long long t = 40LL;
				long long a = 4LL;
				long long b = 2LL;
				_expected = 2LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 1:
			{
				long long s = 10LL;
				long long t = 28LL;
				long long a = 4LL;
				long long b = 2LL;
				_expected = 2LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 2:
			{
				long long s = 10LL;
				long long t = 99LL;
				long long a = 4LL;
				long long b = 2LL;
				_expected = -1LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 3:
			{
				long long s = 345LL;
				long long t = 12345LL;
				long long a = 1LL;
				long long b = 10LL;
				_expected = 895LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			case 4:
			{
				long long s = 1000000000000000000LL;
				long long t = 1000000000000000000LL;
				long long a = 1000000000000000000LL;
				long long b = 1000000000000000000LL;
				_expected = 0LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}
			/*case 5:
			{
				long long s = LL;
				long long t = LL;
				long long a = LL;
				long long b = LL;
				_expected = LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}*/
			/*case 6:
			{
				long long s = LL;
				long long t = LL;
				long long a = LL;
				long long b = LL;
				_expected = LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
			}*/
			/*case 7:
			{
				long long s = LL;
				long long t = LL;
				long long a = LL;
				long long b = LL;
				_expected = LL;
				_received = _obj.minimalSteps(s, t, a, b); break;
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
