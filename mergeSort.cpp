#include <iostream>
#include <fstream>

using namespace std;

void printArray(int array[], int n) {
  for (int i=0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void merge(int array[], int initial, int mid, int end) {
    int *temp = new int [end-initial];
    int i = initial;
    int j = mid;
    int k = 0;

    while(i<mid && j<end) {
        if(array[i] <= array[j]) {
            temp[k]=array[i];
            i++;
            k++;
        } else {
            temp[k] = array[j];
            j++;
            k++;
        }
    }
    while(i<mid) {
        temp[k] = array[i];
        i++;
        k++;
    }
    while(j<end) {
        temp[k] = array[j];
        j++;
        k++;
    }

    for(i = initial; i<end; i++) {
        array[i] = temp[i-initial];
    }
}

void mergeSort(int array[], int initial, int end) {
    int mid;
    if (initial < end-1) {
        mid = (initial+end)/2;
        mergeSort(array, initial, mid);
        mergeSort(array, mid, end);
        merge(array, initial, mid, end);
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
    mergeSort(array, 0, n);
    printArray(array, n);

  } else cout << "Erro ao abrir o arquivo." << endl;

  return 0;

}
