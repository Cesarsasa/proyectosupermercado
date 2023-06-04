#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Compras{
private: string nit, nombres, apellidos,  fecha_factura, fechaingreso;
	   int id, no_orden, id_proveedor,id_producto, id_compra, cantidad;
	   float precio_u;



	   // constructor
public:
	Compras() {
	}
	Compras(string n, string nom, string ape, string f_f,string f_i, int i, int n_o, int ip,int idpr, int ic,int can,float pu) {
		nit = n;
		nombres = nom;
		apellidos = ape;
		fecha_factura = f_f;
		fechaingreso = f_i;
		cantidad = can;
		id = i;
		id_proveedor = ip;
		id_producto = idpr;
		id_compra = ic;
		no_orden = n_o;
		precio_u = pu;
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		float total = 0;
		string no = to_string(no_orden);
		string ip = to_string(id_proveedor);
		char r;
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO compras(no_orden_compra,idproveedor, fecha_orden,fechaingreso ) VALUES ('" + no + "','" + ip + "',curdate(),now())";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				ver_proveedor();
				     maxcompra();
					do{  cout << " " << endl;
					cout << "Ingrese id producto: ";
					cin >> id_producto;
					cin.ignore();
					ver_detalle_compra();
					cout <<" " << endl;
					cout << "Ingrese Costo Unitario de producto: ";
					cin >> precio_u;
					cin.ignore();
					detalle_compra();
					cout << "	Desea ingresar otro producto(s/n): ";
					cin >> r;
					} while (r == 's' || r == 'S');

			
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

			cout << "------------ Datos de compras------------" << endl;
			cout <<  " " << endl;
			string consulta = "SELECT * FROM proyecto_sm.compras";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Idcompra:" << fila[0] << " | " << "No_orden:" << fila[1] << " | " << "Idproveedor:" << fila[2] << " | "<< "FechaOrden:" << fila[3] << " | " << "FechaIngreso:" << fila[4]  << endl;
					cout << " " << endl;
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

			string eliminar = "delete from compras where idcompra= '" + i + "'";
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
		string no = to_string(no_orden);
		string ip = to_string(id_proveedor);
		if (cn.getConectar()) {
			string  insertar = "update compras set no_orden_compra = '" + no + "', idproveedor = '" + ip + "', fecha_orden = '" + fecha_factura + "', fechaingreso = now() where idcompra = '" + i + "' ";
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
	void maxcompra() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "SELECT MAX(idcompra) from proyecto_sm.compras";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (!q_estado) {
				if (fila != NULL) {
					id_compra = atof(fila[0]);
				}
				else {
					cout << " Error en detalle compras" << endl;
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
	void detalle_compra() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string no = to_string(no_orden);
		string ipr = to_string(id_producto);
		string ic = to_string(id_compra);
		string p_u = to_string(precio_u);
		string can = to_string(cantidad);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO compras_detalle(idcompra,idproducto,cantidad,precio_costo_unitario) VALUES ('" + ic + "','" + ipr + "','" + can + "','" + p_u + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " " << endl;
				cout << "Registro Exitoso..." << endl;
			}

			else {
				cout << " xxx Error   xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void ver_detalle_compra() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string idp = to_string(id_producto);
		if (cn.getConectar()) {
			string consulta = "	SELECT producto, precio_costo FROM proyecto_sm.productos where idproducto = '" + idp + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);
			if (!q_estado) {

				if (fila != NULL) {
					cout << "------------------------" << endl;
					cout << "Producto: " << fila[0] << "  " << "Precio Costo:" << fila[1] << endl;
					cout << "------------------------" << endl;
					cout << "Ingrese cantidad:";
					cin >> cantidad;
					cin.ignore();

				}
				else {
					cout << " xxx Error del producto xxx" << endl;

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
	void ver_proveedor() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string idpr = to_string(id_proveedor);
		if (cn.getConectar()) {
			string consulta = "	SELECT proveedor, nit FROM proyecto_sm.proveedores where idproveedor = '" + idpr + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);
			if (!q_estado) {

				if (fila != NULL) {
					cout << "------------------------" << endl;
					cout << "Proveedor: " << fila[0] << "  " << "NIT :" << fila[1] << endl;
					cout << "------------------------" << endl;
	

				}
				else {
					cout << " xxx Error del producto xxx" << endl;

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

};

