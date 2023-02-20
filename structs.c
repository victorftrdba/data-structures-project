#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    float height;
    float base;
} Rectangle;

typedef struct
{
    float radius;
} Circle;

void area(Rectangle *r)
{
    printf("Area: %.2f \n", r->height * r->base);
}

void circumference(Circle *c)
{
    printf("Circumference: %.2f \n", 2 * M_PI * c->radius);
}

int main()
{
    Rectangle r1 = {1.50, 1.50};
    Circle c1 = {2};

    area(&r1);
    circumference(&c1);

    return 0;
}