#include <iostream>
#include <fstream>

using namespace std;

void printArray(int array[], int n) {
  for (int i=0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(int array[], int n) {
  int i, j, aux;

  for (i=1; i<n; i++) {
    j = i;
    while (array[j] < array[j-1] && j>0) {
      aux = array[j];
      array[j] = array[j-1];
      array[j-1] = aux;
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
    int array[n];

    for (int i=0; i<n; i++) {
      input >> array[i];
    }
    insertionSort(array, n);
    printArray(array, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
