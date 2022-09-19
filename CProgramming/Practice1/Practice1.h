/// Practice #1 - Alexander Elguezabal - 9/14/2022
// Practice1.h

struct point
{
    float x;
    float y;
};

void print_point(struct point p);

void reflect_over_y(struct point *p);

struct point translate(struct point *a, struct point *b);