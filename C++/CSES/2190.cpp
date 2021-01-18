#include <iostream>

using namespace std;
const double ep = 1e-9;
const int MAXC = 34;

struct point{
    int x, y;
};

int N, x, y;

double ptOnLine(double m, point p, int x){
    return m * (x - p.x) + p.y;
}

bool below(double m, point p, point test){
    return ptOnLine(m, p, test.x) > test.y;
}

bool onLine(double m, point p, point test){
    return abs(ptOnLine(m, p, test.x) - test.y) < ep;
}

point minY (point a, point b){
    if(a.y < b.y) return a;
    return b;
}

point maxY (point a, point b){
    if(a.y > b.y) return a;
    return b;
}

point minX (point a, point b){
    if(a.x < b.x) return a;
    return b;
}

point maxX (point a, point b){
    if(a.x > b.x) return a;
    return b;
}

bool intersect(point a1, point a2, point b1, point b2){
    if(a2.x == a1.x && b1.x == b2.x){
        if(a1.x != b1.x) return false;
        return maxY(a1, a2).y >= minY(b1, b2).y && minY(a1, a2).y <= maxY(b1, b2).y;
    }
    if(a2.x == a1.x){
        if((b1.x < a1.x && b2.x < a1.x) || (b1.x > a1.x && b2.x > a1.x)) return false;
        double bm = ((double) (b2.y - b1.y)) / (b2.x - b1.x);
        if(onLine(bm, b1, a1) || onLine(bm, b1, a2)) return true;
        return below(bm, b1, a1) ^ below(bm, b1, a2);
    }    
    if(b2.x == b1.x){
        if((a1.x < b1.x && a2.x < b1.x) || (a1.x > b1.x && a2.x > b1.x)) return false;
        double am = ((double) (a2.y - a1.y)) / (a2.x - a1.x);
        if(onLine(am, a1, b1) || onLine(am, a1, b2)) return true;
        return below(am, a1, b1) ^ below(am, a1, b2);
    }

    double ma = ((double) (a2.y - a1.y)) / (a2.x - a1.x), mb = ((double) (b2.y - b1.y)) / (b2.x - b1.x);
    bool t = onLine(ma, a1, b1), u = onLine(ma, a1, b2), v = below(ma, a1, b1), w = below(ma, a1, b2);
    if(t && u){
        return maxX(a1, a2).x >= minX(b1, b2).x && minX(a1, a2).x <= maxX(b1, b2).x;
    }
    if(t || u){}
    else if(v ^ w){}
    else return false;

    t = onLine(mb, b1, a1); u = onLine(mb, b1, a2); v = below(mb, b1, a1); w = below(mb, b1, a2);
    if(t || u){}
    else if(v ^ w){}
    else return false;

    return true;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);


   cin >> N;
   for (size_t i = 0; i < N; i++)
   {
       cin >> x >> y;
       point a = {x, y};
       cin >> x >> y;
       point b = {x, y};
       cin >> x >> y;
       point c = {x, y};
       cin >> x >> y;
       point d = {x, y};
       cout << (intersect(a, b, c, d) ? "YES" : "NO") << "\n"; 
   }
}