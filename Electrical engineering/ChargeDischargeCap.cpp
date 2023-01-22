#include <iostream>
#include <cmath>
#include "matplotlibcpp.h"

using namespace std;
using namespace matplotlibcpp;

int main()
{
    double capacitance;

    cout << "Enter the capacitance in microfarads: ";
    cin >> capacitance;

    // Create a vector of time and voltage
    vector<double> time;
    vector<double> voltage;

    // Charging curve
    for(double i = 0; i <= 10; i += 0.01)
    {
        time.push_back(i);
        voltage.push_back(exp(-i / (capacitance * 0.001)));
    }

    // plot the curve
    plot(time, voltage);
    xlabel("Time (s)");
    ylabel("Voltage (V)");
    title("Capacitor charging and discharging curve");
    grid(true);
    show();

    return 0;
}