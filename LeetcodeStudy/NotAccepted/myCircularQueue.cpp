#include <malloc.h>
int globalQueueSize;
int head;
int tail;
bool isFull;
bool isEmpty;
typedef struct {
    int next;
    int prev;
    int value;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    globalQueueSize = k;
    MyCircularQueue* result = (MyCircularQueue*)malloc(sizeof(MyCircularQueue)*k);
    return result;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return isEmpty == true;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    //return obj[tail].next == head;
    return isFull == true;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (!myCircularQueueIsFull(obj))
    {
        isEmpty = false;
        obj[tail].value = value;
        // Set prev
        if (tail == 0)
        {
            obj[tail].prev = globalQueueSize-1;
        }
        else
        {
            obj[tail].prev = tail-1;
        }

        // Set next
        if (tail == globalQueueSize-1)
        {
            obj[tail].next = 0;
            tail = 0;
        }
        else
        {
            obj[tail].next = tail+1;
            tail++;
        }
        if (tail == head)
        {
            isFull = true;
        }
        return true;
    }
    return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!myCircularQueueIsEmpty(obj))
    {
        isFull = false;
        head = obj[head].next;
        if (head == tail)
        {
            isEmpty = true;
        }
        return true;
    }
    return false;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return obj[head].value;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return obj[obj[tail].prev].value;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    head = 0;
    tail = 0;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/