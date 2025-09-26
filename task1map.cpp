#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <iomanip>

using namespace std;

int displayWeatherCodes() {
    cout << "Weather Condition Codes:\n";
    cout << "S = Sunny\n";
    cout << "R = Rainy\n";
    cout << "C = Cloudy\n";
    cout << "P = Partly Cloudy\n";
    cout << "W = Windy\n";
    cout << "F = Foggy\n\n";
}

int main() {
    map<string, double> weatherData;
    map<string, char> weatherConditions;
    
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    // Map weather condition
    map<char, string> conditionDescriptions = {
        {'S', "Sunny"},
        {'R', "Rainy"},
        {'C', "Cloudy"},
        {'P', "Partly Cloudy"},
        {'W', "Windy"},
        {'F', "Foggy"}
    };
    
    cout << "= Weather Data Entry System =\n"<< std::endl;
    cout << "Enter weather data for the week:\n"<< std::endl;
    
    displayWeatherCodes();
    
    cout << "Please enter the following data for each day: "<< std::endl;
    cout << "- Temperature in °C "<< endl;
    cout << "- Weather condition code (S, R, C, P, W, or F) \n"<< endl;
    
    for (const auto& day : days) {
        double temp;
        char condition;
        
        cout << "= " << day << " ="<< std::endl;
        cout << "Temperature (°C): "<< std::endl;
        cin >> temp;
    
        while (true) {
            cout << "Weather condition (S/R/C/P/W/F): "<< std::endl;
            cin >> condition;
            condition = toupper(condition);
            
            // Check if the entered condition is valid
            if (conditionDescriptions.find(condition) != conditionDescriptions.end()) {
                break;
            } else {
                cout << "Invalid condition code! Please use S, R, C, P, W, or F.\n"<< std::endl;
            }
        }
        
        weatherData[day] = temp;
        weatherConditions[day] = condition;
        cout << endl;
    }
    
    cout << "\n= Weather Data for the Week =\n"<< std::endl;
    cout << setprecision(1) << fixed;
    
    // For calculations
    double totalTemp = 0;
    double maxTemp = 100.0;
    double minTemp = -100.0;
    string warmestDay, coldestDay;
    
    cout << "Daily Weather Details:"<< std::endl;
    cout << "\n";
    for (const auto& [day, temperature] : weatherData) {
        char condition = weatherConditions[day];
        string classification;
        
        // Classify the temperature
        if (temperature < 10) {
            classification = "Cold";
        } else if (temperature <= 20) {
            classification = "Ok";
        } else {
            classification = "Warm";
        }
        
        // Print
        cout << day << ": " << temperature << "°C - " 
             << conditionDescriptions[condition] << " - " 
             << classification << std::endl;
        
        // Update total temperature for average calculation
        totalTemp += temperature;
        
        if (temperature > maxTemp) {
            maxTemp = temperature;
            warmestDay = day;
        }
        if (temperature < minTemp) {
            minTemp = temperature;
            coldestDay = day;
        }
    }
    
    // Calculate average temperature
    double averageTemp = totalTemp / weatherData.size();
    
    // Store warmest and coldest days in tuples
    tuple<string, double> warmestDayInfo = make_tuple(warmestDay, maxTemp);
    tuple<string, double> coldestDayInfo = make_tuple(coldestDay, minTemp);
    
    // Summary information
    cout << "\n= Weekly Weather Summary =\n"<< std::endl;
    cout << "Average Temperature: " << averageTemp << "°C"<< std::endl;
    cout << "Warmest Day: " << get<0>(warmestDayInfo) << " " << get<1>(warmestDayInfo) << "°C"<< std::endl;
    cout << "Coldest Day: " << get<0>(coldestDayInfo) << " " << get<1>(coldestDayInfo) << "°C"<< std::endl;
    cout << "Temperature Range: " << (maxTemp - minTemp) << "°C"<< std::endl;
    
    return 0;
}