/**
 * @file busqueda.cpp
 * @author Abel Ríos González
 * @author Salvador Romero Cortés
 * @brief Archivo para comparar los tiempos de busqueda de la estructuras de datos de la STL <list>
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

int main(int argc, char *argv[]){
  if (argc != 2)  {
    sintaxis();
  }
  int N = atoi(argv[1]);

  //Preparamos el vector
  int numeros[N];
  for (int i=0; i < N; i++){
    numeros[i] = i+1;
  }
  list<int> lista(numeros,numeros+N); //rellenamos la lista con los valores

  clock_t tini, tfin;
  typename list<int>::iterator it = lista.begin();
  tini = clock();
  for (int i=0; i < N; i++){
    ++it;
  }
  int res = (*it);
  tfin = clock();

  cout << N << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

  return 0;
}