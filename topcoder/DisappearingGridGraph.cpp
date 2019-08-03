#include <bits/stdc++.h>

using namespace std;

const int N = 3030;

int p[N * N];
bool potong[N * N];
int R, C;
int enc(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C)
		return -1;
	return r * C + c;
}

int find(int x) {
	return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (-p[u] > -p[v])
		swap(u, v);
	potong[v] |= potong[u];
	p[v] += p[u];
	p[u] = v;
}

bool dead[N * N];
int dx[] = {-1,  0,  1, 1, 1, 0, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 1,  1,  0};

int remove(int r, int c) {
	int now = enc(r, c);
	if (dead[now])
		return 0;
	vector<int> neigh;
	for (int i = 0; i < 8; ++i) {
		neigh.push_back(enc(r+dx[i], c+dy[i]));
	}
	vector<int> alive;
	for (int i = 1; i < 8; i += 2) {
		if (neigh[i] == -1 || dead[neigh[i]]) continue;
		bool ok = 1;
		for (int j : alive) {
			bool blef = 0, brig = 0;
			set<int> penghalang;
			for (int k = j+1; k < i; ++k) {
				if (neigh[k] == -1) {
					blef = 1;
				}
				if (!dead[neigh[k]]) continue;
				int cur = find(neigh[k]);
				penghalang.insert(cur);
				if (potong[cur]) {
					blef = 1;
				}
			}
			for (int k = (i+1) % 8; k != j; k = (k + 1) % 8) {
				if (neigh[k] == -1) {
					brig = 1;
				}
				if (!dead[neigh[k]]) continue;
				if (penghalang.count(find(neigh[k]))) {
					brig = blef = 1;
					break;
				}
				if (potong[find(neigh[k])]) {
					brig = 1;
				}
			}
			if (!blef || !brig) {
				ok = 0;
				break;
			}
		}
		if (ok)
			alive.push_back(i);
	}
	dead[now] = 1;
	for (int x : neigh) {
		if (x == -1) continue;
		if (dead[x]) {
			merge(x, now);
		}
	}
	if (r == 0 || r == R-1 || c == 0 || c == C-1)
		potong[find(now)] = 1;
	return (int)alive.size() - 1;
}

int vis[N][N];

class DisappearingGridGraph {
public:
	vector <int> keepErasing(int R, int C, int N, int seed) {
		::R = R;
		::C = C;
		memset(dead, 0, sizeof dead);
		memset(p, -1, sizeof p);
		long long modulo = (1LL << 31) - 1;
		int dua10 = 1 << 10;
		int connected = 1;
		long long state = seed;
		for (int i = 0; i < N; ++i) {
	    state = (1LL * state * 1103515245LL + 12345) & modulo;
	    int rx    = (state / dua10) % R;
	    state = (1LL * state * 1103515245LL + 12345) & modulo;
	    int cx    = (state / dua10) % C;
	    // cerr << i << " " << rx << " " << cx << endl;
	    connected += remove(rx, cx);
	    state = ((long long)state + connected) & modulo;
	  }
	  if (connected == 0)
	  	return {0, 0, 0};
	  int small = R * C + 1, large = 0;
	  for (int i = 0; i < R; ++i) {
	  	for (int j = 0; j < C; ++j) {
	  		if (vis[i][j]) continue;
	  		if (dead[enc(i, j)]) continue;
	  		queue<pair<int, int>> que;
	  		que.emplace(i, j);
	  		vis[i][j] = true;
	  		int cnt = 0;
	  		while (!que.empty()) {
	  			++cnt;
	  			int x, y;
	  			tie(x, y) = que.front();
	  			que.pop();
	  			for (int k = 1; k < 8; k += 2) {
	  				int u = x+dx[k], v = y+dy[k];
	  				if (enc(u, v) == -1) continue;
	  				if (dead[enc(u, v)]) continue;
	  				if (vis[u][v]) continue;
	  				vis[u][v] = true;
	  				que.emplace(u, v);
	  			}
	  		}
	  		small = min(small, cnt);
	  		large = max(large, cnt);
	  	}
	  }
	  return {connected, small, large};
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
		cout << "Testing DisappearingGridGraph (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1564810702;
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
		DisappearingGridGraph _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 1;
				int C = 7;
				int N = 4;
				int seed = 47;
				int __expected[] = {3, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.keepErasing(R, C, N, seed); break;
			}
			case 1:
			{
				int R = 3;
				int C = 3;
				int N = 5;
				int seed = 47;
				int __expected[] = {3, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.keepErasing(R, C, N, seed); break;
			}
			case 2:
			{
				int R = 1000;
				int C = 1000;
				int N = 1;
				int seed = 0;
				int __expected[] = {1, 999999, 999999 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.keepErasing(R, C, N, seed); break;
			}
			case 3:
			{
				int R = 97;
				int C = 98;
				int N = 900;
				int seed = 424;
				int __expected[] = {2, 4, 8644 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.keepErasing(R, C, N, seed); break;
			}
			case 4:
			{
				int R = 3;
				int C = 5;
				int N = 98765;
				int seed = 47;
				int __expected[] = {0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.keepErasing(R, C, N, seed); break;
			}
			case 5:
			{
				int R = 2995;
				int C = 2993;
				int N = 411478;
				int seed = 175701600;
				int __expected[] = {43, 1, 8561927};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.keepErasing(R, C, N, seed); break;
			}
			/*case 6:
			{
				int R = ;
				int C = ;
				int N = ;
				int seed = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.keepErasing(R, C, N, seed); break;
			}*/
			/*case 7:
			{
				int R = ;
				int C = ;
				int N = ;
				int seed = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.keepErasing(R, C, N, seed); break;
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
