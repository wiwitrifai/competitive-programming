#include <bits/stdc++.h>

using namespace std;

const int N = 155;
int lim;
vector< string > vs;
void dfs(string s) {
	vs.push_back(s);
	string now = "(" + s;
	while (now.size() < lim) {
		dfs(now + ")");
		now += s;
	}
} 

bool check(string a, string b) {
	if (a.size() < b.size()) return 0;
	for (int i = 0, j = 0; i < b.size(); i++) {
		while (j < a.size() && b[i] != a[j]) j++;
		if (j == a.size())
			return 0;
		j++;
	}
	return 1;
}

class RepeatedStrings {
public:
	string findKth(string s, int k) {
		lim = s.size();
		dfs("()");
		sort(vs.begin(), vs.end());
		for (int i = 0; i < vs.size(); i++) {
			if (check(s, vs[i]))
				k--;
			if (k == 0)
				return vs[i];
		}
		return "";
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
		cout << "Testing RepeatedStrings (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486983538;
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
		RepeatedStrings _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "()))((()())";
				int k = 3;
				_expected = "(())";
				_received = _obj.findKth(s, k); break;
			}
			case 1:
			{
				string s = "))))))))))))((((((((((";
				int k = 1;
				_expected = "";
				_received = _obj.findKth(s, k); break;
			}
			case 2:
			{
				string s = "(())(()(()))";
				int k = 1;
				_expected = "(((())))";
				_received = _obj.findKth(s, k); break;
			}
			case 3:
			{
				string s = "(())))()((())())";
				int k = 8;
				_expected = "()";
				_received = _obj.findKth(s, k); break;
			}
			case 4:
			{
				string s = "(()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()())";
				int k = 64;
				_expected = "(((((((((((((()()()())(()()()())))))))))))))";
				_received = _obj.findKth(s, k); break;
			}
			case 5:
			{
				string s = "(";
				int k = 1000000000;
				_expected = "";
				_received = _obj.findKth(s, k); break;
			}
			/*case 6:
			{
				string s = ;
				int k = ;
				_expected = ;
				_received = _obj.findKth(s, k); break;
			}*/
			/*case 7:
			{
				string s = ;
				int k = ;
				_expected = ;
				_received = _obj.findKth(s, k); break;
			}*/
			/*case 8:
			{
				string s = ;
				int k = ;
				_expected = ;
				_received = _obj.findKth(s, k); break;
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
