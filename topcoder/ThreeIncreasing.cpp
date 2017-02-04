#include <bits/stdc++.h>

using namespace std;

class ThreeIncreasing {
public:
	int minEaten(int a, int b, int c) {
		int mb = min(b, c-1);
		int ans = 0;
		ans += b - mb;
		int ma = min(a, mb-1);
		ans += a- ma;
		if (ma <= 0)
			return -1;
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
		cout << "Testing ThreeIncreasing (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485827698;
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
		ThreeIncreasing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 15;
				int b = 40;
				int c = 22;
				_expected = 19;
				_received = _obj.minEaten(a, b, c); break;
			}
			case 1:
			{
				int a = 5;
				int b = 6;
				int c = 6;
				_expected = 2;
				_received = _obj.minEaten(a, b, c); break;
			}
			case 2:
			{
				int a = 6;
				int b = 1;
				int c = 3000;
				_expected = -1;
				_received = _obj.minEaten(a, b, c); break;
			}
			case 3:
			{
				int a = 6;
				int b = 4;
				int c = 2;
				_expected = -1;
				_received = _obj.minEaten(a, b, c); break;
			}
			case 4:
			{
				int a = 4;
				int b = 2;
				int c = 6;
				_expected = 3;
				_received = _obj.minEaten(a, b, c); break;
			}
			case 5:
			{
				int a = 1;
				int b = 1234;
				int c = 3000;
				_expected = 0;
				_received = _obj.minEaten(a, b, c); break;
			}
			case 6:
			{
				int a = 2789;
				int b = 2400;
				int c = 1693;
				_expected = 1806;
				_received = _obj.minEaten(a, b, c); break;
			}
			/*case 7:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = ;
				_received = _obj.minEaten(a, b, c); break;
			}*/
			/*case 8:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = ;
				_received = _obj.minEaten(a, b, c); break;
			}*/
			/*case 9:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = ;
				_received = _obj.minEaten(a, b, c); break;
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
