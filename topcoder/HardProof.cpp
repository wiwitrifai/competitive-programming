#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int g[N][N], low[N], num[N], cntr, n;
bool dfs(int u, int lim, int up) {
	num[u] = low[u] = cntr++;
	for (int v = 0; v < n; v++) if (g[u][v] >= lim && g[u][v] <= up) {
		if (num[v] == -1)
			if (!dfs(v, lim, up))
				return 0;
		low[u] = min(low[u], low[v]);
	}
	if (low[u] == num[u])
		return !u;
	return 1;
}

bool cek(int lim, int up) {
	memset(num, -1, sizeof num);
	cntr = 0;
	if (!dfs(0, lim, up))
		return 0;
	for (int i = 0; i < n; i++)
		if (num[i] == -1)
			return 0;
	return 1;
}

class HardProof {
public:
	int minimumCost(vector <int> D) {
		n = int(sqrt(D.size()) + 0.5);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = D[i * n + j];
		vector< int > v = D;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int ans = v.back() - v[0];
		for (int i = 0; i < v.size(); i++) {
			int lim = v[i];
			int l = i, r = v.size();
			while (l < r) {
				int mid = (l + r)/2;
				if (cek(lim, v[mid]))
					r = mid;
				else
					l = mid+1;
			}
			if (l != v.size())
				ans = min(ans, v[l] - lim);
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
		cout << "Testing HardProof (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489333539;
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
		HardProof _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int D[] = {0,11,13,13,
				          10,0,12,13,
				          10,10,0,11,
				          12,10,10,0};
				_expected = 1;
				_received = _obj.minimumCost(vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 1:
			{
				int D[] = {0,1000,1000,1000,1000,
				          1,0,1000,1000,1000,
				          1,1,0,1000,1000,
				          1,1,1,0,1000,
				          1,1,1,1,0};
				_expected = 999;
				_received = _obj.minimumCost(vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 2:
			{
				int D[] = {0,95,1,10,
				          95,0,76,33,
				          1,76,0,49,
				          10,33,49,0};
				_expected = 32;
				_received = _obj.minimumCost(vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 3:
			{
				int D[] = {0,136946,89305,28946,
				          40152,0,150000,85407,
				          122920,110420,0,32811,
				          2092,79717,53028,0};
				_expected = 50771;
				_received = _obj.minimumCost(vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 4:
			{
				int D[] = {0,2159,2234,2720,2029,2853,2187,
				          2564,0,2409,2519,2441,2665,2654,
				          2666,2575,0,2215,2978,2588,2582,
				          2067,2743,2156,0,2840,2970,2480,
				          2724,2057,2136,2044,0,2030,2424,
				          2860,2512,2026,2867,2594,0,2401,
				          2893,2194,2802,2892,2151,2554,0};
				_expected = 206;
				_received = _obj.minimumCost(vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 5:
			{
				int D[] = {0,44,47,42,44,45,47,42,47,43,46,46,42,47,47,45,44,46,43,47,44,43,43,47,47,44,46,47,44,44,46,43,44,42,42,44,43,43,46,44,45,44,43,43,42,47,47,45,45,42,
				          44,0,44,43,43,46,44,47,43,46,44,42,42,46,44,44,45,44,43,46,46,46,47,47,44,47,42,44,45,44,42,42,43,46,46,44,43,44,42,45,44,45,44,45,46,44,42,47,43,43,
				          42,46,0,42,44,43,42,42,43,46,45,45,45,45,46,46,47,46,42,42,43,45,44,43,45,47,47,47,45,47,46,44,43,46,42,47,42,47,43,43,47,45,44,42,44,44,47,47,42,45,
				          45,43,47,0,47,42,43,47,47,45,43,43,46,46,43,43,43,45,42,45,42,45,47,45,42,47,45,44,42,44,42,43,45,45,42,47,45,42,45,47,43,44,42,42,45,47,44,42,47,45,
				          43,43,46,47,0,44,47,42,45,45,46,46,42,45,43,47,42,45,42,47,44,43,43,45,47,46,47,44,43,42,42,47,44,42,45,47,44,44,44,47,43,42,46,47,46,47,44,43,45,45,
				          42,43,44,45,43,0,43,43,43,44,42,47,42,44,47,45,46,43,47,46,47,43,44,45,43,47,44,44,46,43,43,43,44,43,43,46,47,47,43,44,44,44,44,47,43,43,43,47,45,47,
				          46,45,46,43,47,42,0,43,42,46,42,42,42,44,47,46,46,43,46,44,42,45,45,46,47,47,47,47,42,47,46,45,42,47,45,45,44,44,47,42,47,43,43,44,47,46,47,44,43,45,
				          46,43,45,47,44,47,45,0,44,43,45,47,44,45,44,47,45,42,47,46,44,46,44,44,45,45,43,47,44,44,45,45,42,42,42,42,45,46,42,43,43,42,44,45,47,46,47,47,45,42,
				          46,46,47,44,43,46,44,42,0,43,44,45,43,46,43,42,45,43,43,42,46,47,43,44,44,42,44,47,45,46,42,45,43,45,44,42,45,45,42,43,46,47,43,46,47,46,43,47,46,45,
				          43,46,45,44,43,45,42,42,46,0,44,47,43,42,46,42,45,45,46,45,47,44,45,44,46,47,45,43,45,46,46,45,47,44,46,42,44,46,44,44,46,43,42,45,42,43,42,45,44,44,
				          42,45,46,42,46,42,42,45,44,47,0,45,43,44,44,46,43,42,42,42,45,47,44,44,44,47,44,43,43,47,42,45,47,42,45,45,43,42,45,42,47,44,44,44,44,45,42,45,43,42,
				          47,47,46,43,44,45,45,42,42,43,44,0,43,43,43,46,42,43,42,43,43,46,47,47,42,43,46,47,43,42,43,42,45,45,42,47,45,42,42,44,46,44,43,42,47,47,46,47,47,46,
				          42,43,42,43,43,46,43,47,47,44,44,45,0,47,44,42,44,44,42,46,44,44,46,42,46,47,43,45,46,42,43,46,43,45,42,47,47,47,45,47,47,45,47,45,42,47,43,42,45,44,
				          43,47,47,46,46,43,42,45,47,47,44,44,47,0,44,45,47,45,44,43,46,43,42,43,44,43,42,43,47,42,42,47,44,46,44,47,44,47,47,42,42,42,45,46,45,47,45,44,43,47,
				          43,47,47,42,44,42,45,43,44,47,43,42,46,42,0,43,46,44,42,43,47,45,47,46,46,42,47,42,42,44,44,47,42,43,44,42,42,44,43,45,46,45,42,45,43,47,47,46,45,47,
				          42,42,43,47,46,46,43,42,46,43,43,43,42,45,47,0,42,43,46,47,46,46,44,42,47,46,42,46,44,45,47,46,45,45,42,44,43,46,42,45,45,45,42,47,42,47,42,46,44,44,
				          42,44,45,46,42,45,44,45,47,43,44,45,44,45,46,42,0,43,44,44,46,45,45,43,42,43,47,46,46,43,46,47,46,45,43,47,44,42,42,47,45,46,46,47,43,42,44,43,47,47,
				          45,42,45,46,43,43,42,46,44,46,47,46,47,44,46,42,43,0,44,44,47,45,45,42,43,42,44,46,43,45,45,43,46,47,45,45,46,43,44,47,45,47,45,46,45,47,46,43,45,47,
				          42,45,47,47,46,42,42,43,43,47,46,42,43,47,46,43,42,45,0,42,45,46,42,47,43,47,42,47,44,44,42,44,45,44,46,44,43,46,42,47,46,43,44,47,42,42,44,47,42,45,
				          47,42,45,42,44,47,44,44,43,46,45,46,46,42,45,45,42,42,43,0,45,43,44,42,47,43,43,45,47,42,42,43,46,42,44,47,47,46,44,43,47,43,43,46,47,47,45,45,45,46,
				          42,42,46,46,45,44,42,43,43,45,44,44,46,42,44,46,47,42,43,45,0,43,42,42,46,46,42,45,45,45,44,46,45,43,43,47,42,47,47,43,44,43,44,44,46,45,44,43,43,46,
				          44,44,47,42,46,42,45,47,46,44,43,42,42,44,46,47,46,45,42,47,46,0,43,43,47,42,44,44,42,44,45,45,46,44,46,44,47,46,44,46,46,47,45,42,45,44,43,42,42,42,
				          43,42,44,44,42,44,44,42,47,42,47,47,47,45,45,43,43,45,47,47,46,42,0,42,45,42,47,42,44,43,46,46,42,46,43,43,45,43,46,47,44,42,47,45,43,46,46,47,44,45,
				          44,46,44,43,44,47,46,42,47,47,47,46,43,47,42,47,42,44,44,42,47,46,44,0,44,45,44,42,43,43,42,43,42,46,45,43,44,42,46,43,46,47,43,45,44,46,45,42,42,42,
				          47,46,44,44,42,47,43,47,47,46,42,45,44,43,44,43,45,42,43,43,42,42,45,46,0,46,43,45,43,47,44,42,47,43,42,43,46,45,45,43,43,42,45,45,44,45,42,42,45,45,
				          43,44,47,46,43,43,44,42,44,46,45,45,42,42,44,46,47,44,47,44,46,44,47,47,43,0,43,42,45,42,45,45,44,44,45,46,45,47,45,45,47,47,46,47,46,45,45,43,45,44,
				          46,42,46,42,44,44,45,45,44,44,46,45,43,43,47,43,44,44,43,46,46,43,47,47,45,44,0,44,42,43,47,42,42,47,44,43,45,47,44,43,44,47,43,45,47,42,43,45,46,42,
				          44,47,43,43,45,44,46,42,47,45,46,45,45,42,45,42,44,45,45,47,47,42,47,46,44,42,42,0,44,43,47,47,47,42,44,45,44,42,44,44,47,46,42,45,46,47,42,43,44,43,
				          42,43,42,44,45,45,47,42,42,45,43,47,45,46,46,44,42,46,43,42,47,42,43,47,47,44,45,42,0,42,43,46,46,44,44,45,42,45,43,45,44,42,45,43,44,45,47,47,44,45,
				          47,42,42,46,44,44,46,44,42,47,45,44,43,45,42,44,46,43,44,42,43,42,46,43,44,45,46,47,42,0,45,43,45,43,44,45,46,47,46,45,47,43,44,42,42,46,47,42,43,44,
				          44,44,45,46,47,42,42,45,44,42,44,47,47,44,45,45,45,43,46,42,45,47,43,43,42,44,43,47,47,42,0,47,43,45,45,44,46,43,42,42,44,42,45,43,46,43,42,47,43,42,
				          42,45,43,47,45,46,46,42,43,44,42,47,44,47,45,44,44,45,42,46,47,45,44,46,42,47,42,46,45,42,46,0,44,44,43,45,44,44,44,44,43,44,42,42,44,47,47,45,45,42,
				          43,43,43,46,44,43,43,46,45,45,44,43,42,45,47,42,45,45,46,42,44,42,46,47,43,44,42,44,42,46,43,47,0,42,42,42,45,47,46,45,43,46,45,45,46,47,45,44,45,46,
				          43,47,45,42,46,47,43,46,44,45,45,42,44,47,44,44,46,47,46,46,42,46,43,45,43,45,46,42,46,42,47,46,42,0,43,47,43,42,43,44,47,44,45,42,46,46,47,43,46,43,
				          42,42,44,45,43,45,45,47,47,45,45,43,42,45,42,45,45,43,43,43,46,42,44,47,43,43,42,43,46,42,47,46,47,43,0,44,45,46,42,47,45,44,46,45,46,44,47,46,42,44,
				          43,44,45,45,47,44,44,45,42,45,45,47,46,47,43,46,45,47,44,47,42,44,44,42,45,42,42,43,47,43,42,47,43,47,42,0,43,42,46,46,43,46,45,46,44,45,42,42,47,46,
				          45,47,42,45,45,42,42,44,42,44,42,42,47,47,43,46,47,47,42,43,42,44,42,46,45,44,47,43,45,42,44,44,47,43,43,46,0,45,46,42,43,47,46,44,45,43,47,42,43,46,
				          45,45,44,43,43,45,45,42,42,43,44,47,46,44,42,47,46,45,42,44,43,45,44,46,46,44,47,42,47,44,45,47,47,47,46,42,47,0,46,46,44,44,46,45,47,45,45,44,45,44,
				          47,42,45,46,43,47,42,43,47,42,42,42,46,42,44,42,42,46,45,43,44,46,47,47,43,47,45,44,45,42,46,47,44,44,43,47,42,42,0,46,46,45,47,42,45,46,44,43,44,42,
				          46,42,46,44,44,44,44,46,42,44,44,45,42,44,47,45,44,47,44,42,46,43,45,45,45,43,46,44,44,47,43,42,46,45,47,43,42,46,45,0,43,45,43,42,43,45,43,47,47,42,
				          43,44,46,43,45,42,42,43,43,45,42,46,42,47,45,44,43,42,47,44,42,42,42,44,42,42,46,44,45,42,47,42,42,44,42,46,47,42,44,44,0,45,44,43,45,44,42,47,43,47,
				          45,43,45,45,42,47,42,46,43,45,43,46,43,42,47,45,45,44,47,47,47,43,44,42,47,47,44,45,44,42,43,47,47,45,46,46,43,45,47,44,45,0,47,47,45,42,45,47,42,42,
				          46,42,45,45,47,46,47,46,45,43,43,43,46,45,46,46,47,44,45,44,46,47,45,42,45,45,45,42,44,43,45,42,47,47,46,44,43,45,46,45,44,43,0,44,45,46,47,45,46,43,
				          44,43,43,42,47,45,46,46,43,42,43,45,42,42,42,42,45,46,47,47,45,46,45,43,47,47,45,47,45,42,46,45,46,45,45,44,47,47,45,44,44,47,42,0,44,47,47,43,47,42,
				          46,46,45,47,42,42,47,42,47,45,44,47,46,46,45,43,44,42,44,43,43,47,43,43,47,44,42,42,46,42,46,44,47,47,45,45,44,42,45,47,44,45,46,43,0,44,45,45,46,47,
				          46,46,44,42,42,44,46,45,45,46,44,43,46,45,43,47,47,47,42,42,42,42,45,44,45,45,42,45,44,42,46,43,43,43,44,42,43,43,45,43,47,47,43,43,45,0,43,44,44,46,
				          43,43,42,42,45,47,42,46,44,45,45,45,45,42,44,45,42,43,45,43,43,43,47,43,44,45,47,43,47,45,43,43,45,42,46,47,43,47,44,43,43,42,42,42,43,45,0,44,42,42,
				          47,43,46,42,45,43,47,44,47,45,44,45,43,42,42,46,46,44,46,42,46,43,44,43,42,42,47,45,47,46,45,42,42,47,45,45,46,47,43,43,44,44,42,43,43,42,47,0,42,43,
				          45,45,46,47,42,47,46,46,43,44,46,47,43,46,46,42,47,45,42,45,47,42,42,45,47,43,42,43,43,42,45,47,45,43,43,45,43,43,47,42,46,43,45,46,47,45,47,46,0,45,
				          46,46,42,47,47,47,42,44,43,46,43,47,43,43,46,45,42,45,47,42,47,42,44,42,43,47,43,45,42,44,45,46,43,46,46,44,46,43,42,44,45,42,42,47,43,47,45,46,42,0};
				_expected = 0;
				_received = _obj.minimumCost(vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			/*case 6:
			{
				int D[] = ;
				_expected = ;
				_received = _obj.minimumCost(vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int D[] = ;
				_expected = ;
				_received = _obj.minimumCost(vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int D[] = ;
				_expected = ;
				_received = _obj.minimumCost(vector <int>(D, D+sizeof(D)/sizeof(int))); break;
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
