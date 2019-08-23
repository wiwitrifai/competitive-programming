#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int vis[N][N], w[N*N];
vector<int> g[N * N];
int dx[4] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int used[N * N];

int Root, rootChild, low[N * N], num[N * N], cntr = 0;
int articulation_vertex[N * N];
set<int> st;

void dfs(int v, int par = -1) {
  low[v]= num[v] = ++cntr;
  st.insert(v);
  for(auto u : g[v]) {
    if(num[u] == -1) {
      if(v == Root) rootChild++;
      
      dfs(u, v);
      
      if(low[u] >= num[v])
        articulation_vertex[v] = true;      
      low[v] = min(low[v], low[u]);
    }
    else if(u != par)
      low[v] = min(low[v], num[u]);
  }
}


class TileFlippingGame {
public:
	int HowManyMoves(int n, int m, vector <string> X) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				vis[i][j] = -1;
		for (int i = 0; i < n * m; ++i)
			g[i].clear();
		// for (int i = 0; i < n; ++i)
		// 	cerr << X[i] << endl;
		queue<int> q;
		int id = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (vis[i][j] != -1 || X[i][j] == 'e') continue;
				vis[i][j] = id;
				q.push(i * m + j);
				w[id] = X[i][j] == 'w';
				while (!q.empty()) {
					int x = q.front() / m, y = q.front() % m; q.pop();
					for (int k = 0; k < 4; ++k) {
						int xx = x + dx[k], yy = y + dy[k];
						if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
						if (vis[xx][yy] != -1 && X[xx][yy] != X[i][j]) {
							g[id].push_back(vis[xx][yy]);
							g[vis[xx][yy]].push_back(id);
						}
						if (vis[xx][yy] != -1) continue;
						if (X[xx][yy] != X[i][j]) continue;
						vis[xx][yy] = id;
						q.push(xx * m + yy);
					}
				}
				++id;
			}
		}
		fill(used, used+id, 0);
		int cw = 0, cb = 0;
		for (int i = 0; i < id; ++i) {
			sort(g[i].begin(), g[i].end());
			g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
		}
		memset(num, -1, sizeof num);
		for (int i = 0; i < id; ++i) {
			if (num[i] != -1) continue;
			st.clear();
			Root = i;
			rootChild = 0;
			dfs(i);
			articulation_vertex[i] = rootChild > 1;
			int ww = 0, mw = 0, bb = 0, mb = 0;
			for (int u : st) {
				used[u] = 1;
				if (w[u]) {
					++ww;
					mw += articulation_vertex[u];
				}
				else {
					++bb;
					mb += articulation_vertex[u];
				}
			}
			cw += min(bb, mw+2);
			cb += min(ww, mb+2);
		}
		return min(cw, cb);
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
		cout << "Testing TileFlippingGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1522371760;
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
		TileFlippingGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int m = 3;
				string X[] = {"bbb","eee","www"};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 1:
			{
				int n = 3;
				int m = 3;
				string X[] = {"bwe","wbw","ewb"};
				_expected = 2;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 2:
			{
				int n = 4;
				int m = 4;
				string X[] = {"beww","beww","beww","wewe"};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 3:
			{
				int n = 2;
				int m = 8;
				string X[] = {"ewewbbbb","bwebewww"};
				_expected = 3;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 4:
			{
				int n = 5;
				int m = 5;
				string X[] = {"bwebw","wbebb","eeeee","bbebb","bbebb"};
				_expected = 3;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 5:
			{
				int n = 6;
				int m = 7;
				string X[] = {"bwbbbbb","bwbwwwb","bwbwewb","bwbbbwb","bwwwwwb","bbbbbbb"};
				_expected = 1;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 6:
			{
				int n = 6;
				int m = 7;
				string X[] = {"bwbbbbb","bwbwwwb","eeeeeee","bwbbbwb","bwwwwwb","bbbbbbb"};
				_expected = 3;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			case 7:
			{
				int n = 5;
				int m = 5;
				string X[] = {"bwbwb", "wbwbw", "bwbwb", "wbwbw", "bwbwb"};
				_expected = 10;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}
			/*case 8:
			{
				int n = ;
				int m = ;
				string X[] = ;
				_expected = ;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				int n = ;
				int m = ;
				string X[] = ;
				_expected = ;
				_received = _obj.HowManyMoves(n, m, vector <string>(X, X+sizeof(X)/sizeof(string))); break;
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
