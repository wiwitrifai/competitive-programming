#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

void add(int x, int y, int z) {
	ans.push_back(x);
	ans.push_back(y);
	ans.push_back(z);
}
class CubesOnATable {
public:
	vector <int> placeCubes(int surface) {
		vector<int> mi = {8, 5, 10, 11};
		int r = surface % 4;
		ans.clear();		
		if (mi[r] > surface)
			return vector<int>();
		add(0, 0, 0);
		if (r == 0) {
			add(0, 1, 0);
		}
		else if (r == 2) {
			add(0, 2, 0);
		}
		else if (r == 3) {
			add(0, 1, 0);
			add(1, 0, 0);
		}
		int sisa = surface - mi[r];
		assert((sisa % 4) == 0);
		sisa /= 4;
		for (int i = 0; i < sisa; ++i)
			add(0, 0, i+1);
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
		cout << "Testing CubesOnATable (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1535212830;
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
		CubesOnATable _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int surface = 5;
				int __expected[] = {0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.placeCubes(surface); break;
			}
			case 1:
			{
				int surface = 20;
				int __expected[] = {5, 5, 0, 5, 5, 1, 5, 6, 0, 5, 6, 1, 6, 5, 0, 6, 5, 1, 6, 6, 0, 6, 6, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.placeCubes(surface); break;
			}
			case 2:
			{
				int surface = 25;
				int __expected[] = {0, 0, 0, 2, 2, 0, 4, 4, 0, 6, 6, 0, 8, 8, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.placeCubes(surface); break;
			}
			case 3:
			{
				int surface = 32;
				int __expected[] = {1, 3, 0, 2, 3, 0, 2, 3, 1, 3, 3, 0, 3, 3, 1, 3, 3, 2, 4, 3, 0, 4, 3, 1, 4, 3, 2, 4, 3, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.placeCubes(surface); break;
			}
			/*case 4:
			{
				int surface = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.placeCubes(surface); break;
			}*/
			/*case 5:
			{
				int surface = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.placeCubes(surface); break;
			}*/
			/*case 6:
			{
				int surface = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.placeCubes(surface); break;
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
