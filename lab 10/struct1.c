#include <stdio.h>
#include <string.h>

struct flightInfo {
    int fNum;
    char fDate[20];
    char depCity[20];
    char desCity[20];
    int vacancy;
} f0, f1, f2;

void initFlights() {
    f1.fNum = 101;
    strcpy(f1.fDate, "27/11/24");
    strcpy(f1.depCity, "karachi");
    strcpy(f1.desCity, "lahore");
    f1.vacancy = 50;

    f2.fNum = 102;
    strcpy(f2.fDate, "27/11/24");
    strcpy(f2.depCity, "karachi");
    strcpy(f2.desCity, "islamabad");
    f2.vacancy = 10;
}

void book_Display(struct flightInfo f0) {
    if (strcmp(f0.depCity, f1.depCity) == 0 && strcmp(f0.desCity, f1.desCity) == 0) {
        if (f1.vacancy > 0) {
            printf("Your flight has been booked\n\n");
            printf("Flight Number: %d\n", f1.fNum);
            printf("Flight Date: %s\n", f1.fDate);
            printf("Departure City: %s\n", f1.depCity);
            printf("Destination City: %s\n", f1.desCity);
            printf("Seats Available: %d\n", f1.vacancy);
        } else {
            printf("Seats are not available for this flight, sorry!\n");
        }
    } else if (strcmp(f0.depCity, f2.depCity) == 0 && strcmp(f0.desCity, f2.desCity) == 0) {
        if (f2.vacancy > 0) {
            printf("Your flight has been booked\n");
            printf("Flight Number: %d\n", f2.fNum);
            printf("Flight Date: %s\n", f2.fDate);
            printf("Departure City: %s\n", f2.depCity);
            printf("Destination City: %s\n", f2.desCity);
            printf("Seats Available: %d\n", f2.vacancy);
        } else {
            printf("Seats are not available for this flight, sorry!\n");
        }
    } else {
        printf("Flight not available!\n");
    }
}

int main() {
    int f;

    initFlights();

    printf("Flight Booking (1 = Yes, 0 = No):\n");
    scanf("%d", &f);

    if (f == 1) {
        printf("Enter Your departure city:\n");
        scanf("%s", f0.depCity);
        printf("Enter Your destination city:\n");
        scanf("%s", f0.desCity);

        book_Display(f0);
    }

    return 0;
}
