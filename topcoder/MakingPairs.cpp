#include <bits/stdc++.h>

using namespace std;

class MakingPairs {
public:
	int get(vector <int> card) {
		int ans = 0;
		for (int v : card)
			ans += v /2;
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
		cout << "Testing MakingPairs (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487993675;
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
		MakingPairs _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int card[] = {2,2,2};
				_expected = 3;
				_received = _obj.get(vector <int>(card, card+sizeof(card)/sizeof(int))); break;
			}
			case 1:
			{
				int card[] = {1,1,1};
				_expected = 0;
				_received = _obj.get(vector <int>(card, card+sizeof(card)/sizeof(int))); break;
			}
			case 2:
			{
				int card[] = {5};
				_expected = 2;
				_received = _obj.get(vector <int>(card, card+sizeof(card)/sizeof(int))); break;
			}
			case 3:
			{
				int card[] = {43,23,10,39,39,22,22,0,3,4,3,2};
				_expected = 102;
				_received = _obj.get(vector <int>(card, card+sizeof(card)/sizeof(int))); break;
			}
			case 4:
			{
				int card[] = {0};
				_expected = 0;
				_received = _obj.get(vector <int>(card, card+sizeof(card)/sizeof(int))); break;
			}
			/*case 5:
			{
				int card[] = ;
				_expected = ;
				_received = _obj.get(vector <int>(card, card+sizeof(card)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int card[] = ;
				_expected = ;
				_received = _obj.get(vector <int>(card, card+sizeof(card)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int card[] = ;
				_expected = ;
				_received = _obj.get(vector <int>(card, card+sizeof(card)/sizeof(int))); break;
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
