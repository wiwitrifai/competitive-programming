#include <bits/stdc++.h>

using namespace std;

class EllysSki {
public:
	int getMax(vector <int> height) {
		int ans = 1, n = height.size();
		for (int i = 0; i < n; ++i) {
			bool up = 1, down = 1;
			for (int j = i+1; j < n; ++j) {
				if (height[j] < height[j-1])
					down = 0;
				if (height[j] > height[j-1])
					up = 0;
				if (up || down)
					ans = max(ans, j-i+1);
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
		cout << "Testing EllysSki (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556709162;
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
		EllysSki _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int height[] = {3, 4, 11, 6, 2, 2, 2, 5, 7, 7, 10, 8, 5, 8, 1, 4};
				_expected = 7;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 1:
			{
				int height[] = {42, 42, 42};
				_expected = 3;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 2:
			{
				int height[] = {543, 230, 421, 415, 271, 962, 677, 373, 951, 114, 379, 15, 211, 955, 66, 573, 982, 296, 730, 591};
				_expected = 3;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 3:
			{
				int height[] = {50, 77, 24, 86, 98, 84, 42, 70, 88, 78, 73, 17, 76, 68, 64, 65, 40, 77, 33, 87, 11, 23, 78, 20, 8, 74, 44, 95, 94, 78, 27, 88, 71, 40, 11, 98, 82, 85, 79, 89, 31, 67, 41, 61, 71, 62, 74, 77, 86, 36};
				_expected = 4;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			/*case 4:
			{
				int height[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int height[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int height[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
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
