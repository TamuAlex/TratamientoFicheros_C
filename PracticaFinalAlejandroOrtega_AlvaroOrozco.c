/* Autores: Alejandro Ortega y Alvaro Ortega
   Título: Practica Final
   Descripcion: Tratamiento de datos de cancer de mama
   Organización: UBU
   Versión: 5.3
   Fecha: 2019-05-24
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EDAD1 "10-19"
#define EDAD2 "20-29"
#define EDAD3 "30-39"
#define EDAD4 "40-49"
#define EDAD5 "50-59"
#define EDAD6 "60-69"
#define EDAD7 "70-79"
#define EDAD8 "80-89"
#define EDAD9 "90-99"

#define TAMANO1 "0-4"
#define TAMANO2 "5-9"
#define TAMANO3 "10-14"
#define TAMANO4 "15-19"
#define TAMANO5 "20-24"
#define TAMANO6 "25-29"
#define TAMANO7 "30-34"
#define TAMANO8 "35-39"
#define TAMANO9 "40-44"
#define TAMANO10 "45-49"
#define TAMANO11 "50-54"
#define TAMANO12 "55-59"

#define INV_NODE1 "0-2"
#define INV_NODE2 "3-5"
#define INV_NODE3 "6-8"
#define INV_NODE4 "9-11"
#define INV_NODE5 "12-14"
#define INV_NODE6 "15-17"
#define INV_NODE7 "18-20"
#define INV_NODE8 "21-23"
#define INV_NODE9 "24-26"
#define INV_NODE10 "27-29"
#define INV_NODE11 "30-32"
#define INV_NODE12 "33-35"
#define INV_NODE13 "36-39"

struct datos {
  char    recurrenceEvents[21];
  char    rangoEdad[6];
  char    meno[8];
  char    tumor_size[6];
  char    inv_node[6];
  char    node_caps[4];
  char    deg_malig[4];
  char    breast[20];
  char    breast_quad[10];
  char    irradiant[3];
};

typedef struct datos DATOS;

int     mostrarMenu();
void    seleccionarOpcion(int);
int     contarCaracteres();
void    leerEdad();
void    mostrarRangos();
int     insertar_fila();
void    eliminar_filas();
int     contar_lineas();
int     media_tumor();
void    pacientes_riesgo(int);
bool    comprobar_opcion(int, int, int, int);

void main() {

  int     opcionMenu, caracteres;
  FILE   *f;

  do{
  opcionMenu = mostrarMenu();
  seleccionarOpcion(opcionMenu);
  } while(opcionMenu!=0);
}
/****************************************************************************+
 * Función que muestra por pantalla un menú, y solicita una opción del mismo.*
 * Realiza la comprobación de que los datos son correctos		     *
 * Datos de salida: opcion						     *	
 + ***************************************************************************/
int mostrarMenu() {
  int     option, leidos;
  char    enter;
  bool    correcto;

  do{   
  printf
      ("Introduce una opción:\n|1. Mostrar el numero de caracteres\n|2. Relación edad-tamaño\n|3. Añadir filas\n|4.Eliminar filas repetidas\n|5.Pacientes en riesgo\n|0. Salir\n");
  leidos = scanf("%i", &option);
//
  if(leidos != 1 || option < 0 || option > 5) {
    printf("opción incorrecta\n");
    correcto = false;
    fflush(stdin);
  } else {
    correcto = true;
  }
    } while(!correcto);

  return option;

}

/***************************************************************************+
 * Función que, a partir de la opción introducida, ejecute una de las       *
 * funciones relacionadas con cada una de las opciones.			    *
 * Datos de entrada: opcion						    *
 * datos de salida: ninguno						    *
 + ***************************************************************************/

void seleccionarOpcion(int option) {
  char    rangoEdad[6];
  int     media;

  switch (option) {
    case 0:
      printf("\nadios\n");
      break;
    case 1:
      printf("\nel numero de caracteres son %d\n\n\n", contarCaracteres());
      break;
    case 2:
      mostrarRangos();
      break;
    case 3:
      insertar_fila();
      break;
    case 4:
      eliminar_filas();
      break;
    case 5:
      media = media_tumor();
      pacientes_riesgo(media);
      break;
    default:
      printf("Hay algun error por ahi\n");
  }
}
/****************************************************************************+
 * Función que cuenta los caracteres que hay en el archivo de texto
 * Datos de salida: numero de caracteres	
 + ***************************************************************************/
int contarCaracteres() {
  int     cars = 0;
  char    c;
  FILE   *f;

  f = fopen("breast-cancer.txt", "r");
  if(f != NULL) {
    c = getc(f);
    while(!feof(f)) {
      if(c != '\n') {
	cars++;;
      }				/*hasta fin de línea */
      c = fgetc(f);

    }
  } else
    printf("Error en la apertura de fichero");

  return cars;
}
/****************************************************************************+
 * Función que lee el rango de edad del que se quieren obtener los datos.
 * datos de salida: ninguno
 * ***************************************************************************/
void leerEdad(char rangoEdad[]) {
  int     opcion, leidos;
  bool    correcto;

  do {
    printf
	("Introduce un rango de edad:\n1.10-19\n2.20-29\n3.30-39\n4.40-49\n5.50-59\n6.60-69\n7.70-79\n8.80-89\n9.90-99\n");
    leidos = scanf("%d", &opcion);

    if(leidos != 1 || opcion < 1 || opcion > 9) {
      printf("Opcion incorrecta\n");
      correcto = false;
    } else {
      correcto = true;
    }
  } while(correcto != true);

  switch (opcion) {
    case 1:
      strcpy(rangoEdad, EDAD1);
      break;
    case 2:
      strcpy(rangoEdad, EDAD2);
      break;
    case 3:
      strcpy(rangoEdad, EDAD3);
      break;
    case 4:
      strcpy(rangoEdad, EDAD4);
      break;
    case 5:
      strcpy(rangoEdad, EDAD5);
      break;
    case 6:
      strcpy(rangoEdad, EDAD6);
      break;
    case 7:
      strcpy(rangoEdad, EDAD7);
      break;
    case 8:
      strcpy(rangoEdad, EDAD8);
      break;
    case 9:
      strcpy(rangoEdad, EDAD9);
      break;
  }
}
/****************************************************************************+
 * Función que muestra los rangos del tumor del rango de edad que se 	     *
 * ha introducido previamente						     *
 * datos de salida: ninguno						     *
 + ***************************************************************************/
void mostrarRangos() {
  char    edad[6], tamano[6], edadLeida[6];
  char    rangosTumor[11];
  float   contador = 0;
  int     i;
  FILE   *f;

  for(i = 0; i < 12; i++) {
    rangosTumor[i] = 0;
  }

  leerEdad(edadLeida);
  //printf("%s",edadLeida);

  f = fopen("breast-cancer.txt", "r");

  while(!feof(f)) {
    fscanf(f,
	   "%*[^,],%[^,],%*[^,],%[^,],%*[^,],%*[^,],%*d,%*[^,],%*[^,],%*[^\n]\n",
	   edad, tamano);
    //printf("%s,%s\n",edad,tamano);
    if(strcmp(edad, edadLeida) == 0) {
      contador += 1;
      if(strcmp(tamano, TAMANO1) == 0) {
	rangosTumor[0] += 1;
      } else if(strcmp(tamano, TAMANO2) == 0) {
	rangosTumor[1] += 1;
      } else if(strcmp(tamano, TAMANO3) == 0) {
	rangosTumor[2] += 1;
      } else if(strcmp(tamano, TAMANO4) == 0) {
	rangosTumor[3] += 1;
      } else if(strcmp(tamano, TAMANO5) == 0) {
	rangosTumor[4] += 1;
      } else if(strcmp(tamano, TAMANO6) == 0) {
	rangosTumor[5] += 1;
      } else if(strcmp(tamano, TAMANO7) == 0) {
	rangosTumor[6] += 1;
      } else if(strcmp(tamano, TAMANO8) == 0) {
	rangosTumor[7] += 1;
      } else if(strcmp(tamano, TAMANO9) == 0) {
	rangosTumor[8] += 1;
      } else if(strcmp(tamano, TAMANO10) == 0) {
	rangosTumor[9] += 1;
      } else if(strcmp(tamano, TAMANO11) == 0) {
	rangosTumor[10] += 1;
      } else if(strcmp(tamano, TAMANO12) == 0) {
	rangosTumor[11] += 1;
      }
    }
  }

  //printf("%d",contador);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[0] * 100) / contador), TAMANO1);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[1] * 100) / contador), TAMANO2);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[2] * 100) / contador), TAMANO3);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[3] * 100) / contador), TAMANO4);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[4] * 100) / contador), TAMANO5);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[5] * 100) / contador), TAMANO6);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[6] * 100) / contador), TAMANO7);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[7] * 100) / contador), TAMANO8);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[8] * 100) / contador), TAMANO9);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[9] * 100) / contador), TAMANO10);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n",
	 ((rangosTumor[10] * 100) / contador), TAMANO11);
  printf("Hay un %.2f por ciento de tumores del tipo %s\n\n\n\n",
	 ((rangosTumor[11] * 100) / contador), TAMANO12);

}
/****************************************************************************+
 * Función que sirve para introducir filas en el archivo, a partir de una
 * lista de menús que ofrece al usuario
 * Datos de salida: ninguno
 + ***************************************************************************/ 
int insertar_fila() {
  FILE   *f;
  bool    repetir;
  int     leidos, opcion, contador=0;
  char    respuesta;
  DATOS   dato;

  f = fopen("breast-cancer.txt", "a");
  do{
  do {
    printf("Hay eventos recurrentes?\n1.Si\n2.No\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 2, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.recurrenceEvents, "recurrence-events");
      break;
    case 2:
      strcpy(dato.recurrenceEvents, "no-recurrence-events");
      break;
    default:
      printf("Error al leer recurrenceEvents");
  }

  do {
    printf
	("Menopausia?\n1.Antes de los 40\n2.Despues de los 40\n3.Premenopausia\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 3, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.meno, "lt40");
      break;
    case 2:
      strcpy(dato.meno, "gt40");
      break;
    case 3:
      strcpy(dato.meno, "premeno");
      break;
    default:
      printf("Error al leer meno");
  }

  do {
    printf
	("Introduce el rango de edad del paciente\n1.10-19|\t4.40-49|\t7.70-79|\n2.20-29|\t5.50-59|\t8.80-89|\n3.30-39|\t6.60-69|\t9.90-99|\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 9, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.rangoEdad, "10-19");
      break;
    case 2:
      strcpy(dato.rangoEdad, "20-29");
      break;
    case 3:
      strcpy(dato.rangoEdad, "30-39");
      break;
    case 4:
      strcpy(dato.rangoEdad, "40-49");
      break;
    case 5:
      strcpy(dato.rangoEdad, "50-59");
      break;
    case 6:
      strcpy(dato.rangoEdad, "60-69");
      break;
    case 7:
      strcpy(dato.rangoEdad, "70-79");
      break;
    case 8:
      strcpy(dato.rangoEdad, "80-89");
      break;
    case 9:
      strcpy(dato.rangoEdad, "90-99");
      break;
    default:
      printf("Error al leer rangoEdad");
  }

  do {
    printf
	("Introduce el tamaño del tumor\n1.0-4|\t\t4.15-19|\t\t7.30-34|\t\t10.45-49|\n2.9-9|\t\t5.20-24|\t\t8.35-39|\t\t11.50-54|\n3.10-14|\t6.25-29|\t\t9.40-44|\t\t12.55-59|\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 12, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.tumor_size, "0-4");
      break;
    case 2:
      strcpy(dato.tumor_size, "5-9");
      break;
    case 3:
      strcpy(dato.tumor_size, "10-14");
      break;
    case 4:
      strcpy(dato.tumor_size, "15-19");
      break;
    case 5:
      strcpy(dato.tumor_size, "20-24");
      break;
    case 6:
      strcpy(dato.tumor_size, "25-29");
      break;
    case 7:
      strcpy(dato.tumor_size, "30-34");
      break;
    case 8:
      strcpy(dato.tumor_size, "35-39");
      break;
    case 9:
      strcpy(dato.tumor_size, "40-44");
      break;
    case 10:
      strcpy(dato.tumor_size, "45-49");
      break;
    case 11:
      strcpy(dato.tumor_size, "50-54");
      break;
    case 12:
      strcpy(dato.tumor_size, "55-59");
      break;

    default:
      printf("Error al leer tumor_size");
  }

  do {
    printf
	("Introduce el numero de nodos linfaticos comprometidos\n1.0-2|\t4.9-11|\t\t7.18-20|\t10.27-29|  13.36-39|\n2.3-5|\t5.12-14|\t8.21-23|\t11.30-32|\n3.6-8|\t6.15-17|\t9.24-26|\t12.33-35|\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 13, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.inv_node, "0-2");
      break;
    case 2:
      strcpy(dato.inv_node, "3-5");
      break;
    case 3:
      strcpy(dato.inv_node, "6-8");
      break;
    case 4:
      strcpy(dato.inv_node, "9-11");
      break;
    case 5:
      strcpy(dato.inv_node, "12-14");
      break;
    case 6:
      strcpy(dato.inv_node, "15-17");
      break;
    case 7:
      strcpy(dato.inv_node, "18-20");
      break;
    case 8:
      strcpy(dato.inv_node, "21-23");
      break;
    case 9:
      strcpy(dato.inv_node, "24-26");
      break;
    case 10:
      strcpy(dato.inv_node, "27-29");
      break;
    case 11:
      strcpy(dato.inv_node, "30-32");
      break;
    case 12:
      strcpy(dato.inv_node, "33-35");
      break;
    case 13:
      strcpy(dato.inv_node, "36-39");
      break;

    default:
      printf("Error al leer inv_node");
  }

  do {
    printf
	("Hay presencia de celulas cancerosas que atravesaron la capsula de los nodos?\n1.Si\n2.No\n3.No se sabe\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 3, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.node_caps, "yes");
      break;
    case 2:
      strcpy(dato.node_caps, "no");
      break;
    case 3:
      strcpy(dato.node_caps, "?");
      break;
    default:
      printf("Error al leer node_caps");
  }

  do {
    printf("Grado de malignidad?\n1.\n2.\n3.\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 3, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.deg_malig, "1");
      break;
    case 2:
      strcpy(dato.deg_malig, "2");
      break;
    case 3:
      strcpy(dato.deg_malig, "3");
      break;
    default:
      printf("Error al leer deg_malig");
  }

  do {
    printf("Mama Afectada?\n1.Izquierda\n2.Derecha\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 2, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.breast, "left");
      break;
    case 2:
      strcpy(dato.breast, "right");
      break;
    default:
      printf("Error al leer breast");
  }

  do {
    printf
	("Cuadrante de la mama afectado\n1.Izquierda-Arriba\t3.Izquierda-Abajo\n2.Derecha-Arriba\t4.Derecha-Abajo\n5.Central\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 5, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.breast_quad, "left-up");
      break;
    case 2:
      strcpy(dato.breast_quad, "left-down");
      break;
    case 3:
      strcpy(dato.breast_quad, "right-up");
      break;
    case 4:
      strcpy(dato.breast_quad, "right-down");
      break;
    case 5:
      strcpy(dato.breast_quad, "central");
      break;
    default:
      printf("Error al leer breast_quad");
  }

  do {
    printf("Ha recibido radioterapia?\n1.Si\n2.No\n");
    leidos = scanf("%d", &opcion);
  } while(!comprobar_opcion(1, 2, opcion, leidos) == false);
  switch (opcion) {
    case 1:
      strcpy(dato.irradiant, "yes");
      break;
    case 2:
      strcpy(dato.irradiant, "no");
      break;
    default:
      printf("Error al leer irradiant");
  }

  printf
      ("Se van a introducir los siguientes datos:\n%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
       dato.recurrenceEvents, dato.rangoEdad, dato.meno, dato.tumor_size,
       dato.inv_node, dato.node_caps, dato.deg_malig, dato.breast,
       dato.breast_quad, dato.irradiant);
  fprintf(f, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", dato.recurrenceEvents,
	  dato.rangoEdad, dato.meno, dato.tumor_size, dato.inv_node,
	  dato.node_caps, dato.deg_malig, dato.breast, dato.breast_quad,
	  dato.irradiant);

  contador++;

  //fflush(stdin);
  printf("Quieres introducir otro paciente?\nPulsa [s] para continuar o cualquier otra letra para salir\n");
  scanf("%c",&respuesta);
}while(respuesta=='s');
  fclose(f);
  printf("Se han añadido %d nuevo(s) pacientes\n\n\n", contador);
}
/****************************************************************************+
 * Función comprobar la entrada del scanf				     *
 * Datos de salida: bool=true si se ha introducido lo deseado		     *
 + ***************************************************************************/
bool comprobar_opcion(int min, int max, int valor, int leidos) {
  if(leidos != 1 || valor < min || valor > max) {
    return true;
  } else {
    return false;
  }
}
/****************************************************************************+
 * Función que sirve para eliminar filas del archivo de texto		     *
 * Datos de salida: ninguno						     *
 + ***************************************************************************/
void eliminar_filas() {

  FILE   *f, *l;

  char    fila2[100];
  int     cont1 = 0;
  int     cont2 = 0;
  int     x, y, z;
  int     w = 0;
  char    a[25], b[25], c[25], d[25], e[25], v[25], h[25], i[25], j[25],
      g[25];
  int     correcto = 0;

  DATOS   p;
  DATOS   datos[500];

  f = fopen("breast-cancer.txt", "r");
  l = fopen("breast-cancer-no-repetido.txt", "w");

  z = contar_lineas();
  while(!feof(f)) {
    fscanf(f,
	   "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
	   a, b, c, d, e, v, g, h, i, j);

    strcpy(p.recurrenceEvents, a);
    strcpy(p.rangoEdad, b);
    strcpy(p.meno, c);
    strcpy(p.tumor_size, d);
    strcpy(p.inv_node, e);
    strcpy(p.node_caps, v);
    strcpy(p.deg_malig, g);
    strcpy(p.breast, h);
    strcpy(p.breast_quad, i);
    strcpy(p.irradiant, j);
    datos[w] = p;
    w++;
  }

  for(x = 0; x <= z; x++) {	//El primero lo copia mal
    correcto = 0;
    for(y = x + 1; y <= z; y++) {
      if(strcmp(datos[x].recurrenceEvents, datos[y].recurrenceEvents) == 0
	 && strcmp(datos[x].rangoEdad, datos[y].rangoEdad) == 0
	 && strcmp(datos[x].meno, datos[y].meno) == 0
	 && strcmp(datos[x].tumor_size, datos[y].tumor_size) == 0
	 && strcmp(datos[x].inv_node, datos[y].inv_node) == 0
	 && strcmp(datos[x].node_caps, datos[y].node_caps) == 0
	 && strcmp(datos[x].deg_malig, datos[y].deg_malig) == 0
	 && strcmp(datos[x].breast, datos[y].breast) == 0
	 && strcmp(datos[x].breast_quad, datos[y].breast_quad) == 0
	 && strcmp(datos[x].irradiant, datos[y].irradiant) == 0) {
	correcto++;
      }

      printf("%d", correcto);
    }
    if(correcto == 0) {
      fprintf(l, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
	      datos[x].recurrenceEvents, datos[x].rangoEdad, datos[x].meno,
	      datos[x].tumor_size, datos[x].inv_node, datos[x].node_caps,
	      datos[x].deg_malig, datos[x].breast, datos[x].breast_quad,
	      datos[x].irradiant);
      cont1++;

    }
  }

  fclose(f);
  fclose(l);
  printf("Se han escrito %d registros no repetidos\n", cont1);

}
/****************************************************************************+
 * Función que sirve para contar las lineas que tiene el fichero de texto    *
 * Datos de salida: numero de lineas					     *
 + ***************************************************************************/
int contar_lineas() {
  FILE   *f;
  int     contador = 0;
  char    c;

  f = fopen("breast-cancer.txt", "r");

  c = fgetc(f);
  while(!feof(f)) {
    if(c == '\n') {
      contador++;;
    }
    c = fgetc(f);
  }
  return contador;
  fclose(f);
}


/****************************************************************************+
 * Función que sirve para calcular la media de los tamaños de los tumores    *
 * Datos de salida: numero de lineas					     *
 + ***************************************************************************/
int media_tumor() {
  FILE   *f;
  float   contador = 0.0;
  float   media = 0.0, media_parcial = 0.0;
  int     lineas;
  char    tamano[20];

  f = fopen("breast-cancer.txt", "r");

  while(!feof(f)) {
    fscanf(f,
	   "%*[^,],%*[^,],%*[^,],%[^,],%*[^,],%*[^,],%*d,%*[^,],%*[^,],%*[^\n]\n",
	   tamano);
    //printf("%s",tamano);
    if(strcmp(tamano, TAMANO1) == 0) {
      contador += 1;
    }
    if(strcmp(tamano, TAMANO2) == 0) ; {
      contador += 2;
    }
    if(strcmp(tamano, TAMANO3) == 0) ; {
      contador += 3;
    }
    if(strcmp(tamano, TAMANO4) == 0) ; {
      contador += 4;
    }
    if(strcmp(tamano, TAMANO5) == 0) ; {
      contador += 5;
    }
    if(strcmp(tamano, TAMANO6) == 0) ; {
      contador += 6;
    }
    if(strcmp(tamano, TAMANO7) == 0) ; {
      contador += 7;
    }
    if(strcmp(tamano, TAMANO8) == 0) ; {
      contador += 8;
    }
    if(strcmp(tamano, TAMANO9) == 0) ; {
      contador += 9;
    }
    if(strcmp(tamano, TAMANO10) == 0) ; {
      contador += 10;
    }
    if(strcmp(tamano, TAMANO11) == 0) ; {
      contador += 11;
    }
    if(strcmp(tamano, TAMANO12) == 0) ; {
      contador += 12;
    }
  }
  //printf("%2.f",contador);
  lineas = contar_lineas();
  media_parcial = contador / 12;
  media = media_parcial / lineas;
  fclose(f);

  return media;
}
/****************************************************************************+
 * Función que vuelca a un fichero binario los pacientes en riesgo	     *
 * Datos de salida: fichero binario					     *
 + ***************************************************************************/
void pacientes_riesgo(int media) {
  FILE   *f, *p;
  DATOS   dato;
  int     tamano, cont = 0;

  f = fopen("breast-cancer.txt", "r");
  p = fopen("alto-riesgo.txt", "wb");

  while(!feof(f)) {
    fscanf(f,
	   "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
	   dato.recurrenceEvents, dato.rangoEdad, dato.meno,
	   dato.tumor_size, dato.inv_node, dato.node_caps, dato.deg_malig,
	   dato.breast, dato.breast_quad, dato.irradiant);
    if(strcmp(dato.recurrenceEvents, "recurrence-events") == 0) {
      if(strcmp(dato.irradiant, "yes") == 0) {
	if(strcmp(dato.tumor_size, TAMANO1) == 0) {
	  tamano = 1;
	}
	if(strcmp(dato.tumor_size, TAMANO2) == 0) ; {
	  tamano = 2;
	}
	if(strcmp(dato.tumor_size, TAMANO3) == 0) ; {
	  tamano = 3;
	}
	if(strcmp(dato.tumor_size, TAMANO4) == 0) ; {
	  tamano = 4;
	}
	if(strcmp(dato.tumor_size, TAMANO5) == 0) ; {
	  tamano = 5;
	}
	if(strcmp(dato.tumor_size, TAMANO6) == 0) ; {
	  tamano = 6;
	}
	if(strcmp(dato.tumor_size, TAMANO7) == 0) ; {
	  tamano = 7;
	}
	if(strcmp(dato.tumor_size, TAMANO8) == 0) ; {
	  tamano = 8;
	}
	if(strcmp(dato.tumor_size, TAMANO9) == 0) ; {
	  tamano = 9;
	}
	if(strcmp(dato.tumor_size, TAMANO10) == 0) ; {
	  tamano = 10;
	}
	if(strcmp(dato.tumor_size, TAMANO11) == 0) ; {
	  tamano = 11;
	}
	if(strcmp(dato.tumor_size, TAMANO12) == 0) ; {
	  tamano = 12;
	}
	if(tamano > media) ; {
	  fwrite(&dato, sizeof(dato), 1, p);
	  cont++;
	}
      }
    }
  }
  fclose(f);
  fclose(p);
  printf("Se han copiado %d pacientes en alto riesgo", cont);
}
