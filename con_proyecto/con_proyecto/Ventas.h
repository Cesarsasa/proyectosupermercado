#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <fstream>
#include "ConexionBD.h"
#include<arduino.h>
#include<ArduinoError.h>
using namespace std;

class Ventas {
private: string nit, nombres, apellidos, serie, fecha_factura, fechaingreso, correo, genero;
	   int id, id_venta, id_cliente, id_empleado, no_factura, id_producto, cantidad, telefono;
	   float precio_u;
		


	   // constructor
public:
	Ventas() {
	}
	Ventas(string n, string nom, string ape, string se, int no_f, string f_f, string fe_ingreso, string c_e, string g, int can, int i, int i_cli, int i_emple, int i_ve, int i_pro, float pu, int tele) {
		nit = n;
		nombres = nom;
		apellidos = ape;
		serie = se;
		no_factura = no_f;
		fecha_factura = f_f;
		fechaingreso = fe_ingreso;
		cantidad = can;
		correo = c_e;
		genero = g;
		id = i;
		id_cliente = i_cli;
		id_empleado = i_emple;
		id_venta = i_ve;
		id_producto = i_pro;
		precio_u = pu;
		telefono = tele;
	}
	void empezarcaja() {
		ArduinoPort.PortName = "COM6";
		ArduinoPort.BaudeRate = 9600;
		ArduinoPort.Open();
		ArduinoPort.Write("c");
	}
	void cerrarcaja() {
		SerialPort ArduinoPort = new SerialPort();
		ArduinoPort.PortName = "COM6";
		ArduinoPort.BaudeRate = 9600;
		ArduinoPort.Open();
		ArduinoPort.Write("0");
		ArduinoPort.Close();

	}
	void crear() {
		
		
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		float total = 0;
		string idc = to_string(id_cliente);
		string ide = to_string(id_empleado);
		string nf = to_string(no_factura);
		char r;
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO ventas(nofactura,serie, fechafactura,idcliente,idempleado,fechaingreso ) VALUES ('" + nf + "','" + serie + "',curdate(),'" + idc + "','" + ide + "',now())";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "..." << endl;
				empezarcaja();
				maxventa();
				do {
					cout << "Ingrese id producto, cerrar venta(0): ";
					cin >> id_producto;
					cin.ignore();
					cout << "------------------------" << endl;
					total += precio_u * cantidad;
					if (id_producto == 0) {
						cout << " " << endl;
						cout << "**************************************************" << endl;
						cout << "Gracias por su compra " << " TOTAL : " << total << endl;
						cout << "**************************************************" << endl;
						cout << " " << endl;
						cerrarcaja();
						cout << " Desea imprimir factura(s/n) " << endl;
						cin >> r;
						cin.ignore();

						if (r == 's' || r == 'S') {
							imprimirfactura();
						}
						else {
							cout << "..." << endl;
						}

					}
					else {
						ver_detalle_venta();
						detalle_venta();
					}

				} while (id_producto != 0);
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
	void crearcf() {
	
		
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		float total = 0;
		string idc = to_string(id_cliente);
		string ide = to_string(id_empleado);
		string nf = to_string(no_factura);
		char r;
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO ventas(nofactura,serie, fechafactura,idempleado,fechaingreso ) VALUES ('" + nf + "','" + serie + "',curdate(),'" + ide + "',now())";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "..." << endl;
				empezarcaja();
				maxventa();
				do {
					cout << "Ingrese id producto, cerrar venta(0): ";
				
					cin >> id_producto;
					cin.ignore();
					cout << "------------------------" << endl;
					total += precio_u * cantidad;
					if (id_producto == 0) {
						cout << " " << endl;
						cout << "**************************************************" << endl;
						cout << "Gracias por su compra " << " TOTAL : " << total << endl;
						cout << "**************************************************" << endl;
						cout << " " << endl;
						cerrarcaja();
						cout << " Desea imprimir factura(s/n) " << endl;
						cin >> r;

						cin.ignore();
						if (r == 's' || r == 'S') {
							imprimirfactura_cf();
						}
						else {
							cout << "GRACIAS POR SU COMPRA" << endl;
						}
					}
					else {
						ver_detalle_venta();
						detalle_venta();
					}

				} while (id_producto != 0);
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

			cout << "------------ Datos de Ventas------------" << endl;
			cout << "  " << endl;
			string consulta = "SELECT idventa,nofactura,serie,fechafactura,idempleado,fechaingreso , if(idcliente is not null,idcliente,'cf') FROM proyecto_sm.ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "IDVENTA: "<< fila[0] << " | " <<"No.factura: " << fila[1] << " | " << "Serie :" << fila[2] << " | " << fila[3] << " | "<<"CODEMPLEADO: " << fila[4] << " | " << fila[5] << " | "
						 <<"Codcliente: " << fila[6] << " | " << endl;
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

			string eliminar = "delete from ventas where idventa= '" + i + "'";
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
		string ide = to_string(id_empleado);
		string nf = to_string(no_factura);
		string idc = to_string(id_cliente);
		if (cn.getConectar()) {
			string  insertar = "update ventas set nofactura = '" + nf + "', serie = '" + serie + "', fechafactura = '" + fecha_factura + "', idcliente = '" + idc + "', idempleado = '" + ide + "', fechaingreso = now() where idventa = '" + i + "' ";
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
	void f_nit() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		float total = 0;
		char r;

		if (cn.getConectar()) {
			string consulta = "	SELECT nombres, apellidos, idcliente, now() FROM proyecto_sm.clientes where nit = '" + nit + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (nit.empty()) {
				cout << " xxx debe ingresar nit  xxx" << endl;
			}
			else {
				if (nit == "cf") {
					factura();
					string idc = to_string(id_cliente);
					idc = " ";
					cout << "Ingrese id empleado:";
					cin >> id_empleado;
					cin.ignore();
					crearcf();

				}
				else {
					if (!q_estado) {

						if (fila != NULL) {

							cout << "------------ Datos------------" << endl;
							cout << fila[0] << "  " << fila[1] << " | " << fila[2] << " | " << "Fecha : " << fila[3] << endl;
							id_cliente = atof(fila[2]);
							factura();
							cout << "Ingrese id empleado:";
							cin >> id_empleado;
							cin.ignore();
							crear();


						}
						else {
							cout << " Desea ingresar nit(s/n) " << endl;
							cin >> r;
							cin.ignore();
							if (r == 's' || r == 'S') {
								cout << "Ingrese Nombres:";
								getline(cin, nombres);
								cout << "Ingrese Apellidos:";
								getline(cin, apellidos);
								cout << "Ingrese genero(m/f):";
								getline(cin, genero);
								cout << "Ingrese correo electronico:";
								getline(cin, correo);
								cout << "Ingrese telefono:";
								cin >> telefono;
								cin.ignore();
								crearcliente();
							}
							else {
								cout << "..." << endl;
							}

						}
					}
					else {
						cout << " xxx Error al Consultar  xxx" << endl;
					}
				}

			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}

		cn.cerrar_conexion();
	}
	void factura() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "SELECT MAX(nofactura) from proyecto_sm.ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (!q_estado) {
				if (fila != NULL) {

					cout << "No_factura: ";
					no_factura = atof(fila[0]) + 1;
					cout << no_factura << " ";
					serie = "a";
					cout << "serie: ";
					cout << serie << endl;

				}
				else {
					cout << " Error al ingresar" << endl;
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
	void maxventa() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "SELECT MAX(idventa) from proyecto_sm.ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (!q_estado) {
				if (fila != NULL) {
					id_venta = atof(fila[0]);
				}
				else {
					cout << " Error en detalle ventas " << endl;
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
	void detalle_venta() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string idv = to_string(id_venta);
		string idp = to_string(id_producto);
		string p_u = to_string(precio_u);
		string can = to_string(cantidad);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO ventas_detalle(idventa,idproducto,cantidad,precio_unitario) VALUES ('" + idv + "','" + idp + "','" + can + "','" + p_u + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "..." << endl;
			}

			else {
				cout << " xxx Error no existe producto  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void ver_detalle_venta() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string idp = to_string(id_producto);
		if (cn.getConectar()) {
			string consulta = "	SELECT producto, precio_venta FROM proyecto_sm.productos where idproducto = '" + idp + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);
			if (!q_estado) {

				if (fila != NULL) {
					cout << fila[0] << "  " << "Precio:" << fila[1] << endl;
					cout << "------------------------" << endl;
					precio_u = atof(fila[1]);
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
	void crearcliente() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nombres,apellidos,nit, genero,telefono, correo_electronico,fechaingreso ) VALUES ('" + nombres + "','" + apellidos + "','" + nit + "','" + genero + "','" + t + "','" + correo + "',now())";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
				f_nit();

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
	void imprimirfactura() {
		    system("cls");
			int q_estado;
			int q_estado2;
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			MYSQL_ROW fila2;
			MYSQL_RES* resultado2;
			float precio = 0, total = 0;
			int canti = 0;
			string idv = to_string(id_venta);
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string consulta = "select v.nofactura,v.serie,v.fechafactura,c.nit,c.nombres,c.apellidos from proyecto_sm.clientes c inner join proyecto_sm.ventas v on c.idcliente = v.idcliente where idventa = '"+ idv +"'";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				resultado = mysql_store_result(cn.getConectar());
				fila = mysql_fetch_row(resultado);

				if (!q_estado) {
					if (fila != NULL) {
						ofstream archivo;
						archivo.open("factura.txt");
						archivo << "             SUPER MERCADO" << endl;
						archivo << "---------------------------------------------------" << endl;
						archivo << " NO.FACTURA : " << fila[0] << " SERIE : " << fila[1] << " FECHA : " << fila[2] << endl;
						archivo << "---------------------------------------------------" << endl;
						archivo << "NIT : " << fila[3] << endl;
						archivo << "---------------------------------------------------" << endl;
						archivo << "CLIENTE : "<< fila[4] << " "<< fila[5] << endl;
						

						archivo << "-------------------Productos-----------------------" << endl;
						archivo << "  " << endl;
						string consulta2 = "select  d.idproducto,p.producto,m.marca, d.cantidad,d.precio_unitario from proyecto_sm.ventas_detalle d inner join proyecto_sm.productos p on p.idproducto = d.idproducto inner join proyecto_sm.marcas m on m.idmarca = p.idmarca where idventa = '" + idv + "'";
						const char* c = consulta2.c_str();
						q_estado2 = mysql_query(cn.getConectar(), c);
						if (!q_estado2) {
							resultado2 = mysql_store_result(cn.getConectar());
							while (fila2 = mysql_fetch_row(resultado2)) {
								archivo << fila2[0] << " - " << fila2[1] << " - " << fila2[2] << " - " << fila2[3] << " - Q. " << fila2[4] << " - " << endl;
								archivo << "---------------------------------------------------" << endl;
								precio = atof(fila2[4]);
								canti = atof(fila2[3]);
								total += precio * canti;
							}
							archivo << "TOTAL : " << total << endl;
							archivo << "---------------------------------------------------" << endl;
							archivo << "***********************" << endl;
							archivo << "*GRACIAS POR SU COMPRA*" << endl;
							archivo << "***********************" << endl;

							archivo.close();
							system("start C:\\Users\\CESAR\\Desktop\\c++\\archivosconexionvisualmysql\\con_proyecto\\con_proyecto\\factura.txt");
						}
						else {
							cout << " xxx Error al Consultar  xxx" << endl;
						}
					}
					else {
						cout << " Error en detalle ventas " << endl;
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
	
	void imprimirfactura_cf() {
		system("cls");
		int q_estado;
		int q_estado2;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		MYSQL_ROW fila2;
		MYSQL_RES* resultado2;
		float precio = 0, total = 0;
		int canti = 0;
		string idv = to_string(id_venta);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select v.nofactura,v.serie,v.fechafactura from proyecto_sm.clientes c inner join proyecto_sm.ventas v where idventa = '" + idv + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			resultado = mysql_store_result(cn.getConectar());
			fila = mysql_fetch_row(resultado);

			if (!q_estado) {
				if (fila != NULL) {
					ofstream archivo;
					archivo.open("factura.txt");
					archivo << "             SUPER MERCADO" << endl;
					archivo << "---------------------------------------------------" << endl;
					archivo << " NO.FACTURA : " << fila[0] << " SERIE : " << fila[1] << " FECHA : " << fila[2] << endl;
					archivo << "---------------------------------------------------" << endl;
					archivo << "NIT : " << "C/F" << endl;
					archivo << "---------------------------------------------------" << endl;

					archivo << "-------------------Productos-----------------------" << endl;
					archivo << "  " << endl;
					string consulta2 = "select  d.idproducto,p.producto,m.marca, d.cantidad,d.precio_unitario from proyecto_sm.ventas_detalle d inner join proyecto_sm.productos p on p.idproducto = d.idproducto inner join proyecto_sm.marcas m on m.idmarca = p.idmarca where idventa = '" + idv + "'";
					const char* c = consulta2.c_str();
					q_estado2 = mysql_query(cn.getConectar(), c);
					if (!q_estado2) {
						resultado2 = mysql_store_result(cn.getConectar());
						while (fila2 = mysql_fetch_row(resultado2)) {
							archivo << fila2[0] << " - " << fila2[1] << " - " << fila2[2] << " - " << fila2[3] << " - Q. " << fila2[4] << " - " << endl;
							archivo << "---------------------------------------------------" << endl;
							precio = atof(fila2[4]);
							canti = atof(fila2[3]);
							total += precio * canti;
						}
						archivo << "TOTAL : " << total << endl;
						archivo << "---------------------------------------------------" << endl;
						archivo << "***********************" << endl;
						archivo << "*GRACIAS POR SU COMPRA*" << endl;
						archivo << "***********************" << endl;
						archivo.close();
						system("start C:\\Users\\CESAR\\Desktop\\c++\\archivosconexionvisualmysql\\con_proyecto\\con_proyecto\\factura.txt");
					}
					else {
						cout << " xxx Error al Consultar  xxx" << endl;
					}

			
				}
				else {
					cout << " Error en detalle ventas " << endl;
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

