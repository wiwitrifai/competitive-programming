#include <bits/stdc++.h>

using namespace std;


const int N = 55, mod = 1e9 + 7;
int dp[N];
class ThreeSameLetters {
public:
	int countStrings(int L, int S) {
		dp[0] = 1;
		dp[1] = S-1;
		for (int i = 1; i <= L; ++i) {
			dp[i] = 1LL * (S-1) * (dp[i-1] + dp[i-2]) % mod;
		}
		long long ans = 0;
		for (int i = 0; i+3 <= L; ++i) {
			int sisa = L - i - 3;
			ans = (ans + 1LL * dp[i] * dp[sisa]) % mod;
		}
		ans = 1LL * ans * S % mod;
		if (ans < 0) ans += mod;
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
		cout << "Testing ThreeSameLetters (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1525346561;
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
		ThreeSameLetters _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 3;
				int S = 7;
				_expected = 7;
				_received = _obj.countStrings(L, S); break;
			}
			case 1:
			{
				int L = 4;
				int S = 2;
				_expected = 4;
				_received = _obj.countStrings(L, S); break;
			}
			case 2:
			{
				int L = 2;
				int S = 17;
				_expected = 0;
				_received = _obj.countStrings(L, S); break;
			}
			case 3:
			{
				int L = 10;
				int S = 11;
				_expected = 410199993;
				_received = _obj.countStrings(L, S); break;
			}
			/*case 4:
			{
				int L = ;
				int S = ;
				_expected = ;
				_received = _obj.countStrings(L, S); break;
			}*/
			/*case 5:
			{
				int L = ;
				int S = ;
				_expected = ;
				_received = _obj.countStrings(L, S); break;
			}*/
			/*case 6:
			{
				int L = ;
				int S = ;
				_expected = ;
				_received = _obj.countStrings(L, S); break;
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
