#include <iostream>
using namespace std;

void PreToPost(int preorder[], int n, int postorder[]) {
    if (n <= 0) return;

    int root = preorder[0];
    int i;
    for (i = 1; i < n; i++) {
        if (preorder[i] > root) break;
    }

    static int j=-1;
    postorder[++j]=root;
    PreToPost(preorder + 1, i - 1, postorder);
    PreToPost(preorder + i, n - i, postorder);

    cout << root << " ";
}

int main() {
    int preorder[] = {8, 5, 1, 7, 10, 12};
    int postorder[] = {1, 7, 5, 12, 10, 8};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    cout<<"original preorder: ";
    for(int i=0; i<n; i++){
        cout<<preorder[i]<<" ";
    }
    
    cout<< endl;
    cout<<"converted postorder: ";
    for(int i = 0; i < n; i++){
        cout<<postorder[i]<<" ";
    }

    return 0;
}
