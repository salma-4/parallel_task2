#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

union UserDetails {
    struct User user;
    int isActive; // Flag to indicate whether the user is active (1) or not (0)
};

union UserDetails users[MAX_USERS];
int numUsers = 0;

int registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return 0;
    }

    printf("Enter username: ");
    scanf("%s", users[numUsers].user.username);

    printf("Enter password: ");
    scanf("%s", users[numUsers].user.password);

    printf("Set isActive flag (1 for true, 0 for false): ");
    scanf("%d", &users[numUsers].isActive);

    numUsers++;
    printf("Registration successful.\n");
    return 1;
}

int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].user.username) == 0 &&
            strcmp(password, users[i].user.password) == 0 &&
            users[i].isActive) { // Check if the user is active
            printf("Login successful.\n");
            return 1;
        }
    }

    printf("Invalid username or password, or user is not active.\n");
    return 0;
}

int main() {
    int choice;

    do {
        printf("Enter 1 to Register:\n");
        printf("Enter 2 to Login:\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice);

    return 0;
}
