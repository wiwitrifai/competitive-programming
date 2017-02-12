#include <bits/stdc++.h>

using namespace std;

int x[55][55], r, c;
bool fr[55], fc[55];

void swap_col(int p, int q) {
	// // cerr << "swap col " << p << " " << q << endl;
	if (p == q) return;
	for (int i = 0; i < r; i++) {
		swap(x[i][p], x[i][q]);
	}
}
void swap_row(int p, int q) {
	// // cerr << "swap row " << p << " " << q << endl;
	if (p == q) return;
	for (int i = 0; i < c; i++)
		swap(x[p][i], x[q][i]);
}

class GridSortMax {
public:
	string findMax(int n, int m, vector <int> grid) {
		r = n, c = m;
		int a, b;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				x[i][j] = grid[i * m + j];
			}
		memset(fr, 0, sizeof fr);
		memset(fc, 0, sizeof fc);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int now = i * m + j + 1;
				if (x[i][j] == now) {
					fr[i] = fc[j] = 1;
				}
				if (fr[i] && fc[j]) continue;
				if (fr[i]) {
					for (int k = 0; k < c; k++) if (!fc[k] && x[i][k] == now) {
						swap_col(j, k);
						fc[j] = 1;
						break;
					}
				}
				else if (fc[j]) {
					for (int k = 0; k < r; k++) if (!fr[k] && x[k][j] == now) {
						swap_row(i, k);
						fr[i] = 1;
						break;
					}
				}
				else {
					// // cerr << "tes " << now << " " << i << " " << j << " " << fr[0] << " " << fc[0] << endl;
					bool found = 0;
					for (int p = 0; p < r && !found; p++) if (!fr[p]) {
						for (int q = 0; q < c && !found; q++) if (!fc[q]) {
							// // cerr << now << " " << x[p][q] << endl;
							if (x[p][q] == now) {
								swap_row(p, i);
								swap_col(q, j);
								found = 1;
								fr[i] = fc[j] = 1;
							}
						}
					}
				}
			}
		}
		string ans(grid.size(), '0');
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i * m + j] += (x[i][j] == (i * m + j + 1));
				// cerr << x[i][j];
			}
			// cerr << endl;
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
		cout << "Testing GridSortMax (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486982007;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GridSortMax _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              1,2,
				              3,4
				             };
				_expected = "1111";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              2,1,
				              3,4
				             };
				_expected = "1100";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              4,2,
				              3,1
				             };
				_expected = "1001";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1;
				int m = 10;
				int grid[] = {10,6,2,3,5,7,1,9,4,8};
				_expected = "1111111111";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 3;
				int m = 5;
				int grid[] = {
				              5,2,10,7,9,
				              3,4,14,11,1,
				              15,12,6,8,13
				             };
				_expected = "101100100100000";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 6;
				int m = 2;
				int grid[] = {
				              3,9,
				              5,1,
				              10,6,
				              2,7,
				              8,11,
				              12,4
				             };
				_expected = "100000101010";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
