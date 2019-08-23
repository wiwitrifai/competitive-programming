#include <bits/stdc++.h>

using namespace std;

class FindingFriend {
public:
	int find(int roomSize, vector <int> leaders, int friendPlace) {
		for (int v : leaders) {
			if (v == friendPlace)
				return 1;
		}
		sort(leaders.begin(), leaders.end());
		int cnt = 0;
		int n = leaders.size() * roomSize;
		for (int i = (int)leaders.size()-1; i >= 0; i--) {
			if (leaders[i] < friendPlace) {
				cnt++;
				int below = n - leaders[i]+1;
				if (below == ((int)leaders.size() - i) * roomSize)
					break;
			}
		}
		return cnt;
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
		cout << "Testing FindingFriend (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487049113;
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
		FindingFriend _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int roomSize = 2;
				int leaders[] = {5,1,2};
				int friendPlace = 4;
				_expected = 2;
				_received = _obj.find(roomSize, vector <int>(leaders, leaders+sizeof(leaders)/sizeof(int)), friendPlace); break;
			}
			case 1:
			{
				int roomSize = 5;
				int leaders[] = {1,2,3,4,5};
				int friendPlace = 4;
				_expected = 1;
				_received = _obj.find(roomSize, vector <int>(leaders, leaders+sizeof(leaders)/sizeof(int)), friendPlace); break;
			}
			case 2:
			{
				int roomSize = 6;
				int leaders[] = {10,5,1,4,2,20};
				int friendPlace = 9;
				_expected = 4;
				_received = _obj.find(roomSize, vector <int>(leaders, leaders+sizeof(leaders)/sizeof(int)), friendPlace); break;
			}
			case 3:
			{
				int roomSize = 1000000000;
				int leaders[] = {1};
				int friendPlace = 700700700;
				_expected = 1;
				_received = _obj.find(roomSize, vector <int>(leaders, leaders+sizeof(leaders)/sizeof(int)), friendPlace); break;
			}
			case 4:
			{
				int roomSize = 2;
				int leaders[] = {3,6,8,1,2};
				int friendPlace = 10;
				_expected = 5;
				_received = _obj.find(roomSize, vector <int>(leaders, leaders+sizeof(leaders)/sizeof(int)), friendPlace); break;
			}
			/*case 5:
			{
				int roomSize = ;
				int leaders[] = ;
				int friendPlace = ;
				_expected = ;
				_received = _obj.find(roomSize, vector <int>(leaders, leaders+sizeof(leaders)/sizeof(int)), friendPlace); break;
			}*/
			/*case 6:
			{
				int roomSize = ;
				int leaders[] = ;
				int friendPlace = ;
				_expected = ;
				_received = _obj.find(roomSize, vector <int>(leaders, leaders+sizeof(leaders)/sizeof(int)), friendPlace); break;
			}*/
			/*case 7:
			{
				int roomSize = ;
				int leaders[] = ;
				int friendPlace = ;
				_expected = ;
				_received = _obj.find(roomSize, vector <int>(leaders, leaders+sizeof(leaders)/sizeof(int)), friendPlace); break;
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
