#include <bits/stdc++.h>

using namespace std;

const int N = 2048, mod = 1e9 + 7;

long long dp[N];
long long pm(long long b, long long p) {
	long long ret = 1;
	for (; p; p >>= 1, b = (b * b) % mod)
		if (p & 1) ret = (ret * b) % mod;
	return ret;
}

class ConnectedStates {
public:
	int getSum(vector <int> a) {
		int n = a.size();
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i; j >= 0; j--)
				dp[j+1] = (dp[j+1] + dp[j] * a[i]) % mod;
		}
		long long sum = dp[1], mul = dp[n];
		long long ans = 0, cur = 1;
		for (int i = 0; i <= n-2; i++) {
			long long now = 1;
			now = (now * cur) % mod;
			now = (now * pm(sum, n-2-i)) % mod;
			now = (now * dp[i]) % mod;
			ans = (ans + now) % mod;
			cur = (cur * (n-2-i)) % mod;
		}
		ans = (ans * mul) % mod;
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
		cout << "Testing ConnectedStates (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487330233;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ConnectedStates _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {3, 10};
				_expected = 30;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {2, 2, 2};
				_expected = 96;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {1, 1, 1, 1};
				_expected = 60;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {205659656, 888625810};
				_expected = 118040021;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {2, 1, 2, 1, 2};
				_expected = 27808;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {14204721, 921856626, 804287587, 304606131, 277490604, 
				          310739929, 900757841, 818413665, 155154829, 836327185, 
				          602928524, 26132484, 587345385, 936362852, 92603422};
				_expected = 376924431;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 6:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.getSum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
