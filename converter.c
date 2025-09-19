#include <stdio.h>
#include <stdlib.h>

// Decimal to Binary
void decToBin(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int binary[32], i = 0;
    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

// Decimal to Octal
void decToOct(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int octal[32], i = 0;
    while (n > 0) {
        octal[i++] = n % 8;
        n /= 8;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
}

// Decimal to Hexadecimal
void decToHex(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    char hex[32];
    int i = 0;
    while (n > 0) {
        int rem = n % 16;
        hex[i++] = (rem < 10) ? (rem + '0') : (rem - 10 + 'A');
        n /= 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

// Binary to Decimal
int binToDec(long long n) {
    int decimal = 0, base = 1, rem;
    while (n > 0) {
        rem = n % 10;
        decimal += rem * base;
        base *= 2;
        n /= 10;
    }
    return decimal;
}

// Octal to Decimal
int octToDec(int n) {
    int decimal = 0, base = 1, rem;
    while (n > 0) {
        rem = n % 10;
        decimal += rem * base;
        base *= 8;
        n /= 10;
    }
    return decimal;
}

// Hexadecimal to Decimal
int hexToDec(char hex[]) {
    int decimal = 0, base = 1, i = 0;
    while (hex[i]) {
        int value;
        if (hex[i] >= '0' && hex[i] <= '9')
            value = hex[i] - '0';
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            value = hex[i] - 'A' + 10;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            value = hex[i] - 'a' + 10;
        else {
            printf("Invalid Hex digit\n");
            return -1;
        }
        decimal = decimal * 16 + value;
        i++;
    }
    return decimal;
}

int main() {
    int choice, num;
    long long bin;
    char hex[32];

    while (1) {
        printf("\nNumber System Converter By Safwan Safat\n\n");
        printf("1. Decimal to Binary, Octal, Hexadecimal\n");
        printf("2. Binary to Decimal\n");
        printf("3. Octal to Decimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Decimal number: ");
                scanf("%d", &num);
                printf("Binary: "); decToBin(num);
                printf("\nOctal: "); decToOct(num);
                printf("\nHexadecimal: "); decToHex(num);
                printf("\n");
                break;
            case 2:
                printf("Enter Binary number: ");
                scanf("%lld", &bin);
                printf("Decimal: %d\n", binToDec(bin));
                break;
            case 3:
                printf("Enter Octal number: ");
                scanf("%d", &num);
                printf("Decimal: %d\n", octToDec(num));
                break;
            case 4:
                printf("Enter Hexadecimal number: ");
                scanf("%s", hex);
                printf("Decimal: %d\n", hexToDec(hex));
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid! Pick among 1 to 5 & try again.\n");
        }
    }
    return 0;
}
