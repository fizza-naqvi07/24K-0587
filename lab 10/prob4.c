#include<stdio.h>
#include<string.h>

struct Cars
{
   char make[50];
   char model[50];
   int year;
   int price;
   float mileage;
} c;

void addCars(struct Cars *c)
{
    printf("Enter car's make: ");
    fgets(c->make, sizeof(c->make), stdin);
    c->make[strcspn(c->make, "\n")] = 0;

    printf("Enter car's model: ");
    fgets(c->model, sizeof(c->model), stdin);
    c->model[strcspn(c->model, "\n")] = 0;

    printf("Enter car model's year: ");
    scanf("%d", &c->year);

    printf("Enter car's price: ");
    scanf("%d", &c->price);
    
    printf("Enter car's mileage: ");
    scanf("%f", &c->mileage);
 
    getchar();  // Consume the leftover newline character
}

void displayCars(struct Cars c) {
    printf("\nAvailable Car:\n");
    printf("Car's make: %s\n", c.make);
    printf("Car's model: %s\n", c.model);
    printf("Car model year: %d\n", c.year);
    printf("Car's price: %d\n", c.price);
    printf("Car's mileage: %.2f\n", c.mileage);
}

void searchCars(struct Cars c[], int count, char make[]) {
    int f = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(c[i].make, make) == 0) {
            displayCars(c[i]);
            f = 1;
        }
    }
    if (!f) {
        printf("\nNo cars found with make: %s\n", make);
    }
}

int main() {
    struct Cars c[100];
    int cCount = 0;
    int choice;
    char make[30];

    while (1) {
        printf("\nChoose\n");
        printf("1. Add a new car\n");
        printf("2. Search for the car by car's make\n");
        printf("3. Display all cars available\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the leftover newline character

        switch (choice) {
            case 1:
                addCars(&c[cCount]);
                cCount++;
                break;
            case 2:
                printf("Enter the car's make to search: ");
                fgets(make, sizeof(make), stdin);
                make[strcspn(make, "\n")] = 0; 
                searchCars(c, cCount, make);
                break;
            case 3:
                printf("\nAll Cars Available:\n");
                for (int i = 0; i < cCount; i++) {
                    displayCars(c[i]);
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
