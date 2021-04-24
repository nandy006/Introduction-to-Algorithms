#include<iostream>
#include<cmath>
using namespace std;

template<class Type>
class Array;

template<class Type>
istream& operator >> (istream& s, Array<Type>& arr);

template<class Type>
ostream& operator << (ostream& s, Array<Type>& arr);

template<class Type>
struct info{
    int lower_index, upper_index;
    Type summation;
};

template<class Type>
class Array{
    private:
        int length;
        Type* ptr;

    public:
        friend istream& operator >> <Type> (istream& s, Array<Type>& arr);
        friend ostream& operator << <Type> (ostream& s, Array<Type>& arr);
        info<Type> get_maximal_subarray();
        info<Type> get_maximal_subarray_linear();
};

template<class Type>
info<Type> maximal_crossing_subarray(int low, int mid, int high, Type* array);

template<class Type>
info<Type> maximal_subarray(int low, int high, Type* array);

template<class Type>
info<Type> maximal_subarray_linear(int high, Type* array);

template<class Type>
istream& operator >> (istream& s, Array<Type>& arr){
    cout << "Enter length of array: "; cin >> arr.length;
    arr.ptr = new Type[arr.length];
    for(int i = 0; i < arr.length; i++){
        cout << "Array[" << i << "] = ";
        cin >> *(arr.ptr + i);
    }
    return s;
}

template<class Type>
ostream& operator << (ostream& s, Array<Type>& arr){
    for(int i = 0; i < arr.length; i++)
        cout << " " << *(arr.ptr + i);
    return s;
}

template<class Type> 
info<Type> Array<Type>::get_maximal_subarray(){
    return maximal_subarray(0, length-1, ptr);
}

template<class Type>
info<Type> maximal_subarray(int low, int high, Type* array){
    if(low == high){
        return {low, high, *(array + low)};
    }
    else{
        int mid = (low + high)/2;
        info<Type> low_maximal_subarray = maximal_subarray(low, mid, array);
        info<Type> high_maximal_subarray = maximal_subarray(mid + 1, high, array);
        info<Type> cross_maximal_subarray = maximal_crossing_subarray(low, mid, high, array);
        if((low_maximal_subarray.summation > high_maximal_subarray.summation) &&
            (low_maximal_subarray.summation) > cross_maximal_subarray.summation){
                return low_maximal_subarray;
            }
        else if((high_maximal_subarray.summation > low_maximal_subarray.summation)&&
                (high_maximal_subarray.summation > cross_maximal_subarray.summation)){
                    return high_maximal_subarray;
                }
        else{
            return cross_maximal_subarray;
        }       
    }
}

template<class Type>
info<Type> maximal_crossing_subarray(int low, int mid, int high, Type* array){
    Type left_sum = *(array + mid), right_sum = *(array + mid + 1);
    Type sum = left_sum;
    int i = mid -1;
    int left_index = i + 1;
    while(i >=low){
        sum = sum + *(array + i);
        if(sum > left_sum){
            left_sum = sum;
            left_index = i;
        }
        i--;
    }
    sum = right_sum;
    i = mid + 2;
    int right_index = i - 1;
    while( i <= high){
        sum = sum + *(array + i);
        if(sum > right_sum){
            right_sum = sum;
            right_index = i;
        }
        i++;
    }
    return {left_index, right_index, left_sum + right_sum};
}

template<class Type>
info<Type> Array<Type>::get_maximal_subarray_linear(){
    info<Type> maximal_subarray = {0, 0, *ptr}, maximal_subarray_ending_here = {0, 0, *ptr};
    if(length == 1)
        return maximal_subarray;
    Type temp_sum;
    for(int i = 1; i < length; i++){
        temp_sum = maximal_subarray_ending_here.summation + *(ptr + i);
        maximal_subarray_ending_here.upper_index = i;
        if(temp_sum > *(ptr + i)){
            /*
                If the sum of the maximal contiguous subarray ending at previous position
                was positive, then adding the current value to that will still satisfy 
                all properties of maximal contiguous subarray ending at current. Why?
                Because if there were another contiguous subarray ending at current that
                was maximal, then dropping the latest element from that hypothetical
                subarray would give us the maximal contiguous subarray ending
                at the previous location
            */
            maximal_subarray_ending_here.summation = temp_sum;
        }
        else{
            /*
                If the sum of the maximal subarray ending before current was negative,
                start over.
            */
            maximal_subarray_ending_here.summation = *(ptr + i);
            maximal_subarray_ending_here.lower_index = i;
        }
        if(maximal_subarray_ending_here.summation > maximal_subarray.summation)
            maximal_subarray = maximal_subarray_ending_here;
    }
    return maximal_subarray;
}

int main(){
    Array<float> myarray;
    cin >> myarray;
    cout << myarray << endl;
    info<float> max_sub_arr = myarray.get_maximal_subarray();
    cout << "lower index = " << max_sub_arr.lower_index << 
    "; upper index = " << max_sub_arr.upper_index <<
    "; sum = " << max_sub_arr.summation << endl;
    max_sub_arr = myarray.get_maximal_subarray_linear();
    cout << "lower index = " << max_sub_arr.lower_index << 
    "; upper index = " << max_sub_arr.upper_index <<
    "; sum = " << max_sub_arr.summation << endl;

}
