#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 100
set ejecutable = bin/acceso
set salida =  data/acceso_lista.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
