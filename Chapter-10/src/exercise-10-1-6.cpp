#include<iostream>
using namespace std;

template<class Type>
struct Stack{
        int top;
        int size;
        Type* stack_arr;
};

template<class Type>
void push(Stack<Type>*, Type);

template<class Type>
Type pop(Stack<Type>*);

template<class Type>
void show_stack(Stack<Type>*);

template<class Type>
class Queue: public Stack<Type>{
    private:
        Stack<Type>* ptrstack1;
        Stack<Type>* ptrstack2;

    public:
        Queue(int);
        ~Queue();
        void enqueue(Type);
        Type dequeue();
        void showQueue();
};

template<class Type>
void push(Stack<Type>* stackptr, Type value){
    stackptr->top++;
    if(stackptr-> top > stackptr-> size - 1){
        cout << "Overflow \n"; exit(0);
    }
    stackptr->stack_arr[stackptr->top] = value;
}

template<class Type>
Type pop(Stack<Type>* stackptr){
    if(stackptr->top < 0){
        cout << "Underflow \n"; exit(0);
    }
    stackptr->top--;
    return stackptr->stack_arr[stackptr->top + 1];
}

template<class Type>
void show_stack(Stack<Type>* stackptr){
    /*
    for debugging purposes
    */
    cout << "Top = " << stackptr->top << endl;
    cout << "Size = " << stackptr->size << endl;
    for(int i=0; i< stackptr->size; i++)
        cout << stackptr-> stack_arr[i] << " ";
    cout << endl;
}

template<class Type>
Queue<Type>::Queue(int n){
    ptrstack1 = new Stack<Type>;
    ptrstack2 = new Stack<Type>;
    ptrstack1 -> size = n;
    ptrstack2 -> size = n;
    ptrstack1 -> top = -1;
    ptrstack2 -> top = -1;
    ptrstack1->stack_arr = new Type[n];
    ptrstack2->stack_arr = new Type[n];
}

template<class Type>
Queue<Type>::~Queue(){
    delete[] ptrstack1->stack_arr;
    delete[] ptrstack2->stack_arr;
    delete ptrstack1;
    delete ptrstack2;
}

template<class Type>
void Queue<Type>::enqueue(Type value){
    push(ptrstack1, value);
}

template<class Type>
Type Queue<Type>::dequeue(){
    Type val1;
    while(ptrstack1 -> top != 0){
        val1 = pop(ptrstack1);
        push(ptrstack2, val1);
    }
    val1 = pop(ptrstack1);
    Type val2;
    while(ptrstack2 -> top != -1){
        val2 = pop(ptrstack2);
        push(ptrstack1, val2);
    }
    return val1;
}

template<class Type>
void Queue<Type>::showQueue(){
    /*
    for debugging purposes
    */
    show_stack(ptrstack1);
    show_stack(ptrstack2);
}

int main(){
    Queue<double> myqueue(6);
    myqueue.enqueue(1.1);
    // myqueue.showQueue();
    myqueue.enqueue(1.2);
    // myqueue.showQueue();
    myqueue.enqueue(1.3);
    // myqueue.showQueue();
    myqueue.enqueue(1.4);
    // myqueue.showQueue();
    myqueue.enqueue(1.5);
    // myqueue.showQueue();
    myqueue.enqueue(1.6);
    // myqueue.showQueue();
    cout << myqueue.dequeue() << endl;
    // myqueue.showQueue();
    myqueue.enqueue(1.9);
    // myqueue.showQueue();
    cout << myqueue.dequeue() << endl;
    // myqueue.showQueue();
    cout << myqueue.dequeue() << endl;
    // myqueue.showQueue();
    cout << myqueue.dequeue() << endl;
    // myqueue.showQueue();
    cout << myqueue.dequeue() << endl;
    // myqueue.showQueue();
    cout << myqueue.dequeue() << endl;
    // myqueue.showQueue();
    cout << myqueue.dequeue() << endl;
    // myqueue.showQueue();
    cout << myqueue.dequeue() << endl;
    // myqueue.showQueue();

}