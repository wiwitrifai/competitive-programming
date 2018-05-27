#include <bits/stdc++.h>

using namespace std;

class DayAndNight {
public:
	int minimalCost(vector <int> a, vector <int> b, vector <int> day, vector <int> night, int dayToNight, int nightToDay) {
		
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
		cout << "Testing DayAndNight (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1505063084;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DayAndNight _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0,1};
				int b[] = {1,2};
				int day[] = {10,100,10};
				int night[] = {100,10,100};
				int dayToNight = 1;
				int nightToDay = 2;
				_expected = 33;
				_received = _obj.minimalCost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(day, day+sizeof(day)/sizeof(int)), vector <int>(night, night+sizeof(night)/sizeof(int)), dayToNight, nightToDay); break;
			}
			case 1:
			{
				int a[] = {0,1};
				int b[] = {1,2};
				int day[] = {10,100,10};
				int night[] = {100,10,100};
				int dayToNight = 1000000;
				int nightToDay = 1000000;
				_expected = 120;
				_received = _obj.minimalCost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(day, day+sizeof(day)/sizeof(int)), vector <int>(night, night+sizeof(night)/sizeof(int)), dayToNight, nightToDay); break;
			}
			case 2:
			{
				int a[] = {};
				int b[] = {};
				int day[] = {1,1000,1000,1,1,1000,1000,1000,1,1,1,1};
				int night[] = {1000,1,1,1000,1000,1,1,1,1000,1000,1000,1000};
				int dayToNight = 100;
				int nightToDay = 1000000;
				_expected = 112;
				_received = _obj.minimalCost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(day, day+sizeof(day)/sizeof(int)), vector <int>(night, night+sizeof(night)/sizeof(int)), dayToNight, nightToDay); break;
			}
			case 3:
			{
				int a[] = {1,0,1,2,3,3};
				int b[] = {0,2,2,3,4,5};
				int day[] = {10,100,23,1000,36,178};
				int night[] = {100,99,25,327,38,124};
				int dayToNight = 11;
				int nightToDay = 17;
				_expected = 633;
				_received = _obj.minimalCost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(day, day+sizeof(day)/sizeof(int)), vector <int>(night, night+sizeof(night)/sizeof(int)), dayToNight, nightToDay); break;
			}
			case 4:
			{
				int a[] = {0,0,0,0,0};
				int b[] = {1,1,1,1,1};
				int day[] = {1,2};
				int night[] = {3,4};
				int dayToNight = 5;
				int nightToDay = 6;
				_expected = 3;
				_received = _obj.minimalCost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(day, day+sizeof(day)/sizeof(int)), vector <int>(night, night+sizeof(night)/sizeof(int)), dayToNight, nightToDay); break;
			}
			case 5:
			{
				int a[] = {};
				int b[] = {};
				int day[] = {9876};
				int night[] = {10000};
				int dayToNight = 123456;
				int nightToDay = 1000000;
				_expected = 9876;
				_received = _obj.minimalCost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(day, day+sizeof(day)/sizeof(int)), vector <int>(night, night+sizeof(night)/sizeof(int)), dayToNight, nightToDay); break;
			}
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				int day[] = ;
				int night[] = ;
				int dayToNight = ;
				int nightToDay = ;
				_expected = ;
				_received = _obj.minimalCost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(day, day+sizeof(day)/sizeof(int)), vector <int>(night, night+sizeof(night)/sizeof(int)), dayToNight, nightToDay); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				int day[] = ;
				int night[] = ;
				int dayToNight = ;
				int nightToDay = ;
				_expected = ;
				_received = _obj.minimalCost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(day, day+sizeof(day)/sizeof(int)), vector <int>(night, night+sizeof(night)/sizeof(int)), dayToNight, nightToDay); break;
			}*/
			/*case 8:
			{
				int a[] = ;
				int b[] = ;
				int day[] = ;
				int night[] = ;
				int dayToNight = ;
				int nightToDay = ;
				_expected = ;
				_received = _obj.minimalCost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(day, day+sizeof(day)/sizeof(int)), vector <int>(night, night+sizeof(night)/sizeof(int)), dayToNight, nightToDay); break;
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
