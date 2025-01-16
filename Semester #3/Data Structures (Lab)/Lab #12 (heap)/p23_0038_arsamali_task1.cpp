#include<iostream>
using namespace std;

// Max Heap
class heap {
    int *arr;
    int capacity;
    int length;

public:
    heap(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
        length = 0;
    }
    
    ~heap() {
        delete[] arr;
    }

    void insert(int val) {
        if (length == capacity) {
            cout << "Heap is full..cannot add elements." << endl;
            return;
        }
        arr[length] = val;
        heapifyup(length);
        length++;
    }

    void heapifyup(int index) { // Used for insertion
        int parent = (index - 1) / 2;
        if (parent >= 0 && arr[index] > arr[parent]) {
            swap(arr[index], arr[parent]);
            heapifyup(parent);
        }
    }

    void heapifydown(int index = 0) { // Used for deletion
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < length && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < length && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifydown(largest);
        }
    }

    int deletemax() { // Delete root
        if (length == 0) {
            cout << "Heap is empty, cannot delete elements..." << endl;
            return -1;
        }
        int root = arr[0];
        swap(arr[0], arr[length - 1]);
        length--;
        heapifydown(0);
        return root;
    }

    void heapsort() {
        int tempLength = length;
        for (int i=tempLength-1;i>0;i--) {
            swap(arr[0],arr[i]);
            length--; // Decrease the size for heapifying
            heapifydown(0);
        }
        length=tempLength; // Restore original heap size
    }

    void printheap() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h(10);

    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(10);
    h.insert(40);

    cout << "Heap elements: ";
    h.printheap(); 

    cout << "Deleted max: " << h.deletemax() << endl; 
    cout << "Heap after deleting root: ";
    h.printheap();

    h.insert(50);
    h.insert(5);
    cout << "Heap after inserting more elements: ";
    h.printheap();

    h.heapsort();
    cout << "Heap elements after heap sort: ";
    h.printheap();

    return 0;
}
