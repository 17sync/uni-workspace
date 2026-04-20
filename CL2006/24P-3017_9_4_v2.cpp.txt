#include <iostream>
#include <queue>
using namespace std;

int main() {

    int n  = 3;
    int tq = 4;

    int pid[] = {1, 2, 3};
    int at[]  = {0, 2, 4};
    int bt[]  = {5, 7, 3};

    int remaining[] = {5, 7, 3};    //same as bt 

    int ct[3], tat[3], wt[3];
    
    bool inQueue[3] = {false};

    queue<int> readyQueue;

    int completed    = 0;
    int current_time = 0;

    for (int i = 0; i < n; i++)
        if (at[i] == 0) {
            readyQueue.push(i);
            inQueue[i] = true;
        }

    while (completed < n) {

        if (readyQueue.empty()) {
            current_time++;
            for (int i = 0; i < n; i++)
                if (remaining[i] > 0 && at[i] <= current_time && !inQueue[i]) {
                    readyQueue.push(i);
                    inQueue[i] = true;
                }
            continue;
        }

        int i = readyQueue.front();
        readyQueue.pop();

        if (remaining[i] < tq) {
            current_time  += remaining[i];
            remaining[i]  = 0;
        } else {
            current_time  += tq;
            remaining[i] -= tq;
        }

        //if the process still has bursts remaining push it back into the queue else its completed
        for (int i = 0; i < n; i++)
            if (remaining[i] > 0 && at[i] <= current_time && !inQueue[i]) {
                readyQueue.push(i);
                inQueue[i] = true;
            }

        if (remaining[i] > 0)
            readyQueue.push(i);
        else {
            ct[i] = current_time;
            completed++;
        }
    }

    return 0;
}