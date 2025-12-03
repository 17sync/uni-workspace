#include<iostream>
#include<cstdlib>
using namespace std;

class ArrCircularQueue {
public:
    int front;
    int rear;
    int size;
    int* arr;

    ArrCircularQueue(int value) {
        front = rear = -1;
        arr = new int[value];
        size = value;
    }

    ~ArrCircularQueue() { delete[] arr; }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;  // Circular condition — wraps around
    }

    void Enqueue(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;   // Moves circularly using modulo
            }
            arr[rear] = value;
            cout << value << " Value is enqueued at " << rear << " Position " << endl;
        } else {
            cout << "Queue is already full" << endl;
        }
    }

    void Dequeue() {
        if (!isEmpty()) {
            cout << arr[front] << " is Dequeued Successfully" << endl;
            arr[front] = 0;
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;   // Circular increment
            }
        } else {
            cout << "Queue is Empty" << endl;
        }
    }

    void display() {
        if (!isEmpty()) {
            int i = front;
            while (true) {
                cout << arr[i] << " , ";
                if (i == rear) break;
                i = (i + 1) % size;
            }
            cout << endl;
        } else {
            cout << "Queue is empty " << endl;
        }
    }

    void peek() {
        if (!isEmpty()) {
            cout << "Front element is: " << arr[front] << endl;
        } else {
            cout << "Queue is empty, nothing to peek." << endl;
        }
    }

    int RemainingQueue() {
        if (isEmpty()) return size;
        if (isFull()) return 0;
        if (rear >= front) return size - (rear - front + 1);
        return front - rear - 1;
    }
};

int main() {
    cout << "24P-3017\n" << endl;
    ArrCircularQueue obj(3);

    /* Initially:
       front = -1, rear = -1
       Queue = [ _ , _ , _ ]
    */

    obj.Enqueue(2);
    /* After Enqueue(2):
       front = 0, rear = 0
       Queue = [ 2 , _ , _ ]
       (In Linear Queue -> front=0, rear=0 too)
    */

    obj.Enqueue(4);
    /* After Enqueue(4):
       rear moves (0+1)%3 = 1
       front = 0, rear = 1
       Queue = [ 2 , 4 , _ ]
       (Linear Queue also same till now)
    */

    obj.Enqueue(6);
    /* After Enqueue(6):
       rear moves (1+1)%3 = 2
       front = 0, rear = 2
       Queue = [ 2 , 4 , 6 ]
       Queue is FULL
       (Linear Queue also full here — but after dequeue, linear cannot reuse freed space)
    */

    obj.Dequeue();
    /* After Dequeue():
       2 is removed from front index 0
       front moves (0+1)%3 = 1
       rear = 2
       Queue = [ 0 , 4 , 6 ]
       (Linear Queue → front=1, rear=2, but space at index 0 CANNOT be reused)
       (Circular Queue → space at index 0 WILL be reused next enqueue)
    */

    obj.Enqueue(8);
    /* After Enqueue(8):
       rear moves (2+1)%3 = 0 --> wrap around
       front = 1, rear = 0
       Queue = [ 8 , 4 , 6 ]
       This shows circular behavior: index 0 reused.
       (Linear Queue → would say “Queue Full” here because rear=2 and can’t wrap)
    */

    return 0;
}


