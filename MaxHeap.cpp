#include <iostream>
using namespace std;
class MaxHeap
{
public:
    int* heap;
    int arraySize;
    int heapSize;
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
        return (heapSize==0);
    }
    int leftChild(int i)
    {
        return ((2*i)+1);
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

    void ascending(int arr [], int size)//Heap sort
    {
        MaxHeap h(size);
        for (int i = 0; i < size; i++)
            h.insert(arr[i]);

        for (int i = size - 1; i >= 0; i--)
            arr[i] =h.Delete();
    }
    void descending(int arr[], int size)//Heap sort
    {
        MaxHeap h(size);
        for (int i = 0; i < size; i++)
            h.insert(arr[i]);

        for (int i = 0; i < size; i++)
            arr[i] = h.Delete();
    }
    void heapify(int arr[], int index,int size)
    {
        int max = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if ((left < size) && (arr[left] > arr[max]))
            max = left;
        if((right<size)&&(arr[right]>arr[max]))
            max=right;
        
        if (max != index)
        {
            int temp = arr[max];        //swaping
            arr[max] = arr[index];
            arr[index] = temp;
            
            heapify(arr, max, size);
        }

    }
    void heapify(int arr[], int size)//overloading
    {
        for (int i = (size/2- 1); i >=0 ; i--)//optimizing
            heapify(arr, i, size);
    }
};
int main()
{
    MaxHeap h1(10);
    h1.insert(1);
    h1.insert(2);
    h1.insert(3);
    h1.insert(4);
    h1.insert(5);

    h1.print();
    

    int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
    h1.ascending(arr, 10);
    cout << endl;
    for (int i = 0; i <= 9; i++)
        cout << arr[i] << "\t";


    h1.descending(arr, 10);
    cout << endl;
    for (int i = 0; i <= 9; i++)
        cout << arr[i] << "\t";

    int arr1[5] = {3, 2, 1, 4, 5};
    h1.heapify(arr1, 5);

    cout << endl;
    for (int i = 0; i <= 4; i++)
        cout << arr1[i] << "\t";
    
    return 0;
}
