#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

vector< int > g[N];
int cnt[N][N];

class TreeDiameters {
public:
	void dfs(int s, int v, int par = -1, int depth = 0) {
		cnt[s][depth]++;
		for (int u : g[v]) if (u != par)
			dfs(s, u, v, depth+1);
	}
	int getMax(vector <int> p) {
		int n = p.size() + 1;
		for (int i = 0; i < n-1; i++) {
			g[i+1].push_back(p[i]);
			g[p[i]].push_back(i+1);
		}
		n++;
		int ans = 0;
		for (int i = 0; i < n-1; i++) {
			int u = i+1, v = p[i];
			memset(cnt[u], 0, sizeof cnt[u]);
			memset(cnt[v], 0, sizeof cnt[v]);
			dfs(u, u, v);
			dfs(v, v, u);
			for (int j = 0; j < n; j++) {
				ans = max(ans, cnt[u][j] * cnt[v][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int u : g[i]) {
				memset(cnt[u], 0, sizeof cnt[u]);
				dfs(u, u, i);
			}
			for (int j = 0; j < n; j++) {
				int sum = 0;
				for (int u : g[i]) {
					sum += cnt[u][j];
				}
				int now = 0;
				for (int u : g[i]) {
					now += cnt[u][j] * (sum-cnt[u][j]);
				}
				ans = max(ans, now/2);
			}
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
		cout << "Testing TreeDiameters (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486961868;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeDiameters _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1,2,2};
				_expected = 3;
				_received = _obj.getMax(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0,0,0,0};
				_expected = 6;
				_received = _obj.getMax(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0,1,2,3,4,5,6,7};
				_expected = 1;
				_received = _obj.getMax(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0,0,0,2,3,4};
				_expected = 3;
				_received = _obj.getMax(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {0};
				_expected = 1;
				_received = _obj.getMax(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			/*case 5:
			{
				int p[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int p[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
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
