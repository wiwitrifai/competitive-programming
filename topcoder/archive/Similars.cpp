#include <bits/stdc++.h>

using namespace std;

int mask(int a) {
	int ret = 0;
	set< int > st;
	while (a) {
		st.insert(a % 10); a /= 10;
	}
	for (int v : st)
		ret |= 1 << v;
	return ret;
}

class Similars {
public:
	int maxsim(int L, int R) {
		int ans = 0;
		set< int > m;
		for (int i = L; i <= R; i++) {
			int res = mask(i);
			if (m.count(res))
				ans = max(ans, __builtin_popcount(res));
			m.insert(res);
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			auto it2 = it;
			for (it2++; it2 != m.end(); it2++) {
				ans = max(ans, __builtin_popcount(*it & *it2));
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
		cout << "Testing Similars (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491193656;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Similars _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 1;
				int R = 10;
				_expected = 1;
				_received = _obj.maxsim(L, R); break;
			}
			case 1:
			{
				int L = 1;
				int R = 99;
				_expected = 2;
				_received = _obj.maxsim(L, R); break;
			}
			case 2:
			{
				int L = 99;
				int R = 100;
				_expected = 0;
				_received = _obj.maxsim(L, R); break;
			}
			case 3:
			{
				int L = 1000;
				int R = 1010;
				_expected = 2;
				_received = _obj.maxsim(L, R); break;
			}
			case 4:
			{
				int L = 444;
				int R = 454;
				_expected = 2;
				_received = _obj.maxsim(L, R); break;
			}
			case 5:
			{
				int L = 25433;
				int R = 25467;
				_expected = 5;
				_received = _obj.maxsim(L, R); break;
			}
			/*case 6:
			{
				int L = ;
				int R = ;
				_expected = ;
				_received = _obj.maxsim(L, R); break;
			}*/
			/*case 7:
			{
				int L = ;
				int R = ;
				_expected = ;
				_received = _obj.maxsim(L, R); break;
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
