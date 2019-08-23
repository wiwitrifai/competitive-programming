#include <bits/stdc++.h>

using namespace std;

class OrAndSum {
public:
	string isPossible(vector<long long> pairOr, vector<long long> pairSum) {
		int n = pairSum.size();
		vector<long long> ans(n+1, 0LL);
		for (int i = 0; i < n; i++) {
			long long c = pairSum[i] - pairOr[i];
			if (c < 0) return "Impossible";
			if ((c & pairOr[i]) != c) return "Impossible";
		}
		// cerr << " oke " << endl;
		for (int i = 0; i < 62; i++) {
			int one = 1, zero = 1;
			for (int j = 0; j < n; j++) {
				long long c = pairSum[j] - pairOr[j];
				int none = 0, nzero = 0;
				if (!((pairOr[j] >> i) & 1LL)) {
					nzero = zero;
				}
				else if ((c >> i) & 1LL) {
					none = one;
				}
				else {
					// cerr << "satu " << endl;
					none = zero;
					nzero = one;
				}
				one = none;
				zero = nzero;
				// cerr << " " << c << " " << pairOr[j] << endl;
				// cerr << i << " " << j << " " << zero << " " << one << endl;
			}
			// cerr << i << endl;
			if (!one && !zero)
				return "Impossible";
		}
		return "Possible";
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
		cout << "Testing OrAndSum (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1511884813;
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
		OrAndSum _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long pairOr[] = {7};
				long long pairSum[] = {11};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 1:
			{
				long long pairOr[] = {11};
				long long pairSum[] = {7};
				_expected = "Impossible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 2:
			{
				long long pairOr[] = {3,3,7,5,7};
				long long pairSum[] = {3,5,7,9,11};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 3:
			{
				long long pairOr[] = {1,100,1000};
				long long pairSum[] = {100,1000,10000};
				_expected = "Impossible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 4:
			{
				long long pairOr[] = {261208776456074191,261208776456074191,261208776456074191};
				long long pairSum[] = {333333333333333333,333333333333333333,333333333333333333};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 5:
			{
				long long pairOr[] = {0};
				long long pairSum[] = {0};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			/*case 6:
			{
				long long pairOr[] = ;
				long long pairSum[] = ;
				_expected = ;
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}*/
			/*case 7:
			{
				long long pairOr[] = ;
				long long pairSum[] = ;
				_expected = ;
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}*/
			/*case 8:
			{
				long long pairOr[] = ;
				long long pairSum[] = ;
				_expected = ;
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
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
