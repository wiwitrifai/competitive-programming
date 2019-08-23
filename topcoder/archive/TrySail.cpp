#include <bits/stdc++.h>

using namespace std;

int dp[55][256][256][8];
class TrySail {
public:
	int get(vector <int> strength) {
		int n = strength.size();
		memset(dp, 0, sizeof dp);
		dp[0][0][0][0] = 1;
		int all = 0;
		for (int i = 0; i < n; i++) {
			all ^= strength[i];
			for (int x = 0; x < 256; x++) {
				for (int y = 0; y < 256; y++) {
					for (int m = 0; m < 8; m++) {
						if (dp[i][x][y][m] == 0) continue;
						dp[i+1][x ^ strength[i]][y][m | 1] = 1;
						dp[i+1][x][y ^ strength[i]][m | 2] = 1;
						dp[i+1][x][y][m | 4] = 1;
					}
				}
			}
		}
		int ans = 0;
		for (int x = 0; x < 256; x++) {
			for (int y = 0; y < 256; y++) {
				if (dp[n][x][y][7]) {
					ans = max(ans, x + y + (all ^ x ^ y));
				}
			}
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
		cout << "Testing TrySail (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487994664;
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
		TrySail _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int strength[] = {2,3,3};
				_expected = 8;
				_received = _obj.get(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 1:
			{
				int strength[] = {7,3,5,2};
				_expected = 17;
				_received = _obj.get(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 2:
			{
				int strength[] = {13,13,13,13,13,13,13,13};
				_expected = 26;
				_received = _obj.get(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 3:
			{
				int strength[] = {114,51,4,191,9,81,0,89,3};
				_expected = 470;
				_received = _obj.get(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			case 4:
			{
				int strength[] = {108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197};
				_expected = 567;
				_received = _obj.get(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}
			/*case 5:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.get(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.get(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int strength[] = ;
				_expected = ;
				_received = _obj.get(vector <int>(strength, strength+sizeof(strength)/sizeof(int))); break;
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
