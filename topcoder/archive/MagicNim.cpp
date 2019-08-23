#include <bits/stdc++.h>

using namespace std;

class MagicNim {
public:
	string findWinner(vector <int> arr) {
		int xr = 0, mx = 0;
		for (int v : arr)
			xr ^= v, mx = max(mx, v);
		if (xr == 0 || mx == 1)
			return "Alice";
		int one = xr & 1;
		xr >>= 1;
		mx >>= 1;
		if (mx >= 2 && xr == 0)
			return "Bob";
		if (mx <= 1 && xr == 1)
			return one ? "Alice" : "Bob";
		return "Alice";
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
		cout << "Testing MagicNim (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489114621;
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
		MagicNim _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int arr[] = {1};
				_expected = "Alice";
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}
			case 1:
			{
				int arr[] = {2};
				_expected = "Bob";
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}
			case 2:
			{
				int arr[] = {1,1,1,1};
				_expected = "Alice";
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}
			case 3:
			{
				int arr[] = {1,1,1,1,1};
				_expected = "Alice";
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}
			case 4:
			{
				int arr[] = {1,3};
				_expected = "Bob";
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}
			case 5:
			{
				int arr[] = {4,4,2};
				_expected = "Alice";
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}
			case 6:
			{
				int arr[] = {50,50,50,50,50,50,50,50,50,50};
				_expected = "Alice";
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}
			case 7:
			{
				int arr[] = {6,7};
				_expected = "Bob";
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}
			case 8:
			{
				int arr[] = {2, 2, 2, 1};
				_expected = "Alice";
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}
			/*case 9:
			{
				int arr[] = ;
				_expected = ;
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int arr[] = ;
				_expected = ;
				_received = _obj.findWinner(vector <int>(arr, arr+sizeof(arr)/sizeof(int))); break;
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
