#include <bits/stdc++.h>

using namespace std;

vector< string > g;
int vis[55];
int used[55][55];
pair< int, int > dfs(int u) {
	if (vis[u]) return make_pair(0, 0);
	vis[u] = 1;
	int ver = 1, ed = 0;
	for (int i = 0; i < g[u].size(); i++) if (g[u][i] == 'Y' && !used[u][i]) {
		used[u][i] = used[i][u] = 1;
		ed++;
		auto it = dfs(i);
		ver += it.first;
		ed += it.second;
	}
	return make_pair(ver, ed);
}

class Permatchd2 {
public:
	int fix(vector <string> graph) {
		memset(vis, 0, sizeof vis);
		memset(used, 0, sizeof used);
		g = graph;
		int n = graph.size();
		int odd = 0, even = 0, self = 0, one = 0;
		for (int i = 0; i < n; i++) if(!vis[i]) {
			auto it = dfs(i);
			if (it.second & 1) {
				if (1LL * it.first * (it.first-1)/2 > it.second)
					self++;
				else
					odd++;
			}
			else
				even++;
		}
		if (even > 0) {
			return odd + self;
		}
		else if (self > 0) {
			return odd + self;
		}
		else if (odd > 1)
			return odd;
		else
			return -1;
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
		cout << "Testing Permatchd2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487694268;
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
		Permatchd2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string graph[] = {"NYN",
				                  "YNN",
				                  "NNN"};
				_expected = 1;
				_received = _obj.fix(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 1:
			{
				string graph[] = {"NYY",
				                  "YNN",
				                  "YNN"};
				_expected = 0;
				_received = _obj.fix(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 2:
			{
				string graph[] = {"NYY",
				                  "YNY",
				                  "YYN"};
				_expected = -1;
				_received = _obj.fix(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 3:
			{
				string graph[] = {"NYYY",
				                  "YNYY",
				                  "YYNN",
				                  "YYNN"};
				_expected = 1;
				_received = _obj.fix(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 4:
			{
				string graph[] = {"NYNNNN",
				                  "YNNNNN",
				                  "NNNYNN",
				                  "NNYNNN",
				                  "NNNNNY",
				                  "NNNNYN"};
				_expected = 3;
				_received = _obj.fix(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 5:
			{
				string graph[] = {"N"};
				_expected = 0;
				_received = _obj.fix(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			/*case 6:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.fix(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.fix(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.fix(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
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
