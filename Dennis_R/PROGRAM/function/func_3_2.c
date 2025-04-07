#include <stdio.h>
#include <stdint.h>

#define MAXLINE 1000

/* Function to replace special characters with escape sequences */
void escape(char s[], char t[]) {
    uint32_t index1 = 0, index2 = 0;

    while (t[index1] != '\0') {
        switch (t[index1]) {
            case '\t':
                s[index2++] = '\\';
                s[index2] = 't';
                break;
            case '\n':
                s[index2++] = '\\';
                s[index2] = 'n';
                break;
            default:
                s[index2] = t[index1];
                break;
        }
        ++index1;
        ++index2;
    }
    s[index2] = '\0'; // Null-terminate the string
}

/* Function to convert escape sequences back to actual characters */
void convertback(char s[], char t[]) {
    uint32_t index1 = 0, index2 = 0;

    while (s[index1] != '\0') {
        if (s[index1] == '\\' && s[index1 + 1] != '\0') {
            switch (s[index1 + 1]) {
                case 't':
                    t[index2] = '\t';
                    index1++; // Skip next character
                    break;
                case 'n':
                    t[index2] = '\n';
                    index1++; // Skip next character
                    break;
                default:
                    t[index2] = s[index1]; // Keep as-is
                    break;
            }
        } else {
            t[index2] = s[index1];
        }
        ++index1;
        ++index2;
    }
    t[index2] = '\0'; // Null-terminate the string
}

/* Function to get a line from input */
uint32_t mgetline(char s[], uint32_t lim) {
    uint32_t i = 0;
    int c;

    char buff = getchar();
    while (i < lim - 1 && (c = getchar()) !=  EOF) {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = c; // Store newline character
    }

    s[i] = '\0'; // Null-terminate the string
    return i;
}

/* Function to test escaping and unescaping */
void char_catch() {
    printf("\tConverts characters like newline and tab into visible escape sequences like \\n and \\t\n\n");

    char s[MAXLINE], t[MAXLINE], a[MAXLINE];

    printf("Enter a string (including tabs and newlines if needed):\n");
    mgetline(t, MAXLINE);

    escape(s, t);
    printf("Escaped String: %s\n", s);

    convertback(s, a);
    printf("Converted Back: \n%s\n", a);
}

/* Main function */
/*int main() {
    char_catch();
    return 0;
}*/

