#include <bits/stdc++.h>
//made by @TonyRusher Codeforces

using namespace std;
 
struct point {
    int x, y;
};
 
bool compareX(const point& a, const point& b) {
    return a.x < b.x;
}
 
bool compareY(const point& a, const point& b) {
    return a.y < b.y;
}
 
double distance(const point& a, const point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
 
 
double bruteForce(const vector<point>& points, int n) {
    double min = 1e9;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j)
            if (distance(points[i], points[j]) < min)
                min = distance(points[i], points[j]);
    }
    return min;
}
 
double find_strip_closest(vector<point> & strip, double min){
    int n = strip.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n && (  (strip[j].y - strip[i].y) < min  ); j++){
            if(distance(strip[i], strip[j]) < min)
                min = distance(strip[i], strip[j]);
        }
    }
    return min;
}
 
double closest_pair(vector<point> & points){
    int n = points.size();
    if(n <= 3)
        return bruteForce(points, n);
    int mid = n/2;
    vector<point> left(points.begin(), points.begin() + mid);
    vector<point> right(points.begin() + mid, points.end());
 
    double d = min(closest_pair(left), closest_pair(right));
 
    vector<point> strip;
    for(int i = 0; i < n; i++){
        if(abs(points[i].x - points[mid].x) < d)
            strip.push_back(points[i]);
    }
 
    sort(strip.begin(), strip.end(), compareY);
 
    return min(d, find_strip_closest(strip, d));
}
 
int main(){
    int n;
    cin >> n;
    vector<point> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end(), compareX);
    double ans = closest_pair(points);
 
    cout<<"Closest Pair:"<< ans << endl;
    return 0;
}