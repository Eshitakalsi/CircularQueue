//
//  main.cpp
//  CircularQueue
//
//  Created by Eshita Kalsi on 26/06/20.
//  Copyright © 2020 Eshita Kalsi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    vector<int>queue;
    int front,rear;
    MyCircularQueue(int k) {
        front = -1;
        rear = -1;
        queue.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
//no element present *initial state*
        if(front == -1 && rear == -1){
            front++;
            rear++;
            queue[rear] = value;
            return true;
        } else {
//1. rear is at last pos of queue. 2.front is not at the start i.e some elements have been removed before. 3. rear is not exactly behind front *gaps available*.
            if(rear == queue.size()-1 && front != 0 && rear != front-1){
                rear = 0;
                queue[rear] = value;
                return true;
            }
//1. rear is not exactly behind front. 2. rear is not exceeding the size of queue.
            else if (rear != front-1 && rear<queue.size()-1){
                    rear++;
                    queue[rear] = value;
                    return true;
                }
            }
            
        return false;
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
//if queue is not empty then proceed
        if(!isEmpty()) {
//if both front and end are the end of queue so last element is up for deletion.
             if(front == rear){
            front = rear = -1;
        }
//1.front is at last pos of queue. 2. some enqueues took place and rear is ahead of front in queue.
        else if(front==queue.size()-1 && rear!=front){
                front=0;
            }
// simply increment the front.
        else front++;
            return true;
        }
       
        else return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(!isEmpty()) return queue[front];
        else return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(!isEmpty()) return queue[rear];
        else return -1;
    
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(front==-1 && rear==-1) return true;
        else return false;
    }
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(front==0 && rear==queue.size()-1) return true;
//some elements have been removed therefore front is not zero and rear is exactly behind it.
        else if(front!=0 && rear==front-1) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */