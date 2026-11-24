#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;

int N, L, ans;

inline bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

struct Point{
    double x, y;

    Point operator-(const Point& r){
        return {x - r.x, y - r.y};
    }

    double operator*(const Point& r){
        return x * r.x + y * r.y;
    }

    double operator^(const Point& r){
        return x * r.y - y * r.x;
    }

    bool operator<(const Point& r){
        return x < r.x || (x == r.x && y < r.y);
    }
    /*
    friend Point operator+(const int &a, const Point &b) {

    }
    */
};

struct HLine{
    Point s, e, v;

    double A, B, C;

    HLine(){}

    HLine(Point ns, Point ne)
    {
        s = ns, e = ne, v = e - s;
        A = e.y - s.y, B = s.x - e.x;
        C = A * s.x + B * s.y;
    }

    bool isMeet(HLine& r)
    {
        double det1 = A * r.B - B * r.A, det2 = B * r.C - C * r.B, det3 = A * r.C - C * r.A;

        if(equals(det1, 0) && (!equals(det2, 0) || !equals(det3, 0))) return false;

        Point cp = s;

        if(equals(det1, 0))
        {
            double rv1 = v * (r.s - s), rv2 = r.v * (s - r.s);

            if(rv1 < -EPS && rv2 < -EPS) return false;
        }

        else
        {
            cp = {-det2 / det1, det3 / det1};
            double rv1 = v * (cp - s), rv2 = r.v * (cp - r.s);

            if(rv1 < -EPS || rv2 < -EPS) return false;
            if(cp.x < -EPS || cp.y < -EPS || (cp.x - L) > EPS || (cp.y - L) > EPS) return false;
        }

        return true;
    }

}line[1004];

int main()
{
    scanf("%d %d", &N, &L);

    for(int i = 0; i < N; i++)
    {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        line[i] = HLine({x1, y1}, {x2, y2});
    }

    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(line[i].isMeet(line[j])) ans++;
        }
    }

    printf("%d", ans);

    return 0;
}