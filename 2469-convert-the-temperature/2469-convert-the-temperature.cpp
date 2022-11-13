class Solution {
public:
    vector<double> convertTemperature(double Celsius) {
        double Kelvin = Celsius + 273.15;
        double Fahrenheit = Celsius * 1.80 + 32.00;
        return {Kelvin, Fahrenheit};
    }
};