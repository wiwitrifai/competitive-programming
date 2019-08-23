#include <bits/stdc++.h>

using namespace std;

class Xylophone {
public:
	int countKeys(vector <int> keys) {
		bool used[8];
		memset(used, 0, sizeof used);
		for (int v : keys) {
			used[v % 7] = 1;
		}		
		int ans = 0;
		for (int i = 0; i < 7; i++)
			ans += used[i];
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
		cout << "Testing Xylophone (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487044982;
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
		Xylophone _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int keys[] = {1,8,3};
				_expected = 2;
				_received = _obj.countKeys(vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			case 1:
			{
				int keys[] = {7,3,2,4,1,5,6};
				_expected = 7;
				_received = _obj.countKeys(vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			case 2:
			{
				int keys[] = {1,8,15};
				_expected = 1;
				_received = _obj.countKeys(vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			case 3:
			{
				int keys[] = {25,1,17,9,8};
				_expected = 4;
				_received = _obj.countKeys(vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			case 4:
			{
				int keys[] = {11,11,11,11,11,11,11,11,11,11,11};
				_expected = 1;
				_received = _obj.countKeys(vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			case 5:
			{
				int keys[] = {50,10,20,30,11,30,24,38,5,2,9};
				_expected = 6;
				_received = _obj.countKeys(vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}
			/*case 6:
			{
				int keys[] = ;
				_expected = ;
				_received = _obj.countKeys(vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int keys[] = ;
				_expected = ;
				_received = _obj.countKeys(vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int keys[] = ;
				_expected = ;
				_received = _obj.countKeys(vector <int>(keys, keys+sizeof(keys)/sizeof(int))); break;
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
