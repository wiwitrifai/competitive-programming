#include <bits/stdc++.h>

using namespace std;

class EllysTimeMachine {
public:
	string getTime(string time) {
		int hh = (time[0]-'0') * 10 + time[1]-'0', mm = (time[3]-'0') * 10 + time[4]-'0';
		int h = mm/5, m = hh * 5;
		m %= 60;
		if (h == 0)
			h = 12;
		time[0] = h/10 + '0';
		time[1] = (h % 10) + '0';
		time[3] = m/10 + '0';
		time[4] = (m % 10) + '0';
		return time;
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
		cout << "Testing EllysTimeMachine (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491220055;
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
		EllysTimeMachine _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string time = "11:20";
				_expected = "04:55";
				_received = _obj.getTime(time); break;
			}
			case 1:
			{
				string time = "02:25";
				_expected = "05:10";
				_received = _obj.getTime(time); break;
			}
			case 2:
			{
				string time = "06:30";
				_expected = "06:30";
				_received = _obj.getTime(time); break;
			}
			case 3:
			{
				string time = "05:55";
				_expected = "11:25";
				_received = _obj.getTime(time); break;
			}
			case 4:
			{
				string time = "03:45";
				_expected = "09:15";
				_received = _obj.getTime(time); break;
			}
			case 5:
			{
				string time = "01:00";
				_expected = "12:05";
				_received = _obj.getTime(time); break;
			}
			/*case 6:
			{
				string time = ;
				_expected = ;
				_received = _obj.getTime(time); break;
			}*/
			/*case 7:
			{
				string time = ;
				_expected = ;
				_received = _obj.getTime(time); break;
			}*/
			/*case 8:
			{
				string time = ;
				_expected = ;
				_received = _obj.getTime(time); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
