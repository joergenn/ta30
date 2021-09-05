#include <iostream>
using namespace std;


struct MyStack{
    int *arr = new int[size];
    int top;
    int size;
};

void init(MyStack * st, int size){
    st->size = size;
    st->arr[0] = 1;
    st->top = 1;
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

int main(){
    int sum = 1, size, option;
    cout << "Enter stack size" << endl;
    cin >> size;
    MyStack st;
    // MyStack * st = &s;

    init(&st, size);
    cout << "\n1 - add element\n2 - show stack;\n3 - show array;\n4 - exit\n";

    while(true){
        cout << "\n";
        cin >> option;
        if (option == 1){
            push(&st, sum);
        }
        else if (option == 2){
            print(&st);
        }
        else if (option == 3){
            print_array(&st);
        }
        else {
            break;
        }
        
    }
    return 0;
}