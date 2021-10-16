#------------------------------------------------------------------------------
# File:   Makefile
# Author: PcjSnow
# Date:   octubre 2021
# Coms:   Ejemplo de Makefile para el programa 'Tres en raya'
#         "make all" compila y generará el ejecutable
#         
#         ...
#         "make clean" borra todo lo generado, si existe (ver línea 40-50)
#------------------------------------------------------------------------------

#---------------------------------------------------------
# Definición de macros
CC = g++
CPPFLAGS = -I. -std=c++11      #opciones de compilación
LDFLAGS =                      #opciones de linkado
RM = rm -f                     #comando para borrar ficheros

all: main
#-----------------------------------------------------------
# Compilacion
funciones.o: funciones.cpp funciones.hpp
	${CC} -g -c funciones.cpp -o funciones.o ${CPPFLAGS}
main.o: main.cpp
	${CC} -g -c main.cpp -o main.o ${CPPFLAGS}

#Linkado
main: funciones.o main.o
	${CC} -g main.o funciones.o -o main ${LDFLAGS}
