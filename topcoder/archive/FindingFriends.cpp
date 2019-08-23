#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 6;
int add[N];

class FindingFriends {
public:
	int shortestDistance(int len, vector <int> init, int a, int b, int c, int d, int m) {
		int n = len;
		vector< pair< int, int > > s(len);
		for (int i = 0; i < init.size(); i++) {
			s[i] = {init[i], i};
		}
		long long now = s[(int)init.size() - 1].first;
		for (int i = init.size(); i < len; i++) {
			now = (now * a + 1LL * b * i + c) % d;
			s[i] = {now, i};
		}
		sort(s.begin(), s.end());
		int l = 0, r = s.back().first - s[0].first;
		while (l < r) {
			int k = (l+r)/2;
			bool ok = 0;
			for (int i = 0; i < n; i++)
				add[i] = 0;
			int lo, hi;
			lo = 0, hi = 0;
			set< int > st;
			for (int i = 0; i < n; i++) {
				while (hi < n && s[hi].first-s[i].first <= k) st.insert(s[hi++].second);
				while (lo < i && s[i].first - s[lo].first > k) st.erase(s[lo++].second);
				assert(lo <= i && hi > i);
				auto it = st.lower_bound(s[i].second);
				int le = max(s[i].second-m+1, 0), ri = s[i].second+1;
				auto tmp = it;
				if (tmp != st.begin())
					le = max(le, *(--tmp) + 1);
				it++;
				if (it != st.end()) {
					ri = max(le, min(ri, *(it) - m + 1));
					if (n < 10)
					cerr << *it << " " << (*(it) -m + 1) << " " << m << "?" << ri << endl;
				}
				if (n < 10) {
					for (int x : st) cerr << x << "-";
					cerr << endl;
					cerr << s[i].second << " " << le << " " << ri << endl;
				}
				add[le]++;
				add[ri]--;
			}
			int now = 0;
			for (int i = 0; i+m <= n; i++) {
				now += add[i];
				if (now == 0) {
					ok = 1;
					break;
				}
			}
			cerr << l << " " << r << " " << k << " " << ok << endl;
			if (ok)
				r = k;
			else
				l = k+1;
		}
		return l;
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
		cout << "Testing FindingFriends (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486986235;
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
		FindingFriends _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int len = 6;
				int init[] = {8,1,10,2,9,7};
				int a = 12;
				int b = 34;
				int c = 56;
				int d = 78;
				int m = 2;
				_expected = 1;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
			}
			case 1:
			{
				int len = 7;
				int init[] = {1};
				int a = 1;
				int b = 0;
				int c = 0;
				int d = 12345678;
				int m = 5;
				_expected = 0;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
			}
			case 2:
			{
				int len = 12;
				int init[] = {0};
				int a = 1;
				int b = 0;
				int c = 1;
				int d = 6;
				int m = 3;
				_expected = 0;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
			}
			case 3:
			{
				int len = 10;
				int init[] = {3,4,5};
				int a = 23;
				int b = 34;
				int c = 35;
				int d = 46;
				int m = 4;
				_expected = 4;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
			}
			case 4:
			{
				int len = 2;
				int init[] = {0,1000000000};
				int a = 0;
				int b = 0;
				int c = 0;
				int d = 1;
				int m = 2;
				_expected = 1000000000;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
			}
			case 5:
			{
				int len = 5;
				int init[] = {1,2,1000,3,4};
				int a = 9;
				int b = 8;
				int c = 7;
				int d = 10;
				int m = 3;
				_expected = 996;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
			}
			case 6:
			{
				int len = 100000;
				int init[] = {967948965};
				int a = 758179342;
				int b = 788391896;
				int c = 28648718;
				int d = 999999937;
				int m = 3;
				_expected = 59543;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
			}
			/*case 7:
			{
				int len = ;
				int init[] = ;
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				int m = ;
				_expected = ;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
			}*/
			/*case 8:
			{
				int len = ;
				int init[] = ;
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				int m = ;
				_expected = ;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
			}*/
			/*case 9:
			{
				int len = ;
				int init[] = ;
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				int m = ;
				_expected = ;
				_received = _obj.shortestDistance(len, vector <int>(init, init+sizeof(init)/sizeof(int)), a, b, c, d, m); break;
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
