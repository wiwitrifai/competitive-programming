#include <bits/stdc++.h>

using namespace std;

class LandSplitter {
public:
	long long cheapest(int N, int A, int B) {
		long long x = (N + B - 1) / B;
		long long lebih = 1LL * x * B - N;
		if (1LL * x * A > N) return -1;
		long long d = B - A;
		long long ans = 1LL * N * N;
		while (lebih > 0 && x > 0) {
			long long rem = min(d, lebih);
			lebih -= rem;
			long long cur = B - rem;
			ans -= cur * cur;
			--x;
		}
		ans -= 1LL * x * B * B;
		ans /= 2;
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
		cout << "Testing LandSplitter (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1578762004;
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
		LandSplitter _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 12;
				int A = 3;
				int B = 3;
				_expected = 54LL;
				_received = _obj.cheapest(N, A, B); break;
			}
			case 1:
			{
				int N = 10;
				int A = 3;
				int B = 4;
				_expected = 33LL;
				_received = _obj.cheapest(N, A, B); break;
			}
			case 2:
			{
				int N = 47;
				int A = 1;
				int B = 47;
				_expected = 0LL;
				_received = _obj.cheapest(N, A, B); break;
			}
			case 3:
			{
				int N = 70;
				int A = 40;
				int B = 50;
				_expected = -1LL;
				_received = _obj.cheapest(N, A, B); break;
			}
			case 4:
			{
				int N = 47;
				int A = 4;
				int B = 7;
				_expected = 945LL;
				_received = _obj.cheapest(N, A, B); break;
			}
			/*case 5:
			{
				int N = ;
				int A = ;
				int B = ;
				_expected = LL;
				_received = _obj.cheapest(N, A, B); break;
			}*/
			/*case 6:
			{
				int N = ;
				int A = ;
				int B = ;
				_expected = LL;
				_received = _obj.cheapest(N, A, B); break;
			}*/
			/*case 7:
			{
				int N = ;
				int A = ;
				int B = ;
				_expected = LL;
				_received = _obj.cheapest(N, A, B); break;
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
