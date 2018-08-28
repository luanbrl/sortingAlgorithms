#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printArray(vector<int> &A, int n) {
  for (int i=0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}

void countingSort(vector<int> &A, int n, int max) {
    int i;
    vector<int> B(n);
    vector<int> C(max+1, 0);

    for (i=0; i<n; i++) {
        C[A[i]] = C[A[i]] + 1;
    }
    for (i=2; i<=max; i++) {
        C[i] = C[i] + C[i-1];
    }
    for (i=n-1; i>=0; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
    for (i=0; i<n; i++) {
        A[i] = B[i];
    }
}

int main() {

  string fileName;
  cout << "Digite o nome do arquivo: ";
  cin >> fileName;
  ifstream input(fileName);

  if (input.is_open()) {
    int n;
    input >> n;
    vector<int> A;
    A.resize(n);
    int max = *max_element(A.begin(), A.end());

    for (int i=0; i<n; i++) {
      input >> A[i];
    }
    countingSort(A, n, max);
    printArray(A, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
