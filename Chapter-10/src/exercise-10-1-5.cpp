#include<iostream>
using namespace std;

template<class Type>
class Deque{
    private:
        int length;
        int front;
        int rear;
        int current_length;
        Type* arr;

    public:
        Deque(int);
        ~Deque();
        bool isFull() const;
        bool isEmpty() const;
        void enqueue_front(Type);
        void enqueue_rear(Type);
        Type dequeue_front();
        Type dequeue_rear();
        void showQueue() const;
};

template<class Type>
Deque<Type>::Deque(int n){
    length = n;
    front = 0;
    rear = -1;
    current_length = 0;
    arr = new Type[length];
}

template<class Type>
Deque<Type>::~Deque(){
    cout << "Queue destroyed \n";
    delete[] arr;
}

template<class Type>
void Deque<Type>::enqueue_front(Type value){
    if(isFull()){
        cout << "Queue full \n"; exit(0);
    }
    if(front == 0)
        front = length - 1;
    else
        front--;
    arr[front] = value;
    current_length++;
}

template<class Type>
void Deque<Type>::enqueue_rear(Type value){
    if(isFull()){
        cout << "Queue full \n"; exit(0);
    }
    if(rear == length - 1)
        rear = 0;
    else
        rear++;
    arr[rear] = value;
    current_length++;
}

template<class Type>
Type Deque<Type>::dequeue_front(){
    if(isEmpty()){
        cout << "Queue empty \n"; exit(0);
    }
    if(front == length - 1){
        front = 0;
        current_length--;
        return arr[length-1];
    }
    else{
        front++;
        current_length--;
        return arr[front - 1];
    }
}

template<class Type>
Type Deque<Type>::dequeue_rear(){
    if(isEmpty()){
        cout << "Queue empty \n"; exit(0);
    }
    if(rear == 0){
        rear = length - 1;
        current_length--;
        return arr[0];
    }
    else{
        rear--;
        current_length--;
        return arr[rear + 1];
    }
}

template<class Type>
bool Deque<Type>::isFull() const{
    return (current_length == length)? 1:0;
}

template<class Type>
bool Deque<Type>::isEmpty() const{
    return (current_length == 0)? 1:0;
}

template<class Type>
void Deque<Type>::showQueue() const{
    for(int i=0; i < length; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

int main(){
    Deque<double> myqueue(6);
    myqueue.enqueue_rear(1.1);
    myqueue.enqueue_front(1.2);
    myqueue.enqueue_rear(1.3);
    myqueue.enqueue_front(1.4);
    myqueue.enqueue_rear(1.5);
    myqueue.enqueue_rear(1.6);
    myqueue.showQueue();
    cout << myqueue.dequeue_rear() << endl;
    myqueue.enqueue_front(1.9);
    myqueue.showQueue();
    cout << myqueue.dequeue_rear() << endl;
    cout << myqueue.dequeue_front() << endl;
    cout << myqueue.dequeue_rear() << endl;
    cout << myqueue.dequeue_rear() << endl;
    cout << myqueue.dequeue_rear() << endl;
    cout << myqueue.dequeue_front() << endl;
    myqueue.showQueue();

}