#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to encrypt a message using Vigenère Cipher
void encrypt(char message[], char key[]) {
    int keyLen = strlen(key);
    int msgLen = strlen(message);
    char encryptedMsg[MAX_SIZE];
    for (int i = 0, j = 0; i < msgLen; i++) {
        char c = message[i];
        if (isalpha(c)) {
            int offset = isupper(c) ? 'A' : 'a';
            encryptedMsg[i] = ((c + key[j % keyLen] - 2 * offset) % 26) + offset;
            j++;
        } else {
            encryptedMsg[i] = c;
        }
    }
    encryptedMsg[msgLen] = '\0';
    printf("Encrypted message: %s\n", encryptedMsg);
}

// Function to decrypt a message using Vigenère Cipher
void decrypt(char message[], char key[]) {
    int keyLen = strlen(key);
    int msgLen = strlen(message);
    char decryptedMsg[MAX_SIZE];
    for (int i = 0, j = 0; i < msgLen; i++) {
        char c = message[i];
        if (isalpha(c)) {
            int offset = isupper(c) ? 'A' : 'a';
            decryptedMsg[i] = ((c - key[j % keyLen] + 26) % 26) + offset;
            j++;
        } else {
            decryptedMsg[i] = c;
        }
    }
    decryptedMsg[msgLen] = '\0';
    printf("Decrypted message: %s\n", decryptedMsg);
}

int main() {
    char message[MAX_SIZE], key[MAX_SIZE];

    // Input message from user
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character from the message
    message[strcspn(message, "\n")] = '\0';

    // Input key from user
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline character from the key
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the message
    decrypt(message, key);

    return 0;
}

