#include <stdio.h>
#include <string.h>

void make_new_name(char *new_name, char *original_name) {

        char newName[5] = "new-";

        // Copy the newName char to ponter new_name and concatanate it with new_name.
        strcpy(new_name, newName);
        strcat(new_name, original_name);
        printf("New filename = %s\n", new_name);
}


int is_alpha(char c) {

    char lowerAlpabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char capitialAlphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char *lowerAlpPtr = lowerAlpabet;
    char *capAlpPtr = capitialAlphabet;

    for (int i = 0; i < 26; i++) {
        if (c == *capAlpPtr || c == *lowerAlpPtr) {
            return 1;
        }
        lowerAlpPtr++;
        capAlpPtr++;
    }
    return 0;
}


int is_digit(char c) {

    char numbers[10] = "1234567890";
    char *numPtr = numbers;

    for (int i = 0; i < 10; ++i) {
        if (c == *numPtr) {
            return 1;
        }
        numPtr++;
    }
    return 0;
}


int is_valid_password(char *password) {

    int hasAlpha = 0;
    int hasNum = 0;
    int hasEightChars = 0;
    
    int passwordLength = strlen(password);

    while (*password != '\0') {
        password++;

        if (is_alpha(*password)) { hasAlpha = 1; }
        if (is_digit(*password)) { hasNum = 1; }
        if (passwordLength >= 8) { hasEightChars = 1; }
    }

    if (hasAlpha == 1 && hasNum == 1 && hasEightChars == 1) { 
        printf("Password Length = %d\n", passwordLength);
        return 1;
    }

    if (hasAlpha == 0) {
        printf("The password needs to contain at least 1 alphabetical character.\n");
    }

    if (hasNum == 0) {
        printf("The password needs to contain at least 1 digit.\n");
    }

    if (hasEightChars == 0) {
        printf("The password needs to have at least 8 characters.\n");
    }

    return 0;
}


void perform_XOR(char *input_filename, char *output_filename, char *password) {

    FILE *file, *newFile;
    int passwordLength = strlen(password);
    char passwardArray[passwordLength];
    char block[10];
    int i, numBytes;
    int i2 = 0;

    for (i = 0; i < passwordLength; i++) {
        passwardArray[i] = password[i];
    }
    passwardArray[passwordLength] = '\0';

    file = fopen(output_filename, "rb");
    newFile = fopen(input_filename, "wb");

    do {
        numBytes = fread(block, 1, passwordLength, file);
        for (i = 0; i < numBytes; i++)
            block[i] = block[i] ^ password[i % passwordLength];
        fwrite(block, 1, numBytes, newFile);
    } while (numBytes == passwordLength);

    fclose(newFile);
    fclose(file);
}


void print_first_five(char *filename) {
    FILE *file2;
    unsigned char byte;
    char block[1];

    file2 = fopen(filename, "rb");

    for (int i = 0; i < 5; i++) {
        fread(&byte, 1, 1, file2);
        printf("%02x\n", byte);
    }
    fclose(file2);
}


int main(int argc, char *argv[]) {
    char imageName[15];
    char password[15];

    // Checking if the 3 command line arguments are pass through
    if (argc != 3) {
        printf("Usage: ./A2 filename password\n");
    }

    else{
        // Copies the command line argument into the decleared string variables
        strcpy(imageName, argv[1]);
        strcpy(password, argv[2]);

        // set pointer to the new name and original, the newNamePointer will be updated to point at the updated name
        char *newNamePointer;
        char *orginalNamePointer = imageName;
        make_new_name(newNamePointer, orginalNamePointer);

        if (is_valid_password(password) == 1) {
          perform_XOR(newNamePointer, orginalNamePointer, password);  
          print_first_five(newNamePointer);
        }
    }
}
