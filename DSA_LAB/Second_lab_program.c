#include <stdio.h>
#define MAX 100

int StringMatch(char[], char[], char[], char[]);

int main() {
    char s[MAX] = {0}, p[MAX] = {0}, r[MAX] = {0}, final[MAX] = {0};
    int found;

    printf("Enter Source String: \n");
    gets(s);
    printf("Enter Pattern String: \n");
    gets(p);
    printf("Enter Replace String: \n");
    gets(r);

    found = StringMatch(s, p, r, final);

    if (found == 1) {
        printf("The Final String is : \n");
        puts(final);
    } else {
        printf("Pattern string not found\n");
    }

    return 0;
}

int StringMatch(char s[], char p[], char r[], char final[]) {
    int i, j, k, m, t;
    int found = 0;
    j = m = i = t = 0;

    while (s[i] != '\0') {
        if (s[m] == p[j]) {
            m++;
            j++;
            if (p[j] == '\0') {
                for (k = 0; r[k] != '\0'; k++, t++) {
                    final[t] = r[k];
                }
                i = m;
                j = 0;
                found = 1;
            }
        } else {
            final[t++] = s[i++];
            m = i;
            j = 0;
        }
    }

    final[t] = '\0';
    return found;
}

/*Output 
    Enter Source String: data structure and algorithm
    
    Enter Pattern String: algorithm   
     
    Enter Replace String: applications
    
    The Final String is : data structure and applications
*/