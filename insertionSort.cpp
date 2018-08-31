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

void insertionSort(vector<int> &A, int n) {
  int i, j, aux;

  for (i=1; i<n; i++) {
    j = i;
    while (A[j] < A[j-1] && j>0) {
      aux = A[j];
      A[j] = A[j-1];
      A[j-1] = aux;
      j--;
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
    insertionSort(A, n);
    printArray(A, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
