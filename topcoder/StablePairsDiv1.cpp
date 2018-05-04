#include <bits/stdc++.h>

using namespace std;

class StablePairsDiv1 {
public:
	vector <int> findMaxStablePairs(int n, int c, int k) {
		for (int ma = n + (n-1); ma >= 0; --ma) {
			bool ok = 1;
			int last = n+1;
			int cur = ma;
			vector<int> ans;
			for (int i = 0; i < k; ++i) {
				if (cur < 3) {
					ok = 0;
					break;
				}
				int sel = -1;
				for (int j = last-2; j > 0; --j) {
					int x = cur - j;
					if (x <= j) continue;
					if (x >= last) continue;
					sel = j;
					break;
				}
				if (sel == -1) {
					ok = 0;
					break;
				}
				ans.push_back(cur-sel);
				ans.push_back(sel);
				last = sel;
				cur -= c;
			}
			if (ok) {
				reverse(ans.begin(), ans.end());
				return ans;
			}
		}
		return vector<int>();
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
		cout << "Testing StablePairsDiv1 (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1525347126;
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
		StablePairsDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				int c = 4;
				int k = 2;
				int __expected[] = {2, 3, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxStablePairs(n, c, k); break;
			}
			case 1:
			{
				int n = 4;
				int c = 4;
				int k = 2;
				int __expected[] = {1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxStablePairs(n, c, k); break;
			}
			case 2:
			{
				int n = 1;
				int c = 100;
				int k = 1;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxStablePairs(n, c, k); break;
			}
			case 3:
			{
				int n = 3;
				int c = 100;
				int k = 1;
				int __expected[] = {2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxStablePairs(n, c, k); break;
			}
			case 4:
			{
				int n = 10;
				int c = 6;
				int k = 3;
				int __expected[] = {2, 5, 6, 7, 9, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxStablePairs(n, c, k); break;
			}
			case 5:
			{
				int n = 12;
				int c = 7;
				int k = 3;
				int __expected[] = {4, 5, 6, 10, 11, 12 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxStablePairs(n, c, k); break;
			}
			/*case 6:
			{
				int n = ;
				int c = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxStablePairs(n, c, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int c = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxStablePairs(n, c, k); break;
			}*/
			/*case 8:
			{
				int n = ;
				int c = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxStablePairs(n, c, k); break;
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
