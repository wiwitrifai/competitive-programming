#include <bits/stdc++.h>

using namespace std;

class GridSort {
public:
	string sort(int n, int m, vector <int> grid) {
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				for (int k = 1; k < m; k++) {
					if (grid[i * m + k] - grid[i * m + k-1] != grid[j * m + k] - grid[j * m + k-1])
						ok = 0;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = i+1; j < m; j++) {
				for (int k = 1; k < n; k++) {
					if (grid[k * m + i] - grid[(k-1) * m + i] != grid[k * m + j] - grid[(k-1)* m + j])
						ok = 0;
				}
			}
		}
		int l = ((grid[0]-1)/m) * m, r = l + m; 
		for (int i = 0; i < m; i++) {
			if (grid[i] > r || grid[i] <= l)
				ok = 0;
		}
		return ok ? "Possible" : "Impossible";
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
		cout << "Testing GridSort (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486971400;
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
		GridSort _obj;
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
				_expected = "Possible";
				_received = _obj.sort(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              3,4,
				              1,2
				             };
				_expected = "Possible";
				_received = _obj.sort(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              4,3,
				              1,2
				             };
				_expected = "Impossible";
				_received = _obj.sort(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1;
				int m = 10;
				int grid[] = {4,5,1,2,9,8,3,10,7,6};
				_expected = "Possible";
				_received = _obj.sort(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 3;
				int m = 5;
				int grid[] = {
				              10,6,8,9,7,
				              5,1,3,4,2,
				              15,11,13,14,12
				             };
				_expected = "Possible";
				_received = _obj.sort(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 6;
				int m = 2;
				int grid[] = {
				              11,12,
				              2,1,
				              9,10,
				              7,8,
				              6,5,
				              3,4
				             };
				_expected = "Impossible";
				_received = _obj.sort(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 2;
				int m = 2;
				int grid[] = {2, 4,
											1, 3};
				_expected = "Impossible";
				_received = _obj.sort(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			/*case 7:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.sort(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.sort(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
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
