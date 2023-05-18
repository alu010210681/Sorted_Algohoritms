#ifndef MergeSort_H
#define MergeSort_H

template<typename Key>
void merge(std::vector<Key>& seq, int ini, int cen, int fin) {
  int i = ini; 	
  int j = cen + 1; 
  int k = ini;
  std::vector<int> aux(seq.size());
  while ((i <= cen) && (j <= fin)) {  
    if (seq[i] < seq[j]){
      aux[k] = seq[i];
      i++;
    }
    else{
      aux[k] = seq[j];
      j++;
    }
  	k++;
  }
  if (i > cen)
  	while (j <= fin) {
    	aux[k] = seq[j];
    	j++; k++;
  	}
  else
  	while (i <= cen) {
  	  aux[k] = seq[i];
  	  i++; k++;
  	} 
    for (int k = ini; k <= fin; k++)
      seq[k] = aux[k];
}

template<typename Key>
void mergeSort(std::vector<Key>& seq, int ini, int fin) {
  if (ini < fin) {
    int mitad = (ini + fin) / 2;
    // Ordena subvector izquierdo
    mergeSort(seq, ini, mitad);
    // Ordena subvector derecho
    mergeSort(seq, mitad + 1, fin);
    // Mezcla ambos subvectores
    merge(seq, ini, mitad, fin);
  }
}

#endif
