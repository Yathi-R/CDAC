#include <stdio.h>

union SensorData {
    int temperature;   // Temperature in Celsius
    float pressure;    // Pressure in Pascals
    char status[10];   // Status message
};

int main() {
    union SensorData data;
    
    // Use temperature
    data.temperature = 25;
    printf("Temperature: %d°C\n", data.temperature);

    // Use pressure
    data.pressure = 1013.25;
    printf("Pressure: %.2f Pa\n", data.pressure);

    // Use status
    snprintf(data.status, sizeof(data.status), "OK");
    printf("Status: %s\n", data.status);

    return 0;
}