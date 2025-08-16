#include<stdio.h>

typedef struct {
    float width;
    float height;
} Rectangle;

float area(Rectangle r) {
    return r.width * r.height;
}