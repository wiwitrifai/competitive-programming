#include <bits/stdc++.h>

using namespace std;

const int N = 22;
int sum[N];

class Revmatching {
public:
	int smallest(vector <string> A) {
		int n = A.size();
		int ans = 9 * n * n;
		for (int mask = 1; mask < (1<<n); mask++) {
			memset(sum, 0, sizeof sum);
			for (int i = 0; i < n; i++) if (mask & (1<<i)) {
				for (int j = 0; j < n; j++)
					sum[j] += A[i][j] - '0';
			}
			sort(sum, sum+n);
			reverse(sum, sum+n);
			int now = 0;
			for (int i = __builtin_popcount(mask)-1; i < n; i++)
				now += sum[i];
			ans = min(ans, now);
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
		cout << "Testing Revmatching (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491195620;
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
		Revmatching _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A[] = {"1"};
				_expected = 1;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 1:
			{
				string A[] = {"0"};
				_expected = 0;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 2:
			{
				string A[] = {"44","44"};
				_expected = 8;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 3:
			{
				string A[] = {"861","870","245"};
				_expected = 6;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 4:
			{
				string A[] = {"01000","30200","11102","10001","11001"};
				_expected = 0;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 5:
			{
				string A[] = {"0111101100","0001101001","1001001000","1000100001","0110011111","0011110100","1000001100","0001100000","1000100001","0101110010"};
				_expected = 1;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			/*case 6:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
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
