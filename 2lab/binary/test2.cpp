#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
struct tree{
    int data;
    tree *left;
    tree *right;
};

tree *tree_balance(int n){
      tree *q;
      int nl,nr;
      if (n==0) q=0;
      else{
           nl=n/2;
           nr=n-nl-1;
           q=new tree;
           q->data=rand()%50;
           q->left=tree_balance(nl);
           q->right=tree_balance(nr);
      }
      return q;
}

void print_tree(tree *t, int h){
    if (t!=0){
        print_tree(t->left,h+1);
        for (int i=1;i<=h;i++){
            cout << "\t";
        } 
        cout << t->data<<"\n";
        cout <<"\n";
        print_tree(t->right,h+1);
    }
    return;
}
 
void copy_tree(tree*& a_tree, int arr[], int & index){
    if (NULL == a_tree){
        return; 
    } 
    arr[index++] = a_tree->data;
    copy_tree(a_tree->left, arr, index); 
    copy_tree(a_tree->right, arr, index); 
}

tree *copy_tree_balance(int n, int arr[], int & i, int max, int min, int & flag1, int & flag2){
    tree *q;
    int nl,nr;
    if (n==0){
        q=0;
    } 
    else{
    nl=n/2;
        nr=n-nl-1;
        q=new tree;

        if(arr[i] == max && flag1){
            q->data = min;
            flag1 = 0;
        }
        else if(arr[i] == min && flag2){
            q->data = max;
            flag2 = 0;
        }
        else{
            q->data = arr[i];
        }
        i++; 
        q->left=copy_tree_balance(nl, arr, i, max, min, flag1, flag2);
        q->right=copy_tree_balance(nr, arr, i, max, min, flag1, flag2);
      }
      return q;
}

void min_max(tree*& tree, int & max, int & min){
    if (NULL == tree) return; 
    if(tree->data > max){
        max = tree->data;
    }
    else if(tree->data < min){
        min =  tree->data;
    }
    min_max(tree->left, max, min); 
    min_max(tree->right, max, min);
}

void delete_tree(tree *p) {
    if (!p) return;
    delete_tree(p->left);
    delete_tree(p->right);
    delete p;
}
 
int main(){
    srand(time(NULL));
    int n, option = 0, min = 51, max = 0, flag1 = 1, flag2 = 1, *arr, index = 0;
    tree *a_tree = nullptr, *new_tree = nullptr;
    
    cout << "1. make a tree\n";
    cout << "2. show\n";
    cout << "3. task\n";
    cout << "4. exit\n";
    
    do{
        cin >> option;
        switch (option){
        case 1:
            cout << "enter size" << endl;
            cin >> n;
            arr = new int[n];
            a_tree = tree_balance(n);
            cout << endl;
            break;
        case 2:
            print_tree(a_tree, 0);
            cout << endl << endl;
            break;
        case 3:
            min_max(a_tree, max, min);
            cout << endl << max << " " << min << endl;

            copy_tree(a_tree, arr, index);
            index = 0;
            new_tree = copy_tree_balance(n, arr, index, max, min, flag1, flag2);
            
            
            cout << "\nNew:\n";
            print_tree(new_tree, 0);
            
            cout << "\nOld:\n";
            print_tree(a_tree, 0);
            break;
        }
    } while (option != 4);

    delete[] arr;
    delete_tree(a_tree);
    delete_tree(new_tree);
    return 0;
}