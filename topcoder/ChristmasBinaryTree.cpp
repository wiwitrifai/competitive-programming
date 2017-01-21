#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 105;

long long dp[2][N][N];

class ChristmasBinaryTree {
public:
	int count(long long depth, vector <int> left, vector <int> right) {
		long long ans[N][N], tmp[N][N];
		int n = left.size();
		if (depth == 1)
			return 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[0][i][j] = 0, ans[i][j] = 0;
		for (int i = 0; i < n; i++) {
			dp[0][i][left[i]]++;
			dp[0][i][right[i]]++;
			ans[i][i] = 1;
		}
		int c = 0, b = 1;
		depth--;
		for (long long mask = 1; mask <= depth; mask <<= 1) {
			if (mask & depth) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						long long & cur = tmp[i][j];
						cur = 0;
						for (int k = 0; k < n; k++) {
							cur = (cur + ans[i][k] * dp[c][k][j]) % mod;
						}
					}
				}
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						ans[i][j] = tmp[i][j];
			}
			swap(c, b);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					long long & cur = dp[c][i][j];
					cur = 0;
					for (int k = 0; k < n; k++) {
						cur = (cur + dp[b][i][k] * dp[b][k][j]) % mod;
					}
				}
			}
		}
		long long ret = 0;
		for (int i = 0; i < n; i++) {
			long long tmp = 0;
			for (int j = 0; j < n; j++) {
				tmp = (tmp + ans[i][j] * ans[i][j]) % mod;
				// cerr << ans[i][j] << " ";
			}
			// cerr << endl;
			if (ret < tmp)
				ret = tmp;
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
		cout << "Testing ChristmasBinaryTree (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484993581;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ChristmasBinaryTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long depth = 1LL;
				int left[] = {0};
				int right[] = {0};
				_expected = 1;
				_received = _obj.count(depth, vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
			}
			case 1:
			{
				long long depth = 3LL;
				int left[] = {0,1,2};
				int right[] = {0,1,2};
				_expected = 16;
				_received = _obj.count(depth, vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
			}
			case 2:
			{
				long long depth = 4LL;
				int left[] = {1,2,0};
				int right[] = {2,0,1};
				_expected = 22;
				_received = _obj.count(depth, vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
			}
			case 3:
			{
				long long depth = 4LL;
				int left[] = {0,2,2};
				int right[] = {1,1,2};
				_expected = 64;
				_received = _obj.count(depth, vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
			}
			case 4:
			{
				long long depth = 1000000000000LL;
				int left[] = {0,1,2,3};
				int right[] = {1,1,2,2};
				_expected = 465080044;
				_received = _obj.count(depth, vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
			}
			/*case 5:
			{
				long long depth = LL;
				int left[] = ;
				int right[] = ;
				_expected = ;
				_received = _obj.count(depth, vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				long long depth = LL;
				int left[] = ;
				int right[] = ;
				_expected = ;
				_received = _obj.count(depth, vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				long long depth = LL;
				int left[] = ;
				int right[] = ;
				_expected = ;
				_received = _obj.count(depth, vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int))); break;
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
