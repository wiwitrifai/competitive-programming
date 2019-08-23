#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 2018;
int fin;
long long inv[N * 3];
long long dp[2][N][N + N];
long long powmod(long long b, long long p) {
	long long r = 1;
	for (; p; p >>= 1, b = b*b % mod)
		if (p & 1) r = r * b % mod;
	return r;
}

long long solve(int sakit, int b, int h) {
	if (b * 2 + h == fin) 
		return (b + h) % mod;
	long long & ret = dp[sakit][b][h];
	if (ret != -1) return ret;
	ret = 0;
	int bb = b;
	if (!sakit) bb--;
	if (bb > 0) {
		long long prob = bb * inv[b+h] % mod;
		long long cur = solve(sakit, b-1, h+1) * prob % mod;
		ret = cur;
	}
	int hh = h-1;
	if (sakit) hh--;
	if (hh > 0) {
		long long prob = hh * inv[b+h] % mod;
		long long cur = solve(sakit, b, h-1) * prob % mod;
		ret += cur;
		if (ret >= mod) ret -= mod;
	}
	if (!sakit && b > 0) {
		long long prob =  inv[b+h] % mod;
		long long cur = solve(1, b-1, h+1) * prob % mod;
		ret += cur;
		if (ret >= mod) ret -= mod;	
	}
	ret %= mod;
	if (ret < 0) ret += mod;
	return ret;
}

class DoubleLive {
public:
	int findEV(int B, int H, int T) {
		for (int i = 1; i < 3 * N; ++i)
			inv[i] = powmod(i, mod-2);
		fin = B * 2 + H - T;
		memset(dp, -1, sizeof dp);
		return solve(0, B, H) * B * H % mod;
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
		cout << "Testing DoubleLive (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515642954;
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
		DoubleLive _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int B = 4;
				int H = 3;
				int T = 1;
				_expected = 571428644;
				_received = _obj.findEV(B, H, T); break;
			}
			case 1:
			{
				int B = 3;
				int H = 10;
				int T = 0;
				_expected = 390;
				_received = _obj.findEV(B, H, T); break;
			}
			case 2:
			{
				int B = 1;
				int H = 2;
				int T = 2;
				_expected = 111111113;
				_received = _obj.findEV(B, H, T); break;
			}
			case 3:
			{
				int B = 1;
				int H = 1;
				int T = 1;
				_expected = 1;
				_received = _obj.findEV(B, H, T); break;
			}
			case 4:
			{
				int B = 1;
				int H = 1;
				int T = 2;
				_expected = 0;
				_received = _obj.findEV(B, H, T); break;
			}
			case 5:
			{
				int B = 3;
				int H = 10;
				int T = 16;
				_expected = 0;
				_received = _obj.findEV(B, H, T); break;
			}
			case 6:
			{
				int B = 5;
				int H = 2;
				int T = 5;
				_expected = 519487272;
				_received = _obj.findEV(B, H, T); break;
			}
			case 7:
			{
				int B = 1807;
				int H = 1234;
				int T = 4040;
				_expected = 373880953;
				_received = _obj.findEV(B, H, T); break;
			}
			/*case 8:
			{
				int B = ;
				int H = ;
				int T = ;
				_expected = ;
				_received = _obj.findEV(B, H, T); break;
			}*/
			/*case 9:
			{
				int B = ;
				int H = ;
				int T = ;
				_expected = ;
				_received = _obj.findEV(B, H, T); break;
			}*/
			/*case 10:
			{
				int B = ;
				int H = ;
				int T = ;
				_expected = ;
				_received = _obj.findEV(B, H, T); break;
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
