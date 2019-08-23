#include <bits/stdc++.h>

using namespace std;

class Hyperbox {
public:
	int count(int volume) {
		if (volume & 1)
			return 0;		
		volume /= 2;
		int ans = 0;
		for (int c = 1; c <= volume; ++c) {
			long long cc = c * c;
			if (cc >= volume) break;
			for (int b = 1; b <= c; ++b) {
				long long bcc = b * cc;
				if (bcc >= volume) break;
				long long bc = b * c;
				for (int a = 1; a <= b; ++a) {
					long long abc = a * bc;
					long long abc2 = (bc + 1LL * a * (b + c));
					long long s = volume - abc;
					if (s < 0)
						break;
					long long d = s / abc2;
					if (d < c) break;
					if (s % abc2) continue;
					if (d >= c)
						++ans;
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
		cout << "Testing Hyperbox (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1550800967;
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
		Hyperbox _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int volume = 8;
				_expected = 1;
				_received = _obj.count(volume); break;
			}
			case 1:
			{
				int volume = 1234567;
				_expected = 0;
				_received = _obj.count(volume); break;
			}
			case 2:
			{
				int volume = 120;
				_expected = 3;
				_received = _obj.count(volume); break;
			}
			case 3:
			{
				int volume = 123456;
				_expected = 52;
				_received = _obj.count(volume); break;
			}
			case 4:
			{
				int volume = 200000000;
				_expected = 1414;
				_received = _obj.count(volume); break;
			}
			/*case 5:
			{
				int volume = ;
				_expected = ;
				_received = _obj.count(volume); break;
			}*/
			/*case 6:
			{
				int volume = ;
				_expected = ;
				_received = _obj.count(volume); break;
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
