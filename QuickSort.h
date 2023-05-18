#ifndef QuickSort_H
#define QuickSort_H

int contador = 0;

template<typename Key>
void quickSort(std::vector<Key>& seq, int ini, int fin) {
  int i = ini;
  int f = fin;
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
  std::cout << "Iteration " << ++contador << ": " << seq;
	// Ordena subsecuencia izquierda (números menores que el pivote) 
  if (ini < f) quickSort(seq, ini, f); 
	// Ordena subsecuencia (número mayores que el pivote)
  if (i < fin) quickSort(seq, i, fin);
}
#endif