#include <stdio.h>

struct point {
    float x;
    float y;
};

float calDistance(struct point p1, struct point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return (dx * dx + dy * dy);
}

int WithinBoundary(struct point p, float x1, float y1, float x2, float y2) {
    return (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2);
}

int main() {
    struct point p1, p2;

    printf("Enter coordinates of point 1 (x y): ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter coordinates of point 2 (x y): ");
    scanf("%f %f", &p2.x, &p2.y);

    printf("Squared distance between points: %.3f\n", calDistance(p1, p2));

    float x1, y1, x2, y2;
    printf("Enter bottom-left and top-right coordinates of rectangle (x1 y1 x2 y2): ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    if (WithinBoundary(p1, x1, y1, x2, y2)) {
        printf("Point 1 is within the boundary\n");
    } else {
        printf("Point 1 is outside the boundary\n");
    }

    if (WithinBoundary(p2, x1, y1, x2, y2)) {
        printf("Point 2 is within the boundary\n");
    } else {
        printf("Point 2 is outside the boundary\n");
    }

    return 0;
}