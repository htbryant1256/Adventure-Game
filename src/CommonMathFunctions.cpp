#include "CommonMathFunctions.h"


float CommonMathFunctions::distanceFormula(int x1, int x2, int y1, int y2)
{
    return abs(sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}
