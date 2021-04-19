#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;
class BinaryInteger;


class BinaryInteger{
    private:
        int length;
        int* ptrarr;

    public:
        BinaryInteger(){
            length = 0;
            ptrarr = NULL;
        }
        BinaryInteger(int n);
        BinaryInteger(int n, int* ptr){
            length = n;
            ptrarr = ptr;
        }
        operator int() const;
        friend istream& operator >> (istream& s, BinaryInteger& num);
        friend ostream& operator << (ostream& s, BinaryInteger& num);
        friend BinaryInteger operator + ( BinaryInteger num1, BinaryInteger num2 );
};

BinaryInteger::BinaryInteger(int n){
    int max_len = log2(n + 1) + 1;
    ptrarr = new int[max_len];
    int i=0;
    while( n/2 >= 1){
        *(ptrarr + i) = n % 2;
        n /= 2;
        i++;
    }
    *(ptrarr + i) = n % 2;
    length = i + 1;
}

istream& operator >> (istream& s, BinaryInteger& num){
    int n;
    cout << "Enter an integer: "; cin >> n;
    num = BinaryInteger(n);
    return s;
}

ostream& operator << (ostream& s, BinaryInteger& num){
    for(int i = num.length-1; i >= 0; i--)
        cout << *(num.ptrarr + i);
    return s;
}

BinaryInteger::operator int() const{
    int result=0;
    for(int i =0; i < length; i++)
        result += *(ptrarr + i) * pow(2, i);
    return result;
}
/*
//easy way
BinaryInteger operator + ( BinaryInteger num1, BinaryInteger num2 ){
    int first = static_cast<int>(num1);
    int second = static_cast<int>(num2);
    int sum = first + second;
    return BinaryInteger(sum);
}
*/

/*
Hard way
*/
BinaryInteger operator + ( BinaryInteger num1, BinaryInteger num2 ){
    BinaryInteger result;
    int max_len = (num1.length > num2.length)? (num1.length + 1): (num2.length + 1);
    int min_len = (num1.length > num2.length)? num2.length: num1.length;
    int carry = 0;
    int i=0;
    result.ptrarr = new int[max_len];
    while(i < max_len){
        if(i >= num1.length){
            *(result.ptrarr + i) = ( *(num2.ptrarr + i) + carry)%2;
            carry = (*(num2.ptrarr + i) + carry)/2;            
        }
        else if(i >= num2.length){
            *(result.ptrarr + i) = (*(num1.ptrarr + i) + carry)%2;
            carry = (*(num1.ptrarr + i)  + carry)/2;
        }
        else{
            *(result.ptrarr + i) = (*(num1.ptrarr + i) + *(num2.ptrarr + i) + carry)%2;
            carry = (*(num1.ptrarr + i) + *(num2.ptrarr + i) + carry)/2;
        }
        i++;
    }
    result.length = (*(result.ptrarr + i - 1) == 0) ? (i - 1) : i;
    return BinaryInteger(result.length, result.ptrarr);
}

int main(){
    BinaryInteger bi1, bi2, bisum;
    cin >> bi1;
    cout << bi1 << endl;

    cin >> bi2;
    cout << bi2 << endl;

    bisum = bi1 + bi2;
    cout << bisum << endl;

    int intsum = static_cast<int>(bisum);
    cout << intsum << endl;
}