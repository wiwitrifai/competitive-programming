#include <bits/stdc++.h>

using namespace std;

class LittleElephantAndIntervalsDiv2 {
public:
	int getNumber(int M, vector <int> L, vector <int> R) {
		vector< int > used(M+1, 0);
		int ans = 1;
		for (int i = (int)L.size()- 1; i >= 0; i--) {
			bool change = false;
			for (int j = L[i]; j <= R[i]; j++) {
				change |= (used[j] == 0);
				used[j] = 1;
			}
			if (change)
				ans <<= 1;
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
		cout << "Testing LittleElephantAndIntervalsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483052777;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LittleElephantAndIntervalsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int M = 4;
				int L[] = {1, 2, 3};
				int R[] = {1, 2, 3};
				_expected = 8;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 1:
			{
				int M = 3;
				int L[] = {1, 1, 2};
				int R[] = {3, 1, 3};
				_expected = 4;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 2:
			{
				int M = 100;
				int L[] = {47};
				int R[] = {74};
				_expected = 2;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 3:
			{
				int M = 100;
				int L[] = {10, 20, 50};
				int R[] = {20, 50, 100};
				_expected = 8;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 4:
			{
				int M = 42;
				int L[] = {5, 23, 4, 1, 15, 2, 22, 26, 13, 16};
				int R[] = {30, 41, 17, 1, 21, 6, 28, 30, 15, 19};
				_expected = 512;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			/*case 5:
			{
				int M = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int M = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int M = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.getNumber(M, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
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
