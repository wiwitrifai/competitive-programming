#include <bits/stdc++.h>

using namespace std;

int gcd(int u, int v) {
	return u ? gcd(v % u, u) : v;
}

class DivisibleSetDiv2 {
public:
	string isPossible(vector <int> b) {
		if (b.size() == 1)
			return "Possible";
		set < pair<pair< int, int  >, int > > st;
		for (int v : b) {
			st.insert(make_pair(make_pair(v, v), st.size()));
			if (v == 1)
				return "Impossible";
		}
		bool ok = 1;
		int p = b.size();
		while (ok) {
			auto it = st.begin();
			if (it->first.first >= p)
				break;
			int g = 10000;
			for (auto val : st) {
				g = min(g, val.first.first/val.first.second);
			}
			if (g > 100)
				ok = 0;
			else {
				int now = it->first.first, v = it->first.second, id = it->second;
				st.erase(it);
				st.insert(make_pair(make_pair(now + v, v), id));
				p++;
			}	
		}
		return ok ? "Possible" : "Impossible";
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
		cout << "Testing DivisibleSetDiv2 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487302290;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DivisibleSetDiv2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int b[] = {3,2};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int b[] = {3,3,3};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int b[] = {1,10};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int b[] = {2, 3, 10};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int b[] = {7,10,4,6,3};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int b[] = {9,9,9,9,9,9,9,9,9};
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int b[] = {3,4,5,6,7};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 7:
			{
				int b[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 8:
			{
				int b[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int b[] = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
