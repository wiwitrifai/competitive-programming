#include <bits/stdc++.h>

using namespace std;

class SquadConstructor2 {
public:
	int teamget(int n, int k, vector <int> friends) {
		
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
		cout << "Testing SquadConstructor2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521304606;
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
		SquadConstructor2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int k = 4;
				int friends[] = {0,1,2,3};
				_expected = 8;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 3;
				int k = 4;
				int friends[] = {0,1,2,3,5};
				_expected = 14;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 8;
				int k = 4;
				int friends[] = {0,1,2,3,7};
				_expected = 19;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 8;
				int k = 4;
				int friends[] = {3,4,7,8,9,10,11,15,16,17,18,19,20,21,23,26,27,28,29,33,35,37,41,42,43,45,47,48,49,53,54,55,56,57,58,60,61,62,64,66,67,68,72,74,75,78,80,81,82,83,87,89,90,91,93,94,95,98,99,100,101,103,105,108,111,112,113,115,118,119,121,122,123,125,127,128,129,130,131,137,143,144,147,148,151,152,155,156,160,163,167,169,171,172,173,178,179,180,182,186,188,190,192,193,194,195,196,198,199,204,207,208,212,213,215,217,219,220,221,225,228,231,233,237,240,243,244,245,246,247,249,251,252,254};
				_expected = 100;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 3;
				int k = 5;
				int friends[] = {0,1,2,3,5};
				_expected = 14;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int k = ;
				int friends[] = ;
				_expected = ;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				int friends[] = ;
				_expected = ;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				int friends[] = ;
				_expected = ;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
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
