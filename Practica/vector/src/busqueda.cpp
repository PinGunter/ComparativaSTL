/**
 * @file insercion.cpp
 * @author Abel Ríos González
 * @author Salvador Romero Cortés
 * @brief Archivo para comparar los tiempos de busqueda de la estructuras de datos de la STL <vector>
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
using namespace std;

void sintaxis()
{
  cerr << "Error, se necesitan más argumentos.\n Ejecución correcta: ./binario <numero_de_elementos>" << endl;
  exit(EXIT_FAILURE);
}

int busqueda(vector<int> vect, int x, int inf, int sup) {
  int med;
  bool enc=false;
  while ((inf<=sup) && (!enc)) {
    med = (inf+sup)/2; 
    if (vect[med]==x) 
      enc = true;
    else if (vect[med] < x) 
      inf = med+1;
    else
      sup = med-1;
  }
  if (enc) 
    return med;
  else 
    return -1;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    sintaxis();
  }
  int N = atoi(argv[1]);

  //Preparamos el vector
  vector<int> vect(N);
  int aux, i;
  clock_t tini, tfin;
  //insertamos los elementos de 1 a N
  for (i = 1; i <= N; i++)
  {
    vect[i] = i;
  }

  bool res;
  tini = clock();
  for (int i=0; i < 100000; i++){
    res = busqueda(vect,N+561,0,vect.size());
  }
  tfin = clock();
  cout << N << "\t" << ((tfin - tini)/100000.0) / (double)CLOCKS_PER_SEC << endl;

  return 0;
}