#include <bits/stdc++.h>

using namespace std;

int vis[55];

class Sunnygraphs {
public:
	long long count(vector <int> a) {
		int n = a.size();
		set< int > reach0, reach1;
		int v = 0;
		while (!reach0.count(v)) {
			reach0.insert(v);
			v = a[v];
		}
		v = 1;
		while (!reach1.count(v)) {
			reach1.insert(v);
			v = a[v];
		}
		int common = 0, only0 = 0, only1 = 0;
		for (int x : reach0) {
			if (reach1.count(x))
				common++;
			else
				only0++;
		}
		only1 = reach1.size() - common;
		int total = only0 + only1 + common;
		long long ans = 0;
		ans = ((1LL << only1) - 1 + (1LL<<only0) -1 + !common) * (1LL << (n-total)); 
		return (1LL << n) - ans;
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
		cout << "Testing Sunnygraphs (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489453216;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Sunnygraphs _obj;
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
				int a[] = {2,2,0};
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
				int a[] = {2,2,3,4,3};
				_expected = 30LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8};
				_expected = 2198754820096LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
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
