#include <bits/stdc++.h>

using namespace std;

int cnt[313][313];

class FloodFill {
public:
	vector <int> getCell(vector <int> X, vector <int> Y, long long A) {
		int n = X.size();
		A += n;
		long long low = 1, hig = 1e9;
		auto find_id = [](vector<long long> & v, long long z) {
			return lower_bound(v.begin(), v.end(), z) - v.begin();
		};

		auto calc = [&](long long rad) {
			vector<long long> ally, allx;
			for (int i = 0; i < n; ++i) {
				long long xl = X[i] - rad, xr = X[i] + rad + 1;
				long long yl = Y[i] - rad, yr = Y[i] + rad + 1;
				ally.emplace_back(yl);
				ally.emplace_back(yr);
				allx.emplace_back(xl);
				allx.emplace_back(xr);
			}
			sort(ally.begin(), ally.end());
			ally.erase(unique(ally.begin(), ally.end()), ally.end());
			sort(allx.begin(), allx.end());
			allx.erase(unique(allx.begin(), allx.end()), allx.end());
			for (int i = 0; i <= allx.size(); ++i) {
				for (int j = 0; j <= ally.size(); ++j) {
					cnt[i][j] = 0;
				}
			}

			for (int i = 0; i < n; ++i) {
				long long xl = X[i] - rad, xr = X[i] + rad + 1;
				long long yl = Y[i] - rad, yr = Y[i] + rad + 1;
				xl = find_id(allx, xl);
				xr = find_id(allx, xr);
				yl = find_id(ally, yl);
				yr = find_id(ally, yr);
				for (int x = xl; x < xr; ++x) {
					for (int y = yl; y < yr; ++y) {
						cnt[x][y] = 1;
					}
				}
			}
			long long tot = 0;
			for (int i = 0; i < allx.size(); ++i) {
				long long dx = allx[i+1] - allx[i];
				long long add = 0;
				for (int j = 0; j < ally.size(); ++j) {
					if (cnt[i][j]) {
						add += (ally[j+1] - ally[j]);
					}
				}
				tot += add * dx;
			}
			return tot;
		};
		while (low < hig) {
			long long mid = (low + hig + 1) >> 1;
			long long rad = mid - 1;
			long long tot = calc(rad);
			if (tot < A) {
				low = mid;
			} else {
				hig = mid - 1;
			}
		}

		A -= calc(low - 1);
		{
			long long rad = low;
			vector<long long> ally, allx;
			for (int i = 0; i < n; ++i) {
				long long xl = X[i] - rad, xr = X[i] + rad + 1;
				long long yl = Y[i] - rad, yr = Y[i] + rad + 1;
				ally.emplace_back(yl);
				ally.emplace_back(yl+1);
				ally.emplace_back(yr);
				ally.emplace_back(yr-1);
				allx.emplace_back(xl);
				allx.emplace_back(xl+1);
				allx.emplace_back(xr);
				allx.emplace_back(xr-1);
			}
			sort(ally.begin(), ally.end());
			ally.erase(unique(ally.begin(), ally.end()), ally.end());
			sort(allx.begin(), allx.end());
			allx.erase(unique(allx.begin(), allx.end()), allx.end());
			for (int i = 0; i <= allx.size(); ++i) {
				for (int j = 0; j <= ally.size(); ++j) {
					cnt[i][j] = 0;
				}
			}
			for (int i = 0; i < n; ++i) {
				long long xl = X[i] - rad, xr = X[i] + rad + 1;
				long long yl = Y[i] - rad, yr = Y[i] + rad + 1;
				xl = find_id(allx, xl);
				xr = find_id(allx, xr);
				yl = find_id(ally, yl);
				yr = find_id(ally, yr);
				for (int x = xl; x < xr; ++x) {
					cnt[x][yl] = 1;
					cnt[x][yr-1] = 1;
				}
				for (int y = yl; y < yr; ++y) {
					cnt[xl][y] = 1;
					cnt[xr-1][y] = 1;
				}
			}
			for (int i = 0; i < n; ++i) {
				long long xl = X[i] - rad, xr = X[i] + rad + 1;
				long long yl = Y[i] - rad, yr = Y[i] + rad + 1;
				xl = find_id(allx, xl);
				xr = find_id(allx, xr);
				yl = find_id(ally, yl);
				yr = find_id(ally, yr);
				for (int x = xl+1; x+1 < xr; ++x) {
					for (int y = yl+1; y+1 < yr; ++y) {
						cnt[x][y] = 0;
					}
				}
			}
			for (int i = 0; i < allx.size(); ++i) {
				long long add = 0;
				for (int j = 0; j < ally.size(); ++j) {
					if (cnt[i][j]) {
						add += (ally[j+1] - ally[j]);
					}
				}
				long long dx = allx[i+1] - allx[i];
				if (add * dx >= A) {
					long long mul = A / add;
					if (mul * add == A) {
						--mul;
					}
					A -= mul * add;
					int x = allx[i] + mul;
					for (int j = 0; j < ally.size(); ++j) {
						if (cnt[i][j]) {
							long long dy = (ally[j+1] - ally[j]);
							if (dy >= A) {
								return {x, (int)(ally[j] + A - 1)};
							} else {
								A -= dy;
							}
						}
					}
				} else {
					A -= add * dx;
				}
			}
		}
		return {-1, -1};
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
		cout << "Testing FloodFill (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1607099002;
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
		FloodFill _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {4, 5};
				int Y[] = {7, 2};
				long long A = 1LL;
				int __expected[] = {3, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
			}
			case 1:
			{
				int X[] = {4, 5};
				int Y[] = {7, 2};
				long long A = 8LL;
				int __expected[] = {4, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
			}
			case 2:
			{
				int X[] = {4, 5};
				int Y[] = {7, 2};
				long long A = 17LL;
				int __expected[] = {2, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
			}
			case 3:
			{
				int X[] = {4, 5};
				int Y[] = {7, 2};
				long long A = 53LL;
				int __expected[] = {1, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
			}
			case 4:
			{
				int X[] = {4, 5};
				int Y[] = {7, 2};
				long long A = 84LL;
				int __expected[] = {8, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
			}
			case 5:
			{
				int X[] = {0};
				int Y[] = {0};
				long long A = 123456789012LL;
				int __expected[] = {64258, -175682 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
			}
			case 6:
			{
				int X[] = {0, 0, 0, 1, 1, 2, 2, 2};
				int Y[] = {0, 1, 2, 0, 2, 0, 1, 2};
				long long A = 17LL;
				int __expected[] = {3, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
			}
			case 7:
			{
				int X[] = {1, 11, 21, 31, 41, 51, 61, 71, 81, 91, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 201, 211, 221, 231, 241, 251, 261, 271, 281, 291};
				int Y[] = {1, 11, 21, 31, 41, 51, 61, 71, 81, 91, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 201, 211, 221, 231, 241, 251, 261, 271, 281, 291};
				long long A = 30 * 8;
				int __expected[] = {292, 292};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
			}
			/*case 8:
			{
				int X[] = ;
				int Y[] = ;
				long long A = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
			}*/
			/*case 9:
			{
				int X[] = ;
				int Y[] = ;
				long long A = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getCell(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), A); break;
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
