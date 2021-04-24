#include<iostream>
using namespace std;

template<class Type>
class Stack{

    private:
        int top;
        Type* arr;
        int length;
        static int total;

    public:
        Stack(int n){
            top = -1;
            length = n;
            arr = new Type[length];
        }
        ~Stack(){
            delete[] arr;
        }
        void push(Type value){
            top++;
            total ++;
            if(top > length - 1 || total > length - 1){
                cout << "Stack overflow \n"; exit(0);
            }
            arr[top] = value;
        }

        Type pop(){
            if (top < 0){
                cout << "Stack underflow \n"; exit(0);
            }
            top--;
            return arr[top + 1];
        }
};

template<class Type>
int Stack<Type>::total = -1;

int main(){
    Stack<double> stack1(5), stack2(5);
    stack1.push(1.1);
    stack2.push(1.2);
    stack2.push(1.3);
    stack2.push(1.4);
    stack1.push(1.5);
    double x = stack2.pop();
    cout << x << endl;
    x = stack2.pop();
    cout << x << endl;
    x = stack2.pop();
    cout << x << endl;
    x = stack1.pop();
    cout << x << endl;
    x = stack1.pop();
    cout << x << endl;
    x = stack2.pop();
}