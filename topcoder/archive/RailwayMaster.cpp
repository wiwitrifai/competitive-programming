#include <bits/stdc++.h>

using namespace std;

class RailwayMaster {
public:
	int maxProfit(int N, int M, int K, vector <int> a, vector <int> b, vector <int> v) {
		vector<int> dsu(N, -1);
		function<int(int)> findRoot = [&](int x) {
			return dsu[x] < 0 ? x : dsu[x] = findRoot(dsu[x]);
		};
		vector<tuple<int, int, int>> edges(M);
		for (int i = 0; i < M; ++i) {
			edges[i] = make_tuple(v[i], a[i], b[i]);
		}
		sort(edges.begin(), edges.end());
		vector<bool> used(M, false);
		for (int i = 0; i < M; ++i) {
			int u, v, w;
			tie(w, u, v) = edges[i];
			u = findRoot(u);
			v = findRoot(v);
			if (u == v) continue;
			used[i] = true;
			dsu[u] = v;
		}
		int ans = 0;
		for (int i = M-1; i >= 0 && K > 0; --i) {
			if (used[i]) continue;
			--K;
			ans += get<0>(edges[i]);
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
		cout << "Testing RailwayMaster (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1595589089;
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
		RailwayMaster _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int M = 3;
				int K = 3;
				int a[] = {0, 1, 2};
				int b[] = {1, 2, 0};
				int v[] = {224, 258, 239};
				_expected = 258;
				_received = _obj.maxProfit(N, M, K, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 4;
				int M = 6;
				int K = 2;
				int a[] = {0, 0, 0, 1, 1, 2};
				int b[] = {1, 2, 3, 2, 3, 3};
				int v[] = {500, 900, 600, 700, 800, 100};
				_expected = 1700;
				_received = _obj.maxProfit(N, M, K, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 5;
				int M = 7;
				int K = 1;
				int a[] = {0, 1, 2, 3, 3, 0, 1};
				int b[] = {1, 2, 3, 4, 0, 2, 3};
				int v[] = {100, 100, 100, 900, 100, 100, 100};
				_expected = 100;
				_received = _obj.maxProfit(N, M, K, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 5;
				int M = 7;
				int K = 3;
				int a[] = {0, 0, 0, 0, 1, 2, 3};
				int b[] = {1, 1, 1, 1, 2, 3, 4};
				int v[] = {926, 815, 777, 946, 928, 634, 999};
				_expected = 2687;
				_received = _obj.maxProfit(N, M, K, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 5;
				int M = 7;
				int K = 6;
				int a[] = {0, 1, 2, 3, 4, 1, 3};
				int b[] = {1, 2, 3, 4, 0, 4, 0};
				int v[] = {118, 124, 356, 480, 625, 767, 911};
				_expected = 2303;
				_received = _obj.maxProfit(N, M, K, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 10;
				int M = 15;
				int K = 3;
				int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
				int b[] = {1, 2, 3, 4, 0, 6, 7, 8, 9, 5, 5, 6, 7, 8, 9};
				int v[] = {220284, 869120, 787788, 980412, 133333, 314159, 256312, 192916, 298575, 931110, 175353, 926778, 201513, 202729, 155136};
				_expected = 2838300;
				_received = _obj.maxProfit(N, M, K, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int M = ;
				int K = ;
				int a[] = ;
				int b[] = ;
				int v[] = ;
				_expected = ;
				_received = _obj.maxProfit(N, M, K, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				int K = ;
				int a[] = ;
				int b[] = ;
				int v[] = ;
				_expected = ;
				_received = _obj.maxProfit(N, M, K, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int M = ;
				int K = ;
				int a[] = ;
				int b[] = ;
				int v[] = ;
				_expected = ;
				_received = _obj.maxProfit(N, M, K, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
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
