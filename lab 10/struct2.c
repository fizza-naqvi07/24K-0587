#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};

void addMovie(struct Movie *movie) {
    printf("Enter the title of the movie: ");
    fgets(movie->title, sizeof(movie->title), stdin);
    movie->title[strcspn(movie->title, "\n")] = 0;  

    printf("Enter the genre of the movie: ");
    fgets(movie->genre, sizeof(movie->genre), stdin);
    movie->genre[strcspn(movie->genre, "\n")] = 0;  

    printf("Enter the director of the movie: ");
    fgets(movie->director, sizeof(movie->director), stdin);
    movie->director[strcspn(movie->director, "\n")] = 0;  

    printf("Enter the release year of the movie: ");
    scanf("%d", &movie->releaseYear);

    printf("Enter the rating of the movie (0 to 10): ");
    scanf("%f", &movie->rating);

    getchar(); 
}

void displayMovie(struct Movie movie) {
    printf("\nTitle: %s\n", movie.title);
    printf("Genre: %s\n", movie.genre);
    printf("Director: %s\n", movie.director);
    printf("Release Year: %d\n", movie.releaseYear);
    printf("Rating: %.1f\n", movie.rating);
}

void searchByGenre(struct Movie movies[], int count, char genre[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            displayMovie(movies[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo movies found for the genre '%s'.\n", genre);
    }
}

int main() {
    struct Movie movies[100];
    int movieCount = 0;
    int choice;
    char searchGenre[30];

    while (1) {
        printf("\nMovie Management System\n");
        printf("1. Add a new movie\n");
        printf("2. Search for movies by genre\n");
        printf("3. Display all movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                addMovie(&movies[movieCount]);
                movieCount++;
                break;
            case 2:
                printf("Enter the genre to search for: ");
                fgets(searchGenre, sizeof(searchGenre), stdin);
                searchGenre[strcspn(searchGenre, "\n")] = 0; 
                searchByGenre(movies, movieCount, searchGenre);
                break;
            case 3:
                printf("\nAll Movies:\n");
                for (int i = 0; i < movieCount; i++) {
                    displayMovie(movies[i]);
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
