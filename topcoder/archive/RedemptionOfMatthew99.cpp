#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> point;

class RedemptionOfMatthew99 {
public:
	double bestTraversal(vector <int> X1, vector <int> Y1, vector <int> X2, vector <int> Y2) {
		
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
		cout << "Testing RedemptionOfMatthew99 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1502760527;
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
		RedemptionOfMatthew99 _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X1[] = {0, 1};
				int Y1[] = {1, 1};
				int X2[] = {0, 1};
				int Y2[] = {-1, -1};
				_expected = 6.23606797749979;
				_received = _obj.bestTraversal(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 1:
			{
				int X1[] = {0, 1, 2};
				int Y1[] = {2, 1, 2};
				int X2[] = {0, 1, 2};
				int Y2[] = {-2, -1, -2};
				_expected = 16.32455532033676;
				_received = _obj.bestTraversal(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 2:
			{
				int X1[] = {-2, 2};
				int Y1[] = {1, 5};
				int X2[] = {-2, 2};
				int Y2[] = {-1, -4};
				_expected = 15.614226788360828;
				_received = _obj.bestTraversal(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 3:
			{
				int X1[] = {-2, 1, 2};
				int Y1[] = {1, 2, 6};
				int X2[] = {-3, -2, -1};
				int Y2[] = {-1, -1, -2};
				_expected = -1.0;
				_received = _obj.bestTraversal(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			case 4:
			{
				int X1[] = {331, 667, 2926, 3285};
				int Y1[] = {536, 375, 375, 596};
				int X2[] = {760, 1291, 2251, 2939};
				int Y2[] = {-615, -428, -428, -636};
				_expected = 8698.860039486546;
				_received = _obj.bestTraversal(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int X1[] = ;
				int Y1[] = ;
				int X2[] = ;
				int Y2[] = ;
				_expected = ;
				_received = _obj.bestTraversal(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int X1[] = ;
				int Y1[] = ;
				int X2[] = ;
				int Y2[] = ;
				_expected = ;
				_received = _obj.bestTraversal(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int X1[] = ;
				int Y1[] = ;
				int X2[] = ;
				int Y2[] = ;
				_expected = ;
				_received = _obj.bestTraversal(vector <int>(X1, X1+sizeof(X1)/sizeof(int)), vector <int>(Y1, Y1+sizeof(Y1)/sizeof(int)), vector <int>(X2, X2+sizeof(X2)/sizeof(int)), vector <int>(Y2, Y2+sizeof(Y2)/sizeof(int))); break;
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
