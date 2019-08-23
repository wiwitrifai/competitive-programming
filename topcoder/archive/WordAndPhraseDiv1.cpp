#include <bits/stdc++.h>

using namespace std;

const int N = 1024, mod = 1e9 + 7;

int dp[N][2];

class WordAndPhraseDiv1 {
public:
	int findNumberOfPhrases(string w) {
		int n = w.size();
		dp[n][0] = 1;
		dp[n][1] = 0;
		for (int i = n-1; i >= 0; --i) {
			if (w[i] >= '0' && w[i] <= '9') {
				dp[i][0] = (dp[i+1][0] + dp[i+1][1]) % mod;
				dp[i][1] = 0;
			}
			else if (w[i] == '_') {
				dp[i][1] = (dp[i+1][0] + dp[i+1][1]) % mod;
				dp[i][0] = dp[i+1][1];
			}
			else {
				dp[i][1] = (dp[i+1][0] + dp[i+1][1]) % mod;
				dp[i][0] = 0;
			}
		}
		return dp[0][1];
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
		cout << "Testing WordAndPhraseDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1527318241;
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
		WordAndPhraseDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string w = "tco_topcoder_com";
				_expected = 4;
				_received = _obj.findNumberOfPhrases(w); break;
			}
			case 1:
			{
				string w = "tcotopcodercom";
				_expected = 1;
				_received = _obj.findNumberOfPhrases(w); break;
			}
			case 2:
			{
				string w = "_tco18_admin_id_is_secret";
				_expected = 16;
				_received = _obj.findNumberOfPhrases(w); break;
			}
			case 3:
			{
				string w = "____";
				_expected = 3;
				_received = _obj.findNumberOfPhrases(w); break;
			}
			case 4:
			{
				string w = "a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0_a1_a2_a3_a4_a5_a6_a7_a8_a9_a0";
				_expected = 73741817;
				_received = _obj.findNumberOfPhrases(w); break;
			}
			case 5:
			{
				string w = "d0_0b";
				_expected = 1;
				_received = _obj.findNumberOfPhrases(w); break;
			}
			/*case 6:
			{
				string w = ;
				_expected = ;
				_received = _obj.findNumberOfPhrases(w); break;
			}*/
			/*case 7:
			{
				string w = ;
				_expected = ;
				_received = _obj.findNumberOfPhrases(w); break;
			}*/
			/*case 8:
			{
				string w = ;
				_expected = ;
				_received = _obj.findNumberOfPhrases(w); break;
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
