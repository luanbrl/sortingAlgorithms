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

void heapify(vector<int> &A, int n, int i) {
  int greater = i, left = (2*i)+1, right = (2*i)+2;

  if (left<n && A[left]>A[greater]) {
    greater = left;
  }
  if (right<n && A[right]>A[greater]) {
    greater = right;
  }
  if (greater!=i) {
    swap(A[i], A[greater]);
    heapify(A, n, greater);
  }
}

void heapSort(vector<int> &A, int n) {
  for (int i=(n/2-1); i>=0; i--) {
    heapify(A, n, i);
  }
  for (int i=(n-1); i>=0; i--) {
    swap(A[0], A[i]);
    heapify(A, i, 0);
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
    heapSort(A, n);
    printArray(A, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
