#include <bits/stdc++.h>

using namespace std;

class BearPasswordAny {
public:
	string findPassword(vector <int> x) {
		int n = x.size();
		vector< int > a(n);
		int cnt = 0, last = 0;
		for (int i = n-1; i >= 0; i--) {
			if (x[i] - last < cnt)
				return "";
			a[i] = x[i]-last-cnt;
			cnt += a[i];
			last = x[i];
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i] * (i+1);
		if (sum != n)
			return "";
		string ans = "";
		char now = 'a', oth = 'b';
		for (int i = 0; i < n; i++) {
			while (a[i]--) {
				ans += string(i+1, now);
				swap(now, oth);
			}
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
		cout << "Testing BearPasswordAny (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487550339;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BearPasswordAny _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {5,0,0,0,0};
				_expected = "ababa";
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {4,2,1,0};
				_expected = "baaa";
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {3,1,1};
				_expected = "";
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {4,3,2,1};
				_expected = "aaaa";
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {0};
				_expected = "";
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {4,0,3,2};
				_expected = "";
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {6,3,1,0,0,0};
				_expected = "abbaaa";
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {10,5,2,1,0,0,0,0,0,0};
				_expected = "bbbbaababb";
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 8:
			{
				int x[] = {5,4,2,1,0};
				_expected = "";
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 9:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 11:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
