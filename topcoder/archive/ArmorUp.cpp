#include <bits/stdc++.h>

using namespace std;

class ArmorUp {
public:
	double minimalDamage(int maxHP, int currentHP, int k) {
		double m = maxHP, c = currentHP;
		double le = 0, ri = (double)2 * m * c/(m + c);
		if (k == 1)
			return ri;
		for (int it = 0; it < 100000; it++) {
			double d = (le + ri) / 2.0;
			double a = d * m / (2.0 * m - d), r = 2 * m / (2 * m - d);
			double cc = a * (pow(r, k) - 1) / (r-1);
			if (cc < c)
				le = d;
			else
				ri = d;
		}		
		return ri;
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
		cout << "Testing ArmorUp (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1505059204;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ArmorUp _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int maxHP = 100;
				int currentHP = 100;
				int k = 1;
				_expected = 100.0;
				_received = _obj.minimalDamage(maxHP, currentHP, k); break;
			}
			case 1:
			{
				int maxHP = 100;
				int currentHP = 20;
				int k = 1;
				_expected = 33.333333333333336;
				_received = _obj.minimalDamage(maxHP, currentHP, k); break;
			}
			case 2:
			{
				int maxHP = 100;
				int currentHP = 100;
				int k = 2;
				_expected = 58.57864376269048;
				_received = _obj.minimalDamage(maxHP, currentHP, k); break;
			}
			case 3:
			{
				int maxHP = 1000000000;
				int currentHP = 987654321;
				int k = 1234;
				_expected = 1113069.7492973686;
				_received = _obj.minimalDamage(maxHP, currentHP, k); break;
			}
			/*case 4:
			{
				int maxHP = ;
				int currentHP = ;
				int k = ;
				_expected = ;
				_received = _obj.minimalDamage(maxHP, currentHP, k); break;
			}*/
			/*case 5:
			{
				int maxHP = ;
				int currentHP = ;
				int k = ;
				_expected = ;
				_received = _obj.minimalDamage(maxHP, currentHP, k); break;
			}*/
			/*case 6:
			{
				int maxHP = ;
				int currentHP = ;
				int k = ;
				_expected = ;
				_received = _obj.minimalDamage(maxHP, currentHP, k); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
