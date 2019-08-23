#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int m;
struct trie {
	trie * l, * r;
	int cnt;
	trie(int val = 0) {
		l = r = NULL;
		cnt = val;
	}
	void add(int val) {
		trie * now = this;
		now->cnt++;
		for (int i = m-1; i >= 0; i--) {
			if (val & (1<<i)) {
				if (!now->r)
					now->r = new trie();
				now = now->r;
			}
			else {
				if (!now->l)
					now->l = new trie();
				now = now->l;
			}
			now->cnt++;
		}
	}
	long long get(int val) {
		long long x2 = 0, x = 0;
		trie * now = this;
		for (int i = m-1; i >= 0; i--) {
			long long cur = 0;
			if (val & (1<<i))
				cur = now->l ? now->l->cnt : 0, now = now->r;
			else
				cur = now->r ? now->r->cnt : 0, now = now->l;
			long long cur2 = (cur * cur) % mod;
			cur2 = (cur2 * (1LL << (m-1-i))) % mod;
			x2 = (x2 + x2 + 2LL * x * cur + cur2) % mod;
			x = (x + x + cur *(1LL << (m-1-i))) % mod;
		}
		return x2 % mod;
	}
};

class XorOrderDiv1 {
public:
	int get(int M, int n, int a0, int b) {
		m = M;
		trie * root = new trie();
		int mask = (1<<m) - 1;
		vector< int > a;
		for (int i = 0; i < n; i++) {
			root->add(a0);
			a.push_back(a0);
			a0 += b;
			a0 &= mask;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans ^= (int)((mod + root->get(a[i])) % mod);
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
		cout << "Testing XorOrderDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487327689;
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
		XorOrderDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 2;
				int n = 3;
				int a0 = 0;
				int b = 1;
				_expected = 8;
				_received = _obj.get(m, n, a0, b); break;
			}
			case 1:
			{
				int m = 3;
				int n = 5;
				int a0 = 1;
				int b = 3;
				_expected = 48;
				_received = _obj.get(m, n, a0, b); break;
			}
			case 2:
			{
				int m = 16;
				int n = 100;
				int a0 = 41;
				int b = 5;
				_expected = 523436032;
				_received = _obj.get(m, n, a0, b); break;
			}
			case 3:
			{
				int m = 30;
				int n = 200000;
				int a0 = 399;
				int b = 18082016;
				_expected = 408585698;
				_received = _obj.get(m, n, a0, b); break;
			}
			/*case 4:
			{
				int m = ;
				int n = ;
				int a0 = ;
				int b = ;
				_expected = ;
				_received = _obj.get(m, n, a0, b); break;
			}*/
			/*case 5:
			{
				int m = ;
				int n = ;
				int a0 = ;
				int b = ;
				_expected = ;
				_received = _obj.get(m, n, a0, b); break;
			}*/
			/*case 6:
			{
				int m = ;
				int n = ;
				int a0 = ;
				int b = ;
				_expected = ;
				_received = _obj.get(m, n, a0, b); break;
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
