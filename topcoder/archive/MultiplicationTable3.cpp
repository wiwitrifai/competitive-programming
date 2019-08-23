#include <bits/stdc++.h>

using namespace std;

int max_bit(int x) {
	for (int i = 20; i >= 0; i--)
		if (x & (1<<i))
			return i;
	return -1;
}

int ans[22][22];

class MultiplicationTable3 {
public:
	vector <int> construct(int x) {
		int n = max_bit(x+1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans[i][j] = j;
		x -= (1<<n)-1;
		while (x) {
			int m = max_bit(x);
			for (int i = n; i > m; i--)
				ans[i][n] = ans[n][i] = max(i-1, 0);
			for (int i = m; i >= 0; i--)
				ans[i][n] = ans[n][i] = n;
			n++;
			x -= (1<<m);
		}
		vector< int > ret;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				ret.push_back(ans[i][j]);
		}
		return ret;
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
		cout << "Testing MultiplicationTable3 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489508876;
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
		MultiplicationTable3 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 2;
				int __expected[] = {1, 1, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 1:
			{
				int x = 3;
				int __expected[] = {0, 1, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 2:
			{
				int x = 6;
				int __expected[] = {0, 1, 1, 0, 1, 2, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 3:
			{
				int x = 31;
				int __expected[] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 4:
			{
				int x = 1;
				int __expected[] = {0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			/*case 5:
			{
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}*/
			/*case 6:
			{
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}*/
			/*case 7:
			{
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
