#include "romberg.h"


double Romberg::calc(Data data, int startX, int endX) {
    if (data.size() < 2) return 0;
    // Lambda mencari 2^n
    auto pow2 = [&](double k) {return pow(2.0, k); };

    Data results;
    double er;
    double temp;

    // Mencari hasil trapezoid dengan 2^i pias
    for (int i = 0; pow2(i) < data.size(); i++) {
        results.push_back(Trapezoid::calc(pow2(i), data, startX, endX));
        
    }

    std::cout << "Tabel romberg :\n";
    std::cout << "\n--------" << "O(h^2)" << "--------\n";
    for (double result : results) {
        std::cout << result << " ";
    }
    std::cout << "\n--------" << "O(h^2)" << "--------\n";

    // Mengaplikasi extrapolasi richardson
    for (int n = 0; n < results.size()-1; n++) {
        std::cout << "\n--------" << "O(h^" << 2 * (n + 2) << ")" << "--------\n";
        temp = results[0];
        for (int i = 1; i < results.size() - n; i++) {
            results[i - 1] = results[i] + (results[i] - results[i - 1]) / ((pow2(2 * n + 2)) - 1);
            std::cout << results[i - 1] << " ";
        }
        er = ((results[0] - temp) / results[0]) * 100;
        std::cout << "\nEr = " << abs(er) << "%";
        std::cout << "\n--------" << "O(h^" << 2 * (n + 2) << ")" << "--------\n";
    }

    return results[0];
}



double Trapezoid::calc(int div, Data data, double startX, double endX) {
    if (data.size() < 2) return 0;

    // Div = jumlah pias
    // f0 + fn
    double result = data.front() + data.back();
    // (b-a)/jumlah pias
    double h = (endX - startX) / (div);

    for (int i = (data.size() - 1) / div; i < data.size() - 1; i += (data.size() - 1) / div) {
        result += 2 * data[i];
    }

    result *= h / 2.0;

    return result;
}


