#include <iostream>
using namespace std;
class MinHeap
{
public:
    int* heap;
    int heapSize;
    int arraySize;
    MinHeap(int size)
    {
        arraySize = size;
        heapSize = 0;
        heap = new int[size];
        for (int i = 0; i < size; i++)
            heap[i] = -9999;
    }
    bool isEmpty()
    {
        return (heap == NULL);
    }
    int getLeftIndex(int i)
    {
        return ((2 * i) + 1);
    }
    int getRightIndex(int i)
    {
        return ((2 * i) + 2);
    }
    int getParentIndex(int i)
    {
        return ((i - 1) / 2);
    }
    void swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    bool hasLeft(int i)
    {
        return (getLeftIndex(i) < heapSize);
    }
    bool hasRight(int i)
    {
        return (getRightIndex(i) < heapSize);
    }
    void heapifyUp(int i) //bubble up
    {
        if (i != 0)
        {
            int parent = getParentIndex(i);
            if (heap[i] < heap[parent])
                swap(parent, i);
            heapifyUp(parent);
        }
    }
    bool insert(int val)
    {
        if (heapSize == arraySize)
            return true;

        heapSize++;
        heap[heapSize-1] = val;
        heapifyUp(heapSize - 1);
    }
    void heapifyDown(int index)//bubble down
    {
        int min = index;
        int left = getLeftIndex(index);
        int right = getRightIndex(index); 
        if (hasLeft(index) && heap[min] > heap[left])
            min = left;

        if (hasRight(index) && heap[min] > heap[right])
            min = right;

        if (min != index)
        {
            swap(min,index);
            heapifyDown(min);
        }
    }
    int Delete()
    {
        if (heapSize == 0)
            return -9999;//junk value
        int num=heap[0];
        heap[0] = heap[heapSize - 1];
        heap[heapSize - 1] = -9999;
        heapSize--;
        heapifyDown(0);
        return num;
    }
    void print()
    {
        for (int i = 0; i < arraySize; i ++)
        {
            if (heap[i] != -9999)
                cout << heap[i]<<"\t";
        }
    }
    void ascending(int arr[], int size)//Heap sort
    {
        MinHeap h(size);
        for (int i = 0; i < size; i++)
            h.insert(arr[i]);

        for (int i = 0; i < size; i++) //ascending order heap sort
            arr[i] = h.Delete();
        
    }

    void descending(int arr[], int size)//Heap sort
    {
        MinHeap h(size);
        for (int i = 0; i < size; i++)
            h.insert(arr[i]);

        for (int i = size-1; i >= 0; i--) //decending order heap sort
            arr[i] = h.Delete();

    }
};
int main()
{
    MinHeap h1(13);
    h1.insert(15);
    h1.insert(3);
    h1.insert(6);
    h1.insert(18);
    h1.insert(5);
    h1.insert(9);
    h1.insert(11);
    h1.insert(20);
    h1.insert(17);
    h1.insert(7);
    h1.insert(2);
    h1.insert(3);
    h1.insert(14);

    h1.print();

    cout << endl;

    int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
    h1.ascending(arr, 10);

    for (int i = 0; i <= 9; i++)
        cout << arr[i]<<"\t";

    cout << endl;
    h1.descending(arr, 10);

    for (int i = 0; i <= 9; i++)
        cout << arr[i] << "\t";
    

    return 0;
}
