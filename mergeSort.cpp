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

void merge(vector<int> &A, int initial, int mid, int end) {
  int i = initial, j = mid, k = 0, *temp = new int [end-initial];

  while (i<mid && j<end) {
    if (A[i]<=A[j]) {
      temp[k]=A[i];
      i++;
      k++;
    } else {
      temp[k] = A[j];
      j++;
      k++;
    }
  }
  while (i<mid) {
    temp[k] = A[i];
    i++;
    k++;
  }
  while (j<end) {
    temp[k] = A[j];
    j++;
    k++;
  }
  for (i=initial; i<end; i++) {
  A[i] = temp[i-initial];
  }
}

void mergeSort(vector<int> &A, int initial, int end) {
  int mid;
    if (initial<end-1) {
      mid = (initial+end)/2;
      mergeSort(A, initial, mid);
      mergeSort(A, mid, end);
      merge(A, initial, mid, end);
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
    mergeSort(A, 0, n);
    printArray(A, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
