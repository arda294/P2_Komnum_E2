#include <vector>
#include <math.h>

using Data = std::vector<double>;

namespace Romberg {
    double calc(Data data, int startX, int endX);
}

namespace Trapezoid { 
    double calc(int div, Data data, double startX, double endX);
}