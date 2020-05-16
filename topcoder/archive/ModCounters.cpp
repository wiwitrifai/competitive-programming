#include <bits/stdc++.h>

using namespace std;

const int S = 512, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
	long long r = 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1)
			r = r * b % mod;
	return r;
}

vector<int> combine(vector<int> & a, vector<int> & b) {
	vector<int> ret(S, 0);
	for (int i = 0; i < (int)a.size(); ++i) {
		for (int j = 0; j < (int)b.size(); ++j) {
			int k = (i + j) % S;
			ret[k] = (ret[k] + 1LL * a[i] * b[j]) % mod;
		}
	}
	return ret;
}

vector<int> solve(vector<int> & b, int k) {
	if (k == 0) {
		return vector<int>(S, 0);
	}
	else if (k == 1) {
		return b;
	}
	vector<int> res = solve(b, k/2);
	res = combine(res, res);
	if (k & 1)
		res = combine(res, b);
	return res;
}

class ModCounters {
public:
	int findExpectedSum(vector <int> P, int A0, int X, int Y, int N, int K) {
		vector<int> res(S, 0);
		res[1] = powmod(N, mod-2);
		res[0] = 1LL * (N-1) * res[1] % mod;

		res = solve(res, K);

		vector<int> A(N);
		A[0] = A0;
		for (int i = 1; i < N; ++i) {
		  A[i] = (1LL * A[i-1] * X + Y) % 1812447359;
		}

		vector<long long> suf(S+1, 0);
		long long all = 0;

		for (int i = S-1; i >= 0; --i) {
			suf[i] = (suf[i+1] + res[i]) % mod;
		}
		for (int i = 0; i < S; ++i)
			all = (all + 1LL * res[i] * i) % mod;
		long long ans = 0;
		for (int i = 0; i < N; ++i) {
			int now = i < (int)P.size() ? P[i] : A[i] % 512;
			ans = (ans + now + all- 512LL * suf[S-now]) % mod;
			if (ans < 0)
				ans += mod;
		}
		ans %= mod;
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
		cout << "Testing ModCounters (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1589555710;
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
		ModCounters _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int P[] = {0, 511};
				int A0 = 0;
				int X = 0;
				int Y = 0;
				int N = 2;
				int K = 1;
				_expected = 256;
				_received = _obj.findExpectedSum(vector <int>(P, P+sizeof(P)/sizeof(int)), A0, X, Y, N, K); break;
			}
			case 1:
			{
				int P[] = {0};
				int A0 = 1001;
				int X = 1001;
				int Y = 1001;
				int N = 2;
				int K = 2;
				_expected = 508;
				_received = _obj.findExpectedSum(vector <int>(P, P+sizeof(P)/sizeof(int)), A0, X, Y, N, K); break;
			}
			case 2:
			{
				int P[] = {};
				int A0 = 3583;
				int X = 1000;
				int Y = 1812447358;
				int N = 2;
				int K = 2;
				_expected = 152;
				_received = _obj.findExpectedSum(vector <int>(P, P+sizeof(P)/sizeof(int)), A0, X, Y, N, K); break;
			}
			case 3:
			{
				int P[] = {100, 101};
				int A0 = 5000;
				int X = 50000;
				int Y = 100000;
				int N = 1000;
				int K = 1000;
				_expected = 856925612;
				_received = _obj.findExpectedSum(vector <int>(P, P+sizeof(P)/sizeof(int)), A0, X, Y, N, K); break;
			}
			case 4:
			{
				int P[] = {};
				int A0 = 100000000;
				int X = 100000000;
				int Y = 100000000;
				int N = 10;
				int K = 1000;
				_expected = 454731206;
				_received = _obj.findExpectedSum(vector <int>(P, P+sizeof(P)/sizeof(int)), A0, X, Y, N, K); break;
			}
			case 5:
			{
				int P[] = {};
				int A0 = 501296088;
				int X = 234548363;
				int Y = 703491623;
				int N = 2000000;
				int K = 1894643;
				_expected = 804222535;
				_received = _obj.findExpectedSum(vector <int>(P, P+sizeof(P)/sizeof(int)), A0, X, Y, N, K); break;
			}
			/*case 6:
			{
				int P[] = ;
				int A0 = ;
				int X = ;
				int Y = ;
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.findExpectedSum(vector <int>(P, P+sizeof(P)/sizeof(int)), A0, X, Y, N, K); break;
			}*/
			/*case 7:
			{
				int P[] = ;
				int A0 = ;
				int X = ;
				int Y = ;
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.findExpectedSum(vector <int>(P, P+sizeof(P)/sizeof(int)), A0, X, Y, N, K); break;
			}*/
			/*case 8:
			{
				int P[] = ;
				int A0 = ;
				int X = ;
				int Y = ;
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.findExpectedSum(vector <int>(P, P+sizeof(P)/sizeof(int)), A0, X, Y, N, K); break;
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
