#include <bits/stdc++.h>

using namespace std;

long long get(long long up) {
	if (up < 11)
		return 0;
	long long ret = 10LL * (up / 100), now = ret * 10;
	if (ret) ret--;
  for (int i = 0; i < 10; i++) {
    if (now + 11LL * i <= up && now + 11LL * i > 10)
    	ret++;
  }
  return ret;
}
class Dubs {
public:
	long long count(long long L, long long R) {
		return get(R) - get(L-1);
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
		cout << "Testing Dubs (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488175624;
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
		Dubs _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long L = 10LL;
				long long R = 10LL;
				_expected = 0LL;
				_received = _obj.count(L, R); break;
			}
			case 1:
			{
				long long L = 10LL;
				long long R = 20LL;
				_expected = 1LL;
				_received = _obj.count(L, R); break;
			}
			case 2:
			{
				long long L = 49LL;
				long long R = 101LL;
				_expected = 6LL;
				_received = _obj.count(L, R); break;
			}
			case 3:
			{
				long long L = 1111111LL;
				long long R = 111111111LL;
				_expected = 11000001LL;
				_received = _obj.count(L, R); break;
			}
			case 4:
			{
				long long L = 91750002841LL;
				long long R = 91751522033LL;
				_expected = 151920LL;
				_received = _obj.count(L, R); break;
			}
			/*case 5:
			{
				long long L = LL;
				long long R = LL;
				_expected = LL;
				_received = _obj.count(L, R); break;
			}*/
			/*case 6:
			{
				long long L = LL;
				long long R = LL;
				_expected = LL;
				_received = _obj.count(L, R); break;
			}*/
			/*case 7:
			{
				long long L = LL;
				long long R = LL;
				_expected = LL;
				_received = _obj.count(L, R); break;
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
