#include <bits/stdc++.h>

using namespace std;

long long C[100][100];

class FourLamps {
public:
	long long count(string init, int k) {
		for (int i = 0; i < 100; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j  = 1; j < i; j++)
				C[i][j] = C[i-1][j-1] + C[i-1][j];
			long long tot = 0;
			for (int j = 0; j <= i; j++)

		}
		int cnt = 0, n = init.size();
		for (int i = 0; i + 4 <= n; i++) {
			int one = 0;
			for (int j = 0; j < 4; j++)
				one += init[i+j] == '1';
			if (one == 1 || one == 3)
				cnt++;
		}
		long long ans = 0;
		for (int i = 0; i <= min(cnt+1, k); i++) {
			if (i <= cnt) {
				ans += C[cnt][i] * (i+1);
				cerr << ans << " - " << endl;
			}
			if (i >= 2 && cnt-1 >= i-2 && cnt-1 >= 0) {
				ans += C[cnt-1][i-2] * (i-1);
				cerr << ans << " 0 " << endl;
			}
		}
		cerr << cnt << " " << k << endl;
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
		cout << "Testing FourLamps (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495298415;
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
		FourLamps _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string init = "0001";
				int k = 2;
				_expected = 4LL;
				_received = _obj.count(init, k); break;
			}
			case 1:
			{
				string init = "0001";
				int k = 1000000000;
				_expected = 4LL;
				_received = _obj.count(init, k); break;
			}
			case 2:
			{
				string init = "1010";
				int k = 100;
				_expected = 1LL;
				_received = _obj.count(init, k); break;
			}
			case 3:
			{
				string init = "000111";
				int k = 3;
				_expected = 12LL;
				_received = _obj.count(init, k); break;
			}
			case 4:
			{
				string init = "00000010000";
				int k = 5;
				_expected = 58LL;
				_received = _obj.count(init, k); break;
			}
			case 5:
			{
				string init = "10101100101010001011000100101000100001101";
				int k = 58;
				_expected = 100256132848LL;
				_received = _obj.count(init, k); break;
			}
			/*case 6:
			{
				string init = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(init, k); break;
			}*/
			/*case 7:
			{
				string init = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(init, k); break;
			}*/
			/*case 8:
			{
				string init = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(init, k); break;
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
