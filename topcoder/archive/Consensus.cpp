#include <bits/stdc++.h>

using namespace std;

class Consensus {
public:
	double expectedTime(vector <int> opinions) {
		
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
		cout << "Testing Consensus (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556589680;
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
		Consensus _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int opinions[] = {47};
				_expected = 0.0;
				_received = _obj.expectedTime(vector <int>(opinions, opinions+sizeof(opinions)/sizeof(int))); break;
			}
			case 1:
			{
				int opinions[] = {1, 1};
				_expected = 1.0;
				_received = _obj.expectedTime(vector <int>(opinions, opinions+sizeof(opinions)/sizeof(int))); break;
			}
			case 2:
			{
				int opinions[] = {1, 1, 1};
				_expected = 4.0;
				_received = _obj.expectedTime(vector <int>(opinions, opinions+sizeof(opinions)/sizeof(int))); break;
			}
			case 3:
			{
				int opinions[] = {4, 1};
				_expected = 8.333333333333334;
				_received = _obj.expectedTime(vector <int>(opinions, opinions+sizeof(opinions)/sizeof(int))); break;
			}
			case 4:
			{
				int opinions[] = {3, 2, 5, 1};
				_expected = 84.62698412698413;
				_received = _obj.expectedTime(vector <int>(opinions, opinions+sizeof(opinions)/sizeof(int))); break;
			}
			/*case 5:
			{
				int opinions[] = ;
				_expected = ;
				_received = _obj.expectedTime(vector <int>(opinions, opinions+sizeof(opinions)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int opinions[] = ;
				_expected = ;
				_received = _obj.expectedTime(vector <int>(opinions, opinions+sizeof(opinions)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int opinions[] = ;
				_expected = ;
				_received = _obj.expectedTime(vector <int>(opinions, opinions+sizeof(opinions)/sizeof(int))); break;
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
