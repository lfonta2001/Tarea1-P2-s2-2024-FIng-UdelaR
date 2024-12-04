#include "../include/fecha.h"

struct rep_fecha {
    nat dia, mes, anio;
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
    nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) {
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
    delete fecha;
    fecha = NULL;
    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha) {
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);

    /****** Fin de parte Parte 3.5 *****/
}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/
bool anioBisiesto(nat anio) {
    bool bisiesto;
    if (anio % 100 == 0) {
        bisiesto = (anio % 400 == 0);
    } else {
        bisiesto = (anio % 4 == 0);
    }

    return bisiesto;
}

nat diasMes(nat mes, nat anio) {
    switch (mes)
    {
    case 2:
        return anioBisiesto(anio) ? 29 : 28;
        break;

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    
    default:
        return 30;
        break;
    }
}

void aumentarTFecha(TFecha &fecha, nat dias) {
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio)) {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12) {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
    if (fecha1-> anio != fecha2->anio) {
        res = (fecha1->anio > fecha2->anio) ? 1 : -1;
    } else if (fecha1->mes != fecha2->mes) {
        res = (fecha1->mes > fecha2->mes) ? 1 : -1;
    } else {
        res = (fecha1->dia > fecha2->dia) ? 1 : ((fecha1->dia < fecha2->dia) ? -1 : 0);
    }
    /****** Fin de parte Parte 3.10 *****/
    return res;
}
