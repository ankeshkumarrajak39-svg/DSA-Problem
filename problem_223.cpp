#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// Rectangle A area
int rectangleA(int ax1, int ay1, int ax2, int ay2,
               int bx1, int by1, int bx2, int by2)
{

    int widthofA = ax2 - ax1;
    int heightofA = ay2 - ay1;

    return widthofA * heightofA;
}

// Rectangle B area
int rectangleB(int ax1, int ay1, int ax2, int ay2,
               int bx1, int by1, int bx2, int by2)
{

    int widthofB = bx2 - bx1;
    int heightofB = by2 - by1;

    return widthofB * heightofB;
}

int computeArea(int ax1, int ay1, int ax2, int ay2,
                int bx1, int by1, int bx2, int by2)
{

    int areaofrecA = rectangleA(ax1, ay1, ax2, ay2,
                                bx1, by1, bx2, by2);

    int areaofrecB = rectangleB(ax1, ay1, ax2, ay2,
                                bx1, by1, bx2, by2);

    // Overlapping rectangle
    int zx1 = max(ax1, bx1);
    int zy1 = max(ay1, by1);
    int zx2 = min(ax2, bx2);
    int zy2 = min(ay2, by2);

    int widthofoverlap = zx2 - zx1;
    int heightofoverlap = zy2 - zy1;

    // No overlap
    if (widthofoverlap <= 0 || heightofoverlap <= 0)
        return areaofrecA + areaofrecB;

    int areaofoverlap = widthofoverlap * heightofoverlap;

    return areaofrecA + areaofrecB - areaofoverlap;
}
    int main()
    {
        //fuction call

        return 0;
    }
