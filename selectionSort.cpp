#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printArray(vector<int> &A, int n) {
  for (int i=0; i<n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}

void selectionSort(vector<int> &A, int n) {
  int i, j, aux;

  for (i=0; i<n-1; i++) {
    j = i+1;
    while (j<n) {
      if (A[j]<A[i]) {
        aux = A[i];
        A[i] = A[j];
        A[j] = aux;
      }
      ++j;
    }
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

    for (int i=0; i<n; i++) {
      input >> A[i];
    }
    selectionSort(A, n);
    printArray(A, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
