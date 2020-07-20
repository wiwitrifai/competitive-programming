#include <bits/stdc++.h>

using namespace std;

const int S = 1e7 + 1;

bool flag[S];
vector<vector<int>> g;
vector<int> vis;
int cntr = 0;

vector<int> visited;

bool dfs(int v) {
	vis[v] = 1;
	visited.push_back(v);
	for (int u : g[v]) {
		if (vis[u] == 0) {
			bool res = dfs(u);
			if (res)
				return res;
		}
		if (vis[u] == 1) {
			visited.push_back(u);
			return true;
		}
	}
	vis[v] = 2;
	visited.pop_back();
	return false;
}

class PrimeSubstrings {
public:
	string construct(int N, int L) {
		if (L == 1) {
			return string(N, '3');
		}
		flag[0] = flag[1] = true;
		for (int i = 2; i < S; ++i) {
			if (flag[i]) continue;
			for (int j = i+i; j < S; j += i) {
				flag[j] = true;
			}
		}
		vector<int> cnt;
		vector<int> nodes;
		vector<pair<int, int>> edges;
		int low = 1, hig = 10;
		for (int i = 1; i < L; ++i) {
			low *= 10;
			hig *= 10;
		}
		for (int i = 2; i < S; ++i) {
			if (flag[i]) continue;
			if (i < low || i >= hig) continue;
			int a = i / 10, b = i % low;
			nodes.emplace_back(a);
			nodes.emplace_back(b);
			edges.emplace_back(a, b);
		}
		sort(nodes.begin(), nodes.end());
		nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
		auto find = [&](int x) {
			return lower_bound(nodes.begin(), nodes.end(), x) - nodes.begin();
		};
		g.resize(nodes.size());
		vector<int> topo, deg(nodes.size(), 0);
		for (auto & e : edges) {
			e.first = find(e.first);
			e.second = find(e.second);
			++deg[e.second];
			g[e.first].push_back(e.second);
		}
		for (int i = 0; i < nodes.size(); ++i)
			if (deg[i] == 0)
				topo.push_back(i);
		for (int i = 0; i < topo.size(); ++i) {
			int v = topo[i];
			for (int u : g[v]) {
				--deg[u];
				if (deg[u] == 0)
					topo.push_back(u);
			}
		}
		vis.assign(nodes.size(), 0);
		bool res = false;
		for (int i = 0; i < nodes.size(); ++i) {
			if (deg[i] == 0) continue;
			res = dfs(i);
			if (res)
				break;
		}
		assert(res);
		vector<int> cycle;
		cycle.push_back(visited.back());
		for (int i = (int)visited.size()-2; i >= 0; --i) {
			if (visited[i] == visited.back())
				break;
			cycle.push_back(visited[i]);
		}
		reverse(cycle.begin(), cycle.end());
		string ans(N, '0');
		for (int i = L-2, j = nodes[cycle[0]]; i >= 0; --i) {
			ans[i] += j % 10;
			j /= 10;
		}
		for (int i = L-1, k = 1; i < N; ++i, ++k) {
			if (k >= cycle.size())
				k = 0;
			ans[i] += nodes[cycle[k]] % 10;
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
		cout << "Testing PrimeSubstrings (400.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1594386940;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 400.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PrimeSubstrings _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int L = 2;
				_expected = "5317";
				_received = _obj.construct(N, L); break;
			}
			case 1:
			{
				int N = 7;
				int L = 7;
				_expected = "1301779";
				_received = _obj.construct(N, L); break;
			}
			case 2:
			{
				int N = 5;
				int L = 4;
				_expected = "13079";
				_received = _obj.construct(N, L); break;
			}
			case 3:
			{
				int N = 3;
				int L = 3;
				_expected = "";
				_received = _obj.construct(N, L); break;
			}
			case 4:
			{
				int N = 5;
				int L = 5;
				_expected = "";
				_received = _obj.construct(N, L); break;
			}
			case 5:
			{
				int N = 6;
				int L = 6;
				_expected = "";
				_received = _obj.construct(N, L); break;
			}
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
