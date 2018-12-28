#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 2e5 + 4;

long long f[N];

class Chains4 {
public:
	int count(int n) {
		long long sum = 0;
		f[0] = 1;
		f[1] = 2;
		sum = 0;
		for (int i = 2; i <= n; ++i) {
			f[i] = (3LL * f[i-1] + sum) % mod;
			sum += f[i-1];
			if (sum >= mod)
				sum -= mod;
		}
		long long ans = 1;
		for (int i = 1; i <= n; ++i) {
			ans = (ans + 1LL * f[i] * (n+1-i)) % mod;
		}
		if (ans < 0)
			ans += mod;
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
		cout << "Testing Chains4 (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1545964389;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Chains4 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				_expected = 11;
				_received = _obj.count(n); break;
			}
			case 1:
			{
				int n = 3;
				_expected = 39;
				_received = _obj.count(n); break;
			}
			/*case 2:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 3:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
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
