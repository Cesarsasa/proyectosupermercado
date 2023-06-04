#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Cliente{
private: string nombres,apellidos, nit, genero,correo_ele, fechaingreso;
	   int id,telefono;
	


	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string n, string g,string co_ele, string fe_ingreso, int i, int tele) {
		nombres= nom;
		apellidos = ape;
		nit = n;
		genero = g;
		correo_ele = co_ele;
		fechaingreso = fe_ingreso;
		id = i;
		telefono= tele;
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nombres,apellidos,nit, genero,telefono, correo_electronico,fechaingreso ) VALUES ('" + nombres + "','" + apellidos + "','" + nit + "','" + genero+ "','" + t + "','" + correo_ele + "',now())";
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

			cout << "------------ Datos de Clientes------------" << endl;
			cout << "  " << endl;
			string consulta = "SELECT * FROM clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "ID: " << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | "
						<< fila[6] << " | " << fila[7] << " | " <<  endl;
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

			string eliminar = "delete from clientes where idcliente= '" + i + "'";
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
		string i = to_string(id);
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "update clientes set nombres = '" + nombres + "', apellidos = '" + apellidos + "', nit = '" + nit + "', genero = '" + genero + "', telefono = '" + t + "', correo_electronico = '" + correo_ele + "', fechaingreso = now() where idcliente = '" + i + "' ";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Modificacion Exitosa ..." << endl;
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

