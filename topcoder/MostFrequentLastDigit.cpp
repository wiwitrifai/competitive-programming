#include <bits/stdc++.h>

using namespace std;

class MostFrequentLastDigit {
public:
	vector <int> generate(int n, int d) {
		int r = 1, s = d-r;
		for (int i = 1; i < 10; ++i) {
			if (((d-i) % 10) == 0) continue;
			r = i;
			s = (d-i) % 10;
			if (s < 0) s += 10;
		}
		vector<int> ans(n, r);
		for (int i = 0; i < n/2; ++i)
			ans[i] = s;
		sort(ans.begin(), ans.end());
		set<int> st;
		for (int i = 0; i < n; ++i) {
			int now = ans[i];
			while (st.count(now)) {
				now += 10;
			}
			st.insert(now);
			ans[i] = now;
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
		cout << "Testing MostFrequentLastDigit (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1547914089;
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
		MostFrequentLastDigit _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int d = 7;
				int __expected[] = {1, 6, 13, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}
			case 1:
			{
				int n = 2;
				int d = 8;
				int __expected[] = {44, 444 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}
			case 2:
			{
				int n = 7;
				int d = 2;
				int __expected[] = {109, 22, 74, 23, 29, 9, 1003 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}
			/*case 3:
			{
				int n = ;
				int d = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}*/
			/*case 4:
			{
				int n = ;
				int d = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}*/
			/*case 5:
			{
				int n = ;
				int d = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
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
