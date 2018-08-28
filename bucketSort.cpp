#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printArray(vector<float> &A, int n) {
  for (int i=0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}

void bucketSort(vector<float> &A, int n) {
  int i, j;
  vector<float> count(n);
  for (i=0; i<n; i++) {
    count[i] = 0;
  }
  for (i=0; i<n; i++) {
    (count[A[i]])++;
  }
  for (i=0, j=0; i<n; i++) {
    for(; count[i] > 0; (count[i])--) {
      A[j++] = i;
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
    vector<float> A;
    A.resize(n);

    for (int i=0; i<n; i++) {
      input >> A[i];
    }
    bucketSort(A, n);
    printArray(A, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
