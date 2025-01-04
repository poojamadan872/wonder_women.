#ifndef ADMIN_H
#define ADMIN_H
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>


#define MAX_LINE_LENGTH 256
#define MAX_LENGTH 100

// Structure to store the account information
typedef struct {
    long long int accountNumber;
    char fullName[MAX_LENGTH];
    char gender[2];
    char address[MAX_LENGTH];
    char email[MAX_LENGTH];
    char nationality[MAX_LENGTH];
    char phoneNumber[10];

} Account;


//function to add account
int writeToCSV(Account *account) {
    FILE *file = fopen("accounts.csv", "a");  // Open file in append mode
    if (file == NULL) {
        perror("Error opening file");
        return 0;

    }

    // Write account details to the file in CSV format
    fprintf(file, "%d,%s,%s,%s,%s,%s,%s\n", account->accountNumber,
            account->fullName, account->gender, account->address,
            account->email, account->nationality, account->phoneNumber);

    fclose(file);
    return 1;
  }

// Function to generate a unique 10-digit ID
long long generateUniqueId() {
    srand(time(NULL));  // Seed the random number generator

    long long newId;
    int exists;

    do {
        newId = (rand() % 9000000000LL) + 1000000000LL;  // Generate a 10-digit ID
        exists = 0;

        FILE *file = fopen("accounts.csv", "r");
        if (file == NULL) {
            perror("Error opening file");
            break;  // If file doesn't exist, consider ID unique
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, sizeof(line), file)) {
            long long fileId;
            sscanf(line, "%lld", &fileId);  // Read the ID from the line
            if (fileId == newId) {
                exists = 1;  // ID exists
                break;
            }
        }

        fclose(file);
        if (exists) {
            generateUniqueId();
        }
    } while (exists);

    return newId;
}

#endif

