#include "../include/grupo.h"
#include "../include/persona.h"

struct rep_grupo {
    TPersona personas[MAX_PERSONAS];
    int tope;
};

TGrupo crearTGrupo(){
    TGrupo grupo = NULL;
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */

    grupo = new rep_grupo;
    grupo->personas[0] = NULL;
    grupo->tope = 0;
    /****** Fin de parte Parte 5.2 *****/
    return grupo;
}

// Función para agregar una persona a un grupo
// Recibe un elemento de tipo TGrupo y un elemento de tipo TPersona y lo agrega al grupo en orden por fecha de nacimiento (de menor a mayor)
// Si dos personas tienen la misma fecha de nacimiento, deben ordenarse por orden de ingreso al grupo, de más nuevo a más antiguo
// Si la cantidad de personas en el grupo es igual a MAX_PERSONAS, la función no tiene efecto
void agregarAGrupo(TGrupo& grupo, TPersona persona){
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (grupo->tope < MAX_PERSONAS) {
        int i = 0;
        int igualdad;
        bool agregado = false;
        TPersona temp1, temp2;
        TFecha fecha1, fecha2;
        if (grupo->tope == 0) {
            grupo->personas[0] = persona;
            grupo->tope = 1;
        } else {
            while (i < grupo->tope && !agregado) {
                fecha1 = fechaNacimientoTPersona(grupo->personas[i]);
                fecha2 = fechaNacimientoTPersona(persona);
                igualdad = compararTFechas(fecha1, fecha2);
                if( igualdad == 1) {
                    i++;
                } else {
                    grupo->tope == grupo->tope + 1;
                    temp1 = grupo->personas[i];
                    grupo->personas[i] = persona;
                    int j = i + 1;
                    while (j <= grupo->tope) { // error loop infinito, al agregar segunda persona buggea
                        temp2 = grupo->personas[j];
                        grupo->personas[j] = temp1;
                        temp1 = temp2;
                    }
                    agregado = true;
                }
            }
        }
    }
    /****** Fin de parte Parte 5.2 *****/
}

// Función para imprimir todas las personas de un grupo
// Recibe un elemento de tipo TGrupo e imprime sus personas en orden cronológico
// El formato en el que se debe imprimir el grupo es utilizando de forma secuencial la función imprimirTPersona
// Si el grupo está vacío no imprime nada
void imprimirTGrupo(TGrupo grupo){
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (grupo->tope > 0) {
        for (int i = 0; i < grupo->tope; i++) {
            imprimirTPersona(grupo->personas[i]);
        }
    }
    /****** Fin de parte Parte 5.2 *****/
}

// Función para liberar un grupo
// Recibe una referencia a un elemento de tipo TGrupo y libera su memoria
// Libera además la memoria de cada una de las personas en el grupo
void liberarTGrupo(TGrupo& grupo){
   /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    for (int i = 0; i < grupo->tope; i++) {
        liberarTPersona(grupo->personas[i]);
    }
    delete grupo;
    grupo = NULL;
    /****** Fin de parte Parte 5.2 *****/
}

// Función para verificar si un elemento de tipo TPersona existe en un grupo
// Recibe un grupo y la cédula de la persona y regresa un booleano indicando su existencia
bool estaEnGrupo(TGrupo grupo, int cedula){
    bool esta = false;
	/************ Parte 5.3 ************/
    /*Escriba el código a continuación */
    int i = 0;
    int cedula1;
    while (i < grupo->tope  && !esta) {
        cedula1 = cedulaTPersona(grupo->personas[i]);
        esta = (cedula1 == cedula);
        i++;
    }
    /****** Fin de parte Parte 5.3 *****/
	return esta;
}

// Esta función remueve la persona con ci "cedula" del grupo "grupo"
void removerDeGrupo(TGrupo &grupo, int cedula){
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */
    if (estaEnGrupo(grupo, cedula)) {
        int i, ind;
        bool encontrado = false;
        for (i = 0; i < grupo->tope && !encontrado; i++) {
            encontrado = (cedulaTPersona(grupo->personas[i]), cedula);
            ind = i - 1;
        }

        for (i = ind; i < grupo->tope - 1; i++) {
            grupo->personas[i] = grupo->personas[i + 1];
        }
        grupo->tope--;
    }
    /****** Fin de parte Parte 5.4 *****/   
}

// Función para verificar si hay, al menos, una persona en el grupo que tenga la fecha de nacimiento "fecha"
// Debe implementarse utilizando búsqueda binaria
bool hayPersonasFecha(TGrupo grupo, TFecha fecha){
    bool hay = false;
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    TFecha fecha1;
    for (int i = 0; i < grupo->tope && !hay; i++) {
        fecha1 = fechaNacimientoTPersona(grupo->personas[i]);
        hay = (compararTFechas(fecha1, fecha) == 0);
    }
    /****** Fin de parte Parte 5.5 *****/ 
    return hay;
}

// Imprime en pantalla las personas del grupo que tengan la fecha de nacimiento "fecha" 
void imprimirPersonasFecha(TGrupo grupo, TFecha fecha){
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    if (hayPersonasFecha(grupo, fecha)) {
        int ind;
        TFecha fecha1, fecha2;
        bool encontrado = false;
        for (int i = 0; i < grupo->tope && !encontrado; i++) {
            fecha1 = fechaNacimientoTPersona(grupo->personas[i]);
            encontrado = (compararTFechas(fecha1, fecha) == 0);
            ind = i - 1;
        }

        do
        {
            fecha2 = fechaNacimientoTPersona(grupo->personas[ind]);
            imprimirTPersona(grupo->personas[ind]);
            ind++;
        } while (ind < grupo->tope && compararTFechas(fecha2, fecha) == 0);
        
    } else {
        printf("NO SE ENCONTRARON PERSONAS.\n");
    }
    /****** Fin de parte Parte 5.5 *****/ 
}
