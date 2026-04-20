#include <stdio.h>

int main() {
    int n = 3;   

    int pid[] = {1, 2, 3};        // Process IDs
    int at[]  = {0, 2, 4};        // Arrival Times
    int bt[]  = {6, 4, 3};        // Burst Times

    int ct[n], tat[n], wt[n];
    int done[n];   

    int i;
    int completed = 0, current_time = 0;
    int smallest, flag;

    
    for (i = 0; i < n; i++) {
        done[i] = 0;
    }

    // Scheduling loop
    while (completed < n) {

        smallest = -1;
        flag = 0;

        for (i = 0; i < n; i++) {
        	//
            if (!done[i] && at[i] <= current_time) {
                if (smallest == -1 || bt[i] < bt[smallest]) {
                    smallest = i;
                    flag = 1;
                }
            }
        }

        
        if (!flag) {
            current_time++;
            continue;
        }

        
        current_time += bt[smallest];
        ct[smallest] = current_time;
        done[smallest] = 1;
        completed++;
    }

    // Calculate TAT and WT
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];         // Turnaround Time      1= 6-0 =6,   2= 13-2 =11,      3= 9-4=5
        wt[i]  = tat[i] - bt[i];        // Waiting Time         1= 0 ,       2= 11-4 =7,      3= 5-3=2
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
    printf("AVG. TAT: %.2f\n",avg_TAT);     //avg tat = 6+11+5/3 => 7.3333
    
    sum=0;
    for (i = 0; i < n; i++) {
        sum+= wt[i];
    }
    avg_WT=sum/n;
    printf("AVG. WT: %.2f\n",avg_WT);     //avg wt = 0+7+2/3 => 3
  

    return 0;
}
