#include <iostream>
using namespace std;
class MaxHeap
{
public:
    int* heap;
    int arraySize;
    int heapSize;
    MaxHeap(){}
    MaxHeap(int size)
    {
        heap = new int[size];
        arraySize = size;
        heapSize = 0;

        for (int i = 0; i < arraySize; i++) //filling heap with junk value
            heap[i] = -9999;
    }
    bool isEmpty()
    {
        return (heapSize == 0);
    }
    int leftChild(int i)
    {
        return ((2 * i) + 1);
    }
    int rightChild(int i)
    {
        return ((2 * i) + 2);
    }
    int getParent(int i)
    {
        return ((i - 1) / 2);
    }
    bool hasLeft(int i)
    {
        return (leftChild(i) < (heapSize - 1));
    }
    bool hasRight(int i)
    {
        return (rightChild(i) < (heapSize - 1));
    }
    void swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    void heapifyUp(int index)//bubble up
    {
        if (index == 0)
            return;

        int parent = getParent(index);

        if (heap[index] > heap[parent])
            swap(parent, index);

        heapifyUp(parent);
    }
    bool insert(int data)
    {
        if (heapSize == arraySize)
            return false;

        heapSize++;
        heap[heapSize - 1] = data;

        heapifyUp(heapSize - 1);
        return true;
    }
    void heapifyDown(int index)//bubble down
    {
        int max = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (hasLeft(index) && (heap[left] > heap[max]))
            max = left;

        if (hasRight(index) && (heap[right] > heap[max]))
            max = right;

        if (max != 0)
        {
            swap(max, index);
            heapifyUp(max);
        }
    }
    int Delete()
    {
        if (heapSize == 0)
            return -9999;

        int num = heap[0];
        heap[0] = heap[heapSize - 1];
        heap[heapSize - 1] = -9999;//junk value
        heapSize--;
        heapifyDown(0);
        return num;
    }

    void print()
    {
        cout << endl;
        for (int i = 0; i < heapSize; i++)
            if (heap[i] != -9999)
                cout << heap[i] << "\t";
    }

    
};
class prioorityQueue
{
    MaxHeap h;
public:
    prioorityQueue(int size)
    {
        h.heap = new int[size];
        h.arraySize = size;
        h.heapSize = 0;

        for (int i = 0; i < h.arraySize; i++) //filling heap with junk value
            h.heap[i] = -9999;
    }
    bool isEmpty()
    {
        return h.isEmpty();
    }
    void enqueue(int data)
    {
        h.insert(data);
    }
    int dequeue()
    {
        if (h.isEmpty())
            return -9999;

        return h.Delete();
    }
};
int main()
{
    prioorityQueue q1(10);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);

    cout << endl << q1.dequeue();
    cout << endl << q1.dequeue();
    cout << endl << q1.dequeue();
    cout << endl << q1.dequeue();
    cout << endl << q1.dequeue();

    cout << endl << q1.dequeue();
    return 0;
}
