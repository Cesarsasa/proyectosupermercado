#pragma once
#include<iostream>
using namespace std;


class Persona
{
protected: string nombres, apellidos, direccion,dpi, genero,fn_nacimiento,fningreso;
         int telefono = 0;
         //constructor
protected:
    Persona() {

    }
    Persona(string nom, string ape, string dir,string dp, string ge,string fn,int tel, string fnin) {
        nombres = nom;
        apellidos = ape;
        direccion = dir;
        dpi = dp;
        fn_nacimiento = fn;
        genero = ge;
        telefono = tel;
        fningreso = fnin;


    }
};