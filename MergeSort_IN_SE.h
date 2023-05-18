#ifndef MergeSort_IN_SE_H
#define MergeSort_IN_SE_H

void selectionSort(std::vector<int>& seq, int ini, int fin) {
	for (int i = ini; i < fin; ++i) {
		int min_index = i;
		for(int j = i + 1; j < fin; ++j) {
			if (seq[j] < seq[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			std::swap(seq[i], seq[min_index]);
		}
	}
}
void insertionSort(std::vector<int>& seq, int ini, int fin) {
	for (int i = ini + 1; i < fin; ++i) {
		int aux = seq[i];
		int j = i - 1;
		while ((j >= ini) && (seq[j] < aux)) {
			seq[j + 1] = seq[j];
			j--;
		}
		seq[j + 1] = aux;
	}
}
void merge(std::vector<int>& seq, int cen, int ini, int fin) {
	int i = ini;
	int j = fin;
	std::vector<int> aux(seq.size()); // Vector auxiliar que usaremos para reoorndenar el vector
  for (int k = ini; k <= fin; k++){
    if (i <= cen && ((j > cen) || seq[i] < seq[j])){ // Ordenar la primera submitad
      aux[k] = seq[i];
      i++;
    }
    else { // Ordenador la segunda submitad
      aux[k] = seq[j];
      j--;
    }
  }
  for (int k = ini; k <= fin; k++) {
		std::cout << "El: " << aux[k] << std::endl;
		seq[k] = aux[k]; 
	}
}
void merge2(std::vector<int>& seq, int cen, int ini, int fin) {
  int i = ini; 	
  int j = fin; 
  int k = ini;
  std::vector<int> aux(seq.size());
  while ((i <= cen) && (j >= cen + 1)) {
    if (seq[i] < seq[j]){
      aux[k] = seq[i];
      i++;
    }
    else{
      aux[k] = seq[j];
      j--;
    }
  	k++;
  }
  if (i > cen)
  	while (j >= cen + 1) {
    	aux[k] = seq[j];
    	j--; k++;
  	}
  else
  	while (i <= cen) {
  	  aux[k] = seq[i];
  	  i++; k++;
  	} 
  for (int k = ini; k <= fin; k++)
    seq[k] = aux[k];

}
void mergeSortInSe(std::vector<int>& seq, unsigned size) {
  selectionSort(seq, 0, ((size - 1) / 2));
	std::cout << "Sorted: " << seq;
	insertionSort(seq, (((size - 1) / 2) + 1), (size - 1));
	std::cout << "Sorted: " << seq;
	merge(seq, (seq.size() / 2), 0, (seq.size() - 1));
	std::cout << "Sorted: " << seq;

}


#endif