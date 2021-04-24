#include<iostream>
using namespace std;

template<class Type>
void MinHeapify(Type**, int, int);

template<class Type>
void BuildMinHeap(Type**, int);

template<class Type>
void Heapsort_min(Type**, int);

template<class Type>
void MaxHeapify_iterative(Type**, int, int);

template<class Type>
class Array{
    private:
        int length;
        Type** ptrarr;

    public:
        void get_array();
        void show_array() const;
        void heapsort_min();
};

template<class Type>
void Array<Type>::get_array(){
    cout << "Enter length of the array: ";
    cin >> length;
    ptrarr = new Type*[length];
    for(int i=0; i < length; i++){
        *(ptrarr + i) = new Type;
        cout << "array[" << i << "] = ";
        cin >> **(ptrarr + i);
    }
}

template<class Type>
void Array<Type>::show_array() const{
    for(int i=0; i < length; i++)
        cout << **(ptrarr + i) << " ";
}


template<class Type>
void Array<Type>::heapsort_min(){
    Heapsort_min(ptrarr, length);
}

template<class Type>
void Heapsort_min(Type** ptrptr, int heap_size){
    BuildMinHeap(ptrptr, heap_size);
    Type* key_ptr;
    int len = heap_size;
    for(int i = len - 1; i >= 1; i--){
        key_ptr = *(ptrptr + i);
        *(ptrptr + i) = *ptrptr;
        *ptrptr = key_ptr;
        heap_size--;
        MinHeapify(ptrptr, 0, heap_size);
    }
}

template<class Type>
void MinHeapify(Type** ptrptr, int index, int heap_size){
    int left_child = 2*index + 1, right_child = 2*index + 2;
    int smallest;
    if((left_child <= heap_size -1) && **(ptrptr + left_child) < **(ptrptr + i))
        smallest = left_child;
    else
        smallest = i;

    if((right_child <= heap_size - 1) && **(ptrptr + right_child) < **(ptrptr + smallest))
        smallest = right_child;

    if(smallest != index){
        Type* temp = *(ptrptr + smallest);
        *(ptrptr + smallest) = *(ptrptr + index);
        *(ptrptr + index) = temp;
        MinHeapify(ptrptr, smallest, heap_size);
    }
}

template <class Type>
void BuildMinHeap(Type** ptrptr, int heap_size){
    for(int i = heap_size/2 - 1; i >=0; i--)
        MinHeapify(ptrptr, i, heap_size);
}

template <class Type>
void MaxHeapify_iterative(Type** ptrptr, int index, int heap_size){

}

int main(){
    Array<double> myarray;
    myarray.get_array();
    myarray.show_array();
    cout << endl;
    myarray.heapsort_min();
    myarray.show_array();
    cout << endl;
}