#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> g[N], V;

int st[N], en[N], cntr = 0;
long long ans = -1;
int lv[N], sz[N];
int nodes[N], n;

long long seg[N << 2], sum[N << 2], lazy[N << 2];
void build(int id = 1, int l = 0, int r = n) {
	if (r-l < 2) {
		int v = nodes[l];
		sum[id] = 1LL * V[v] * sz[v];
		seg[id] = sum[id] * lv[v];
		lazy[id] = 0;
		// cerr << l << " " << v << " " << V[v] << " " << sz[v] << " " << lv[v] << endl;
		return;
	}
	int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
	build(il, l, mid);
	build(ir, mid, r);
	sum[id] = sum[il] + sum[ir];
	seg[id] = seg[il] + seg[ir];
	lazy[id] = 0;
}

inline void upd(int id, long long x) {
	seg[id] += 1LL * sum[id] * x;
	lazy[id] += x;
}

inline void push(int id, int il, int ir) {
	if (lazy[id] == 0) return;
	upd(il, lazy[id]);
	upd(ir, lazy[id]);
	lazy[id] = 0;
}

void update(int x, int y, long long v, int id = 1, int l = 0, int r = n) {
	if (x >= r || l >= y) return;
	if (x <= l && r <= y) {
		upd(id, v);
		return;
	}
	int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
	push(id, il, ir);
	update(x, y, v, il, l, mid);
	update(x, y, v, ir, mid, r);
	seg[id] = seg[il] + seg[ir];
	sum[id] = sum[il] + sum[ir];
}

void assign(int x, long long v, int id = 1, int l = 0, int r = n) {
	if (r-l < 2) {
		sum[id] = v;
		assert(seg[id] == 0);
		return;
	}
	int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
	push(id, il, ir);
	if (x < mid)
		assign(x, v, il, l, mid);
	else
		assign(x, v, ir, mid, r);
	sum[id] = sum[il] + sum[ir];
	seg[id] = seg[il] + seg[ir];
}

void check(int id = 1, int l = 0, int r= n) {
	cerr << " check " << id << " [" << l << ", " << r <<  "] = " << seg[id] << endl;
	if (r-l < 2)
		return;
	int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
	push(id, il, ir);
	check(il, l, mid);
	check(ir, mid, r);
}


void dfs(int v) {
	nodes[cntr] = v;
	st[v] = cntr++;
	sz[v] = 1;
	for (int u : g[v]) {
		lv[u] = lv[v] + 1;
		dfs(u);
		sz[v] += sz[u];
	}
	en[v] = cntr;
}


void dfs2(int v) {
	if (ans < 0 || ans > seg[1]) {
		ans = seg[1];
	}
	for (int u : g[v]) {
		assign(st[v], 1LL * V[v] * (n - sz[u]));
		update(0, n, +1);
		update(st[u], en[u], -2);
		dfs2(u);
		update(st[u], en[u], +2);
		update(0, n, -1);
		assign(st[v], 1LL * V[v] * sz[v]);
	}
}

class RootItRight {
public:
	long long findMinimumTotalCost(int N, vector <int> edge, vector <int> val, int D, int seed, int MX) {
		::n = N;
		vector<long long> A(2 * N);
		A[0] = seed;
		for (int i = 1; i < 2*N; ++i)
		  A[i] = (1LL * A[i-1] * 1103515245LL + 12345LL) % 2147483648LL;

		vector<int> E = edge;
		E.resize(N);
		for (int i = (int)edge.size(); i < N; ++i) {
		  E[i] = (A[i] % min(i,D)) + i - min(i,D);
		}

		for (int i = 1; i < N; ++i) {
		  assert(E[i] < i);
			g[E[i]].push_back(i);
		}

		V = val;
		V.resize(N);
		for (int i = (int)val.size(); i < N; ++i)
		  V[i] = A[N+i] % MX;
		cntr = 0;
		lv[0] = 0;
		dfs(0);
		assert(cntr == n);
		build();
		dfs2(0);
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
		cout << "Testing RootItRight (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1563376443;
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
		RootItRight _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int edge[] = {-1,0,1,2};
				int val[] = {4,3,3,4};
				int D = 1;
				int seed = 0;
				int MX = 5;
				_expected = 18LL;
				_received = _obj.findMinimumTotalCost(N, vector <int>(edge, edge+sizeof(edge)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int)), D, seed, MX); break;
			}
			case 1:
			{
				int N = 4;
				int edge[] = {-1,0,0,0};
				int val[] = {3,2,3,0};
				int D = 1;
				int seed = 0;
				int MX = 4;
				_expected = 5LL;
				_received = _obj.findMinimumTotalCost(N, vector <int>(edge, edge+sizeof(edge)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int)), D, seed, MX); break;
			}
			case 2:
			{
				int N = 5;
				int edge[] = {-1,0,0,1,3};
				int val[] = {5,0,3,2,3};
				int D = 1;
				int seed = 0;
				int MX = 6;
				_expected = 20LL;
				_received = _obj.findMinimumTotalCost(N, vector <int>(edge, edge+sizeof(edge)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int)), D, seed, MX); break;
			}
			case 3:
			{
				int N = 17;
				int edge[] = {-1};
				int val[] = {};
				int D = 7;
				int seed = 176;
				int MX = 15;
				_expected = 620LL;
				_received = _obj.findMinimumTotalCost(N, vector <int>(edge, edge+sizeof(edge)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int)), D, seed, MX); break;
			}
			case 4:
			{
				int N = 200000;
				int edge[] = {-1,0,0,0};
				int val[] = {4,7};
				int D = 1;
				int seed = 0;
				int MX = 1000;
				_expected = 166346919874650680LL;
				_received = _obj.findMinimumTotalCost(N, vector <int>(edge, edge+sizeof(edge)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int)), D, seed, MX); break;
			}
			/*case 5:
			{
				int N = ;
				int edge[] = ;
				int val[] = ;
				int D = ;
				int seed = ;
				int MX = ;
				_expected = LL;
				_received = _obj.findMinimumTotalCost(N, vector <int>(edge, edge+sizeof(edge)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int)), D, seed, MX); break;
			}*/
			/*case 6:
			{
				int N = ;
				int edge[] = ;
				int val[] = ;
				int D = ;
				int seed = ;
				int MX = ;
				_expected = LL;
				_received = _obj.findMinimumTotalCost(N, vector <int>(edge, edge+sizeof(edge)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int)), D, seed, MX); break;
			}*/
			/*case 7:
			{
				int N = ;
				int edge[] = ;
				int val[] = ;
				int D = ;
				int seed = ;
				int MX = ;
				_expected = LL;
				_received = _obj.findMinimumTotalCost(N, vector <int>(edge, edge+sizeof(edge)/sizeof(int)), vector <int>(val, val+sizeof(val)/sizeof(int)), D, seed, MX); break;
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
