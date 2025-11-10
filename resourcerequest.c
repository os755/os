#include <stdio.h>
#include <stdbool.h>

int p = 5;    // number of processes
int r = 3;    // number of resources

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
int need[5][3];
int safeseq[5];

void calneed() {
    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

bool safe() {
    int work[3] = {avail[0], avail[1], avail[2]};
    int finish[5] = {false, false, false, false, false};
    int count = 0;

    while (count < p) {
        bool found = false;
        for (int i = 0; i < p; i++) {
            if (!finish[i]) {
                bool executable = true;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        executable = false;
                        break;
                    }
                }

                if (executable) {
                    for (int j = 0; j < r; j++)
                        work[j] += alloc[i][j];

                    safeseq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found)
            return false;  
    }

    return true;  
}

void display() {
    printf("\nP\tAllocation\tMax\t\tNeed\n");
    for (int i = 0; i < p; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < r; j++) printf("%d ", alloc[i][j]);
        printf("\t\t");
        for (int j = 0; j < r; j++) printf("%d ", max[i][j]);
        printf("\t\t");
        for (int j = 0; j < r; j++) printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for (int i = 0; i < r; i++)
        printf("%d ", avail[i]);
    printf("\n");
}

void resourcereq() {
    int proc_id;
    int req[3];

    printf("\nEnter process ID making the request (0 to 4): ");
    scanf("%d", &proc_id);

    printf("Enter the requested resources (space-separated): ");
    for (int i = 0; i < r; i++)
        scanf("%d", &req[i]);

    bool valid = true;
    for (int i = 0; i < r; i++) {
        if (req[i] > need[proc_id][i] || req[i] > avail[i]) {
            valid = false;
            break;
        }
    }

    if (valid) {
        for (int i = 0; i < r; i++) {
            avail[i] -= req[i];
            alloc[proc_id][i] += req[i];
            need[proc_id][i] -= req[i];
        }

        if (safe()) {
            printf("\nRequest granted. System remains in a safe state.\n");
            printf("Safe Sequence: ");
            for (int i = 0; i < p; i++)
                printf("P%d ", safeseq[i]);
            printf("\n");
        } else {
            for (int i = 0; i < r; i++) {
                avail[i] += req[i];
                alloc[proc_id][i] -= req[i];
                need[proc_id][i] += req[i];
            }
            printf("\nRequest denied. System would enter unsafe state.\n");
        }
    } else {
        printf("\nInvalid request! Exceeds process need or available resources.\n");
    }

    printf("\nUpdated state after request:\n");
    display();
}

int main() {
    calneed();
    printf("Initial System State:");
    display();

    if (safe()) {
        printf("\nInitial state is SAFE.\nSafe Sequence: ");
        for (int i = 0; i < p; i++)
            printf("P%d ", safeseq[i]);
        printf("\n");
    } else {
        printf("\nInitial state is NOT safe.\n");
        return 0;
    }

    resourcereq();

    return 0;
}
