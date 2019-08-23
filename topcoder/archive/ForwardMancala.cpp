#include <bits/stdc++.h>

using namespace std;

void move(vector< int > & v, int id) {
	int now = v[id];
	v[id] = 0;
	while (now--) {
		id++;
		if (id >= v.size()) id -= v.size();
		v[id]++;
	}
}

class ForwardMancala {
public:
	vector <int> findMoves(vector <int> start) {
		vector< int > ans;
		bool ok = 1;
		while (ok) {
			ok = 0;
			for (int i = 0; i+1 < start.size(); i++) if (start[i] > 0) {
				move(start, i);
				ans.push_back(i);
				ok = 1;
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
		cout << "Testing ForwardMancala (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489234555;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ForwardMancala _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int start[] = {6,1,0,1};
				int __expected[] = {1, 2, 3, 1, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			case 1:
			{
				int start[] = {0,10,0,0,0};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			case 2:
			{
				int start[] = {0,1,0,1,0,1};
				int __expected[] = {3, 4, 1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			case 3:
			{
				int start[] = {5,0,0,1,3,0,2,0};
				int __expected[] = {3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			case 4:
			{
				int start[] = {10,10,10,10,10,10,10,10,10,10};
				int __expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}
			/*case 5:
			{
				int start[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int start[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int start[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMoves(vector <int>(start, start+sizeof(start)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
