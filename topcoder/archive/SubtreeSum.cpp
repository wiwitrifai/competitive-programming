#include <bits/stdc++.h>

using namespace std;

const int N = 123, mod = 1e9 + 7;
int c[N];
vector< int > g[N];
long long count(int v, long long & cnt) {
	long long cur = 1;
	for (int u : g[v]) if (!c[u]) {
		cur = (cur * count(u, cnt)) % mod;
	}
	cnt += cur;
	if (cnt >= mod) cnt -= mod;
	cur++;
	if (cur >= mod) cur -= mod;
	return cur;
}

class SubtreeSum {
public:
	int getSum(vector <int> p, vector <int> x) {
		int n = p.size() + 1;
		for (int i = 0; i < n; i++)
			g[i].clear();
		for (int i = 0; i < n-1; i++)
			g[p[i]].push_back(i+1);
		memset(c, 0, sizeof c);
		long long all = 0;
		count(0, all);
		int ma = 0;
		for (int i = 0; i < n; i++)
			ma = max(ma, x[i]);
		long long ans = 0;
		for (int i = 1; i <= ma; i<<=1) {
			for (int j = 0; j < n; j++)
				c[j] = (x[j] & i) > 0; 
			long long cnt = 0;
			long long now = all;
			if (c[0] == 0) {
				count(0, cnt);
				now += mod - cnt;
				if (now >= mod) now -= mod;
			}
			for (int j = 0; j < n-1; j++) if (c[p[j]] && !c[j+1]) {
				cnt = 0;
				count(j+1, cnt);
				now += mod - cnt;
				if (now >= mod) now -= mod;
			}
			ans = (ans + now * i) % mod; 
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
		cout << "Testing SubtreeSum (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487255509;
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
		SubtreeSum _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0};
				int x[] = {1,2};
				_expected = 6;
				_received = _obj.getSum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0,1};
				int x[] = {1,2,4};
				_expected = 23;
				_received = _obj.getSum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0,0,0,0,0,0,0,0,0,0};
				int x[] = {1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000};
				_expected = 33999993;
				_received = _obj.getSum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0,0,1,0,2,2,3,0,0,2,1};
				int x[] = {4,5,6,7,0,8,9,5,1,2,3,6};
				_expected = 6378;
				_received = _obj.getSum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 4:
			{
				int p[] = ;
				int x[] = ;
				_expected = ;
				_received = _obj.getSum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int p[] = ;
				int x[] = ;
				_expected = ;
				_received = _obj.getSum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int p[] = ;
				int x[] = ;
				_expected = ;
				_received = _obj.getSum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
