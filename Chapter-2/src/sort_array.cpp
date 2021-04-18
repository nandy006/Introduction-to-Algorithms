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
class Array{
    private:
    int length;
    Type** ptrarr;

    public:
        int size() const;
        Type** get_array() const;
        friend istream& operator >> <Type> (istream& s, Array<Type>& arr);
        friend ostream& operator << <Type> (ostream& s, Array<Type>& arr);
        void insertion_sort();
        void quick_sort();
        void heap_sort();
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

template<class Type>
void Array<Type>::quick_sort(){
    QuickSort(ptrarr, 0, length - 1);
}


template<class Type>
void Array<Type>::heap_sort(){
    HeapSort(ptrarr, length);
}
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

int main(){
    Array<double> intarray;
    cin >> intarray;
    cout << intarray;
    intarray.heap_sort();
    cout << intarray;
    return 0;
}

