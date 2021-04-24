#include<iostream>
using namespace std;

const int MAX=5;

template<class Type>
class TwoStacks{
    private:
        int top1, top2;
        Type stack1[MAX], stack2[MAX];

    public:
        TwoStacks(){
            top1 = -1;
            top2 = MAX;
        }
        void push(Type value, int which_stack){
            cout << "top1 = " << top1 << " top2 = " << top2 << endl;
            if(which_stack == 1)
                top1++;
            else
                top2--;

            if(top1 == top2){
                cout << "Stack overflow" << endl; exit(0); 
            }
            if(which_stack == 1)
                stack1[top1] = value;
            else
                stack2[top2] = value;

        }

        Type pop(int which_stack){
            if(which_stack == 1){
                if(top1 < 0){
                    cout << "Stack underflow" << endl; exit(0); 
                }
                top1--;
                return stack1[top1 + 1];
            }
            else{
                if(top2 > MAX-1){
                    cout << "Stack underflow" << endl; exit(0);
                }
                top2++;
                return stack2[top2 - 1];
            }
        }

};

int main(){
    TwoStacks<double> twostacks;
    twostacks.push(1.5, 1);
    // double x = twostacks.pop(2);
    twostacks.push(7.5, 2);
    twostacks.push(2.5, 1);
    twostacks.push(3.5, 1);
    twostacks.push(6.5, 2);
    double x = twostacks.pop(1);
    cout << x << endl;
    x = twostacks.pop(1);
    cout << x << endl;
    x = twostacks.pop(1);
    cout << x << endl;
    x = twostacks.pop(2);
    cout << x << endl;
    x = twostacks.pop(2);
    cout << x << endl;
}