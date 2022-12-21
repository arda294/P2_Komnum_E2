#include "romberg.h"


double Romberg::calc(Data data, int startX, int endX) {
    if (data.size() < 3) return 0;

    auto pow2 = [&](double k) {return pow(2.0, k); };

    Data results;

    for (int i = 0; pow2(i) < data.size(); i++) {
        results.push_back(Trapezoid::calc(pow2(i), data, startX, endX));
    }

    for (int n = 0; n < results.size(); n++) {
        for (int i = 1; i < results.size() - n; i++) {
            results[i - 1] = results[i] + (results[i] - results[i - 1]) / ((pow2(2 * n + 2)) - 1);
        }
    }

    return results[0];
}



double Trapezoid::calc(int div, Data data, double startX, double endX) {
    if (data.size() < 3) return 0;

    double result = data.front() + data.back();
    double h = (endX - startX) / (div);

    for (int i = (data.size() - 1) / div; i < data.size() - 1; i += (data.size() - 1) / div) {
        result += 2 * data[i];
    }

    result *= h / 2.0;

    return result;
}
