#include <iostream>

using namespace std;

double bezier_rec(double *numberArray, int count, double prev_two_number_average, double average, int elem) {

    // Base Case, returns average if array end's reached
    if(elem == count){
        return average;
    }

    // Average of two numbers
    double two_number_average = (numberArray[elem] + numberArray[elem+1])*0.5;

    // Average of the average of two numbers
    double two_averages = prev_two_number_average + two_number_average;

    // Average is first elem in first iteration
    if(elem == 0){
        average = numberArray[elem];
    }

    // If second iteration or higher, average taken of two averages
    if(elem > 0){
        two_averages = two_averages*0.5;
    }

    // If second iteration, average is two averages
    if(elem == 1){
        average = two_averages;
    }

    // If third iteration or higher, average is the average of two averages
    if(elem > 1){
        average = (average + two_averages)*0.5;
    }

    // Recursively calls for function until base case is reached and correct average is returned
    return bezier_rec(numberArray, count, two_number_average, average, elem+1);
}

double bezier(double *numberArray, int count) {
    return bezier_rec(numberArray, count-1, 0, 0, 0);
}

int main(int argc, char **argv) {
    int count = 4;
    double *numberArray = new double[count];
    numberArray[0] = 3.4;
    numberArray[1] = 1.4;
    numberArray[2] = 2.4;
    numberArray[3] = 5.4;

    cout << "Bezier(" << numberArray[0];
    for(int i = 1; i < count; i++) {
        cout << ", " << numberArray[i];
    }
    cout << "): " << bezier(numberArray, count) << endl;

    delete numberArray;

    count = 7;
    numberArray = new double[count];
    numberArray[0] = 3.2;
    numberArray[1] = 3.9;
    numberArray[2] = 2.2;
    numberArray[3] = 7.4;
    numberArray[4] = 5.4;
    numberArray[5] = 5.3;
    numberArray[6] = 8.4;

    cout << "Bezier(" << numberArray[0];
    for(int i = 1; i < count; i++) {
        cout << ", " << numberArray[i];
    }
    cout << "): " << bezier(numberArray, count) << endl;

    delete numberArray;

    count = 3;
    numberArray = new double[count];
    numberArray[0] = 1;
    numberArray[1] = 2;
    numberArray[2] = 3;

    cout << "Bezier(" << numberArray[0];
    for(int i = 1; i < count; i++) {
        cout << ", " << numberArray[i];
    }
    cout << "): " << bezier(numberArray, count) << endl;

    delete numberArray;
}
