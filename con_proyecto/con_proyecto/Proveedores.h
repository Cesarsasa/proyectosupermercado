#pragma once	
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Proveedores {
private: string proveedor, nit , direccion;
	   int id;
	   int telefono;


	   // constructor
public:
	Proveedores() {
	}
	Proveedores(string pro,string n,string dir, int tele, int i) {
		proveedor = pro;
		nit = n;
		direccion = dir;
		telefono = tele;
		id = i;
	}


	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		string i = to_string(id);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO proveedores(proveedor, nit, direccion, telefono) VALUES ('" + proveedor + "','" + nit + "','" + direccion + "','" + t + "')";
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

			cout << "------------ Datos de proveedores ------------" << endl;
			cout << "  " << endl;
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout <<"ID: " << fila[0] << " | " << fila[1] << " | " <<"Nit: " << fila[2] << " | " << fila[3] << " | "<<"TEL:" << fila[4] << endl;
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

			string eliminar = "delete from proveedores where idproveedor = '" + i + "'";
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
		string i = to_string(id);
		if (cn.getConectar()) {
			string  insertar = "update proveedores set proveedor = '" + proveedor + "', nit ='" + nit + "',direccion = '" + direccion + "',telefono ='" + t + "' where idproveedor = '" + i + "'";
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

