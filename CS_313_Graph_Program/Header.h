#pragma once
#include <vector>
#include <string>
#include <algorithm>
struct Point 
{
    double x;
    double y;
};
struct Edge 
{
    Point start;
    Point end;
};
int orientation(Point p, Point q, Point r);
bool  segmentsIntersect(Point p1, Point q1, Point p2, Point q2);
Point stringToPoint(std::string s);