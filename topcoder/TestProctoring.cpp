#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 20;

double dp[N], prob[N];
double t[21][N];

class TestProctoring {
public:
	double expectedTime(vector <int> p, vector <int> q) {
		int n = p.size();
		int nmask = 1 << n;
		for (int i = 0; i < n; ++i)
			prob[i] = p[i] * 1.0 / q[i];
		for (int i = 1; i < nmask; ++i) {
			double allfail = 1;
			for (int j = 0; j < n; ++j) {
				t[j][i] = j ? t[j-1][i] : 0;
				if (i & (1 << j)) {
					t[j][i] += t[j][i^(1<<j)] * prob[j];
					allfail *= 1 - prob[j];
				}
			}
			dp[i] = (1 + t[n-1][i]) / (1 - allfail);
			for (int j = 0; j < n; ++j)
				t[j][i] += dp[i] * allfail;
		}
		return dp[nmask-1];
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
		cout << "Testing TestProctoring (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1532049651;
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
		TestProctoring _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {2};
				int q[] = {4};
				_expected = 2.0;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {1,2};
				int q[] = {2,4};
				_expected = 2.6666666666666665;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {3,1,2,4,2,5};
				int q[] = {3,1,2,4,2,5};
				_expected = 1.0;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {1,1,1,1,1,1,1,1};
				int q[] = {1,2,3,4,5,6,7,8};
				_expected = 13.604834665120991;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {2,3,5,7,11,13,17};
				int q[] = {3,5,7,11,13,17,19};
				_expected = 2.6299445065924276;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 5:
			{
				int p[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int q[] = {1000000000,1000000000,1000000000,1000000000,1000000000,
				          1000000000,1000000000,1000000000,1000000000,1000000000,
				          1000000000,1000000000,1000000000,1000000000,1000000000,
				          1000000000,1000000000,1000000000,1000000000,1000000000};
				_expected = 3.597740924491638E9;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			/*case 6:
			{
				int p[] = ;
				int q[] = ;
				_expected = ;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int q[] = ;
				_expected = ;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int p[] = ;
				int q[] = ;
				_expected = ;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
