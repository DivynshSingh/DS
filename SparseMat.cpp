#include <iostream>
#include <vector>
using namespace std;
struct Entry {
    int r, c, v;
};
void printSparseMatrix(const vector<Entry>& m) {
  for(const Entry& e : m)
    cout << e.r << ' ' << e.c << ' ' << e.v << endl;
}
vector<Entry> addSparseMatrices(vector<Entry>& a, vector<Entry>& b) {
 vector<Entry> r;
 int i = 0, j = 0;

 while (i < a.size() && j < b.size()) {
     if (a[i].r < b[j].r || (a[i].r == b[j].r && a[i].c < b[j].c)) {
         r.push_back(a[i]);
         i++;
     } else if (a[i].r == b[j].r && a[i].c == b[j].c) {
         r.push_back({a[i].r, a[i].c, a[i].v + b[j].v});
         i++;
         j++;
     } else {
         r.push_back(b[j]);
         j++;
     }
 }

 while (i < a.size()) r.push_back(a[i++]);
 while (j < b.size()) r.push_back(b[j++]);
 return r;
}

vector<Entry> multiplySparseMatrices(vector<Entry>& a, vector<Entry>& b, int ra, int cb) {
    vector<Entry> r;

 for (int i = 0; i < ra; i++)
     for (int j = 0; j < cb; j++) {
         int s = 0;

         for(int k = 0; k < a.size(); k++)
             if (a[k].r == i)
                 for (int l = 0; l < b.size(); l++)
                     if (b[l].c == j && a[k].c == b[l].r)
                         s += a[k].v * b[l].v;

         if(s != 0) r.push_back({i, j, s});
     }
 return r;
}

vector<Entry> transposeSparseMatrix(vector<Entry>& a, int ca) {
    vector<Entry> r;

    for (int j = 0; j < ca; j++)
        for (int k = 0; k < a.size(); k++)
            if (a[k].c == j) r.push_back({a[k].c, a[k].r, a[k].v});

    return r;
}

int main() {
 vector<Entry> a = {{0, 0, 1}, {1, 2, 2}, {2, 3, 3}};
 vector<Entry> b = {{0, 0, 4}, {1, 2, 5}, {2, 3, 6}};
 int ra = 3, ca = 4, cb = 4;

 cout<< "Matrix one i: " <<endl;
 printSparseMatrix(a);
 cout<< "Matrrix two is: " <<endl;
 printSparseMatrix(b);

 cout<< "addition of the two matrices is: " <<endl;
 printSparseMatrix(addSparseMatrices(a, b));
 cout<< "Multiplication of the two matrices is: " <<endl;
 printSparseMatrix(multiplySparseMatrices(a, b, ra, cb));
 cout<< "transpose of matrix 1 is: " <<endl;
 printSparseMatrix(transposeSparseMatrix(a, ca));

 return 0;
}