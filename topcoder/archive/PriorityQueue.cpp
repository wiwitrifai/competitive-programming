#include <bits/stdc++.h>

using namespace std;

class PriorityQueue {
public:
	int findAnnoyance(string S, vector <int> a) {
		int ans = 0;
		int n = S.size();
		for (int i = 0; i < n; i++) {
      if (S[i] == 'b') {
        for (int j = 0; j < i; j++)
        	ans += a[j];
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
		cout << "Testing PriorityQueue (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488175388;
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
		PriorityQueue _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "bbbbb";
				int a[] = {1,1,1,1,1};
				_expected = 10;
				_received = _obj.findAnnoyance(S, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				string S = "bee";
				int a[] = {50,40,30};
				_expected = 0;
				_received = _obj.findAnnoyance(S, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				string S = "ebbe";
				int a[] = {5,2,11,1};
				_expected = 12;
				_received = _obj.findAnnoyance(S, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				string S = "bbeebeebeeeebbb";
				int a[] = {58,517,301,524,79,375,641,152,810,778,222,342,911,313,336};
				_expected = 20485;
				_received = _obj.findAnnoyance(S, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 4:
			{
				string S = ;
				int a[] = ;
				_expected = ;
				_received = _obj.findAnnoyance(S, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				string S = ;
				int a[] = ;
				_expected = ;
				_received = _obj.findAnnoyance(S, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string S = ;
				int a[] = ;
				_expected = ;
				_received = _obj.findAnnoyance(S, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
