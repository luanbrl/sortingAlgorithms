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

int partition(vector<int> &A, int initial, int end) {
    int aux, left = initial, right = end, p = A[end];

    while (left<right) {
        while (A[left]<=p) {
            left++;
        }
        while (A[right]>p) {
            right--;
        }
        if (left<right) {
            aux = A[left];
            A[left] = A[right];
            A[right] = aux;
        }
    }
    A[initial] = A[right];
    A[right] = p;

    return right;
}

void quickSort(vector<int> &A, int initial, int end) {
    if (initial<end) {
        int p = partition(A, initial, end);
        quickSort(A, initial, p-1);
        quickSort(A, p+1, end);
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
    quickSort(A, 0, n-1);
    printArray(A, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
