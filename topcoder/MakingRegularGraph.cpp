#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int d[N];
int g[N][N];

vector<int> ans;
vector<int> kurang, used;
bool can(int id) {
	if (id >= (int)kurang.size()) {
		return true;
	}
	if (used[id]) return can(id+1);
	for (int j = id+1; j < (int)kurang.size(); ++j) {
		int u = kurang[id], v = kurang[j];
		if (used[j]) continue;
		if (u == v) continue;
		if (g[u][v]) continue;
		g[u][v] = g[v][u] = 1;
		if (u > v) swap(u, v);
		ans.push_back(u);
		ans.push_back(v);
		used[id] = used[j] = 1;
		if (can(id+1))
			return true;
		ans.pop_back();
		ans.pop_back();
		used[id] = used[j] = 0;
		g[u][v] = g[v][u] = 0;
	}
	return false;
}

class MakingRegularGraph {
public:
	vector <int> addEdges(int n, vector <int> x, vector <int> y) {
		memset(g, 0, sizeof g);
		memset(d, 0, sizeof d);
		int m = x.size();
		for (int i = 0; i < m; ++i) {
			g[x[i]][y[i]] = g[y[i]][x[i]] = 1;
			++d[x[i]];
			++d[y[i]];
		}
		kurang.clear();
		for (int i = 0; i < n; ++i)
			if (d[i] < 2) {
				for (int j = d[i]; j < 2; ++j)
					kurang.push_back(i);
			}
		used.assign(kurang.size(), 0);
		ans.clear();
		if (!can(0))
			return vector<int>{-1};
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
		cout << "Testing MakingRegularGraph (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1527955668;
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
		MakingRegularGraph _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 6;
				int x[] = {0,2};
				int y[] = {2,3};
				int __expected[] = {0, 1, 1, 4, 3, 5, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 4;
				int x[] = {1,2,1};
				int y[] = {2,3,3};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 3;
				int x[] = {};
				int y[] = {};
				int __expected[] = {0, 1, 0, 2, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 5;
				int x[] = {0};
				int y[] = {4};
				int __expected[] = {0, 1, 1, 2, 2, 3, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 5;
				int x[] = {2};
				int y[] = {3};
				int __expected[] = {0, 1, 0, 2, 1, 4, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
