#include <bits/stdc++.h>

using namespace std;

const int N = 105;

vector<int> g[N];
bool vis[N];
vector<int> ans;
void dfs(int v, int col) {
	vis[v] = 1;
	if (col)
		ans.push_back(v);
	for (int u : g[v]) {
		if (vis[u]) continue;
		dfs(u, col^1);
	}
	if (!col)
		ans.push_back(v);
}
class BannedBook {
public:
	vector <int> passAround(vector <string> friends) {
		int n = friends.size();
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				if (friends[i][j] == 'N') continue;
				g[i].push_back(j);
			}
		}
		memset(vis, 0, sizeof vis);
		ans.clear();
		for (int i = 0; i < n; ++i)
			if (!vis[i])
				dfs(i, 0);
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
		cout << "Testing BannedBook (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1568170411;
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
		BannedBook _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string friends[] = {"YNN",
				                   "NYN",
				                   "NNY"};
				int __expected[] = {0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.passAround(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}
			case 1:
			{
				string friends[] = {"YYYYY",
				                   "YYNNN",
				                   "YNYNN",
				                   "YNNYN",
				                   "YNNNY"};
				int __expected[] = {0, 1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.passAround(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}
			case 2:
			{
				string friends[] = {"YYNNN",
				                   "YYYNN",
				                   "NYYYN",
				                   "NNYYY",
				                   "NNNYY"};
				int __expected[] = {0, 2, 4, 3, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.passAround(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}
			case 3:
			{
				string friends[] = {"YYNNYNYNN", 
				                   "YYNNNYNNN", 
				                   "NNYNNNNNN", 
				                   "NNNYNNNNN", 
				                   "YNNNYNNNY", 
				                   "NYNNNYNYN", 
				                   "YNNNNNYNY", 
				                   "NNNNNYNYN", 
				                   "NNNNYNYNY"};
				int __expected[] = {0, 5, 7, 1, 8, 6, 4, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.passAround(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}
			/*case 4:
			{
				string friends[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.passAround(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string friends[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.passAround(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string friends[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.passAround(vector <string>(friends, friends+sizeof(friends)/sizeof(string))); break;
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
