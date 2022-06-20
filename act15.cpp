#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <float.h>

using namespace std;

vector<string> bestFriends(2);

struct Point
{
    string name;
    float x, y;
    Point()
    {
        name = "-";
        x = 0;
        y = 0;
    }

    Point(string name, float x, float y)
    {
        this->name = name;
        this->x = x;
        this->y = y;
    }
};

bool lexicographic(string a, string b)
{
    //Buscar si uno de los string es un substring y regresar el mas grande
    if (a.compare(0, b.size(), b) == 0 || b.compare(0, a.size(), a) == 0)
    {
        return a.size() > b.size();
    }
    else
    {
        //Regresa cual es el string menor (esto ya es una comparacion lexicografica)
        return a < b;
    }  
}

bool compareX(const Point &p1, const Point &p2)
{
    return (p1.x < p2.x);
}

bool compareY(const Point &p1, const Point &p2)
{
    return (p1.y < p2.y);
}

float distance(Point &p1, Point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(vector<Point> &p, int ini, int fin)
{
    float minBF = FLT_MAX;
    float temp;
    string p1;
    string p2;
    
    for(int i = 0; i < fin; i++)
    {
        for(int j = i+1; j <= fin; j++)
        {
            temp = distance(p[i], p[j]);
            if(temp < minBF)
            {
                minBF = temp;
                bestFriends[0] = p[i].name;
                bestFriends[1] = p[j].name;
            }
        }
    }

    return minBF;
}
 
float stripClosest(vector<Point> &strip, float dMenor)
{
    float minStrip = dMenor;
    float temp;
    string p1;
    string p2;

    sort(strip.begin(), strip.end(), compareY);
    
    for(int i = 0; i < strip.size(); i++)
    {
        for(int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < minStrip; j++)
        {
            temp = distance(strip[i], strip[j]);
            if(temp < minStrip)
            {
                minStrip = temp;
                bestFriends[0] = strip[i].name;
                bestFriends[1] = strip[j].name;
            }
        }
    }

    return minStrip;
}

//Complejidad: O(nlogn)
float closest_Helper(vector<Point> &p, int ini, int fin)
{
    if(fin - ini < 3)
    {
        return bruteForce(p, ini, fin);
    }

    int mid = (fin + ini) / 2;
    Point midPoint = p[mid];
    float dl = closest_Helper(p, ini, mid);
    float dr = closest_Helper(p, mid+1, fin);
    float dMenor = dl < dr ? dl : dr;
    vector<Point> strip;

    for(int i = ini; i <= fin; i++)
    {
        if(abs(p[i].x) - midPoint.x < dMenor)
        {
            strip.push_back(p[i]);
        }
    }

    float dResult = stripClosest(strip, dMenor);
    sort(bestFriends.begin(), bestFriends.end(), lexicographic);
    return dResult;
}

float closest(vector<Point> &points)
{   
    sort(points.begin(), points.end(), compareX);
    return closest_Helper(points, 0, points.size()-1);
}

int main()
{
    int n;
    float x, y;
    string name;
    cin >> n;
    vector<Point> points(n);

    for(int i = 0; i < n; i++)
    {
        cin >> name >> x >> y;
        points[i] = Point(name, x, y);
    }

    float ans = closest(points);

    cout.precision(2);
    cout << "Best friend in BeagleTown are: " << bestFriends[0] << " & " << bestFriends[1] << " (" << fixed << ans << ")" << endl;
    return 0;
}