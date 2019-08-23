#include <bits/stdc++.h>

using namespace std;

const vector<int> FAIL = {-1};

vector<int> row[1000];

int encode(int r1, int c1, int r2, int c2) {
	return (r1 * 1000000 + c1 * 10000 + r2 * 100 + c2);
}
class TransformBoardDiv1 {
public:
	vector <int> getOperations(vector <string> start, vector <string> target) {
		int n = start.size(), m = start[0].size();
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (start[i][j] == '#')
					row[j].push_back(i);
				if (target[i][j] == '#') {
					int k = j;
					while (k >= 0 && row[k].size() == 0) --k;
					if (k < 0) {
						return FAIL;
					}
					int r = row[k].back();
					row[k].pop_back();
					if (k != j) {
						if (target[r][j] == '#') {
							if (r != i)
								ans.push_back(encode(r, j, i, j));
							ans.push_back(encode(r, k, r, j));
							r = i;
						}
						else {
							ans.push_back(encode(r, k, r, j));
						}
					}
					if (r != i) {
						ans.push_back(encode(r, j, i, j));
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < m; ++i)
			cnt += row[i].size();
		if (cnt & 1)
			return FAIL;
		for (int i = 0; i < m; ++i) {
			while (row[i].size() >= 2) {
				int r2 = row[i].back(); row[i].pop_back();
				int r1 = row[i].back(); row[i].pop_back();
				ans.push_back(encode(r1, i, r2, i));
			}
		}
		for (int i = 0; i < m; ++i) {
			if (row[i].empty()) continue;
			for (int j = i+1; j < m; ++j) {
				if (row[j].empty()) continue;
				int r1 = row[i].back();
				int r2 = row[j].back();
				int c1 = i, c2 = j;
				row[i].pop_back();
				row[j].pop_back();
				if (r1 > r2) {
					swap(r1, r2);
					swap(c1, c2);
				}
				if (target[r2][c1] == '#') {
					ans.push_back(encode(r2, c1, r2, c2));
					if (r1 != r2)
						ans.push_back(encode(r1, c1, r2, c1));
				}
				else {
					if (r1 != r2)
						ans.push_back(encode(r1, c1, r2, c1));					
					ans.push_back(encode(r2, c1, r2, c2));
				}
				break;
			}
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
		cout << "Testing TransformBoardDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1549111261;
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
		TransformBoardDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string start[] = {"#.",".."};
				string target[] = {"..",".#"};
				int __expected[] = {1, 10101 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOperations(vector <string>(start, start+sizeof(start)/sizeof(string)), vector <string>(target, target+sizeof(target)/sizeof(string))); break;
			}
			case 1:
			{
				string start[] = {"..",".#"};
				string target[] = {"#.",".."};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOperations(vector <string>(start, start+sizeof(start)/sizeof(string)), vector <string>(target, target+sizeof(target)/sizeof(string))); break;
			}
			case 2:
			{
				string start[] = {"#..#","#..."};
				string target[] = {"....","...#"};
				int __expected[] = {3, 1000103 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOperations(vector <string>(start, start+sizeof(start)/sizeof(string)), vector <string>(target, target+sizeof(target)/sizeof(string))); break;
			}
			case 3:
			{
				string start[] = {"###############################################", "###############################################", "###############################################", "###############################################", "###############################################", "###############################################", "###############################################", "###############################################", "##############################################."};
				string target[] = {".##############################################", "###############################################", "###############################################", "###############################################", "###############################################", "###############################################", "###############################################", "###############################################", "###############################################"};
				int __expected[] = {};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOperations(vector <string>(start, start+sizeof(start)/sizeof(string)), vector <string>(target, target+sizeof(target)/sizeof(string))); break;
			}
			case 4:
			{
				string start[] = {"###############################################", "###############################################", "##########.#...#.#.##.#..#####.#####.##.#######", "##########.#.####.#####..#..####.##############", "#.#######..#.##..##.#.######.#.#.######.#..#.##", "..#.#####.######.####.#.#.####.#.##.#.#####..##", "##.##############.##.###########.####.##..###..", "###..###.##########.#...#.##.#############.####", "###..##..#.#######.#..#..#########.####.#######"};
				string target[] = {".......#....#..#.#....#...#....#......#........", "......##...##......##..#...#.#......##.......#.", ".#..#.##.##..###.#...#.......#....#.#.###..#.#.", "##.#....#.....#........##....#.#....#...#....#.", ".#..........#..#.#..##.#.#...#..###....#....#..", "###...#...#...#..##...#..#......#..##..........", "#..##...#..#..#............##.##..##..#...#...#", "..###.##...#...#........#.#..#.##...#..#....##.", "##.......##..#........#.........#..###..#.....#"};
				int __expected[] = {};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOperations(vector <string>(start, start+sizeof(start)/sizeof(string)), vector <string>(target, target+sizeof(target)/sizeof(string))); break;
			}
			/*case 5:
			{
				string start[] = ;
				string target[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getOperations(vector <string>(start, start+sizeof(start)/sizeof(string)), vector <string>(target, target+sizeof(target)/sizeof(string))); break;
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
