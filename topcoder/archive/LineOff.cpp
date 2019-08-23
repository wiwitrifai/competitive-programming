#include <bits/stdc++.h>

using namespace std;

class LineOff {
public:
	int movesToDo(string points) {
		string cur = points;		
		while (1) {
			string nx = "";
			for (int i = 0; i < cur.size(); ++i) {
				if (i + 1 < cur.size() && cur[i] == cur[i+1]) {
					++i;
				}
				else
					nx.push_back(cur[i]);
			}
			if (cur.size() == nx.size()) break;
			cur.swap(nx);
		}
		return ((int)points.size() - (int)cur.size()) / 2;
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
		cout << "Testing LineOff (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1525347766;
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
		LineOff _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string points = "abba";
				_expected = 2;
				_received = _obj.movesToDo(points); break;
			}
			case 1:
			{
				string points = "zwwwzffw";
				_expected = 2;
				_received = _obj.movesToDo(points); break;
			}
			case 2:
			{
				string points = "rrrrrrr";
				_expected = 3;
				_received = _obj.movesToDo(points); break;
			}
			case 3:
			{
				string points = "dfghj";
				_expected = 0;
				_received = _obj.movesToDo(points); break;
			}
			case 4:
			{
				string points = "wasitacarooracatisaw";
				_expected = 10;
				_received = _obj.movesToDo(points); break;
			}
			/*case 5:
			{
				string points = ;
				_expected = ;
				_received = _obj.movesToDo(points); break;
			}*/
			/*case 6:
			{
				string points = ;
				_expected = ;
				_received = _obj.movesToDo(points); break;
			}*/
			/*case 7:
			{
				string points = ;
				_expected = ;
				_received = _obj.movesToDo(points); break;
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
