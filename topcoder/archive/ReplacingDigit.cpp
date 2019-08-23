#include <bits/stdc++.h>

using namespace std;

class ReplacingDigit {
public:
	int getMaximumStockWorth(vector <int> A, vector <int> D) {
		vector< int > vd[10];
		for (int v : A) {
			int now = v;
			for (int i = 0; i < 10; i++) {
				if (now == 0) break;
				vd[i].push_back(now % 10);
				now /= 10;
			}
		}
		int cur = 8;
		for (int i = 9; i >= 0; i--) {
			sort(vd[i].begin(), vd[i].end());
			for (int j = 0; j < vd[i].size(); j++) {
				while (cur >= 0 && D[cur] == 0) cur--;
				if (cur >= 0 && cur + 1 > vd[i][j]) {
					D[cur]--;
					vd[i][j] = cur+1;
				}
			}
		}
		long long ans = 0, mul = 1;
		for (int i = 0; i < 10; i++) {
			int sum = 0;
			for (int v : vd[i])
				sum += v;
			ans += mul * sum;
			mul *= 10; 
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
		cout << "Testing ReplacingDigit (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491228070;
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
		ReplacingDigit _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {100, 90};
				int D[] = {0, 0, 0, 0, 2, 1, 0, 0, 0};
				_expected = 745;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {9};
				int D[] = {1, 1, 1, 1, 1, 1, 1, 1, 0};
				_expected = 9;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {123456};
				int D[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
				_expected = 988777;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {10, 970019, 1976, 10936, 68750, 756309, 37600, 559601, 6750, 76091, 640, 312, 312, 90, 8870};
				int D[] = {11, 2, 8, 10, 7, 6, 3, 1, 3};
				_expected = 3297500;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int D[] = {111, 111, 111, 111, 111, 111, 111, 111, 111};
				_expected = 198;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				int D[] = ;
				_expected = ;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				int D[] = ;
				_expected = ;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int D[] = ;
				_expected = ;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
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
