#include <stdio.h>

int main() {
    
    int n = 3; // number of processes
    int pid[] = {1, 2, 3};
    int at[]  = {0, 2, 4}; 
    int bt[]  = {5, 7, 3};

    int tq = 4; // Time Quantum

    int remaining[3];
    int ct[3], tat[3], wt[3];

    int completed = 0;
    int current_time = 0;
    int i;

    // initialize remaining burst time = burst time
    for (i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }

    while (completed < n) {
        int executed = 0;

        for (i = 0; i < n; i++) {
            
            // process must have arrived and must have remaining time
            if (remaining[i] > 0 && at[i] <= current_time) {

                executed = 1;

                if (remaining[i] > tq) { 
                    current_time += tq;
                    remaining[i] -= tq;
                } 
                else {
                    current_time += remaining[i];
                    ct[i] = current_time;
                    remaining[i] = 0;
                    completed++;
                }
            }
        }                   // P1 remaining 5-4 = 1(preempted), P2 remaining 7-4 = 3 , P3 remaining 3-3 = 0 , now P1 1-1 = 0 then P2 3-3 = 0

        
        if (!executed) {
            current_time++;
        }
    }

    // calculate TAT and WT
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];     // Turnaround Time      1= 12-0 =12,   2= 15-2 =6,      3= 11-4=7
        wt[i] = tat[i] - bt[i];     // Waiting Time         1= 12-5 =7 ,   2= 13-7 =6,      3= 7-3=4
    }

    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }



    float avg_TAT,avg_WT;   
    float sum=0;
    for (i = 0; i < n; i++) {
        sum+= tat[i];
    }
    avg_TAT=sum/n;
    printf("AVG. TAT: %.2f\n",avg_TAT);     //avg tat = 12+13+7/3 => 10.666666
    
    sum=0;
    for (i = 0; i < n; i++) {
        sum+= wt[i];
    }
    avg_WT=sum/n;
    printf("AVG. WT: %.2f\n",avg_WT);     //avg wt = 7+6+4/3 => 5.666666

    return 0;
}
