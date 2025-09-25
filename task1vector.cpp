#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <limits>

using namespace std;

int main() {
    // Vector to store days of the week
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    // Vector to store temperature readings for each day
    vector<double> temperatures;
    
    cout << "Enter temperature readings for each day of the week:\n"<< std::endl;
    for (const auto& day : days) {
        double temp;
        cout << day << ": ";
        cin >> temp;
        temperatures.push_back(temp);
    }
    
    cout << "\n= Weather Data for the Week =\n"<< std::endl;
    
    // Variables to track the warmest day
    double maxTemp = -numeric_limits<double>::infinity();
    string warmestDay;
    
    // Print each day and its temperature with classification
    for (size_t i = 0; i < days.size(); i++) {
        string classification;
        
        if (temperatures[i] < 10) {
            classification = "Cold";
        } else if (temperatures[i] <= 20) {
            classification = "Ok";
        } else {
            classification = "Warm";
        }
        
        cout << days[i] << ": " << temperatures[i] << "°C - " << classification << endl;
        
        // Track warmest day
        if (temperatures[i] > maxTemp) {
            maxTemp = temperatures[i];
            warmestDay = days[i];
        }
    }
    
    // Store warmest day in a tuple
    tuple<string, double> warmestDayInfo = make_tuple(warmestDay, maxTemp);
    
    // Print the information
    cout << "\n= Warmest Day of the Week =\n"<< std::endl;
    cout << "Day: " << get<0>(warmestDayInfo) << std::endl;
    cout << "Temperature: " << get<1>(warmestDayInfo) << "°C" << std::endl;
    
    return 0;
}