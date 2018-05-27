#include <bits/stdc++.h>

using namespace std;

class TreesAndBrackets {
public:
	string a, b;
	bool rec(int l, int r, int x, int y) {
		int cnt = 0;
		vector<pair<int, int> > child1;
		vector<pair<int, int> > child2;
		for (int i = l+1, last = l+1; i < r; ++i) {
			if (a[i] == '(') ++cnt;
			else --cnt;
			if (cnt == 0) {
				child1.emplace_back(last, i);
				last = i+1;
			}
		}
		cnt = 0;
		for (int i = x+1, last = x+1; i < y; ++i) {
			if (b[i] == '(') ++cnt;
			else --cnt;
			if (cnt == 0) {
				child2.emplace_back(last, i);
				last = i+1;
			}
		}
		for (int i = 0, j = 0; i < child2.size(); ++i) {
			while (j < child1.size() && !rec(child1[j].first, child1[j].second, child2[i].first, child2[i].second)) ++j;
			if ((int)child1.size() - j < (int)child2.size() - i) return false;
			else ++j;
		}
		return true;
	}
	string check(string t1, string t2) {
		a = t1;
		b = t2;
		return rec(0, (int)a.size()-1, 0, (int)b.size()-1) ? "Possible" : "Impossible";
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
		cout << "Testing TreesAndBrackets (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521302407;
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
		TreesAndBrackets _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string t1 = "(())";
				string t2 = "()";
				_expected = "Possible";
				_received = _obj.check(t1, t2); break;
			}
			case 1:
			{
				string t1 = "()";
				string t2 = "()";
				_expected = "Possible";
				_received = _obj.check(t1, t2); break;
			}
			case 2:
			{
				string t1 = "(()()())";
				string t2 = "((()))";
				_expected = "Impossible";
				_received = _obj.check(t1, t2); break;
			}
			case 3:
			{
				string t1 = "((())((())())())";
				string t2 = "(()(())())";
				_expected = "Possible";
				_received = _obj.check(t1, t2); break;
			}
			case 4:
			{
				string t1 = "((())((())())())";
				string t2 = "((()()()()()))";
				_expected = "Impossible";
				_received = _obj.check(t1, t2); break;
			}
			/*case 5:
			{
				string t1 = ;
				string t2 = ;
				_expected = ;
				_received = _obj.check(t1, t2); break;
			}*/
			/*case 6:
			{
				string t1 = ;
				string t2 = ;
				_expected = ;
				_received = _obj.check(t1, t2); break;
			}*/
			/*case 7:
			{
				string t1 = ;
				string t2 = ;
				_expected = ;
				_received = _obj.check(t1, t2); break;
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
