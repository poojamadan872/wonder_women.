#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define  FILENAME "test.csv"

// Structure to hold account information
typedef struct {
    char accountNumber[20];
    char accountHolder[50];
    float balance;
} Account;

// Function to load accounts from the CSV file
int loadAccounts(Account accounts[], int maxAccounts) {
    FILE *file = fopen("test.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Read each line from the file (skip header)
    fgets(line, sizeof(line), file);  // Skip the header line
    while (fgets(line, sizeof(line), file) != NULL && count < maxAccounts) {
        scanf(line, "%19[^,],%49[^,],%f", accounts[count].accountNumber, accounts[count].accountHolder, &accounts[count].balance);
        count++;
    }

    fclose(file);
    return count;
}

// Function to save updated accounts back to the CSV file
void saveAccounts(Account accounts[], int numAccounts) {
    FILE *file = fopen("test.csv", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write the header
    fprintf(file, "AccountNumber,AccountHolder,Balance\n");

    // Write the account data
    for (int i = 0; i < numAccounts; i++) {
        fprintf(file, "%s,%s,%.2f\n", accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }

    fclose(file);
}

// Function to withdraw money from an account
int withdrawMoney(Account accounts[], int numAccounts, const char *accountNumber, float withdrawalAmount) {
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            if (accounts[i].balance >= withdrawalAmount) {
                accounts[i].balance -= withdrawalAmount;
                printf("Withdrawal successful! New balance for %s: %.2f\n", accounts[i].accountHolder, accounts[i].balance);
                return 1;
            } else {
                printf("Insufficient balance in account %s.\n", accountNumber);
                return 0;
            }
        }
    }
    printf("Account not found.\n");
    return 0;
}

int main() {
    Account accounts[100];
    int numAccounts = loadAccounts(accounts, 100);

    if (numAccounts == 0) {
        printf("No accounts found.\n");
        return 1;
    }

    // Input account number and withdrawal amount
    char accountNumber[20];
    float withdrawalAmount;

    printf("Enter account number for withdrawal: ");
    scanf("%19s", accountNumber);
    printf("Enter withdrawal amount: ");
    scanf("%f", &withdrawalAmount);

    // Perform the withdrawal
    if (withdrawMoney(accounts, numAccounts, accountNumber, withdrawalAmount)) {
        // Save the updated accounts to the file
        saveAccounts(accounts, numAccounts);
    }

    return 0;
}
