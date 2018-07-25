#include <iostream>
#include <fstream>

using namespace std;

void printArray(int array[], int n) {
  for (int i=0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int n) {
  int i, j, aux;

  for (i=0; i<n-1; i++) {
    j = i+1;
    while (j < n) {
      if (array[j] < array[i]) {
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
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
    int array[n];

    for (int i=0; i<n; i++) {
      input >> array[i];
    }
    selectionSort(array, n);
    printArray(array, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
