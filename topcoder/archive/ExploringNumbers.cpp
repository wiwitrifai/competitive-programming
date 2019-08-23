#include <bits/stdc++.h>

using namespace std;

set< int > st;

class ExploringNumbers {
public:
	int numberOfSteps(int n) {
		st.clear();
		int ans = 1;
		bool ok = 1;
		if (n == 1) return -1;
		for (int i = 2; 1LL * i * i <= n; i++) if ((n % i) == 0) {
			ok = 0;
			break;
		}
		if (ok)
			return 1;
		while (1) {
			ans++;
			int m = 0;
			while (n) {
				int r = n % 10;
				n /= 10;
				m += r * r;
			}
			ok = 1;
			for (int i = 2; 1LL * i * i <= m; i++) if ((m % i) == 0) {
				ok = 0;
				break;
			}
			if (m == 1) return -1;
			if (ok)
				break;
			if (st.count(m))
				return -1;
			st.insert(m);
			n = m;
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
		cout << "Testing ExploringNumbers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491227506;
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
		ExploringNumbers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				_expected = 1;
				_received = _obj.numberOfSteps(n); break;
			}
			case 1:
			{
				int n = 57;
				_expected = 4;
				_received = _obj.numberOfSteps(n); break;
			}
			case 2:
			{
				int n = 1;
				_expected = -1;
				_received = _obj.numberOfSteps(n); break;
			}
			case 3:
			{
				int n = 6498501;
				_expected = 2;
				_received = _obj.numberOfSteps(n); break;
			}
			case 4:
			{
				int n = 989113;
				_expected = 6;
				_received = _obj.numberOfSteps(n); break;
			}
			case 5:
			{
				int n = 12366;
				_expected = -1;
				_received = _obj.numberOfSteps(n); break;
			}
			/*case 6:
			{
				int n = ;
				_expected = ;
				_received = _obj.numberOfSteps(n); break;
			}*/
			/*case 7:
			{
				int n = ;
				_expected = ;
				_received = _obj.numberOfSteps(n); break;
			}*/
			/*case 8:
			{
				int n = ;
				_expected = ;
				_received = _obj.numberOfSteps(n); break;
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
