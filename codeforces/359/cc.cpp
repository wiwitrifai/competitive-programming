// Copyright (C) 2016 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.


#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

using std::sort;
using std::generate;
using std::min_element;
using std::max_element;

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

struct coord {
    int64_t x;
    int64_t y;
    int64_t z;
};

struct equation {
    pair<int64_t, int64_t> S;
    pair<int64_t, int64_t> a;
    pair<int64_t, int64_t> b;
    pair<int64_t, int64_t> c;
};

vector<coord> list;

equation operator+(const equation& e1, const equation& e2) {
    equation res;
    res.S = {max(e1.S.first, e2.S.first), min(e1.S.second, e2.S.second)};
    res.a = {max(e1.a.first, e2.a.first), min(e1.a.second, e2.a.second)};
    res.b = {max(e1.b.first, e2.b.first), min(e1.b.second, e2.b.second)};
    res.c = {max(e1.c.first, e2.c.first), min(e1.c.second, e2.c.second)};
    return res;
}

coord get_solution(const equation& eq) {
    if ((eq.S.first > eq.S.second)
     or (eq.a.first > eq.a.second)
     or (eq.b.first > eq.b.second)
     or (eq.c.first > eq.c.second))
        return coord {INT64_MAX, INT64_MAX, INT64_MAX};
        
     if ((eq.a.first + eq.b.first + eq.c.first > eq.S.second)
     or (eq.a.second + eq.b.second + eq.c.second < eq.S.first))
        return coord {INT64_MAX, INT64_MAX, INT64_MAX};

     coord res;
     res.x = eq.a.first;
     res.y = eq.b.first;
     res.z = eq.c.first;
     int64_t delta = max(int64_t(0), eq.S.first - res.x - res.y - res.z);

     res.x += min(delta, eq.a.second - eq.a.first);
     delta -= min(delta, eq.a.second - eq.a.first);
     res.y += min(delta, eq.b.second - eq.b.first);
     delta -= min(delta, eq.b.second - eq.b.first);
     res.z += min(delta, eq.c.second - eq.c.first);
     delta -= min(delta, eq.c.second - eq.c.first);

     assert(delta == 0);
     
     return res;
}

int64_t DIV2(int64_t arg) {
    return (arg - (arg & 1)) / 2;
}

coord can(int64_t MAXANS) {
    equation eq;
    eq.S = eq.a = eq.b = eq.c = {INT64_MIN, INT64_MAX};
    
    for (const coord& crd: list) {
        equation nw;
        nw.S = { crd.x + crd.y + crd.z - MAXANS,  crd.x + crd.y + crd.z + MAXANS};
        nw.a = {-crd.x + crd.y + crd.z - MAXANS, -crd.x + crd.y + crd.z + MAXANS};
        nw.b = { crd.x - crd.y + crd.z - MAXANS,  crd.x - crd.y + crd.z + MAXANS};
        nw.c = { crd.x + crd.y - crd.z - MAXANS,  crd.x + crd.y - crd.z + MAXANS};
        
        eq = eq + nw;
    }

    for (int64_t r = 0; r <= 1; ++r) {
        equation tr = eq;

        tr.S.first  = DIV2(tr.S.first - 3 * r + 1);
        tr.a.first  = DIV2(tr.a.first - r + 1);
        tr.b.first  = DIV2(tr.b.first - r + 1);
        tr.c.first  = DIV2(tr.c.first - r + 1);

        tr.S.second = DIV2(tr.S.second - 3 * r);
        tr.a.second = DIV2(tr.a.second - r);
        tr.b.second = DIV2(tr.b.second - r);
        tr.c.second = DIV2(tr.c.second - r);

        coord sol = get_solution(tr);
        if (sol.x != INT64_MAX) {
            coord ans;
            ans.x = r + sol.y + sol.z;
            ans.y = r + sol.x + sol.z;
            ans.z = r + sol.x + sol.y;

            return ans;
        }
    }
    return coord {INT64_MAX, INT64_MAX, INT64_MAX};
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list.reserve(100000);
    
    for (size_t T = input<size_t>(); T != 0; --T) {
        list.resize(input<size_t>());
        
        for (coord& crd: list)
            cin >> crd.x >> crd.y >> crd.z;

        int64_t L = -1; // definitely imposible
        int64_t R = 3 * int64_t(1000 * 1000 * 1000) * int64_t(1000 * 1000 * 1000) + 10; // definitely possible

        while (R - L > 1) {
            int64_t M = L + (R - L) / 2;
            if (can(M).x != INT64_MAX)
                R = M;
            else
                L = M;
        }
        coord ans = can(R);
        cout << ans.x << " " << ans.y << " " << ans.z << "\n";
    }
    
    return 0;
}