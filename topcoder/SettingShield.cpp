#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
const long long inf = 1e18;
int protection[N], lef[N], rig[N];
int add[N];
int n;
vector< pair< int, int > > seg, used;
long long get(int k, int t) {
	long long ret = 0;
	fill(add, add+n, 0);
	int cur = 0, val = 0, now = 0;
	for (int i = 0; i < n; i++) {
		while (cur+1 < used.size() && used[cur+1].first <= i) cur++, val = 0;
		now += add[i];
		if (now < protection[i]-k) {
			if (cur < used.size() && used[cur].first <= i && used[cur].second >= i) {
				int tmp = protection[i]-k-now;
				val += tmp;
				now += tmp;
				add[used[cur].second+1] -= tmp;
				ret += tmp;
			}
			else
				return inf;
		}
	}
	return ret + 1LL * t * k;
}

class SettingShield {
public:
	long long getOptimalCost(int n, int h, int t, vector <int> val0, vector <int> a, vector <int> b, vector <int> m) {
		::n = n;
		protection[0] = val0[0];
		for (int i = 1; i < n; i++)
		  protection[i] = (1LL * a[0] * protection[i-1] + b[0]) % m[0];

		lef[0] = val0[1];
		rig[0] = val0[2];
		for (int i = 1; i < h; i++) {
		  lef[i] = min(n-1LL, (1LL * a[1] * lef[i-1] + b[1]) % m[1]);
		  int dist = rig[i-1] - lef[i-1];
		  rig[i] = min(n-1LL, lef[i] + ((1LL * a[2] * dist + b[2]) % m[2]));
		}
		seg.clear();
		used.clear();
		for (int i = 0; i < h; i++)
			seg.emplace_back(lef[i], rig[i]);
		sort(seg.begin(), seg.end());
		pair<int, int > last = seg[0];
		for (int i = 0; i < h; i++) {
			if (seg[i].first == last.first)
				last = max(last, seg[i]);
			else
				if (seg[i].second > last.second) {
					used.push_back(last);
					last = seg[i];
				}
		}
		if (used.empty() || used.back() != last)
			used.push_back(last);
		int l = 0, r = 0;
		for (int i = 0; i < n; i++)
			r = max(r, protection[i]);
		int id = 0;
		for (int i = 0; i < n; i++) {
			while (id+1 < used.size() && used[id+1].first <= i) id++; 
			if (id >= used.size())
				l = max(l, protection[i]);
			else if (used[id].first > i || used[id].second < i)
				l = max(l, protection[i]);
		}
		long long ans = min(get(r, t), get(l, t));
		while (r-l > 4) {
			int midl = (l + l + r)/3, midr = (l + r + r)/3;
			long long resl = get(midl, t), resr = get(midr, t);
			ans = min(ans, min(resl, resr));
			if (resl <= resr)
				r = midr;
			else
				l = midl;
		}
		for (int i = l; i <= r; i++)
			ans = min(ans, get(i, t));
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
		cout << "Testing SettingShield (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491228545;
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
		SettingShield _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int h = 3;
				int t = 10;
				int val0[] = {4, 0, 1};
				int a[] = {1, 1, 1};
				int b[] = {3, 1, 1};
				int m[] = {6, 10, 10};
				_expected = 8LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 3;
				int h = 1;
				int t = 10;
				int val0[] = {4, 0, 1};
				int a[] = {1, 1, 1};
				int b[] = {3, 1, 1};
				int m[] = {6, 10, 10};
				_expected = 40LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 6;
				int h = 3;
				int t = 2;
				int val0[] = {4, 1, 3};
				int a[] = {2, 4, 3};
				int b[] = {3, 2, 2};
				int m[] = {20, 9, 4};
				_expected = 22LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 12;
				int h = 6;
				int t = 4;
				int val0[] = {4, 3, 7};
				int a[] = {2, 4, 5};
				int b[] = {3, 8, 7};
				int m[] = {40, 23, 13};
				_expected = 108LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 50;
				int h = 77;
				int t = 4;
				int val0[] = {4, 11, 30};
				int a[] = {9, 40, 7};
				int b[] = {33, 8, 12};
				int m[] = {20000, 200, 13};
				_expected = 79111LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 555;
				int h = 120;
				int t = 4;
				int val0[] = {10000000, 301, 520};
				int a[] = {9999999, 9999998, 9999997};
				int b[] = {9995999, 0, 9919999};
				int m[] = {1999999, 9993999, 9299999};
				_expected = 40000000LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 501;
				int h = 2;
				int t = 2;
				int val0[] = {10000000, 500, 500};
				int a[] = {10000000, 10000000, 10000000};
				int b[] = {0, 0, 500};
				int m[] = {1000003, 10000000, 10000000};
				_expected = 10000000LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 7:
			{
				int n = 100000;
				int h = 99901;
				int t = 900;
				int val0[] = {712, 0, 99};
				int a[] = {37, 1, 0};
				int b[] = {13, 1, 99};
				int m[] = {1000, 1000000, 1000000};
				_expected = 848460LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			/*case 8:
			{
				int n = ;
				int h = ;
				int t = ;
				int val0[] = ;
				int a[] = ;
				int b[] = ;
				int m[] = ;
				_expected = LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int n = ;
				int h = ;
				int t = ;
				int val0[] = ;
				int a[] = ;
				int b[] = ;
				int m[] = ;
				_expected = LL;
				_received = _obj.getOptimalCost(n, h, t, vector <int>(val0, val0+sizeof(val0)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
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
