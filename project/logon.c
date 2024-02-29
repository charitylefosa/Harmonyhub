#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a User
struct User {
    char username[20];
    char password[20];
};

// Function to register a new user
void registerUser(struct User* users, int* numUsers) {
    printf("Enter your username: ");
    scanf("%s", users[*numUsers].username);

    printf("Enter your password: ");
    scanf("%s", users[*numUsers].password);

    (*numUsers)++;
    printf("Registration successful!\n");
}

// Function to check if the user is registered
int loginUser(const struct User* users, int numUsers, const char* username, const char* password) {
    for (int i = 0; i < numUsers; ++i) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // User found and login successful
        }
    }
    return 0; // User not found or incorrect password
}

int main() {
    // Define an array to store users
    struct User users[10];
    int numUsers = 0;

    // Menu for login/register
    int choice;
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numUsers < 10) {
                    registerUser(users, &numUsers);
                } else {
                    printf("Maximum users reached. Cannot register more users.\n");
                }
                break;

            case 2: {
                char username[20];
                char password[20];

                printf("Enter your username: ");
                scanf("%s", username);

                printf("Enter your password: ");
                scanf("%s", password);

                if (loginUser(users, numUsers, username, password)) {
                    printf("Login successful!\n");

                    // Code for recommending music can go here

                    // Example:
                    printf("User is now ready to explore music recommendations.\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;
            }

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
