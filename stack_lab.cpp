#include <iostream>
using namespace std;


struct MyStack{
    int *arr = new int[size];
    int top;
    int size;
};

void init(MyStack * st, int size){
    st->size = size;
    st->top = 0;
}

void print_array(MyStack * st){
    for (int i = 0; i < st->size; i++){
        printf("%d ", st->arr[i]);
    }
}

void print(MyStack * st){
    for (int i = 0; i < st->top; i++){
        printf("%d ", st->arr[i]);
    }
}

void push(MyStack * st, int & sum){
    if (st->top < st->size){
        st->arr[st->top] = sum;
        sum += st->arr[st->top];
        st->top++;
        printf("Added item!");
    }
    else {
        printf("Stack overflow!\n");
    }
}

int read_stack(MyStack * st){
    if(st->top <= 0){
        cout << "Stack is empty!" << endl;
    }
    else{
        return st->arr[--st->top];
    }
}

void divide_stack(MyStack * st, MyStack * od, MyStack * td){
    for (int i = 0; i < st->top; i++){
        if(st->arr[i] / 10 == 0){
            push(od, st->arr[i]);
        }
        else if ((st->arr[i] / 10) <= 9){
            push(td, st->arr[i]);
        }
    }
    cout << "One digit:" << endl;
    print(od);
    cout << endl << "Two digit:" << endl;
    print(td);
}

int main(){
    int size, option, a;
    cout << "Enter stack size" << endl;
    cin >> size;
    
    MyStack s;
    MyStack * st = &s;
    MyStack two_dig;
    MyStack * td = &two_dig;
    MyStack one_dig;
    MyStack * od = &one_dig;

    init(st, size);
    init(od, size);
    init(td, size);
    cout << "\n1 - add element\n2 - show stack and array;\n3 - divide stack;\n4 - read from stack;\nelse - exit\n";

    while(true){
        cout << "\n";
        cin >> option;
        if (option == 1){
            cout << "Enter value:" << endl;
            cin >> a;
            push(st, a);
        }
        else if (option == 2){
            print(st);
            cout << endl;
            print_array(st);
        }
        else if (option == 3){
            divide_stack(st, od, td);
        }
        else if (option == 4){
            cout << read_stack(st);
        }
        else {
            break;
        }
        
    }
    return 0;
}