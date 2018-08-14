#include <iostream>
#include <fstream>

using namespace std;

void printArray(int array[], int n) {
  for (int i=0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int partition(int array[], int initial, int end) {
    int aux;
    int left = initial, right = end;
    int p = array[end];

    while (left < right) {
        while(array[left] <= p) {
            left++;
        }
        while(array[right] > p) {
            right--;
        }
        if(left < right) {
            aux = array[left];
            array[left] = array[right];
            array[right] = aux;
        }
    }
    array[initial] = array[right];
    array[right] = p;

    return right;
}

void quickSort(int array[], int initial, int end) {
    if(initial<end) {
        int p = partition(array, initial, end);
        quickSort(array, initial, p-1);
        quickSort(array, p+1, end);
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
    quickSort(array, 0, n-1);
    printArray(array, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
