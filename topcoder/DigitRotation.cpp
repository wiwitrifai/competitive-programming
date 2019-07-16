#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

const int N = 1024;

long long pw[N];

class DigitRotation {
public:
	int sumRotations(string X) {
		pw[0] = 1;
		for (int i = 1; i < N; ++i) {
			pw[i] = pw[i-1] * 10 % mod;
		}
		int n = X.size();
		long long all = 0;
		for (int i = 0; i < n; ++i) X[i] -= '0';
		for (int i = 0; i < n; ++i) {
			all = (1LL * all * 10 + (long long)X[i]) % mod;
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			long long now = all;
			now -= (long long)X[i] * pw[n-1-i];
			now %= mod;
			if (now < 0) now += mod;
			long long dig = 0, aa = 0;
			long long cnt = 0;
			long long sisa = 0;
			for (int j = i+1; j < n; ++j) {
				now -= (long long)X[j] * pw[n-1-j];
				now %= mod;
				bool ok = 1;
				if (i == 0 && X[j] == 0) ok = 0;
				if (cnt == 0) ok = 0;
				if (ok) {
					ans = (ans + now * cnt + dig * pw[n-1-j]) % mod;
					ans = (ans + aa + pw[n-1-i] * (long long)X[j] * cnt) % mod;
					ans = (ans + sisa * (cnt - 1)) % mod;
				}
				sisa = (sisa + pw[n-1-j] * (long long)X[j]) % mod;
				++cnt;
				aa = (aa + pw[n-1-j] * (long long)X[i]) % mod;
				dig = (dig + (long long)X[j]) % mod;
				// cerr << i << " " << j << " " << ans << endl;
			}
		}
		ans %= mod;
		if (ans < 0) ans += mod;	
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
		cout << "Testing DigitRotation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1534345209;
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
		DigitRotation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string X = "123";
				_expected = 312;
				_received = _obj.sumRotations(X); break;
			}
			case 1:
			{
				string X = "3570";
				_expected = 10407;
				_received = _obj.sumRotations(X); break;
			}
			case 2:
			{
				string X = "5545";
				_expected = 21208;
				_received = _obj.sumRotations(X); break;
			}
			case 3:
			{
				string X = "1283749218734901238749213847902";
				_expected = 867286291;
				_received = _obj.sumRotations(X); break;
			}
			case 4:
			{
				string X = "4";
				_expected = 0;
				_received = _obj.sumRotations(X); break;
			}
			/*case 5:
			{
				string X = ;
				_expected = ;
				_received = _obj.sumRotations(X); break;
			}*/
			/*case 6:
			{
				string X = ;
				_expected = ;
				_received = _obj.sumRotations(X); break;
			}*/
			/*case 7:
			{
				string X = ;
				_expected = ;
				_received = _obj.sumRotations(X); break;
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
