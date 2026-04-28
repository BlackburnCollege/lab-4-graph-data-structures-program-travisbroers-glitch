#include "Header.h"
int orientation(Point p, Point q, Point r) 
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool segmentsIntersect(Point A, Point B, Point C, Point D)
{
    int o1 = orientation(A, B, C);
    int o2 = orientation(A, B, D);
    int o3 = orientation(C, D, A);
    int o4 = orientation(C, D, B);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(A, C, B)) return true;
    if (o2 == 0 && onSegment(A, D, B)) return true; 
    if (o3 == 0 && onSegment(C, A, D)) return true;
    if (o4 == 0 && onSegment(C, B, D)) return true; 

    return false; 
}
Point stringToPoint(std::string s) 
{
    size_t commaPos = s.find(',');
    double x = std::stod(s.substr(0, commaPos));
    double y = std::stod(s.substr(commaPos + 1));
    return { x, y };
}
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;
    return false;
}