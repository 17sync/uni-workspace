#include <stdio.h>

int main() {
    int n = 3;
    int pid[] = {1, 2, 3};          // Process IDs
    int at[]  = {0, 1, 2};          // Arrival Times
    int bt[]  = {4, 3, 5};          // Burst Times

    int ct[3], tat[3], wt[3];
    int i;
    int current_time = 0;

    for (i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];   
        }

        current_time += bt[i];
        ct[i] = current_time;       
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];     // Turnaround Time      1= 4-0 =4,   2= 7-1 =6,      3= 12-2=10
        wt[i]  = tat[i] - bt[i];    // Waiting Time         1= 0 ,       2= 6-3 =3,      3= 10-5=5
    }


    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    float avg_TAT,avg_WT;   
    float sum=0;
    for (i = 0; i < n; i++) {
        sum+= tat[i];
    }
    avg_TAT=sum/n;
    printf("AVG. TAT: %.2f\n",avg_TAT);     //avg tat = 4+6+10/3 => 6.666666
    
    sum=0;
    for (i = 0; i < n; i++) {
        sum+= wt[i];
    }
    avg_WT=sum/n;
    printf("AVG. WT: %.2f\n",avg_WT);     //avg wt = 0+3+5/3 => 2.666666

    return 0;
}