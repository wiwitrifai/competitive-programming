#include <bits/stdc++.h>

using namespace std;

class MagicSubset {
public:
	int findBest(vector <int> values) {
		int ma = 0, mi = 0;
		for (int i = 1; i < values.size(); i++)
			if (values[i] > 0)
				ma += values[i];
			else
				mi += values[i];
		return max(ma, -(mi + values[0]));
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
		cout << "Testing MagicSubset (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489234381;
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
		MagicSubset _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int values[] = {1,10,4,-6,3};
				_expected = 17;
				_received = _obj.findBest(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 1:
			{
				int values[] = {3,-5,1,-6};
				_expected = 8;
				_received = _obj.findBest(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 2:
			{
				int values[] = {0,0,0,0,0,0,0,0,0};
				_expected = 0;
				_received = _obj.findBest(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 3:
			{
				int values[] = {-100};
				_expected = 100;
				_received = _obj.findBest(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 4:
			{
				int values[] = {100};
				_expected = 0;
				_received = _obj.findBest(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 5:
			{
				int values[] = {-3,1,-4,1,5,-9,2,6,-5,3,5};
				_expected = 23;
				_received = _obj.findBest(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			/*case 6:
			{
				int values[] = ;
				_expected = ;
				_received = _obj.findBest(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int values[] = ;
				_expected = ;
				_received = _obj.findBest(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int values[] = ;
				_expected = ;
				_received = _obj.findBest(vector <int>(values, values+sizeof(values)/sizeof(int))); break;
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
