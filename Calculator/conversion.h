void binToOctal(int a[]);           // Strictly converts binary to octal without considering sign
void compToOctal(int a[]);          // Uses binToOctal to convert from 2s comp bin to 8s comp octal
void binToDecimal(int a[]);         // Strictly converts binary to decimal without considering sign
void compToDecimal(int a[]);        // Uses binToDecimal to convert from 2s comp bin to 10s comp decimal
void binToHexadecimal(int a[]);     // Strictly converts binary to hexadecimal without considering sign
void compToHexadecimal(int a[]);    // Uses binToHexadecimal to convert from 2s comp bin to Fs (16s) comp hexadecimal
char toHexChar(int digit);          // Converts integer (0 <= x <= 15) to character in hex
int power(int base, int exp);       // Returns base^exp