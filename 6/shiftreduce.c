#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[20], act[20], stk[20], ac[20];
int i, j, z, c;

void check() {
    strcpy(ac, "Reduce to E");

    for (z = 0; z < c; z++) {
        if (stk[z] == 'i' && stk[z + 1] == 'd') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s\t%s", stk, a, ac);
            j++;
        }
    }

    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s\t%s", stk, a, ac);
            i -= 2;
        }
    }

    for (z = 0; z < c; z++) {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s\t%s", stk, a, ac);
            i -= 2;
        }
    }

    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s\t%s", stk, a, ac);
            i -= 2;
        }
    }
}

int main() {
    printf("Grammar is E-->E+E  E-->(E) E-->E*E  E-->id\n\n");

    printf("Enter input string: ");
    scanf("%s", a);
    strcpy(act, "SHIFT-->");

    printf("stack\tinput\taction\n");
    c = strlen(a);

    for (i = 0, j = 0; j < c; i++, j++) {
        if (a[j] == 'i' && a[j + 1] == 'd') {
            stk[i] = 'i';
            stk[i + 1] = 'd';
            stk[i + 2] = '\0';
            a[j]=' ';
            a[j+1]=' ';
            printf("\n$%s\t%s\t%sid", stk, a, act);
            check();
        } else {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j]=' ';
            printf("\n$%s\t%s\t%sSymbols", stk, a,act);
            check();
        }
    }

    if (stk[0] == 'E' && a[0] == '\0') {
        printf("\n$%s\t%s\tACCEPT", stk, a);
    }

    return 0;
}