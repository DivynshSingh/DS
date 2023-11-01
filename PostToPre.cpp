#include <iostream>
using namespace std;

void PostToPre(int postorder[], int n, int preorder[]) {
    if (n <= 0) return;

    int root = postorder[n - 1];
    int i;
    for (i = 0; i < n - 1; i++) {
        if (postorder[i] > root) break;
    }
    static int j=-1;
    preorder[++j]=root;
    PostToPre(postorder, i, preorder);
    PostToPre(postorder + i, n - i - 1, preorder);
}

int main() {
    int postorder[] = {1, 7, 5, 12, 10, 8};
    int n = sizeof(postorder) / sizeof(postorder[0]);
    int preorder[n];

    cout << "Original postorder: ";
    for (int i = 0; i < n; i++) {
        cout << postorder[i] << " ";
    }
    cout << endl;

    PostToPre(postorder, n, preorder);
    cout << "Converted preorder: ";
    for(int i = 0; i < n; i++){
        cout<<preorder[i]<<" ";
    }
    cout<<endl;

    return 0;
}
