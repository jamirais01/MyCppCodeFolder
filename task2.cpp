#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

template<typename T>
T calculateAverage(T* data, int size) {
    if (size == 0) {
        throw std::runtime_error("Division by zero in average calculation");
    }
    
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

class WeatherStation {
private:
    std::string location;
    float* readings;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        float* newReadings = new float[capacity];
        
        for (int i = 0; i < size; ++i) {
            newReadings[i] = readings[i];
        }
        
        delete[] readings;
        readings = newReadings;
    }

public:
    WeatherStation(const std::string& loc) : location(loc), capacity(10), size(0) {
        readings = new float[capacity];
    }

    ~WeatherStation() {
        delete[] readings;
    }

    void addReading(float value) {
        if (size >= capacity) {
            resize();
        }
        readings[size++] = value;
    }

    void printReadings() const {
        std::cout << "Location: " << location << std::endl;
        std::cout << "Readings: ";
        for (int i = 0; i < size; ++i) {
            std::cout << readings[i];
            if (i < size - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    void saveToFile(const std::string& filename) {
        try {
            std::ofstream file(filename);
            if (!file.is_open()) {
                throw std::runtime_error("Could not open file for writing");
            }
            
            file << location << std::endl;
            file << size << std::endl;
            for (int i = 0; i < size; ++i) {
                file << readings[i] << std::endl;
            }
            std::cout << "Saved to file: " << filename << std::endl;
        }
        catch (const std::exception& e) {
            throw std::runtime_error("File I/O error: " + std::string(e.what()));
        }
    }

    void displayAverage() const {
        try {
            float avg = calculateAverage(readings, size);
            std::cout << "Average: " << std::fixed << std::setprecision(2) << avg << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    int countAboveThreshold(float threshold) const {
        return std::count_if(readings, readings + size, 
                           [threshold](float reading) { return reading > threshold; });
    }
};

int main() {
    WeatherStation station("Lahti");
    
    // Add the exact readings from the example
    station.addReading(22.5);
    station.addReading(24.0);
    station.addReading(26.3);
    station.addReading(21.8);
    station.addReading(25.7);
    
    // Display the required output
    station.printReadings();
    station.displayAverage();
    std::cout << "Readings above 25°C: " << station.countAboveThreshold(25.0) << std::endl;
    station.saveToFile("lahti_readings.txt");
    
    return 0;
}