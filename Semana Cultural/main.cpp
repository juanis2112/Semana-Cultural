//
//  main.cpp
//  Semana Cultural
//
//  Created by Juanita Gomez on 11/20/13.
//  Copyright © 2013 Juanita Gomez. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;


//ESTRUCTURAS

struct actividad
{
    string nombre;
    int codigo;
    string tipo;
    string jornada;
    int duracion;
    string dia;
    int horainicio;
    
}arregloact[30];

void llenaractividades (struct actividad arregloact[], struct actividad matriz[][5])
{
    
    //Declaracion de las 5 actividades que estan previamente en el sistema
    
    //Actividad 1
    arregloact[0].nombre ="Futbol";
    arregloact[0].codigo=0;
    arregloact[0].tipo="deportiva";
    arregloact[0].jornada="tarde";
    arregloact[0].duracion=90;
    arregloact[0].dia="lunes";
    arregloact[0].horainicio=1400;
    matriz[8][0]=arregloact[0];
    matriz[9][0]=arregloact[0];
    matriz[10][0]=arregloact[0];
    
    //Actividad 2
    arregloact[1].nombre="Concierto";
    arregloact[1].codigo=1;
    arregloact[1].tipo="musical";
    arregloact[1].jornada="maÒana";
    arregloact[1].duracion=60;
    arregloact[1].dia="martes";
    arregloact[1].horainicio=800;
    matriz[0][1]=arregloact[1];
    matriz[1][1]=arregloact[1];
    
    //Actividad 3
    arregloact[2].nombre="Feria";
    arregloact[2].codigo=2;
    arregloact[2].tipo="cultural";
    arregloact[2].jornada="tarde";
    arregloact[2].duracion=60;
    arregloact[2].dia="miercoles";
    arregloact[2].horainicio=1700;
    matriz[14][2]=arregloact[2];
    matriz[15][2]=arregloact[2];
    
    //Actividad 4
    arregloact[3].nombre="Teatro";
    arregloact[3].codigo=3;
    arregloact[3].tipo="artistica";
    arregloact[3].jornada="maÒana";
    arregloact[3].duracion=60;
    arregloact[3].dia="jueves";
    arregloact[3].horainicio=900;
    matriz[2][3]=arregloact[3];
    matriz[3][3]=arregloact[3];
    
    //Actividad 5
    arregloact[4].nombre="Origami";
    arregloact[4].codigo=4;
    arregloact[4].tipo="plastica";
    arregloact[4].jornada="maÒana";
    arregloact[4].duracion=90;
    arregloact[4].dia="viernes";
    arregloact[4].horainicio=1030;
    matriz[5][4]=arregloact[4];
    matriz[6][4]=arregloact[4];
    
}

struct usuario
{
    int edad;
    int personal;
}u1;

string semana[5];
string horas[16];
int horasn[16];
struct actividad matriz[16][5];

struct jornada
{
    int tipo[6];
};

struct dia
{
    struct jornada j[2];
    
};
struct contador
{
    struct dia d[5];
}c1;


void inicializarcontadores(struct contador c1)
{
    
    
    c1.d[0].j[1].tipo[0]=1;
    c1.d[1].j[0].tipo[3]=1;
    c1.d[2].j[1].tipo[1]=1;
    c1.d[3].j[0].tipo[2]=1;
    c1.d[4].j[0].tipo[4]=1;
}

//FUNCIONES

//Funciones que cuentan el n˙mero de actividades por jornada cada dÌa

int contadormanana (struct actividad arregloact[], int manana, int i)
{
    if((arregloact[i].jornada.compare("maÒana"))==0)
    manana=manana+1;
    
    return manana;
}

int contadortarde (struct actividad arregloact[], int tarde, int i)
{
    if((arregloact[i].jornada.compare("tarde"))==0)
    tarde=tarde+1;
    return tarde;
}

//Funcion que verifica la jornada para establecer el contador de las actividades por tipo, jornada y dia
int verificacionjornada(struct actividad arregloact[], int i)
{    int j1=2;
    if((arregloact[i].jornada.compare("maÒana"))==0)
    j1=0;
    if((arregloact[i].jornada.compare("tarde"))==0)
    j1=1;
    return j1;
}
//Funcion que inicializa la matriz que contiene el horario
void inicializarmatriz(struct actividad matriz[][5], int f)
{
    
    for (int x=0;x<f;x++)
    {
        for(int y=0;y<5;y++)
        {
            
            matriz[x][y].nombre="              ";
            matriz[x][y].codigo=-1;
            matriz[x][y].tipo=" ";
            matriz[x][y].jornada=" ";
            matriz[x][y].duracion=0;
            matriz[x][y].dia=" ";
            matriz[x][y].horainicio=0;
        }
        
    }
}

//Funcion que imprime la matriz que contiene el horario


void imprimirhorario(struct actividad matriz[][5], int f, string semana[], string horas[])
{
    
    cout<<"\n ______________________________________________________________________\n";
    cout<<"        ";
    for(int z=0; z<5; z++)
    cout<<semana[z];
    
    cout<<"\n ______________________________________________________________________\n";
    
    for (int x=0;x<f;x++)
    {
        for(int y=0;y<5;y++)
        {
            if(y==0)
            {
                cout<<" "<<horas[x]<<"| ";
            }
            
            string tamanopalabras="              ";
            int tamanop1=matriz[x][y].nombre.size();
            int tamanop2= tamanopalabras.size();
            int espacios=tamanop2-tamanop1;
            
            cout<<matriz[x][y].nombre;
            for (int w=0; w<espacios; w++)
            cout<<" ";
            
        }
        
        cout<<"\n ______________________________________________________________________\n";
        
    }
}
//Funcion que lee los datos para llenar los arreglos
int leerdatos(int tamano, struct actividad arregloact[], struct usuario u1, struct actividad matriz[][5], int horasn[], struct contador c1, int i)
{
    int numcasillas, opcion2=0, s=0, j=0, ver=0, d1, t1, j1, mananal=0, mananama=1, mananami=0, mananaju=1, mananavi=1, tardel=1, tardema=0, tardemi=1, tardeju=0, tardevi=0, codigoelim;
    
    
    
    while(opcion2!=3)
    {
        
        
        cout<<"\nDigite: \n1 para ingresar una actividad \n2 para eliminar \n3 para volver al menu principal ";
        cin>>opcion2;
        
        
        switch(opcion2)
        {
            
            case 1:
            
            cout<<"\nIngrese el nombre de la actividad n˙mero  "<<i<<"  ";
            cin>>arregloact[i].nombre;
            ver=0;
            while(ver==0)
            {
                cout<<"\nIngrese el dia de la actividad n˙mero  "<<i<<"  ";
                cin>>arregloact[i].dia;
                if (((arregloact[i].dia).compare("lunes"))==0)
                {
                    j=0;
                    d1=0;
                    ver=2;
                    
                    cout<<"\nIngrese la jornada de la actividad n˙mero  "<<i<<"  ";
                    cin>>arregloact[i].jornada;
                    j1=verificacionjornada(arregloact, i);
                    mananal=contadormanana(arregloact, mananal, i);
                    tardel=contadortarde(arregloact, tardel, i);
                    
                    
                    if (mananal>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                    if (tardel>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                }
                
                if (((arregloact[i].dia).compare("martes"))==0)
                {
                    
                    j=1;
                    d1=1;
                    ver=2;
                    cout<<"\nIngrese la jornada de la actividad n˙mero  "<<i<<"  ";
                    cin>>arregloact[i].jornada;
                    j1=verificacionjornada(arregloact, i);
                    mananama=contadormanana(arregloact, mananama, i);
                    tardema=contadortarde(arregloact, tardema, i);
                    
                    if (mananama>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                    if (tardema>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                }
                
                if (((arregloact[i].dia).compare("miercoles"))==0)
                {
                    j=2;
                    d1=2;
                    ver=2;
                    cout<<"\nIngrese la jornada de la actividad n˙mero  "<<i<<"  ";
                    cin>>arregloact[i].jornada;
                    j1=verificacionjornada(arregloact, i);
                    mananami=contadormanana(arregloact, mananami, i);
                    tardemi=contadortarde(arregloact, tardemi, i);
                    
                    if (mananami>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                    if (tardemi>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                }
                
                if (((arregloact[i].dia).compare("jueves"))==0)
                {
                    j=3;
                    d1=3;
                    ver=2;
                    cout<<"\nIngrese la jornada de la actividad n˙mero  "<<i<<"  ";
                    cin>>arregloact[i].jornada;
                    j1=verificacionjornada(arregloact, i);
                    mananaju=contadormanana(arregloact, mananaju, i);
                    tardeju=contadortarde(arregloact, tardeju, i);
                    
                    if (mananaju>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                    if (tardeju>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                }
                
                if (((arregloact[i].dia).compare("viernes"))==0)
                {
                    j=4;
                    d1=4;
                    ver=2;
                    cout<<"\nIngrese la jornada de la actividad n˙mero  "<<i<<"  ";
                    cin>>arregloact[i].jornada;
                    j1=verificacionjornada(arregloact, i);
                    mananavi=contadormanana(arregloact, mananavi, i);
                    tardevi=contadortarde(arregloact, tardevi, i);
                    
                    if (mananavi>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                    if (tardevi>3)
                    {
                        cout<<"Solo puede registrar 3 actividades por jornada cada dÌa";
                        ver=0;
                        i=i-1;
                    }
                    
                }
                
            }
            
            while(ver==2)
            {
                
                cout<<"\nIngrese el tipo de la actividad numero  "<<i<<" (deportiva, artistica, musical, cultural, plastica, organizacion)  ";
                cin>>arregloact[i].tipo;
                
                //Verificacion del tipo de actividad con respecto al publico permitido
                
                if(((arregloact[i].tipo).compare("deportiva"))==0)
                {
                    ver=1;
                    t1=0;
                    
                }
                if(((arregloact[i].tipo).compare("cultural"))==0)
                {
                    ver=1;
                    t1=1;
                }
                
                if(((arregloact[i].tipo).compare("artistica"))==0)
                {
                    
                    if(((arregloact[i].jornada).compare("tarde")==0)&&u1.edad<18)
                    {
                        cout<<"Las actividades artisticas por la tarde son solo para mayores de edad";
                        ver=0;
                    }
                    else
                    {
                        arregloact[i].tipo=arregloact[i].tipo;
                        ver=1;
                        t1=2;
                    }
                }
                if(((arregloact[i].tipo).compare("musical"))==0)
                {
                    
                    if(((arregloact[i].jornada).compare("tarde")==0&&u1.edad<18))
                    
                    {
                        cout<<"Las actividades musicales por la tarde son solo para mayores de edad";
                        ver=0;
                        
                    }
                    else
                    {
                        arregloact[i].tipo=arregloact[i].tipo;
                        ver=1;
                        t1=3;
                    }
                }
                if((arregloact[i].tipo).compare("plastica")==0)
                {
                    if(((arregloact[i].jornada).compare("tarde")==0)&&u1.edad<18)
                    {
                        cout<<"Las actividades plasticas por la tarde son solo para mayores de edad";
                        ver=0;
                    }
                    else
                    {
                        arregloact[i].tipo=arregloact[i].tipo;
                        ver=1;
                        t1=4;
                    }
                }
                if(((arregloact[i].tipo).compare("organizacion"))==0)
                {
                    if(u1.personal!=1)
                    {
                        cout<<"Las actividadesde la organizacion son solo para personal autorizado";
                        ver=0;
                    }
                    else
                    {
                        arregloact[i].tipo=arregloact[i].tipo;
                        ver=1;
                        t1=5;
                    }
                }
                
                else
                {
                    if((ver!=1)&&(ver!=0))
                    {
                        
                        cout<<"\nEl tipo de actividad ingresado no es valido";
                        ver=2;
                    }
                    
                }
                
            }
            
            c1.d[d1].j[j1].tipo[t1]++;
            if(c1.d[d1].j[j1].tipo[t1]>1)
            {
                cout<<"Dos actividades del mismo tipo no pueden quedar registradas en la misma jornada";
                ver=0;
                
            }
            if (ver==1)
            {
                arregloact[i].codigo=i;
                cout<<"\nEl codigo de la actividad numero "<<i<< "es  "<<arregloact[i].codigo;
                
                cout<<"\n\nIngrese la duracion en minutos de la actividad n˙mero  "<<i<<"  ";
                cin>>arregloact[i].duracion;
                
                cout<<"\nIngrese la hora de inicio (hora militar) de la actividad n˙mero  "<<i<<"  ";
                cin>>arregloact[i].horainicio;
                
                for(int w=0; w<16; w++)
                {
                    if(arregloact[i].horainicio==horasn[w])
                    s=w;
                }
                numcasillas=(arregloact[i].duracion/30);
                
                for(int q=0; q<numcasillas; q++)
                {
                    if((matriz[s+q][j].nombre).compare("              ")!=0)
                    {
                        cout<<"Ya existe una actividad en el horario especificado";
                        q=numcasillas;
                        i=i-1;
                    }
                    else
                    matriz[s+q][j]=arregloact[i];
                }
                i++;
                imprimirhorario(matriz, 16, semana, horas);
                
            }
            
            
            
            
            break;
            
            case 2:
            cout<<"Escriba el codigo de la actividad que desea eliminar";
            cin>>codigoelim;
            
            for(int g=0; g<30; g++)
            {
                if(arregloact[g].codigo==codigoelim)
                {
                    cout<<"La actividad eliminada es "<<arregloact[g].nombre;
                    arregloact[g].nombre="              ";
                    arregloact[g].codigo=-1;
                    arregloact[g].tipo=" ";
                    arregloact[g].jornada=" ";
                    arregloact[g].duracion=0;
                    arregloact[g].dia=" ";
                    arregloact[g].horainicio=0;
                    
                    
                }
            }
            for (int x=0;x<16;x++)
            {
                for(int y=0;y<5;y++)
                {
                    if(matriz[x][y].codigo==codigoelim)
                    {
                        matriz[x][y].nombre="              ";
                        matriz[x][y].codigo=-1;
                        matriz[x][y].tipo=" ";
                        matriz[x][y].jornada=" ";
                        matriz[x][y].duracion=0;
                        matriz[x][y].dia=" ";
                        matriz[x][y].horainicio=0;
                        
                        
                    }
                }
            }
            imprimirhorario(matriz, 16, semana, horas);
            
            break;
            
            
        }
        
    }
    return i;
}

void consultarportipo(struct actividad arregloact[])
{
    
    int l;
    cout<<"\n\nDeportivas: ";
    for(l=0; l<30; l++)
    {
        
        if(((arregloact[l].tipo).compare("deportiva"))==0)
        {
            cout<<"\nCodigo:"<<arregloact[l].codigo<<"   Nombre:"<<arregloact[l].nombre;
        }
    }
    
    cout<<"\n\nArtisticas: ";
    for(l=0; l<30; l++)
    {
        if(((arregloact[l].tipo).compare("artistica"))==0)
        {
            cout<<"\nCodigo:"<<arregloact[l].codigo<<"   Nombre:"<<arregloact[l].nombre;
        }
    }
    cout<<"\n\nCulturales: ";
    for(l=0; l<30; l++)
    {
        if(((arregloact[l].tipo).compare("cultural"))==0)
        {
            cout<<"\nCodigo:"<<arregloact[l].codigo<<"   Nombre:"<<arregloact[l].nombre;
        }
    }
    cout<<"\n\nMusicales: ";
    for(l=0; l<30; l++)
    {
        if(((arregloact[l].tipo).compare("musical"))==0)
        {
            cout<<"\nCodigo:"<<arregloact[l].codigo<<"   Nombre:"<<arregloact[l].nombre;
        }
    }
    cout<<"\n\nPlasticas: ";
    for(l=0; l<30; l++)
    {
        if(((arregloact[l].tipo).compare("plastica"))==0)
        {
            cout<<"\nCodigo:"<<arregloact[l].codigo<<"   Nombre:"<<arregloact[l].nombre;
        }
    }
    cout<<"\n\nDe la organizacion: ";
    for(l=0; l<30; l++)
    {
        if(((arregloact[l].tipo).compare("organizacion"))==0)
        {
            cout<<"\nCodigo:"<<arregloact[l].codigo<<"   Nombre:"<<arregloact[l].nombre;
        }
    }
}
void consultarpornombre(struct actividad arregloact[])

{
    int actividadencontrada=0;
    string nombrebuscar;
    cout<<"\nIngrese el nombre de la actividad que desea buscar   ";
    cin>>nombrebuscar;
    
    for(int l=0; l<30; l++)
    {
        if(((arregloact[l].nombre).compare(nombrebuscar))==0)
        {
            
            cout<<"\nCodigo: "<<arregloact[l].codigo;
            cout<<"\nTipo: "<<arregloact[l].tipo;
            cout<<"\nJornada: "<<arregloact[l].jornada;
            cout<<"\nDuracion: "<<arregloact[l].duracion<<"  minutos";
            cout<<"\nDia: "<<arregloact[l].dia;
            cout<<"\nHora de inicio: "<<arregloact[l].horainicio;
            actividadencontrada=1;
        }
    }
    if (actividadencontrada==0)
    cout<<"La actividad consultada no se encuentra registrada en el sistema";
    
    
}


void horariosdisponibles(struct actividad matriz[][5], string horas[], string semana[])
{
    cout<<"Los horarios disponibles en la semana son: ";
    
    for(int b=0;b<5;b++)
    {
        for (int a=0;a<16;a++)
        {
            
            if((matriz[a][b].nombre).compare("              ")==0)
            cout<<"\n"<<semana[b]<<" a las "<<horas[a];
        }
        
    }
}

int main(int argc, char *argv[])
{
    
    system("color f5");
    semana[0]="Lunes         ";
    semana[1]="Martes        ";
    semana[2]="Miercoles     ";
    semana[3]="Jueves        ";
    semana[4]="Viernes       ";
    
    horas[0]=" 8:00";
    horas[1]=" 8:30";
    horas[2]=" 9:00";
    horas[3]=" 9:30";
    horas[4]="10:00";
    horas[5]="10:30";
    horas[6]="11:00";
    horas[7]="11:30";
    horas[8]="14:00";
    horas[9]="14:30";
    horas[10]="15:00";
    horas[11]="15:30";
    horas[12]="16:00";
    horas[13]="16:30";
    horas[14]="17:00";
    horas[15]="17:30";
    
    horasn[0]=800;
    horasn[1]=830;
    horasn[2]=900;
    horasn[3]=930;
    horasn[4]=1000;
    horasn[5]=1030;
    horasn[6]=1100;
    horasn[7]=1130;
    horasn[8]=1400;
    horasn[9]=1430;
    horasn[10]=1500;
    horasn[11]=1530;
    horasn[12]=1600;
    horasn[13]=1630;
    horasn[14]=1700;
    horasn[15]=1730;
    
    int n=30;
    int i=5;
    int opcion=0;
    inicializarmatriz(matriz, 16);
    inicializarcontadores(c1);
    
    cout<<"__________________________________________________________________";
    cout<<"                       Bienvenido a la Programacion de la Semana Cultural\n";
    cout<<"__________________________________________________________________";
    cout<<"\nPor favor ingrese su edad  ";
    cin>>u1.edad;
    cout<<"Inserte 1 si es personal autorizado, de lo contrario inserte 2  ";
    cin>>u1.personal;
    llenaractividades (arregloact, matriz);
    while(opcion!=6)
    {
        
        cout<<"\n\nElija una de las siguientes opciones \n1. Ver el horario \n2. Ingresar o eliminar actividad \n3. Ver actividades por tipos \n4. Consultar actividad por nombre \n5. Consultar horarios disponibles \n6. Salir \n";
        cin>>opcion;
        switch(opcion)
        {
            case 1:
            imprimirhorario(matriz, 16, semana, horas);
            break;
            case 2:
            i=leerdatos(n, arregloact, u1, matriz, horasn, c1, i);
            break;
            case 3:
            consultarportipo(arregloact);
            break;
            case 4:
            consultarpornombre(arregloact);
            break;
            case 5:
            horariosdisponibles(matriz, horas, semana);
            break;
            
            
        }
        
    }
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}
