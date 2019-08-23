#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int vis[N];
class Sunnygraphs2 {
public:
	long long count(vector <int> a) {
		memset(vis, 0, sizeof vis);
		int n = a.size();
		vector< int > sz;
		for (int i = 0; i < n; i++) if (!vis[i]) {
			int v = i;
			while (!vis[v]) {
				vis[v] = 1;
				v = a[v];
			}
			bool cont = 0;
			if (vis[v] == 2) cont = 1;
			v = i;
			while(vis[v] != 2) {
				vis[v] = 2;
				v = a[v];
			}
			if (cont) continue;
			int u = a[v], cnt = 1;
			while (u != v) {
				u = a[u];
				cnt++;
			}
			sz.push_back(cnt);
		}
		int bebas = n;
		long long ans = (1LL << n), cur = 1;
		for (int s : sz) {
			bebas -= s;
			ans -= cur * (1LL << bebas);
			cur *= (1LL << s) - 1;
		}
		if (sz.size() == 1) ans++;
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
		cout << "Testing Sunnygraphs2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489414089;
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
		Sunnygraphs2 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,0};
				_expected = 4LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {1,0,0};
				_expected = 7LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {2,3,0,1};
				_expected = 9LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {2,3,0,1,0};
				_expected = 18LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {2,3,0,1,0,4,5,2,3};
				_expected = 288LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {29,34,40,17,16,12,0,40,20,35,5,13,27,7,29,13,14,39,42,9,30,38,27,40,34,33,42,20,29,42,12,29,30,21,4,5,7,25,24,17,39,32,9};
				_expected = 6184752906240LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 6:
			{
				int a[] = {9,2,0,43,12,14,39,25,24,3,16,17,22,0,6,21,18,29,34,35,23,43,28,28,20,11,5,12,31,24,8,13,17,10,15,9,15,26,4,13,21,27,36,39};
				_expected = 17317308137473LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 7:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
