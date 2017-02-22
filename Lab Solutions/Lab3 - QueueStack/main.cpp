//*
#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

    void intStackTest();
    void doubleStackTest();
    void stringStackTest();

    void intQueueTest();
    void doubleQueueTest();
    void stringQueueTest();

int main()
{
    intStackTest();
    doubleStackTest();
    stringStackTest();

    intQueueTest();
    doubleQueueTest();
    stringQueueTest();

    return 0;
}

//*/
void intStackTest() {


    cout << "\n -- new Stack --" << endl;
    Stack<int> stac;

    int value = 53;
    stac.push(value);

    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;
    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = 3;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    value = 8;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    value = 43;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = 58;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    value = 1003;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }
}
//*/
//*/
void doubleStackTest() {

    cout << "\n -- new Stack --" << endl;
    Stack<double> stac;

    double value = 53.8;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = 33.35;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    value = 8.7;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    value = 43.56;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = 58.6;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    value = 1003.5;
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }
}
//*/
//*/
void stringStackTest() {

    cout << "\n -- new Stack --" << endl;
    Stack<string> stac;

    string value = "ned";
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = "brandon";
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    value = "jamie";
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    value = "tywin";
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = "sandor";
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    value = "gregor";
    stac.push(value);
    cout << "push(" << value << ")" << endl;
    cout << "stack: " << stac << endl;

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "pop()" << endl;
        value = stac.pop();
        cout << "value = " << value << endl;
        cout << "stack: " << stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

}
//*/
//*/
void intQueueTest() {


    cout << "\n -- new Queue --" << endl;
    Queue<int> que;

    int value = 53;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = 3;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    value = 8;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    value = 43;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = 58;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    value = 1003;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }
}
/*/
/*/
void doubleQueueTest() {


    cout << "\n -- new Queue --" << endl;
    Queue<double> que;

    double value = 53.7;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = 3.4;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    value = 8.8;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    value = 43.3;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = 58.2;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    value = 1003.7;
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }
}
/*/
/*/
void stringQueueTest() {

    cout << "\n -- new Queue --" << endl;
    Queue<string> que;

    string value = "cercei";
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = "arya";
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    value = "daenerys";
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    value = "margaery";
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    value = "sansa";
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    value = "olenna";
    que.add(value);
    cout << "add(" << value << ")" << endl;
    cout << "queue: " << que << endl;

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }

    try
    {
        cout << "remove()" << endl;
        value = que.remove();
        cout << "value = " << value << endl;
        cout << "queue: " << que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }
}
//*/
