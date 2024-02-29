#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Defining User structure
struct User {
    char username[20];
    char password[20];
};

// Defining song structure
struct Song {
    char title[50];
    char artist[50];
    char genre[20];
};

// Registering a new user
void registerUser(struct User* users, int* numUsers) {
    printf("Enter your username: ");
    scanf("%s", users[*numUsers].username);

    printf("Enter your password: ");
    scanf("%s", users[*numUsers].password);

    (*numUsers)++;
    printf("Registration successful!\n");
}

// Checking if user is registered
int loginUser(const struct User* users, int numUsers, char* loggedInUser) {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; ++i) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            strcpy(loggedInUser, username);
            return 1; // If user is found - login successful
        }
    }
    return 0; // If user is not found or incorrect password
}

// Recommending a song based on the selected genre
void recommendSong(const struct Song* songs, int numSongs) {
    // Creating an array to store recommended songs
    struct Song recommendedSongs[10];
    int recommendedCount = 0;

    // Displaying available genres
    printf("Available Genres:\n");
    printf("1. Gospel\n");
    printf("2. Amapiano\n");
    printf("3. Jazz\n");
    printf("4. R&B\n");

    // Getting user input for the genre
    char userGenre[20];
    printf("Enter the genre you are looking for: ");
    scanf("%s", userGenre);

    // Convertting the user input genre to lowercase
    for (int i = 0; userGenre[i]; ++i) {
        userGenre[i] = tolower(userGenre[i]);
    }

    // Map numeric input to corresponding genre name
    if (isdigit(userGenre[0])) {
        int genreIndex = atoi(userGenre);
        switch (genreIndex) {
            case 1:
                strcpy(userGenre, "gospel");
                break;
            case 2:
                strcpy(userGenre, "amapiano");
                break;
            case 3:
                strcpy(userGenre, "jazz");
                break;
            case 4:
                strcpy(userGenre, "r&b");
                break;
            default:
                printf("Invalid genre selection.\n");
                return;
        }
    }

    // Loop through the songs to find recommendations
    for (int i = 0; i < numSongs; ++i) {
        // Convert the genre in the songs array to lowercase
        char lowercaseSongGenre[20];
        strcpy(lowercaseSongGenre, songs[i].genre);
        for (int j = 0; lowercaseSongGenre[j]; ++j) {
            lowercaseSongGenre[j] = tolower(lowercaseSongGenre[j]);
        }

        if (strcmp(lowercaseSongGenre, userGenre) == 0) {
            recommendedSongs[recommendedCount] = songs[i];
            recommendedCount++;

            // Limitting the number of recommendations to 10
            if (recommendedCount == 10) {
                break;
            }
        }
    }

    // If no songs matched the entered genre, display a message
    if (recommendedCount == 0) {
        printf("No songs found in the %s genre.\n", userGenre);
    } else {
        // Displaying recommended songs
        printf("Recommended Songs in %s:\n", userGenre);
        for (int i = 0; i < recommendedCount; ++i) {
            printf("%d. %s - %s\n", i + 1, recommendedSongs[i].title, recommendedSongs[i].artist);
        }
    }
}

int  main() {
    // Seed the random number generator for variety in recommendations
    srand(time(NULL));

    // Defining an array to store users
    struct User users[10];
    int numUsers = 0;

    // Defining an array of sample songs
    struct Song songs[] = {
        {"Don't Let Me Die", "Rebecca Malope", "Gospel"},
        {"Masimdumise", "Rebecca Malope", "Gospel"},
        {"Baya Vuya", "Rebecca Malope", "Gospel"},
        {"Unamandla", "Rebecca Malope", "Gospel"},
        {"Umoya Wam", "Rebecca Malope", "Gospel"},
        {"Take Five", "Dave Brubeck", "Jazz"},
        {"So What", "Miles Davis", "Jazz"},
        {"Autumn Leaves", "Cannonball Adderley", "Jazz"},
        {"Blue Monk", "Thelonious Monk", "Jazz"},
        {"All Blues", "John Coltrane", "Jazz"},
        {"Summertime", "Ella Fitzgerald", "Jazz"},
        {"My Favorite Things", "John Coltrane", "Jazz"},
        {"Birdland", "Weather Report", "Jazz"},
        {"Cantaloupe Island", "Herbie Hancock", "Jazz"},
        {"Fly Me to the Moon", "Frank Sinatra", "Jazz"},
        {"Labantwana Ama Uber", "Semi Tee ft. Miano & Kammu Dee", "Amapiano"},
        {"eMcimbini", "Kabza De Small & DJ Maphorisa ft. Aymos, Samthing Soweto, Mas Musiq & Myztro", "Amapiano"},
        {"Uthando", "Soa Mattrix ft. Soulful G", "Amapiano"},
        {"Emathandweni", "Kabza De Small ft. Aymos", "Amapiano"},
        {"Umsebenzi Wethu", "Busta 929 & Mpura ft. Zuma, Mr JazziQ, Lady Du & Reece Madlisa", "Amapiano"},
        {"John Wick", "De Mthuda & Ntokzin ft. Sir Trill & Da Muziqal Chef", "Amapiano"},
        {"Focalistic Ke Star", "Focalistic ft. Vigro Deep", "Amapiano"},
        {"Jazzidisciples (Zlele)", "Reece Madlisa & Zuma ft. Mr JazziQ & Busta 929", "Amapiano"},
        {"Sponono", "Kabza De Small, DJ Maphorisa, Wizkid, Burna Boy & Cassper Nyovest", "Amapiano"},
        {"Lalela", "Kwiish SA ft. De Mthuda & Njelic", "Amapiano"},
        // More songs will be added with time
    };

    int numSongs = sizeof(songs) / sizeof(songs[0]);

    char loggedInUser[20] = ""; // Store the username of the logged-in user
    int isLoggedIn = 0; // Flag to track login status

    // Menu loop
    int choice;
    do {
        if (isLoggedIn) {
            printf("\n3. Recommend Songs\n");
            printf("4. Logout\n");
        } else {
            printf("\n1. Register\n");
            printf("2. Login\n");
        }
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isLoggedIn) {
                    if (numUsers < 10) {
                        registerUser(users, &numUsers);
                    } else {
                        printf("Maximum users reached. Cannot register more users.\n");
                    }
                } else {
                    printf("You are already logged in.\n");
                }
                break;

            case 2:
                if (!isLoggedIn) {
                    if (loginUser(users, numUsers, loggedInUser)) {
                        printf("Login successful!\n");
                        isLoggedIn = 1; // Set login status to true
                    } else {
                        printf("Login failed. Invalid username or password.\n");
                    }
                } else {
                    printf("You are already logged in as %s.\n", loggedInUser);
                }
                break;

            case 3:
                if (isLoggedIn) {
                    char userGenre[20];
                    printf("Enter the genre you are looking for: ");
                    scanf("%s", userGenre);
                    recommendSong(songs, numSongs);
                } else {
                    printf("You need to log in first.\n");
                }
                break;

            case 4:
                if (isLoggedIn) {
                    printf("Logging out %s...\n", loggedInUser);
                    isLoggedIn = 0; // Clear the login status
                    loggedInUser[0] = '\0'; // Clear the logged-in user
                } else {
                   printf("You are not logged in.\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

