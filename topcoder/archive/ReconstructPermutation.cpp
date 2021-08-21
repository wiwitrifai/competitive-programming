#include <bits/stdc++.h>

using namespace std;

struct ReconstructPermutation {
	vector <int> reconstruct(int N, vector <int> partial) {
		vector<int> ada(N+1, 0);
		for (int x : partial) {
			ada[x] = 1;
		}
		vector<int> ans;
		int now = 0;
		for (int x : partial) {
			while (now < x) {
				while (now < x && ada[now]) ++now;
				if (now < x) {
					ans.push_back(now++);
				}
			}
			ans.push_back(x);
			now += now == x;
		}
		while (now < N) {
			ans.push_back(now++);
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
		cout << "Testing ReconstructPermutation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1629562007;
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
		ReconstructPermutation _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 8;
				int partial[] = {1, 3, 5, 7};
				int __expected[] = {0, 1, 2, 3, 4, 5, 6, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(N, vector <int>(partial, partial+sizeof(partial)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 5;
				int partial[] = {3, 1, 4, 0, 2};
				int __expected[] = {3, 1, 4, 0, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(N, vector <int>(partial, partial+sizeof(partial)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 5;
				int partial[] = {0, 3, 1};
				int __expected[] = {0, 2, 3, 1, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(N, vector <int>(partial, partial+sizeof(partial)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 8;
				int partial[] = {};
				int __expected[] = {0, 1, 2, 3, 4, 5, 6, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(N, vector <int>(partial, partial+sizeof(partial)/sizeof(int))); break;
			}
			/*case 4:
			{
				int N = ;
				int partial[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(N, vector <int>(partial, partial+sizeof(partial)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int N = ;
				int partial[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(N, vector <int>(partial, partial+sizeof(partial)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int partial[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(N, vector <int>(partial, partial+sizeof(partial)/sizeof(int))); break;
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
