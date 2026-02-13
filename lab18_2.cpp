#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(const Rect *a, const Rect *b){
    double aLeft  = a->x;
    double aRight = a->x + a->w;
    double bLeft  = b->x;
    double bRight = b->x + b->w;
    
    double aTop    = a->y;
    double aBottom = a->y - a->h;
    double bTop    = b->y;
    double bBottom = b->y - b->h;

    double left, right, bottom, top;

    if (aLeft > bLeft) left = aLeft;
    else left = bLeft;

    if (aRight < bRight) right = aRight;
    else right = bRight;

    if (aBottom > bBottom) bottom = aBottom;
    else bottom = bBottom;

    if (aTop < bTop) top = aTop;
    else top = bTop;

    double overlapW = right - left;
    double overlapH = top - bottom;
    
    if (overlapW <= 0 || overlapH <= 0) return 0;
    return overlapW * overlapH;
}
