#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"


using namespace std;

class Empleados: Persona {
private: string fe_inicio;
	   int id;
	   int idpuesto;



	   // constructor
public:
	Empleados() {
	}
	Empleados(string nom, string ape, string dir, string dp, string ge, string fn, int tel, string fnin,string fi, int i, int ip) : Persona(nom, ape, dir,dp, ge, fn,tel, fnin) {

		fe_inicio = fi;
		id = i;
		idpuesto = ip;
	}


	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		string ipu = to_string(idpuesto);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO empleados(nombres,apellidos,direccion,telefono, dpi,genero, fecha_nacimiento,idpuesto,fecha_inicio_labores, fechaingreso ) VALUES ('" + nombres + "','" + apellidos + "','" + direccion + "','" + t + "','" + dpi + "','" + genero + "','" + fn_nacimiento + "','" + ipu + "','" + fe_inicio +"',now())";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		system("cls");
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Empleados ------------" << endl;
			cout << "  " << endl;
			string consulta = "select * from empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " 
						<< fila[6] << " | " << fila[7] << " | " << fila[8] << " | " << fila[9] << " | " << fila[10] << " | " << endl;
					cout << "  " << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void Eliminar() {
		
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string i = to_string(id);
		if (cn.getConectar()) {

			cout << "------------ Datos de Empleados------------" << endl;
			string eliminar = "delete from empleados where idempleado = '" + i + "'";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "eliminado con exito" << endl;

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void Modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		string ii = to_string(id);
		string ipu = to_string(idpuesto);
		if (cn.getConectar()) {
			string  insertar = "update empleados set nombres = '" + nombres + "',apellidos= '" + apellidos+ "', direccion = '" + direccion + "',telefono = '" + t + "',dpi = '" + dpi + "',genero = '" + genero + "', fecha_nacimiento = '" + fn_nacimiento+ "',idpuesto = '" + ipu+ "',fecha_inicio_labores = '" + fe_inicio + "', fechaingreso = now() where idempleado = '" + ii + "' ";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};