#include <bits/stdc++.h>

using namespace std;

class EllysTeleport {
public:
	int getMax(int N, int H1, int A, int B, int P, int Q, int M) {
		vector<int> h;
		h.push_back(H1);
		while (h.size() < N) {
			h.push_back((1LL * h.back() * A + B) % M);
		}
		sort(h.begin(), h.end());
		vector<int> p(N, -1);
		for (int i = 0; i < N; ++i) {
			int x = (1LL * h[i] * P + Q) % M;
			p[i] = upper_bound(h.begin(), h.end(), x) - h.begin() - 1;
			// cerr << i << " " << h[i] << " " << p[i] << endl;
		}
		// cerr << endl;
		int ans = 0;
		vector<int> dp(N, -1);
		vector<int> vis(N, 0);
		for (int i = 0; i < N; ++i) {
			if (!vis[i]) {
				vector<int> nodes;
				int now = i;
				while (now != -1 && !vis[now]) {
					nodes.push_back(now);
					vis[now] = 1;
					now = p[now];
				}
				// cerr << now << " " << i << " " << nodes.size() << endl;
				reverse(nodes.begin(), nodes.end());
				if (now == -1) {
					for (int j = 0; j < nodes.size(); ++j)
						dp[nodes[j]] = j+1;
				}
				else {
					if (vis[now] == 1) {
						int cnt = 0;
						for (int j = 0; j < nodes.size(); ++j) {
							if (nodes[j] == now) {
								cnt = j+1;
								break;
							}
						}
						assert(cnt > 0);
						for (int j = 0; j < cnt; ++j)
							dp[nodes[j]] = cnt;
						for (int j = cnt, last = cnt; j < nodes.size(); ++j) {
							dp[nodes[j]] = ++last;
						}
					}
					else {
						int last = dp[now];
						for (int x : nodes) {
							dp[x] = ++last;
						}
					}
				}
				for (int x : nodes)
					vis[x] = 2;
			}
			// cerr << dp[i] << " ";
			ans = max(ans, dp[i]);
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
		cout << "Testing EllysTeleport (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556709487;
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
		EllysTeleport _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 11;
				int H1 = 9;
				int A = 17;
				int B = 9;
				int P = 7;
				int Q = 13;
				int M = 23;
				_expected = 6;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			case 1:
			{
				int N = 8;
				int H1 = 17;
				int A = 23;
				int B = 19;
				int P = 15;
				int Q = 28;
				int M = 43;
				_expected = 4;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			case 2:
			{
				int N = 15;
				int H1 = 42;
				int A = 114;
				int B = 52;
				int P = 76;
				int Q = 1;
				int M = 131;
				_expected = 5;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			case 3:
			{
				int N = 10;
				int H1 = 71;
				int A = 54;
				int B = 85;
				int P = 96;
				int Q = 52;
				int M = 100;
				_expected = 10;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			case 4:
			{
				int N = 1000;
				int H1 = 1337;
				int A = 706135;
				int B = 1085680;
				int P = 1153206;
				int Q = 345473;
				int M = 1234567;
				_expected = 42;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			/*case 5:
			{
				int N = ;
				int H1 = ;
				int A = ;
				int B = ;
				int P = ;
				int Q = ;
				int M = ;
				_expected = ;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}*/
			/*case 6:
			{
				int N = ;
				int H1 = ;
				int A = ;
				int B = ;
				int P = ;
				int Q = ;
				int M = ;
				_expected = ;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}*/
			/*case 7:
			{
				int N = ;
				int H1 = ;
				int A = ;
				int B = ;
				int P = ;
				int Q = ;
				int M = ;
				_expected = ;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
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
