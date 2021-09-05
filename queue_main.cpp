#include <iostream>
using namespace std;

struct MyStack{
    int *arr_st = new int[10];
    int top;
    int size;
};

struct MyQueue{
    int *arr = new int[10];
    int head = 0;
    int tail = 0;
    int size;
};

void init(MyStack * st, int size){
    st->size = size;
    st->top = 0;
    for (int i = 0; i < st->size; i++){
        st->arr_st[i] = 0;
    }  
}

void push(MyStack * st, int x){
    if (st->top < st->size){
        st->arr_st[st->top] = x;
        st->top++;
        cout << "Added item!" << endl;
    }
    else {
        cout << "Stack overflow!" << endl;
    }
}

int read_stack(MyStack * st){
    if(st->top <= 0){
        cout << "Stack is empty!" << endl;
    }
    else{
        return st->arr_st[--st->top];
    }
}

void init_queue(MyQueue * qu, int size){
    qu->size = size;
    qu->head = 0;
    qu->tail = 0;
    for (int i = 0; i < qu->size; i++){
        qu->arr[i] = 0;
    } 
}

void print_array_queue(MyQueue * qu){
    cout << "Array: " << endl;
    for (int i = 0; i < qu->size; i++){
        cout << qu->arr[i] << " ";
    }
}

void print_queue(MyQueue * qu){
    cout << "Queue: ";
    for (int i = qu->head; i < qu->tail; i++){
        cout << qu->arr[i] << " ";
    }
}

int read_queue(MyQueue * qu){
    int a;
    if(qu->head >= qu->tail){
        cout << "Queue is empty" << endl;
    }
    else{
        a = qu->arr[qu->head];
        qu->head++;
        return a;
    }
}

void push_queue(MyQueue * qu, int x){
    if(qu->tail == qu->size+1){
        cout << "Queue is full!" << endl;
    }
    else{
        qu->arr[qu->tail] = x;
        qu->tail++;
        cout << "Added item!" << endl;
    }
}

void reverse_queue(MyQueue * qu, MyStack * st){
    int temp;
    for (int i = 0; i < qu->tail; i++){
        temp = read_queue(qu);
        push(st, temp);
    }
    qu->head = 0;
    qu->tail = 0;
    for (int i = st->top-1; i >= 0; i--){
        temp = read_stack(st);
        push_queue(qu, temp);
    }
    print_queue(qu);    
}

int main(){
    int a, size, option;
    cout << "Enter queue size" << endl;
    cin >> size;

    MyQueue q;
    MyQueue * qu = &q;
    MyStack s;
    MyStack * st = &s;

    init(st, size);
    init_queue(qu, size);
    cout << "\n1 - add element\n2 - show queue;\n3 - show array;\n4 - reverse\n5- exit\n";

    while(true){
        cout << "\n";
        cin >> option;
        if (option == 1){
            cout << "Enter value: " << endl;
            cin >> a;
            push_queue(qu, a);
        }
        else if (option == 2){
            print_queue(qu);   
        }
        else if (option == 3){
            print_array_queue(qu);   
        }
        else if (option == 4){
            reverse_queue(qu, st);
        }
        else{
            break;
        }   
    }
    return 0;
}