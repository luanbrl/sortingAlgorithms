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

void countingSort(vector<int> &A, int n, int max) {
  int i;
  vector<int> B(10, 0);
  vector<int> C(n);

  for (i=0; i<n; i++) {
    ++B[(A[i]/max)%10];
  }
  for (i=1; i<10; i++) {
    B[i] += B[i-1];
  }
  for (i=n-1; i>=0; i--) {
    C[B[(A[i]/max)%10]-1] = A[i];
    --B[(A[i]/max)%10];
  }
  for (i=0; i<n; i++) {
    A[i] = C[i];
  }
}

void radixSort(vector<int> &A, int n) {
  int max = *max_element(A.begin(), A.end());

  for (int i=1; (max/i)>0; i*=10) {
    countingSort(A, n, i);
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
    radixSort(A, n);
    printArray(A, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
