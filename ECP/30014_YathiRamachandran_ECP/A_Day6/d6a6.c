/*Write a C program to print the temperature and pressure of a heat chamber on the given
console one by one with efficient memory usage through unions.*/

#include <stdio.h>

//union for efficient memory usage
union SensorData {
    float temperature;
    float pressure;
};

int main() {
    
    union SensorData data;
    
    // Assign and print temperature
    data.temperature = 36.5;
    printf("Temperature of the heat chamber: %.2f°C\n", data.temperature);
    
    // Assign and print pressure
    data.pressure = 101.3;
    printf("Pressure of the heat chamber: %.2f Pa\n", data.pressure);
    
    return 0;
}
