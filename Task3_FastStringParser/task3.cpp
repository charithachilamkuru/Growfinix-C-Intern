#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("logs.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    char line[1024];
    int errorCount[600] = {0}; 

    while (fgets(line, sizeof(line), file)) {
        char *ptr = line;

        
        char ip[20];
        int i = 0;

        while (*ptr != ' ' && *ptr != '\0') {
            ip[i++] = *ptr;
            ptr++;
        }
        ip[i] = '\0';

        
        
char *p = line;

int code = 0;


while (*p != '\0') {

    if (*p >= '0' && *p <= '9') {
        int temp = 0;

        
        while (*p >= '0' && *p <= '9') {
            temp = temp * 10 + (*p - '0');
            p++;
        }

        
        code = temp;
    } else {
        p++;
    }
}

        
        if (code >= 400 && code <= 599) {
            errorCount[code]++;
        }
    }

    fclose(file);

    
    printf("Error Code Summary:\n");
    for (int i = 400; i <= 599; i++) {
        if (errorCount[i] > 0) {
            printf("Error %d: %d times\n", i, errorCount[i]);
        }
    }

    return 0;
}
