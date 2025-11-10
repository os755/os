#include <stdio.h>
#include <stdbool.h>

int main() {
    int p,r;
    p = 5;      //number of processes
    r = 3;      //number of resources
    int finish[p];

    int alloc[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[5][3] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int avail[3] = {3,3,2};
    int work[3] = {avail[0],avail[1],avail[2]};

    for(int i = 0; i < p; i++) 
        finish[i] = false;

    int need[5][3];
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int safeseq[5];
    int count = 0;

    while (count < p) {
        bool found = false;
        for (int i = 0; i < p; i++) {
            if (finish[i] == false) {
                bool canexe = true;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        canexe = false;
                        break;
                    }
                }

                if (canexe) {
                    for (int j = 0; j < r; j++)
                        work[j] += alloc[i][j];

                    safeseq[count] = i;
                    count++;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (found == false) {
            printf("\nSystem is not in a safe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in a safe state.\nSafe Sequence is: ");
    for (int i = 0; i < p; i++)
        printf("P%d ", safeseq[i]);
    printf("\n");

    return 0;
}    