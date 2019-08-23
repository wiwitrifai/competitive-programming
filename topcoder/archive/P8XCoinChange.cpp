#include <bits/stdc++.h>

using namespace std;

const int N = 40;

class P8XCoinChange {
public:
	map< long long
	int solve(long long coins_sum, vector<long long> values) {
		
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
		cout << "Testing P8XCoinChange (1050.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483086173;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1050.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		P8XCoinChange _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long coins_sum = 4LL;
				long long values[] = {1, 3};
				_expected = 2;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 1:
			{
				long long coins_sum = 4LL;
				long long values[] = {1, 2, 4};
				_expected = 4;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 2:
			{
				long long coins_sum = 3LL;
				long long values[] = {1, 5};
				_expected = 1;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 3:
			{
				long long coins_sum = 11LL;
				long long values[] = {1, 2, 6};
				_expected = 9;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 4:
			{
				long long coins_sum = 1000000000000000000LL;
				long long values[] = {1, 1000000000, 1000000000000000000};
				_expected = 997005;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 5:
			{
				long long coins_sum = 961320341778342848LL;
				long long values[] = {1,2,10,30,150,300,1200,2400,4800,14400,
				                     28800,57600,288000,576000,2304000,9216000,LL
				                     18432000,73728000,221184000,663552000,LL
				                     1327104000,5308416000,31850496000,LL
				                     95551488000,191102976000,764411904000,LL
				                     1528823808000,6115295232000,18345885696000,LL
				                     36691771392000,73383542784000,220150628352000,LL
				                     440301256704000,1320903770112000,3962711310336000,LL
				                     15850845241344000,31701690482688000,95105071448064000,LL
				                     475525357240320000,951050714480640000}LL;
				_expected = 245264;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 6:
			{
				long long coins_sum = 1000000000000000000LL;
				long long values[] = {1, 2};
				_expected = 499989;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			/*case 7:
			{
				long long coins_sum = LL;
				long long values[] = ;
				_expected = ;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}*/
			/*case 8:
			{
				long long coins_sum = LL;
				long long values[] = ;
				_expected = ;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}*/
			/*case 9:
			{
				long long coins_sum = LL;
				long long values[] = ;
				_expected = ;
				_received = _obj.solve(coins_sum, vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
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
