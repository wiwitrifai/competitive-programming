#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1 << 11, mod = 1e9 + 9;

int a[NMAX], b[NMAX], tmp[NMAX];
int add[NMAX][30];
int dp[2][NMAX];

void multiple(int n, int x[NMAX], int y[NMAX], int res[NMAX]) {
	for (int i = 0; i <= n; i++) {
		tmp[i] = 0;
		for (int j = 0; j <= i; j++) {
			tmp[i] = (tmp[i] + 1LL * x[j] * y[i-j]) % mod; 
		}
	}
	for (int i = 0; i <= n; i++)
		res[i] = tmp[i];
} 


class LinenCenter {
public:
	int countStrings(string S, int N, int K) {
		int L = S.size();
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < 26; j++) {
				string cur = S.substr(0, i) + char(j + 'a');
				add[i][j] = 0;
				for (int k = 1; k <= i+1; k++)
					if (cur.substr(i+1-k, i+1) == S.substr(0, k))
						add[i][j] = k;
			}
		}
		int c = 0, be = 1;
		memset(dp, 0, sizeof dp);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		dp[0][0] = 1;
		b[0] = 1;
		a[0] = 1;
		for (int i = 1; i <= N + L; i++) {
			swap(c, be);
			memset(dp[c], 0, sizeof dp[c]);
			for (int j = 0; j < L; j++) {
				for (int ch = 0; ch < 26; ch++) {
					int x = add[j][ch];
					if (x >= L) continue;
					dp[c][x] = (dp[c][x] + dp[be][j]) % mod;
					if (x != j+1 && i >= x && i-x <= N)
						b[i-x] = (b[i-x] + dp[be][j]) % mod;
				}
			}
			if (i <= N) {
				a[i] = 0;
				for (int j = 0; j < L; j++)
					a[i] = (a[i] + dp[c][j]) % mod;
			}
		}
		for (; K; K >>= 1, multiple(N, b, b, b))
			if (K & 1) multiple(N, a, b, a);
		int ans = 0;
		for (int i = 0; i <= N; i++)
			ans = (ans + a[i]) % mod;
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
		cout << "Testing LinenCenter (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489334914;
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
		LinenCenter _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "xy";
				int N = 2;
				int K = 1;
				_expected = 2079;
				_received = _obj.countStrings(S, N, K); break;
			}
			case 1:
			{
				string S = "q";
				int N = 2;
				int K = 1;
				_expected = 1926;
				_received = _obj.countStrings(S, N, K); break;
			}
			case 2:
			{
				string S = "ababab";
				int N = 5;
				int K = 4;
				_expected = 527166180;
				_received = _obj.countStrings(S, N, K); break;
			}
			case 3:
			{
				string S = "fgcdx";
				int N = 500;
				int K = 10;
				_expected = 942389748;
				_received = _obj.countStrings(S, N, K); break;
			}
			case 4:
			{
				string S = "ghjhhhgjhjhgjhghghjhjg";
				int N = 8;
				int K = 10000000;
				_expected = 618639712;
				_received = _obj.countStrings(S, N, K); break;
			}
			case 5:
			{
				string S = "pdpfrpfdfdpfdpfdpfpdfldfpfldpfdlfpdlfdpflepflfldpflofpwpldlfpde";
				int N = 999;
				int K = 500000000;
				_expected = 852730493;
				_received = _obj.countStrings(S, N, K); break;
			}
			case 6:
			{
				string S = "a";
				int N = 100;
				int K = 0;
				_expected = 990669582;
				_received = _obj.countStrings(S, N, K); break;
			}
			case 7:
			{
				string S = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
				int N = 1000;
				int K = 1000000000;
				_expected = 286425258;
				_received = _obj.countStrings(S, N, K); break;
			}
			/*case 8:
			{
				string S = ;
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.countStrings(S, N, K); break;
			}*/
			/*case 9:
			{
				string S = ;
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.countStrings(S, N, K); break;
			}*/
			/*case 10:
			{
				string S = ;
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.countStrings(S, N, K); break;
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
