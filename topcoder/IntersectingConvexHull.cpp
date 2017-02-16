#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 102;

long long powmod(long long b, long long p) {
	long long ret = 1;
	for (; p; b = (b * b) % mod, p >>= 1)
		if (p & 1) ret = (ret * b) % mod;
	return ret;
}
bool ccw[N][N][N];

class IntersectingConvexHull {
public:
	int count(vector <int> x, vector <int> y) {
		int n = x.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					ccw[i][j][k] = 1LL * (x[j]-x[i]) * (y[k]-y[i]) > 1LL * (y[j]-y[i]) * (x[k]-x[i]);
				}
			}
		}
		long long fac[N], ifac[N];
		fac[0] = ifac[0] = 1;
		for (int i = 1; i < N; i++) {
			fac[i] = (fac[i-1] * i) % mod;
			ifac[i] = powmod(fac[i], mod-2);
		}
		long long ans = 0;
		for (int i = 3; i <= n; i++) {
			for (int j = 3; j <= n - i; j++) {
				ans += (((ifac[i] * ifac[j]) % mod) * ifac[n-i-j]) % mod;
				if (ans >= mod) ans -= mod;
			}
		}
		ans = (ans * fac[n]) % mod;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) if (i != j) {
				int c, d;
				c = d = 0;
				for (int k = 0; k < n; k++) if (k != i && k != j) {
					if (ccw[i][j][k]) c++; else d++;
				}
				ans -= ((powmod(2, c)-c-1) * (powmod(2, d)-d-1)) % mod;
				if (ans < 0) ans += mod;
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
		cout << "Testing IntersectingConvexHull (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487257454;
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
		IntersectingConvexHull _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,0,-1,-1,0,1};
				int y[] = {1,2,1,-1,-2,-1};
				_expected = 14;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {444, -646, 367, 302, -506, 810};
				int y[] = {-530, 660, 872, -78, -621, 77};
				_expected = 10;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {-737, -245, -51, 943, -7, 1000, -976, -723};
				int y[] = {-355, 898, -372, -585, -98, -53, 490, -954};
				_expected = 900;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {-928, 852, 840, 813, -564, -594, -667, 838, -74, -675, -530, -476, -154, 702, 817, 969, 845, 592, 867, -330};
				int y[] = {-898, 682, 604, 22, -452, 901, 464, -624, -272, -792, -906, 36, 249, -287, 871, 877, 446, 910, 943, 427};
				_expected = 296398747;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 4:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
