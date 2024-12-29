#include <stdio.h>

int main() {
    FILE *file = fopen("test.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the header
    fprintf(file, "AccountNumber,AccountHolder,Balance\n");

    // Write data
    fprintf(file, "87979797,per1,30000\n");
    fprintf(file, "7879778,per2,8000\n");
    fprintf(file, "9808080,per3,70000\n");

    fclose(file);
    return 0;
}