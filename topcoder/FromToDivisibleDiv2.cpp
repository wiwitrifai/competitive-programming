#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
vector< int > adj[3 * N];
int d[3 * N];


class FromToDivisibleDiv2 {
public:
	int shortest(int n, int s, int t, vector <int> a, vector <int> b) {
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				adj[j].push_back(i+N);
				adj[i+N+N].push_back(j);
			}
		}
		for (int i = 0; i < a.size(); i++)
			adj[a[i]+N].push_back(b[i]+N+N);
		memset(d, -1, sizeof d);
		d[s] = 0;
		queue< int > q;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			if (v == t) break;
			for (int u : adj[v]) if (d[u] == -1) {
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
		return d[t] >= 0 ? d[t] / 3 : -1;
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
		cout << "Testing FromToDivisibleDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487108998;
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
		FromToDivisibleDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 11;
				int S = 9;
				int T = 6;
				int a[] = {3,10};
				int b[] = {5,2};
				_expected = 2;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 12345;
				int S = 18;
				int T = 12;
				int a[] = {1,42,50};
				int b[] = {1,17,3};
				_expected = 1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 60;
				int S = 30;
				int T = 8;
				int a[] = {16,15,12};
				int b[] = {2,20,5};
				_expected = -1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 77;
				int S = 10;
				int T = 62;
				int a[] = {2,5,7,4,17,26};
				int b[] = {25,7,11,13,31,34};
				_expected = 4;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 100;
				int S = 90;
				int T = 40;
				int a[] = {20,30,100,99,100};
				int b[] = {10,30,100,100,99};
				_expected = 2;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 100000;
				int S = 700;
				int T = 42345;
				int a[] = {3500,12000,42345,20000,35,19};
				int b[] = {15,1,700,20000,40000,17};
				_expected = 3;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int N = 2;
				int S = 1;
				int T = 2;
				int a[] = {2};
				int b[] = {1};
				_expected = -1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 7:
			{
				int N = ;
				int S = ;
				int T = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int S = ;
				int T = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int N = ;
				int S = ;
				int T = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
