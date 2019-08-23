#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long dp[1 << 23], cnt[1 << 23];
long long to[55], sm[55];

void add(long long & a, long long b) {
	a += b;
	if (a >= mod) a -= mod;
}

class CliqueCuts {
public:
	int sum(int n, vector <int> a, vector <int> b, vector <int> c) {
		memset(dp, 0, sizeof dp);
		memset(cnt, 0, sizeof cnt);
		memset(to, 0, sizeof to);
		memset(sm, 0, sizeof sm);
		int m = b.size();
		for (int i = 0; i < m; i++) {
			to[a[i]] |= 1LL << b[i];
			to[b[i]] |= 1LL << a[i];
			add(sm[a[i]], c[i]); 
			add(sm[b[i]], c[i]);
		}
		for (int i = 0; i < n; i++)
			to[i] |= 1LL << i;
		int s1 = n/2, s2 = n - s1;
		long long all = 1LL<<s1;
		for (long long mask = 0; mask < all; mask++) {
			bool ok = 1;
			long long cur = 0;
			for (int i = 0; i < s1; i++)
				if (mask & (1LL<<i)) {
					if ((mask & to[i]) != mask) {
						ok = 0; break;
					}
					add(cur, sm[i]);
				}
				else
					add(cur, mod-sm[i]);
			if (!ok) continue;
			cnt[mask]++;
			dp[mask] = cur % mod;
		}
		for (int i = 0; i < s1; i++) {
			for (long long mask = 0; mask < all; mask++)
			if (mask & (1LL<<i)) {
				add(dp[mask], dp[mask^(1LL<<i)]);
				add(cnt[mask], cnt[mask^(1LL<<i)]);
			}
		}
		all = 1LL<<s2;
		long long ans = 0;
		for (long long mask = 0; mask <all; mask++) {
			bool ok = 1;
			long long cur = 0, need = (1LL << s1) - 1;
			for (int i = 0; i < s2; i++) {
				if (mask & (1LL<<i)) {
					long long cmask = mask << s1;
					if ((cmask & to[i+s1]) != cmask) {
						ok = 0; break;
					}
					add(cur, sm[i+s1]);
					need &= to[i+s1];
				}
				else
					add(cur, mod-sm[i+s1]);
			}
			if (!ok) continue;
			add(ans, (cur * cnt[need] + dp[need]) % mod);
		}
		for (int i = 0; i < n; i++)
			add(ans, sm[i]);
		const long long inv2 = (mod + 1)/2;
		ans = (ans * inv2) % mod;
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
		cout << "Testing CliqueCuts (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491291161;
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
		CliqueCuts _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int a[] = {0};
				int b[] = {1};
				int c[] = {100};
				_expected = 100;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				int a[] = {0,0,0,0,1,1,1,2,2,3};
				int b[] = {1,2,3,4,2,3,4,3,4,4};
				int c[] = {0,1,2,3,4,5,6,7,8,9};
				_expected = 45;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 5;
				int a[] = {0,1,2,3};
				int b[] = {1,2,3,4};
				int c[] = {9,2,4,3};
				_expected = 999999941;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 10;
				int a[] = {0,1,2,9,5,3,4,7,3,4,1,5,2,3,0,7,8};
				int b[] = {6,7,4,5,6,2,6,3,1,8,2,0,9,9,8,2,5};
				int c[] = {10000,10000000,100000000,100,10,1,1000,100,10000,100,10000,1000,100,10,100,100000000,10};
				_expected = 209370454;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 45;
				int a[] = {};
				int b[] = {};
				int c[] = {};
				_expected = 0;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
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
