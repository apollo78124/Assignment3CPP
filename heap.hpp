//
// Created by dldms on 12/7/2018.
//
#ifndef ASSIGNMENT3_HEAP_HPP
#define ASSIGNMENT3_HEAP_HPP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
  * Singleton Design Pattern
  * @tparam T
  * @tparam Container
 */
template <typename T, template <typename, typename> class Container>
class Heap {
private:

    /**
     * Current instance of the heap.
     */
    static Heap heap_instance;

    /**
     * Data in the vector.
     */
    vector<T> data;

    /**
     * Initialize the heap.
     */
    Heap() = default;
public:
    /**
     * Initialize the Heap from the passed In values.
     * @param passedIn
     */
    Heap(vector<T> passedIn) {
        data = passedIn;
    };

    /**
     * Setup the heap
     * @param array
     */
    void set_heap(Container<T, allocator<T>> array) {
        data = array;
        make_heap(data.begin(), data.end());
    }

    /**
     * Pop the root of the vector.
     */
    void pop() {
        pop_heap(data.begin(), data.end());
        data.pop_back();
    }

    /**
     * Push the new value to the heap
     * and make the heap.
     * @param pushed
     */
    void push(int pushed) {
        data.push_back(pushed);
        push_heap(data.begin(), data.end());
    }

    /**
     * Operator overload.
     * @param os
     * @param m
     * @return os
     */
    friend ostream &operator << (ostream &os, const Heap & m) {
        for(int i = 0; i < m.data.size(); i++) {
            os << " " << m.data[i];
        }
        os << "\n";
        return os;
    }

    /**
     * Instance of the heap.
     * @return Heap&
     */
    static Heap& instance() {
        static Heap heap_instance;
        return heap_instance;
    }

    /**
     * Return the size of the vector.
     * @return int
     */
    int size() {
        return data.size();
    }

    /**
     * Whether the heap is empty or not.
     * @return
     */
    bool is_empty() {
        if(data.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Clear the heap and delete the data.
     */
    void clear() {
        data.clear();
    }
};
#endif //ASSIGNMENT3_HEAP_HPP
