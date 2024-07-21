#include <stdio.h>

void main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    // Initialize arrays to zero
    for(i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        g[i] = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the arrival times: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate the completion time for each process
    g[0] = a[0] + b[0];
    for(i = 1; i < n; i++) {
        if(g[i-1] < a[i]) {
            g[i] = a[i] + b[i];
        } else {
            g[i] = g[i-1] + b[i];
        }
    }

    // Calculate waiting time and turnaround time
    for(i = 0; i < n; i++) {
        t[i] = g[i] - a[i]; // Turnaround time
        w[i] = t[i] - b[i]; // Waiting time
        awt += w[i];
        att += t[i];
    }

    awt /= n;
    att /= n;

    // Display results
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }

    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);
}