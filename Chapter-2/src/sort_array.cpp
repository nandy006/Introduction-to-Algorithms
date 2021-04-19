#include<iostream>
using namespace std;
template<class Type>
class Array;

template<class Type>
istream& operator >> (istream& s, Array<Type>& arr);

template<class Type>
ostream& operator << (ostream& s, Array<Type>& arr);

template<class Type>
int partition(Type**, int, int);

template<class Type>
void QuickSort(Type**, int, int);

template<class Type>
void MaxHeapify(Type**, int, int);

template<class Type>
void BuildMaxHeap(Type**, int);

template<class Type>
void HeapSort(Type**, int);

template<class Type>
void Merge(Type**, int, int, int);

template<class Type>
void MergeSort(Type**, int, int);

template<class Type>
void InsertionSortRecursive(Type**, int);

template<class Type>
void Insert(Type**, int);

template<class Type>
int BinarySearch(Type**, int, int, Type);

template<class Type>
struct which_values{
    Type low;
    Type high;
};

template<class Type>
class Array{
    private:
    int length;
    Type** ptrarr; 
/* 
Since the array to be sorted could have any data type
including possibly very large objects we always sort 
the pointers not the objects themselves
*/

    public:
        int size() const;
        Type** get_array() const;
        friend istream& operator >> <Type> (istream& s, Array<Type>& arr);
        friend ostream& operator << <Type> (ostream& s, Array<Type>& arr);
        void insertion_sort();
        void quick_sort();
        void heap_sort();
        void merge_sort();
        void insertion_sort_recursive();
        int binary_search(Type);
        which_values<Type> two_sum(Type);
};

template<class Type>
int Array<Type>::size() const{
    return length;
}

template<class Type>
Type** Array<Type>::get_array() const{
    return ptrarr;
}

template<class Type>
istream& operator >> (istream& s, Array<Type>& arr){
    cout << "Enter length of array: "; cin >> arr.length;
    arr.ptrarr = new Type*[arr.length];
    for(int i = 0; i < arr.length; i++){
        *(arr.ptrarr+ i) = new Type;
        cout << "Array[" << i << "] = ";
        cin >> **(arr.ptrarr + i);
    }
    return s;
}

template<class Type>
ostream& operator << (ostream& s, Array<Type>& arr){
    for(int i = 0; i < arr.length; i++)
        cout << " " << **(arr.ptrarr + i);
    cout << endl;

    return s;
}

template<class Type>
void Array<Type>::insertion_sort(){
    Type* key_ptr, curr_ptr;
    for(int i =1; i < length; i++){
        key_ptr = *(ptrarr + i);
        int j = i - 1;
        while(j >= 0 && **(ptrarr + j) > *key_ptr){
            *(ptrarr + j + 1) = *(ptrarr + j);
            j--;
        }
        *(ptrarr + j + 1) = key_ptr;
    }
}

template<class Type>
void Array<Type>::quick_sort(){
    QuickSort(ptrarr, 0, length - 1);
}


template<class Type>
void Array<Type>::heap_sort(){
    HeapSort(ptrarr, length);
}

template<class Type>
void Array<Type>::merge_sort(){
    MergeSort(ptrarr, 0, length - 1);
}


/*
functions for Quick Sort
*/

template<class Type>
int partition(Type**ptrptr, int low, int high){
    Type pivot = **(ptrptr + high);
    Type* temp;
    int i = low - 1;
    for(int j=low; j < high; j++){
        if(**(ptrptr + j) < pivot){
            i++;
            cout << **(ptrptr + i) << **(ptrptr + j) << endl;
            temp = *(ptrptr +j);
            *(ptrptr + j) = *(ptrptr +i);
            *(ptrptr + i) = temp;
        }
    }
    temp = *(ptrptr + high);
    *(ptrptr + high) = *(ptrptr + i + 1);
    *(ptrptr + i + 1) = temp;
    return i+1;
}

template<class Type>
void QuickSort(Type** ptrptr, int low, int high){
    if(low < high){
        int i = partition(ptrptr, low, high);
        QuickSort(ptrptr, low, i-1);
        QuickSort(ptrptr, i+1, high);  
    }
    
}

/*
Functions for heap sort
*/

template<class Type>
void MaxHeapify(Type** ptrptr, int index, int heapsize){
    int left_child = 2*index + 1, right_child = 2*(index + 1), largest;
    if((left_child <= heapsize - 1)&&(**(ptrptr + index) < **(ptrptr + left_child))){
        largest = left_child;
    }else{
        largest = index;
    }
    if((right_child <= heapsize -1)&&(**(ptrptr + largest) < **(ptrptr + right_child)))
        largest = right_child;
    if(largest != index){
        Type* temp = *(ptrptr + largest);
        *(ptrptr + largest) = *(ptrptr + index);
        *(ptrptr + index) = temp;
        MaxHeapify(ptrptr, largest, heapsize);
    }
}

template<class Type>
void BuildMaxHeap(Type** ptrptr, int heapsize){
    for(int i = heapsize/2 - 1; i >=0; i--){
        MaxHeapify(ptrptr, i, heapsize);
    }
    cout << endl;
}

template<class Type>
void HeapSort(Type** ptrptr, int heapsize){
    BuildMaxHeap(ptrptr, heapsize);
    for(int i = heapsize - 1; i >=1; i--){
        Type* temp = *(ptrptr + i);
        *(ptrptr + i) = *ptrptr;
        *ptrptr = temp;
        heapsize --;
        MaxHeapify(ptrptr, 0, heapsize);
    }
}


/*
functions for merge sort
*/

template<class Type>
void MergeSort(Type** ptrptr, int low, int high){
    if(high > low){
        int mid = (low + high)/2;
        MergeSort(ptrptr, low, mid);
        MergeSort(ptrptr, mid+1, high);
        Merge(ptrptr, low, mid, high);
    }
}

template<class Type>
void Merge(Type** ptrptr, int low, int mid, int high){
    Type** leftarr, ** rightarr;
    leftarr = new Type*[mid - low + 1];
    rightarr = new Type*[high - mid];

    for(int i=0; i <= mid - low; i++)
        *(leftarr + i) = *(ptrptr + low + i);

    for(int i=0; i < high - mid; i++)
        *(rightarr + i) = *(ptrptr + mid + 1 + i);

    int i = low, j = 0, k=0;

    while(j <= mid - low && k < high - mid ){
        if(**(leftarr + j) < **(rightarr + k) ){
            *(ptrptr + i++) = *(leftarr + j++);
        }
        else{
            *(ptrptr + i++) = *(rightarr + k++);
        }
    }

    if(j > mid - low){
        while(i <= high)
            *(ptrptr + i++) = *(rightarr + k++);
    }

    if(k >= high - mid){
        while(i <= high)
            *(ptrptr + i++) = *(leftarr + j++);
    }

    delete[] leftarr;
    delete[] rightarr;    
}


/*
functions for recursive insertion sort
*/
template<class Type>
void Array<Type>::insertion_sort_recursive(){
    InsertionSortRecursive(ptrarr, length-1);
}

template<class Type>
void InsertionSortRecursive(Type** ptrptr, int n){
    if(n >= 1){
        InsertionSortRecursive(ptrptr, n-1);
        Insert(ptrptr, n);
    }
}

template<class Type>
void Insert(Type** ptrptr, int n){
    Type* keyptr = *(ptrptr + n);
    int i = n-1;
    while(i >= 0 && **(ptrptr + i) > *keyptr){
        *(ptrptr + i + 1) = *(ptrptr + i);
        i--;
    }
    *(ptrptr + i + 1) = keyptr;
}

/*
functions for binary search
*/

template<class Type>
int Array<Type>::binary_search(Type key){
    Array<Type>::merge_sort();
    return BinarySearch(ptrarr, 0, length-1, key);
}

template<class Type>
int BinarySearch(Type** ptrptr, int low, int high, Type key){
    if(high >= low){
        int mid = (low + high)/2;
        if(**(ptrptr + mid) == key)
            return mid;
        else if(**(ptrptr + mid) > key)
            return BinarySearch(ptrptr, low, mid-1, key);
        else
            return BinarySearch(ptrptr, mid+1, high, key);
    }
    return -1;
}

/*
function for two sum
right now it only shows one of many possible matches
we'll modify this later
*/

template<class Type>
which_values<Type> Array<Type>::two_sum(Type sum_val){
    Array<Type>::merge_sort();
    for(int i =length-1; i > 0; i--){
        Type key = sum_val - **(ptrarr + i);
        int found = BinarySearch(ptrarr, 0, i-1, key);
        if(found != -1)
            return {**(ptrarr + found), **(ptrarr + i)};
    }
    return {-1, -1};
}

int main(){
    Array<double> myarray;
    cin >> myarray;
    cout << myarray;
    which_values<double> matches = myarray.two_sum(11);
    // int location = myarray.binary_search(1.5);
    cout << "The numbers that sum to " << 11 
    << " are (" << matches.low <<", " << matches.high << ")" << endl;
    return 0;
}

