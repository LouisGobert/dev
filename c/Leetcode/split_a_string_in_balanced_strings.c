#include <stdio.h>

int balancedStringSplit(char* s) {

    // i -> pos dans s
    // n -> nombre de r
    int n_l = 0, n_r = 0, x = 0, nb = 0;

    while (s[x] != '\0')
    {
        if (s[x] == 'R')
            n_r++;
        else if (s[x] == 'L')
            n_l++;

        x++;

        if (n_l && n_l == n_r) {
            nb++;
            n_l = 0;
            n_r = 0;

        }
    }

   

    return nb;
}


