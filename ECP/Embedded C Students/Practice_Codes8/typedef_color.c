#include <stdio.h>

// Define the Color enum
typedef enum {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
    PURPLE
} Color;

// Function to convert Color enum to a string
const char* colorToString(Color color) {
    switch (color) {
        case RED:    return "Red";
        case GREEN:  return "Green";
        case BLUE:   return "Blue";
        case YELLOW: return "Yellow";
        case ORANGE: return "Orange";
        case PURPLE: return "Purple";
        default:     return "Unknown";
    }
}

int main() {
    // Define the favorite color
    Color favoriteColor = GREEN;
    
    // Get the string representation of the favorite color
    const char* colorName = colorToString(favoriteColor);
    
    // Print the color
    printf("Favorite color: %s\n", colorName);
    
    return 0;
}