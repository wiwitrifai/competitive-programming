#include <bits/stdc++.h>

using namespace std;

class BearKRoads {
	vector < int > x, a, b;
	vector< int > used, mark;
	int n, m;
	int rec(int k) {
		if (k == 0)
			return 0;
		int bscore = 0, node = -1;
		for (int i = 0; i < m; i++) if (!mark[i]) {
			int score = 0;
			if (!used[a[i]])
				score += x[a[i]];
			if (!used[b[i]])
				score += x[b[i]];
			if (score > bscore)
				bscore = score, node = used[a[i]] ? b[i] : a[i];
		}
		if (node == -1)
			return 0;
		int ans = 0;
		for (int i = 0; i < m; i++) {
			if (!mark[i] && (node == a[i] || node == b[i])) {
				bool tmpa = used[a[i]], tmpb = used[b[i]];
				int score = 0;
				if (!tmpa) {
					score += x[a[i]];
					used[a[i]] = 1;
				}
				if (!tmpb) {
					score += x[b[i]];
					used[b[i]] = 1;
				}
				mark[i] = 1;
				ans = max(ans, score + rec(k-1));
				mark[i] = 0;
				used[a[i]] = tmpa;
				used[b[i]] = tmpb;
			}
		}
		return ans;
	}
public:
	int maxHappy(vector <int> x, vector <int> a, vector <int> b, int K) {
		this->a = a;
		this->b = b;
		this->x = x;
		this->n = x.size();
		this->m = a.size();
		used.assign(n, 0);
		mark.assign(m, 0);
		return rec(K);
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
		cout << "Testing BearKRoads (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487553426;
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
		BearKRoads _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {10, 50, 50, 10};
				int a[] = {0, 1, 2};
				int b[] = {1, 2, 3};
				int K = 1;
				_expected = 100;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 1:
			{
				int x[] = {10, 50, 50, 10};
				int a[] = {0, 1, 2};
				int b[] = {1, 2, 3};
				int K = 2;
				_expected = 120;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 2:
			{
				int x[] = {42, 100, 500};
				int a[] = {0, 1};
				int b[] = {1, 2};
				int K = 2;
				_expected = 642;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 3:
			{
				int x[] = {42, 100, 500, 999, 999, 999, 999};
				int a[] = {0, 1};
				int b[] = {1, 2};
				int K = 2;
				_expected = 642;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 4:
			{
				int x[] = {969,467,808,263,179,428,595,557,406,80};
				int a[] = {5,4,9,7,9,3};
				int b[] = {4,0,8,8,0,1};
				int K = 3;
				_expected = 2841;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 5:
			{
				int x[] = {1,2,3,4};
				int a[] = {0,0,0};
				int b[] = {1,2,3};
				int K = 2;
				_expected = 8;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 6:
			{
				int x[] = {1,2,3,4,2};
				int a[] = {0,0,0,1};
				int b[] = {1,2,3,4};
				int K = 2;
				_expected = 9;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			case 7:
			{
				int x[] = {8,18,14,10,7,16,4,19,6,12,17,10,12,3,15,8,15,12};
				int a[] = {0,15,1,5,7,3,17,4,15,3,13,14,4,7};
				int b[] = {8,10,16,13,2,10,2,10,11,13,0,9,3,6};
				int K = 7;
				_expected = 173;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}
			/*case 8:
			{
				int x[] = ;
				int a[] = ;
				int b[] = ;
				int K = ;
				_expected = ;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}*/
			/*case 9:
			{
				int x[] = ;
				int a[] = ;
				int b[] = ;
				int K = ;
				_expected = ;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
			}*/
			/*case 10:
			{
				int x[] = ;
				int a[] = ;
				int b[] = ;
				int K = ;
				_expected = ;
				_received = _obj.maxHappy(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), K); break;
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
