#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <iomanip>

using namespace std;

void displayWeatherCodes() {
    cout << "Weather Condition Codes:\n";
    cout << "S = Sunny\n";
    cout << "R = Rainy\n";
    cout << "C = Cloudy\n";
    cout << "P = Partly Cloudy\n";
    cout << "W = Windy\n";
    cout << "F = Foggy\n\n";
}

int main() {
    // Map to store day-temperature pairs
    map<string, double> weatherData;
    map<string, char> weatherConditions;
    
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    // Map weather condition codes to descriptions
    map<char, string> conditionDescriptions = {
        {'S', "Sunny"},
        {'R', "Rainy"},
        {'C', "Cloudy"},
        {'P', "Partly Cloudy"},
        {'W', "Windy"},
        {'F', "Foggy"}
    };
    
    cout << "= Weather Data Entry System =\n";
    cout << "Enter weather data for the week:\n\n";
    
    // Display weather condition codes once at the beginning
    displayWeatherCodes();
    
    cout << "Please enter the following data for each day:\n";
    cout << "- Temperature in °C\n";
    cout << "- Weather condition code (S, R, C, P, W, or F)\n\n";
    
    // Get user input for each day
    for (const auto& day : days) {
        double temp;
        char condition;
        
        cout << "= " << day << " =\n";
        cout << "Temperature (°C): ";
        cin >> temp;
        
        // Input validation for weather condition
        while (true) {
            cout << "Weather condition (S/R/C/P/W/F): ";
            cin >> condition;
            condition = toupper(condition);
            
            // Check if the entered condition is valid
            if (conditionDescriptions.find(condition) != conditionDescriptions.end()) {
                break;
            } else {
                cout << "Invalid condition code! Please use S, R, C, P, W, or F.\n";
            }
        }
        
        weatherData[day] = temp;
        weatherConditions[day] = condition;
        
        cout << endl;
    }
    
    cout << "\n= Weather Data for the Week =\n";
    cout << setprecision(1) << fixed;
    
    // Variables for calculations
    double totalTemp = 0;
    double maxTemp = -100.0;
    double minTemp = 100.0;
    string warmestDay, coldestDay;
    
    // Print each day's weather data with classification
    cout << "Daily Weather Details:\n";
    cout << "\n";
    for (const auto& [day, temperature] : weatherData) {
        char condition = weatherConditions[day];
        string classification;
        
        // Classify the temperature using if-else statements
        if (temperature < 10) {
            classification = "Cold";
        } else if (temperature <= 20) {
            classification = "Ok";
        } else {
            classification = "Warm";
        }
        
        // Print day, temperature, condition, and classification
        cout << day << ": " << temperature << "°C - " 
             << conditionDescriptions[condition] << " - " 
             << classification << endl;
        
        // Update total temperature for average calculation
        totalTemp += temperature;
        
        // Track warmest and coldest days
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
    
    // Print summary information
    cout << "\n= Weekly Weather Summary =\n";
    cout << "Average Temperature: " << averageTemp << "°C\n";
    cout << "Warmest Day: " << get<0>(warmestDayInfo) << " " << get<1>(warmestDayInfo) << "°C\n";
    cout << "Coldest Day: " << get<0>(coldestDayInfo) << " " << get<1>(coldestDayInfo) << "°C\n";
    cout << "Temperature Range: " << (maxTemp - minTemp) << "°C\n";
    
    return 0;
}