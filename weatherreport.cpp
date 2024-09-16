#include <assert.h>
#include <string>
#include <iostream>

using std::cout, std::endl, std::string;

namespace WeatherSpace {
class IWeatherSensor {
 public:
        virtual double TemperatureInC() const = 0;
        virtual int Precipitation() const = 0;
        virtual int Humidity() const = 0;
        virtual int WindSpeedKMPH() const = 0;
};

/// This is a stub for a weather sensor. For the sake of testing
/// we create a stub that generates weather data and allows us to
/// test the other parts of this application in isolation
/// without needing the actual Sensor during development

class SensorStub : public IWeatherSensor {
 public:
    int Humidity() const override {
        return m_humidity;
    }

    int Precipitation() const override {
        return m_precipitation;
    }

    double TemperatureInC() const override {
        return m_temperature;
    }

    int WindSpeedKMPH() const override {
        return m_windSpeed;
    }
    SensorStub() :m_humidity(72), m_precipitation(70), m_temperature(26), m_windSpeed(52) {}
    SensorStub(int humidity, int precipitation, int temperature, int windspeed):
    m_humidity(humidity),
    m_precipitation(precipitation),
    m_temperature(temperature),
    m_windSpeed(windspeed) {}

 private:
    int m_humidity;
    int m_precipitation;
    int m_temperature;
    int m_windSpeed;
};

// This is a function to predict the weather, based on readings
// from a sensor

string Report(const IWeatherSensor& sensor) {
    int precipitation = sensor.Precipitation();
    // precipitation < 20 is a sunny day
    string report = "Sunny day";

    if (sensor.TemperatureInC() > 25) {
        if (precipitation >= 20 && precipitation < 60)
            report = "Partly cloudy";
        else if (sensor.WindSpeedKMPH() > 50)
            report = "Alert, Stormy with heavy rain";
    }
    return report;
}

// Test a rainy day

void TestRainy() {
    SensorStub sensor;
    string report = Report(sensor);
    cout << report << endl;
    assert(report.find("rain") != string::npos);
}

// Test another rainy day

void TestHighPrecipitationAndLowWindspeed() {
    // This instance of stub needs to be different-
    // to give high precipitation (>60) and low wind-speed (<50)
    SensorStub sensor(72, 70, 26, 49);

    // strengthen the assert to expose the bug
    // (function returns Sunny day, it should predict rain)
    string report = Report(sensor);
    assert(report.length() > 0);
    assert(report.find("Sunny") == string::npos);
    assert(report.find("rain") != string::npos);
}
}  // namespace WeatherSpace

int main() {
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitationAndLowWindspeed();
    cout << "All is well (maybe)\n";
    return 0;
}
