#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int n, par[N], lv[N], dep[N];
vector< int > g[N];
string col;

vector< pair< int, int > > seg;

void dfs(int v, int depth = 0) {
	lv[v] = dep[v] = depth;
	for (int u : g[v]) {
		dfs(u, depth+1);
		if (col[u] == col[v])
			dep[v] = max(dep[u], dep[v]);
	}
}

const int mod = 1e9 + 7;

int dp[N];
void add(int &le, int ri) {
	le += ri;
	if (le >= mod) le -= mod;
}

class DengklekGaneshAndTree {
public:
	int getCount(string labels, vector <int> parents) {
		n = labels.size();
		col = labels;
		par[0] = -1;
		for (int i = 1; i < n; i++) {
			g[parents[i-1]].push_back(i);
			par[i] = parents[i-1];
		}
		dfs(0);
		int m = 0;
		seg.clear();
		for (int i = 0; i < n; i++) {
			m = max(m, lv[i]);
			if (par[i] < 0 || col[i] != col[par[i]]) {
				seg.emplace_back(lv[i], dep[i]+1);
			}
		}
		m++;
		memset(dp, 0, sizeof dp);
		sort(seg.begin(), seg.end());
		dp[0] = 1;
		for (auto it : seg) {
			for (int i = it.second; i <= m; i++)
				add(dp[i], dp[i]);
			for (int i = it.first; i < it.second; i++)
				add(dp[it.second], dp[i]);
		}
		int ans = dp[m] % mod;
		if (ans < 0) ans += mod;
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
		cout << "Testing DengklekGaneshAndTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499531359;
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
		DengklekGaneshAndTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string labels = "seems";
				int parents[] = {0, 1, 0, 3};
				_expected = 5;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			case 1:
			{
				string labels = "like";
				int parents[] = {0, 0, 0};
				_expected = 7;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			case 2:
			{
				string labels = "a";
				int parents[] = {};
				_expected = 1;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			case 3:
			{
				string labels = "coincidence";
				int parents[] = {0, 1, 2, 0, 2, 1, 4, 7, 7, 6};
				_expected = 218;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			case 4:
			{
				string labels = "topcoderopenroundtwobgoodluckhavefun";
				int parents[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
				_expected = 147418098;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			/*case 5:
			{
				string labels = ;
				int parents[] = ;
				_expected = ;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string labels = ;
				int parents[] = ;
				_expected = ;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string labels = ;
				int parents[] = ;
				_expected = ;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
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
