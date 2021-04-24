#include<iostream>
using namespace std;

template<class Type>
class Queue{
    private:
        int length;
        int current_length;
        int first;
        int last;
        Type* arr;

    public:
        Queue(int);
        ~Queue();
        bool isEmpty() const;
        bool isFull() const;
        void enqueue(Type);
        Type deque();
        void showQueue() const;
};

template<class Type>
Queue<Type>::Queue(int n){
    length=n;
    current_length=0;
    first=0;
    last=-1;
    arr = new Type[length];
}

template<class Type>
Queue<Type>::~Queue(){
    cout << "Queue destroyed \n";
    delete[] arr;
}

template<class Type>
void Queue<Type>::enqueue(Type value){
    if(isFull()){
        cout << "Queue overflow \n"; exit(0);
    }
    if(last == length-1)
        last = 0;
    else
        last++;
    current_length++;
    arr[last] = value;
}

template<class Type>
Type Queue<Type>::deque(){
    if(isEmpty()){
        cout << "Queue underflow \n"; exit(0);
    }
    if(first == length-1){
        first = 0;
        current_length--;
        return arr[length-1];
    }
    else{
        first++;
        current_length--;
        return arr[first-1];
    }
}

template<class Type>
bool Queue<Type>::isFull() const{
    return (current_length == length)? 1:0;
}

template<class Type>
bool Queue<Type>::isEmpty() const{
    return (current_length == 0)? 1:0;
}

template<class Type>
void Queue<Type>::showQueue() const{
    /*
    for debugging
    */
    for(int i=0; i<length-1; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    Queue<double> myqueue(6);
    myqueue.enqueue(1.1);
    myqueue.enqueue(1.2);
    myqueue.enqueue(1.3);
    myqueue.enqueue(1.4);
    myqueue.enqueue(1.5);
    myqueue.enqueue(1.6);
    myqueue.showQueue();
    cout << myqueue.deque() << endl;
    myqueue.enqueue(1.9);
    myqueue.showQueue();
    cout << myqueue.deque() << endl;
    cout << myqueue.deque() << endl;
    cout << myqueue.deque() << endl;
    cout << myqueue.deque() << endl;
    cout << myqueue.deque() << endl;
    cout << myqueue.deque() << endl;
    myqueue.showQueue();
}