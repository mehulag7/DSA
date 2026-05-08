#include <vector>
using namespace std;

class minHeap {
private:
    vector<int> heap;

    // Move element up to maintain heap property
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else break;
        }
    }

    // Move element down to maintain heap property
    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else break;
        }
    }

public:

    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    int peek() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    int size() {
        return heap.size();
    }
};