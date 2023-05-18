#ifndef quickSort_IN_SE_H
#define quickSort_IN_SE_H

void insertionSortQuick (std::vector<int>& seq, int ini, int fin) {
  //Sort Algohorithm
  for (unsigned int i = ini + 1; i <= fin; i++) {
    int key = seq[i];
    int j = i - 1;
    while (j >= 0 && seq[j] > key) {
      seq[j+1] = seq[j];
      j--;
    }
    seq[j+1] = key;
    // Sequence sorted
    //std::cout << "Iteration " << i << ": " << seq;
  }
}
void selectionSortQuick(std::vector<int>& seq, int ini, int fin) {
  for (unsigned int i = ini; i < fin; i++) {
    int min_index = i;
    for (unsigned int j = i + 1; j < fin; j++) {
      if (seq[j] < seq[min_index]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      std::swap(seq[i], seq[min_index]);
    }
  }
}
void quickSort_IN_SE(std::vector<int>& seq, unsigned size) {
	int i = 0;
  int f = size - 1;
  int p = seq[(i+f)/2]; // Seleccionamos el pivote
  std::cout << "Pivote: " << p << std::endl;
  while (i <= f){
    while (seq[i] < p) i++;
    while (seq[f] > p) f--;
    if (i <= f) {
			// Cambia el elemento mayor del pivote por el menor
      std::cout << "Se intercambia " << seq[i] << " por " << seq[f] << std::endl;
    	std::swap(seq[i],seq[f]); 
    	i++; 
    	f--;
    }
  }
  std::cout << "Ini: " << i << std::endl;
  std::cout << "Fin: " << f << std::endl;
  insertionSortQuick(seq, 0, f);
  selectionSortQuick(seq, i, size - 1);
  std::cout << "Sorted: " << seq;
}

#endif