#include<stdio.h>
#include<stdlib.h>
#include "admin.h"
#include<string.h>


void inputAccountData(Account *account) {
    
    account->accountNumber = generateUniqueId();

    

    printf("Enter Full Name: ");
    fgets(account->fullName, sizeof(account->fullName), stdin);
   

    printf("Enter Gender: ");
    fgets(account->gender, sizeof(account->gender), stdin);
    

    printf("Enter Address: ");
    fgets(account->address, sizeof(account->address), stdin);
    

    printf("Enter Email ID: ");
    fgets(account->email, sizeof(account->email), stdin);
    

    printf("Enter Nationality: ");
    fgets(account->nationality, sizeof(account->nationality), stdin);
    
    printf("Enter Phone Number: ");
    fgets(account->phoneNumber, sizeof(account->phoneNumber), stdin);
    

    writeToCSV(account);
}
    


int main() {
	Account *account;
    long long uniqueId = generateUniqueId();
    printf("Generated unique 10-digit ID: %lld\n", uniqueId);
    inputAccountData(account);
    return 0;
}