#define nume "patrate3"

#ifndef INFOARENA
#define fisier "../algorithm solutions/" nume
#define DBG
#else
#define fisier nume
#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

ifstream fin(fisier".in");
ofstream fout(fisier".out");

#ifdef DBG
#define fout cout
#endif

const double EPS = 1e-4;

bool eq(const double &a, const double &b)
{
    return abs(a - b) < EPS;
}

struct Point {
    double x,y;
    friend bool operator < (const Point &a, const Point &b) {
        return a.x + EPS < b.x || (eq(a.x,b.x) && a.y + EPS < b.y);
    }
};


int main()
{
    int n;
    fin >> n;
    
    vector<Point> points(n);
    for(int i = 0; i < n; i ++){
        Point a;
        fin >> a.x >> a.y;
        points[i] = a;
//        H.insert(points[i]);
    }
    sort(points.begin(),points.end());
    int sol = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            auto a = points[i];
            auto b = points[j];
            auto c = (Point){a.x + (a.y - b.y), a.y + (b.x - a.x)};
            auto d = (Point){b.x + (a.y - b.y), b.y + (b.x - a.x)};
            if (binary_search(points.begin(), points.end(), c)
             && binary_search(points.begin(), points.end(), d))
                sol ++;
        }
    }
    fout << sol/2 << '\n';
    return 0;
}