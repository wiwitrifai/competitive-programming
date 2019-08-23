#include <bits/stdc++.h>

using namespace std;

class BearPasswordLexic {
public:
	string findPassword(vector <int> x) {
		int n = x.size();
		vector < int > a;
		int cnt = 0, last = 0, sum = 0;
		for (int i = n-1; i >= 0; i--) {
			if (x[i] - last < cnt)
				return "";
			int now = x[i] - last - cnt;
			sum += now * (i+1);
			last = x[i];
			cnt += now;
			while (now--)
				a.push_back(i+1);
		}
		if (sum != n)
			return "";
		sort(a.begin(), a.end());
		int i = 0, j = (int)a.size()-1;
		char now = 'a', oth = 'b';
		string ans = "";
		while (i <= j) {
			if (now == 'a')
				ans += string(a[j--], 'a');
			else
				ans += string(a[i++], 'b');
			swap(now, oth);
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
		cout << "Testing BearPasswordLexic (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487552981;
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
		BearPasswordLexic _obj;
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
				_expected = "aaab";
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
			/*case 6:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.findPassword(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
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
