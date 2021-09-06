#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct MyQueue{
    int *arr = new int[10];
    int head = 0;
    int tail = 0;
    int size;
};

void init_queue(MyQueue * qu, int size){
    qu->size = size;
    qu->head = 0;
    qu->tail = 0;
    // for (int i = 0; i < qu->size; i++){
    //     qu->arr[i] = 0;
    // } 
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

void copy_queue(MyQueue * qu, MyQueue * copy_qu){
    int help_arr[qu->tail];
    for (int i = 0; i < qu->tail; i++){
        help_arr[i] = read_queue(qu);
    }
    for (int i = 0; i < qu->tail; i++){
        cout << help_arr[i] << " ";
    }
    init_queue(copy_qu, qu->size);
    for (int i = 0; i < qu->tail; i++){
        push_queue(copy_qu, help_arr[i]);
    }
    cout << endl;
    print_queue(copy_qu);
    
}

int main(){
    srand(time(0));
    int a, size, option;
    cout << "Enter queue size" << endl;
    cin >> size;

    MyQueue q;
    MyQueue * qu = &q;
    MyQueue copy_q;
    MyQueue * copy_qu = &copy_q;

    init_queue(qu, size);
    cout << "\n1 - add element\n2 - show stack & array;\n3 - copy queue;\n4 - read queue\nelse - exit\n";

    while(true){
        cout << "\n";
        cin >> option;
        if (option == 1){
            a = rand()%50;
            
            push_queue(qu, a);
        }
        else if (option == 2){
            print_queue(qu);
            cout << endl;
            print_array_queue(qu);
        }
        else if (option == 3){
            copy_queue(qu, copy_qu);
        }
        else if (option == 4){
            int a = read_queue(qu);
            cout << a << endl;
        }
        else{
            break;
        }   
    }
    return 0;
}