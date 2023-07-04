#include <iostream>
using namespace std;
class kstacks
{
    int *arr;
    int *top;
    int *next;
    int n, k;
    int free;

public:
    // constructor
    kstacks(int k1, int n1)
    {
        {
            k = k1, n = n1;
            arr = new int[n];
            top = new int[n];
            next = new int[n];
        }
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        free = 0;
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }
    // isfull and isempty

    // A utility function to check if there is space available
    bool isFull() { return (free == -1); }

    bool isEmpty(int sn) { return (top[sn] == -1); }

    // push
    void push(int item, int sn)
    {
        if (isFull())
        {
            cout << "Stack overflow\n"
                 << endl;
            return;
        }
        // 5 steps
        // check index that is free
        int i = free;
        // update free ptr to next index
        free = next[i];
        // update next[i] to previous topmost element on the current pushing stack
        next[i] = top[sn];
        // current updated top of current stack is
        top[sn] = i;
        // perform push operation
        arr[i] = item;
    }

    int pop(int sn)
    {
        if (isEmpty(sn))
        {
            cout << "stack underflow!!\n";
            return INT_MAX;
        }
        // find index of top item in the given stack
        int i = top[sn];
        // change top to store next previous top of the same stack
        top[sn] = next[i];
        // attach the popping index (currentlyy)as free in the next
        next[i] = free;
        // update the free ptr
        free = i;
        // return previous top element
        return arr[i];
    }
};
int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    kstacks ks(k, n);

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}