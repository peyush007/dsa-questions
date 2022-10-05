
//https://www.geeksforgeeks.org/interleave-first-half-queue-second-half-2/

// CPP program to interleave queue elements
// using only queue data structure.
#include <bits/stdc++.h>
using namespace std;
 
void interleave(queue<int> &q)
{
    queue<int> q1, q2;
 
    int n = q.size();
 
    // Insert first half in q1
    for (int i = 0; i < n / 2; i++) {
        q1.push(q.front());
        q.pop();
    }
 
    // insert second half in q2
    for (int i = 0; i < n / 2; i++) {
        q2.push(q.front());
        q.pop();
    }
    
    // Insert elements of q1 and q2 back
    // to q in alternate order.
    for (int i = 0; i < n/2; i++) {
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
}
 
// Driver code
int main()
{
    // Creating an example queue with 10
    // elements.
    queue<int> q;
    for (int i = 1; i <= 10; i++)
        q.push(i); 
 
    interleave(q);
 
    // Printing queue elements
    int n = q.size();
    for (int i = 0; i < n; i++) {
        cout << q.front() << " ";
        q.pop();
    }
}