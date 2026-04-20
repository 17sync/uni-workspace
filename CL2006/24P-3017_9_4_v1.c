#include <stdio.h>

int main() {
    
    int n = 3; 
    int pid[] = {1, 2, 3};
    int at[]  = {0, 2, 4}; 
    int bt[]  = {5, 7, 3};

    int tq = 4; 

    int remaining[3];
    int ct[3], tat[3], wt[3];

    int completed = 0;
    int current_time = 0;
    int i;

    
    for (i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }

    while (completed < n) {
        int executed = 0;

        for (i = 0; i < n; i++) {
            
            
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
        }                   

        
        if (!executed) {
            current_time++;
        }
    }

    return 0;
}
