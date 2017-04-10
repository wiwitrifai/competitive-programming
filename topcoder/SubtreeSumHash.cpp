#include <bits/stdc++.h>

using namespace std;

const int N = 505, mod = 1e9 + 7;

long long powmod(long long b, long long pw) {
	long long ret = 1;
	for (; pw; pw >>= 1, b = b*b % mod)
		if (pw & 1) ret = ret * b % mod;
	return ret;
}

long long p, ans;
vector< int > g[N];
vector< int > w;
long long dfs(int v, int par) {
	long long ret = powmod(p, w[v]);
	for (int u : g[v]) if (u != par) {
		long long res = dfs(u, v);
		res++;
		if (res >= mod) res -= mod;
		ret = (res * ret) % mod;
	}
	ans += ret;
	if (ans >= mod) ans -= mod;
	return ret;
}

class SubtreeSumHash {
public:
	int count(vector <int> weight, vector <int> p, int x) {
		w = weight;
		::p = x;
		int n = w.size();
		for (int i = 0; i < n-1; i++) {
			g[i+1].push_back(p[i]);
			g[p[i]].push_back(i+1);
		}
		ans = 0;
		dfs(0, 0);
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
		cout << "Testing SubtreeSumHash (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491836310;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SubtreeSumHash _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int weight[] = {1,2,3};
				int p[] = {0,1};
				int x = 10;
				_expected = 1102110;
				_received = _obj.count(vector <int>(weight, weight+sizeof(weight)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), x); break;
			}
			case 1:
			{
				int weight[] = {123456789,987654321,111111111,999999999};
				int p[] = {0,0,0};
				int x = 1;
				_expected = 11;
				_received = _obj.count(vector <int>(weight, weight+sizeof(weight)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), x); break;
			}
			case 2:
			{
				int weight[] = {10};
				int p[] = {};
				int x = 10;
				_expected = 999999937;
				_received = _obj.count(vector <int>(weight, weight+sizeof(weight)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), x); break;
			}
			case 3:
			{
				int weight[] = {3,7,6,8,9,4,2,1,5,6,7,8,9,6,1,2,3,5};
				int p[] = {0,0,0,3,1,1,2,0,0,3,7,8,9,0,0,4,1};
				int x = 987654321;
				_expected = 46327623;
				_received = _obj.count(vector <int>(weight, weight+sizeof(weight)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), x); break;
			}
			/*case 4:
			{
				int weight[] = ;
				int p[] = ;
				int x = ;
				_expected = ;
				_received = _obj.count(vector <int>(weight, weight+sizeof(weight)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), x); break;
			}*/
			/*case 5:
			{
				int weight[] = ;
				int p[] = ;
				int x = ;
				_expected = ;
				_received = _obj.count(vector <int>(weight, weight+sizeof(weight)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), x); break;
			}*/
			/*case 6:
			{
				int weight[] = ;
				int p[] = ;
				int x = ;
				_expected = ;
				_received = _obj.count(vector <int>(weight, weight+sizeof(weight)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int)), x); break;
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
