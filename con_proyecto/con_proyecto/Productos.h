#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Productos {
private: string producto, descripcion, imagen,  fechaingreso;
	   int id, idmarca, existencia;
	   float precio_costo, precio_venta;


	   // constructor
public:
	Productos() {
	}
	Productos(string pro, string desc, string ima, float pre_costo, float pre_venta, int existen, string fe_ingreso, int i, int i_marca) {
		producto = pro;
		descripcion = desc;
		imagen = ima;
		precio_costo = pre_costo;
		precio_venta = pre_venta;
		existencia = existen;
		fechaingreso = fe_ingreso;
		id = i;
		idmarca = i_marca;
	}


	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string i = to_string(id);
		string i_m = to_string(idmarca);
		string p_c = to_string(precio_costo);
		string p_v = to_string(precio_venta);
		string ex = to_string(existencia);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO productos(producto,idmarca,descripcion,imagen, precio_costo,precio_venta, existencia,fecha_ingreso ) VALUES ('" + producto + "','" + i_m + "','" + descripcion + "','" + imagen + "','" + p_c+ "','" + p_v + "','" + ex+ "',now())";
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

			cout << "------------ Datos de Producto------------" << endl;
			string consulta = "SELECT idproducto,producto,marca,descripcion,imagen,precio_costo,precio_venta, existencia, fecha_ingreso FROM proyecto_sm.productos INNER JOIN proyecto_sm.marcas where productos.idmarca = marcas.idmarca";
			cout << "  " << endl;
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout <<"ID: " << fila[0] << " | "<<"Producto: " << fila[1] << " | " <<"Marca: " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | "
						<< fila[6] << " | " << fila[7] << " | " << fila[8] << " | " << endl;
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

			string eliminar = "delete from productos where idproducto = '" + i + "'";
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
		string i_m = to_string(idmarca);
		string p_c = to_string(precio_costo);
		string p_v = to_string(precio_venta);
		string ex = to_string(existencia);
		if (cn.getConectar()) {
			string  insertar = "update productos set producto = '" + producto + "', idmarca= '" + i_m + "', descripcion = '" + descripcion+ "',imagen = '" + imagen+ "',precio_costo = '" + p_c + "',precio_venta = '" +  p_v + "', existencia = '" + ex+ "', fecha_ingreso = now() where idproducto = '" + i + "' ";
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

