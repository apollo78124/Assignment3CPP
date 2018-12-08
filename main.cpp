#include "heap.hpp"

int main() {

    vector<int> initial = {10, 15, 8, 3, 16, 20, 11, 12, 5, 7, 4, 1, 19, 13, 2, 6, 9, 14, 17, 18};
    Heap<int, vector> myheap = Heap<int, vector>::instance();
    myheap.set_heap(initial);
    cout << "Initial heap: \n";
    cout << myheap;
    cout << "Pop one out: \n";
    myheap.pop();
    cout << myheap;
    cout << "Push back 69: \n";
    myheap.push(69);
    cout << myheap;

    return 0;
}