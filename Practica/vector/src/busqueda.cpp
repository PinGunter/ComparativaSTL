/**
 * @file busqueda.cpp
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

int busqueda(const vector<int> & v, int x, int inf, int sup) {
  int med;
  bool enc=false;
  while ((inf<=sup) && (!enc)) {
    med = (inf+sup)/2; 
    if (v[med]==x) 
      enc = true;
    else if (v[med] < x) 
      inf = med+1;
    else
      sup = med-1;
  }
  if (enc) 
    return med;
  else 
    return -1;
}


void sintaxis()
{
  cerr << "Error, se necesitan más argumentos.\n Ejecución correcta: ./binario <numero_de_elementos>" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    sintaxis();
  }
  int N = atoi(argv[1]);

  vector<int> v(N);
  for (int i = 0; i < N; i++) 
    v[i] = i + 1;
  clock_t tini, tfin;
  tini = clock();
  for (int i=0; i < 1000000; i++)
    bool enc = busqueda(v, N, 0, N - 1) == -1;
  tfin = clock();
  
  cout << N << "\t" << ((tfin - tini)/1000000.0) / (double)CLOCKS_PER_SEC << endl;
}