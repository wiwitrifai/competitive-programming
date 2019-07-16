#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

class ChangeDistances {
public:
	vector <string> findGraph(vector <string> g) {
		int n = g.size();
		cerr << n << endl;
		vector<vector<int> > h(n);
		for (int i = 0; i < n; ++i) {
			h[i].resize(n);
			for (int j = 0; j < n; ++j) {
				h[i][j] = g[i][j] == '1' ? 1 : inf;
			}
		}
		for (int i = 0; i < n; ++i)
			h[i][i] = 0;
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
		}
		vector<string> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i].resize(n);
			for (int j = 0; j < n; ++j) {
				cerr << h[i][j] << " ";
				ans[i][j] = h[i][j] != 1 ? '1' : '0';
			}
			ans[i][i] = '0';
			cerr << endl;
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
		cout << "Testing ChangeDistances (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1547572245;
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
		ChangeDistances _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string g[] = {"011","100","100"};
				string __expected[] = {"000", "001", "010" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGraph(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 1:
			{
				string g[] = {"000","000","000"};
				string __expected[] = {"011", "100", "100" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGraph(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 2:
			{
				string g[] = {"0100","1000","0001","0010"};
				string __expected[] = {"0011", "0010", "1100", "1000" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGraph(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			/*case 3:
			{
				string g[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGraph(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string g[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGraph(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string g[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGraph(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
