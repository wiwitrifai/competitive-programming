#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int p[N];
long long dp[40];
int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

class PowerEquation {
public:
	int count(int n) {
		memset(p, 0, sizeof p);
		for (int i = 2; i < N; i++) if (p[i] == 0) {
			for (int j = i; j < N; j += i) if (p[j] == 0)
				p[j] = i;
		}
		for (int i = 1; i < 40; i++) {
			dp[i] = 0;
			for (int j = 1; j <= i; j++)
				for (int k = 1; k <= i; k++) {
					if (j == k) continue;
					int d = gcd(j, k);
					int jd = j/d, kd = k/d;
					dp[i] = (dp[i] + min(n/jd, n/kd)) % mod;
				}
		}
		int a;
		long long ans = 1LL * n * n;
		for (a = 2; 1LL * a * a <= n; a ++) {
			ans = (ans + n) % mod;
			int now = a;
			int g = 0;
			while (now > 1) {
				int q = p[now], cnt = 0;
				while ((now % q) == 0) {
					cnt++;
					now /= q;
				}
				g = gcd(g, cnt);
			}
			if (g != 1) continue;
			int q = 0;
			long long cur = 1;
			while (cur * a <= n) cur *= a, q++;
			ans = (ans + dp[q]) % mod;	
		}
		ans = (ans + max(0LL, 1LL * (n-a+1) * n)) % mod;
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
		cout << "Testing PowerEquation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1493254859;
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
		PowerEquation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				_expected = 6;
				_received = _obj.count(n); break;
			}
			case 1:
			{
				int n = 3;
				_expected = 15;
				_received = _obj.count(n); break;
			}
			case 2:
			{
				int n = 100;
				_expected = 21620;
				_received = _obj.count(n); break;
			}
			case 3:
			{
				int n = 22306;
				_expected = 68467;
				_received = _obj.count(n); break;
			}
			case 4:
			{
				int n = 1;
				_expected = 1;
				_received = _obj.count(n); break;
			}
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 6:
			{
				int n = ;
				_expected = ;
				_received = _obj.count(n); break;
			}*/
			/*case 7:
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
