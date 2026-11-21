#include <bits/stdc++.h>

using namespace std;
using pid = pair<int, double>;

const double EPS = 1e-6;

int N, L;

pair<int, double> vt[1006];

double dist;

inline bool equals(double a, double b){
    return fabs(a - b) < EPS;
}

struct Cross{

    int ord1;
    double d1;

    int ord2;
    double d2;

    bool operator<(const Cross& t){
        return max(d1, d2) < max(t.d1, t.d2);
    }
};

vector<Cross> v;

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
};

Point cross;

struct HLine{
    Point s, e, v;

    double A, B, C;

    HLine(){}

    HLine(Point ns, Point ne){
        s = ns, e = ne, v = e - s;
        A = e.y - s.y, B = s.x - e.x;
        C = A * s.x + B * s.y;
    }

    bool isMeet(HLine& r){
        double det1 = A * r.B - B * r.A, det2 = B * r.C - C * r.B, det3 = A * r.C - C * r.A;

        if(equals(det1, 0) && (!equals(det2, 0) || !equals(det3, 0))) return false;

        Point cp = s;

        if(equals(det1, 0)){
            double rv1 = v * (r.s - s), rv2 = r.v * (s - r.s);

            if(rv1 < -EPS && rv2 < -EPS) return false;

            if(rv1 > 0 && rv2 < 0) cross = r.s;
            else if(rv1 < 0 && rv2 > 0) cross = cp;
            else cross = {(cp.x + r.s.x) / 2, (cp.y + r.s.y) / 2};
        }

        else{
            cp = {-det2 / det1, det3 / det1};
            double rv1 = v * (cp - s), rv2 = r.v * (cp - r.s);

            cross = cp;

            if(rv1 < -EPS || rv2 < -EPS) return false;
            if(cp.x < -EPS || cp.y < -EPS || (cp.x - L) > EPS || (cp.y - L) > EPS) return false;
        }

        return true;
    }

}line[1004];

HLine wall[4];

int main()
{
    scanf("%d %d", &N, &L);

    for(int i = 0; i < N; i++){
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        line[i] = HLine({x1, y1}, {x2, y2});
    }

    wall[0] = HLine({0, 0}, {0, L});
    wall[1] = HLine({0, 0}, {L, 0});
    wall[2] = HLine({0, L}, {L, L});
    wall[3] = HLine({L, 0}, {L, L});

    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(line[i].isMeet(line[j])){
                double x1 = cross.x - line[i].s.x, y1 = cross.y - line[i].s.y;
                double x2 = cross.x - line[j].s.x, y2 = cross.y - line[j].s.y;

                double d1 = sqrt((x1 * x1) + (y1 * y1));
                double d2 = sqrt((x2 * x2) + (y2 * y2));

                v.push_back({i, d1, j, d2});
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            if(line[i].isMeet(wall[j])){
                double x1 = cross.x - line[i].s.x, y1 = cross.y - line[i].s.y;
                double x2 = cross.x - wall[j].s.x, y2 = cross.y - wall[j].s.y;

                double d1 = sqrt((x1 * x1) + (y1 * y1));
                double d2 = sqrt((x2 * x2) + (y2 * y2));

                v.push_back({i, d1, j + N, d2});
            }
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(v[i].ord2 >= N && vt[v[i].ord1].first) continue;

        if(vt[v[i].ord1].first && vt[v[i].ord2].first) continue;

        if(v[i].ord2 >= N){
            dist = max(dist, v[i].d1);
        
            vt[v[i].ord1] = {1, v[i].d1};
        }

        else if(vt[v[i].ord1].first){
            dist = max(dist, v[i].d2);
            
            if(vt[v[i].ord1].second >= v[i].d1){
                if(v[i].d2 >= v[i].d1) vt[v[i].ord2] = {1, v[i].d2};
            }
        }

        else if(vt[v[i].ord2].first){
            dist = max(dist, v[i].d1);

            if(vt[v[i].ord2].second >= v[i].d2){
                if(v[i].d1 >= v[i].d2) vt[v[i].ord1] = {1, v[i].d1};
            }
        }

        else{
            if(v[i].d1 > v[i].d2){
                vt[v[i].ord1] = {1, v[i].d1};
                dist = v[i].d1;
            }

            else if(v[i].d1 < v[i].d2){
                vt[v[i].ord2] = {1, v[i].d2};
                dist = v[i].d2;
            }

            else{
                vt[v[i].ord1] = vt[v[i].ord2] = {1, v[i].d1};
                dist = v[i].d1;
            }
        }
    }

    printf("%.2f", dist);

    return 0;
}
