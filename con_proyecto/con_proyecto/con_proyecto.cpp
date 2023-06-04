#include "Puestos.h"
#include "Marcas.h"
#include "Empleados.h"
#include "Productos.h"
#include "Proveedores.h"
#include "Cliente.h"
#include "Ventas.h"
#include "Compras.h"
#include <iostream>
#include<arduino.h>
#include<ArduinoError.h>
using namespace  std;

int main()
{
	void tabla_puestos();
	void tabla_marcas();
	void tabla_empleados();
	void tabla_productos();
	void tabla_proveedores();
	void tabla_clientes();
	void tabla_ventas();
	void tabla_compras();
	int op;
	do{
		system("cls");
	cout<<"         ***SUPER MERCADO***" << endl;
	cout << "" << endl;
	cout << "1.Puestos " << "           2.Marcas" << endl;
	cout << " " << endl;
	cout << "3.Empleados" << "         4.Productos" << endl;
	cout << "" << endl;
	cout << "5.Proveedores" << "       6.Clientes " << endl;
	cout << "" << endl;
	cout << "7.Ventas" << "            8.Compras" << endl;
	cout << "" << endl;
	cout << "Ingresar opcion: ";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		tabla_puestos();
		break;
	case 2:
		tabla_marcas();
		break;
	case 3:
		tabla_empleados();
		break;
	case 4:
		tabla_productos();
		break;
	case 5:
		tabla_proveedores();
		break;
	case 6:
		tabla_clientes();
		break;
	case 7:
		tabla_ventas();
		break;
	case 8:
		tabla_compras();
		break;
	}
	} while (op <= 6 || op >= 6);

	return 0;

}
void tabla_puestos(){
	system("cls");
	int op;
	string  puesto;
	int id=0;
	Puestos c;
	cout << "Puestos" << endl;
	cout << "1.Crear Puesto" << endl;
	cout << "2.Modificar Puesto" << endl;
	cout << "3.Eliminar Puesto" << endl;
	cout << "4.Mostrar Puesto" << endl;
	cout << "Ingrese opcion :";
	cin >> op;
	cin.ignore();
	switch(op) { 
	case 1:
		cout << "" << endl;
		cout << "Ingrese puesto:";
		getline(cin, puesto);
		c = Puestos(puesto, id);
		c.crear();
		
		break;
	case 2:
		cout << "" << endl;
		cout << "Ingrese id:";
		cin>> id;
		cin.ignore();
		cout << "Ingrese puesto para modificar:";
		getline(cin, puesto);
		c = Puestos(puesto, id);
		c.Modificar();
		
		break;
	case 3:
		cout << "" << endl;
		cout << "Ingrese id:";
		cin >> id;
		c = Puestos(puesto, id);
		c.Eliminar();
		
		break;
	case 4:
		cout << "" << endl;
		c = Puestos(puesto, id);
		c.leer();
		
		break;
	}
	
	system("pause");
}
void tabla_marcas() {
	system("cls");
	int op;
	string  marca;
	int id = 0;
	Marcas c;
	cout << "Marcas" << endl;
	cout << "1.Crear Marca" << endl;
	cout << "2.Modificar Marca" << endl;
	cout << "3.Eliminar Marca" << endl;
	cout << "4.Mostrar Marca" << endl;
	cout << "Ingrese opcion :";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "" << endl;
		cout << "Ingrese Marca:";
		getline(cin, marca);
		c = Marcas(marca, id);
		c.crear();

		break;
	case 2:
		cout << "" << endl;
		cout << "Ingrese id:";
		cin >> id;
		cin.ignore();
		cout << "Ingrese marca para modificar:";
		getline(cin, marca);
		c = Marcas(marca, id);
		c.Modificar();

		break;
	case 3:
		cout << "" << endl;
		cout << "Ingrese id:";
		cin >> id;
		c = Marcas(marca, id);
		c.Eliminar();

		break;
	case 4:
		cout << "" << endl;
		c = Marcas(marca, id);
		c.leer();

		break;
	}

	system("pause");
}
void tabla_empleados() {
	system("cls");
	int op;
	string nombres, apellidos, direccion, dpi, genero, fn_nacimiento, fningreso, fe_inicio;
	int idpuesto=0;
	int telefono = 0, id=0;
	Empleados c;
	cout << "Empleados" << endl;
	cout << "1.Crear Empleado " << endl;
	cout << "2.Modificar Empleado " << endl;
	cout << "3.Eliminar Empleado" << endl;
	cout << "4.Mostrar Empleado" << endl;
	cout << "Ingrese opcion :";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "Ingrese nombres:";
		getline(cin, nombres);
		cout << "Ingrese apellidos:";
		getline(cin, apellidos);
		cout << "Ingrese direccion:";
		getline(cin, direccion);
		cout << "Ingrese telefono:";
		cin>> telefono;
		cin.ignore();
		cout << "Ingrese dpi:";
		getline(cin, dpi);
		cout << "Ingrese genero(m/f):";
		getline(cin, genero);
		cout << "Ingrese fecha de nacimiento:";
		getline(cin, fn_nacimiento);
		cout << "Ingrese No.puesto:";
		cin >> idpuesto;
		cin.ignore();
		cout << "Ingrese fecha de inicio:";
		getline(cin, fe_inicio);
		c = Empleados(nombres, apellidos, direccion, dpi, genero, fn_nacimiento,telefono, fningreso, fe_inicio, id,idpuesto);
		c.crear();

		break;
	case 2:
		cout << "Ingrese id:";
		cin >> id;
		cin.ignore();
		cout << "Ingrese nombres:";
		getline(cin, nombres);
		cout << "Ingrese apellidos:";
		getline(cin, apellidos);
		cout << "Ingrese direccion:";
		getline(cin, direccion);
		cout << "Ingrese telefono:";
		cin >> telefono;
		cin.ignore();
		cout << "Ingrese dpi:";
		getline(cin, dpi);
		cout << "Ingrese genero(m/f):";
		getline(cin, genero);
		cout << "Ingrese fecha de nacimiento:";
		getline(cin, fn_nacimiento);
		cout << "Ingrese No.puesto:";
		cin >> idpuesto;
		cin.ignore();
		cout << "Ingrese fecha de inicio:";
		getline(cin, fe_inicio);
	
		c = Empleados(nombres, apellidos, direccion, dpi, genero, fn_nacimiento, telefono, fningreso, fe_inicio, id, idpuesto);
		c.Modificar();

		break;
	case 3:
		cout << "Ingrese id:";
		cin >> id;
		c = Empleados(nombres, apellidos, direccion, dpi, genero, fn_nacimiento, telefono, fningreso, fe_inicio, id, idpuesto);
		c.Eliminar();

		break;
	case 4:

		c = Empleados(nombres, apellidos, direccion, dpi, genero, fn_nacimiento, telefono, fningreso, fe_inicio, id, idpuesto);

		c.leer();

		break;
	}

	system("pause");
}
void tabla_productos() {
	system("cls");
	int op;
	string producto, descripcion, imagen, fechaingreso;
	int id=0, idmarca=0, existencia=0;
	float precio_costo=0, precio_venta=0;
	Productos c;
	cout << "Productos" << endl;
	cout << "1.Crear Producto" << endl;
	cout << "2.Modificar Producto" << endl;
	cout << "3.Eliminar Producto" << endl;
	cout << "4.Mostrar Producto" << endl;
	cout << "Ingrese opcion :";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "Ingrese Producto:";
		getline(cin, producto);
		cout << "Ingrese no.marca:";
		cin >> idmarca;
		cin.ignore();
		cout << "Ingrese descripcion:";
		getline(cin, descripcion);
		cout << "Ingrese imagen:";
		getline(cin, imagen);
		cout << "Ingrese Precio de costo:";
		cin >> precio_costo;
		cin.ignore();
		cout << "Ingrese Precio de venta:";
		cin >> precio_venta;
		cin.ignore();
		cout << "Ingrese existencia:";
		cin >> existencia;
		cin.ignore();
		
		c = Productos(producto, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso, id, idmarca);
		c.crear();

		break;
	case 2:
		cout << "Ingrese id:";
		cin >> id;
		cin.ignore();
		cout << "Ingrese Producto:";
		getline(cin, producto);
		cout << "Ingrese no.marca:";
		cin >> idmarca;
		cin.ignore();
		cout << "Ingrese descripcion:";
		getline(cin, descripcion);
		cout << "Ingrese imagen:";
		getline(cin, imagen);
		cout << "Ingrese Precio de costo:";
		cin >> precio_costo;
		cin.ignore();
		cout << "Ingrese Precio de venta:";
		cin >> precio_venta;
		cin.ignore();
		cout << "Ingrese existencia:";
		cin >> existencia;
		cin.ignore();
		c = Productos(producto, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso, id, idmarca);
		c.Modificar();

		break;
	case 3:
		cout << "Ingrese id:";
		cin >> id;
		c = Productos(producto, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso, id, idmarca);
		c.Eliminar();

		break;
	case 4:

		c = Productos(producto, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso, id, idmarca);

		c.leer();

		break;
	}

	system("pause");
}
void tabla_proveedores() {
	system("cls");
	int op;
	string proveedor, nit,direccion;
	int id = 0, telefono=0;

	Proveedores c;
	cout << "Proveedores" << endl;
	cout << "1.Crear Proveedores" << endl;
	cout << "2.Modificar Proveedores " << endl;
	cout << "3.Eliminar Proveedores " << endl;
	cout << "4.Mostrar Proveedores" << endl;
	cout << "Ingrese opcion :" ;
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "Ingrese Proveedor:";
		getline(cin, proveedor);
		cout << "Ingrese nit:";
		getline(cin, nit);
		cout << "Ingrese direccion:";
		getline(cin, direccion);
		cout << "Ingrese telefono:";
		cin >> telefono;
		cin.ignore();
		c = Proveedores(proveedor,nit,direccion,telefono,id);
		c.crear();

		break;
	case 2:
		cout << "Ingrese id:";
		cin >> id;
		cin.ignore();
		cout << "Ingrese Proveedor:";
		getline(cin, proveedor);
		cout << "Ingrese nit:";
		getline(cin, nit);
		cout << "Ingrese direccion:";
		getline(cin, direccion);
		cout << "Ingrese telefono:";	
		cin >> telefono;
		cin.ignore();
		c = Proveedores(proveedor, nit, direccion, telefono, id);
		c.Modificar();
		break;
	case 3:
		cout << "Ingrese id:";
		cin >> id;
		c = Proveedores(proveedor, nit, direccion, telefono, id);
		c.Eliminar();

		break;
	case 4:

		c = Proveedores(proveedor, nit, direccion, telefono, id);

		c.leer();

		break;


}
	system("pause");

}
void tabla_clientes() {
	system("cls");
	int op;
	string nombres, apellidos, nit, genero, correo_ele, fechaingreso;
	int id=0, telefono=0;
	Cliente c;
	cout << "Clientes" << endl;
	cout << "1.Crear Clientes" << endl;
	cout << "2.Modificar Clientes" << endl;
	cout << "3.Eliminar Clientes" << endl;
	cout << "4.Mostrar Clientes" << endl;
	cout << "Ingrese opcion :";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		cout << "Ingrese Nombres:";
		getline(cin, nombres);
		cout << "Ingrese Apellidos:";
		getline(cin, apellidos);
		cout << "Ingrese nit:";
		getline(cin, nit);
		cout << "Ingrese genero(m/f):";
		getline(cin, genero);
		cout << "Ingrese correo electronico:";
		getline(cin, correo_ele);
		cout << "Ingrese telefono:";
		cin >> telefono;
		cin.ignore();
		c = Cliente(nombres, apellidos,nit, genero, correo_ele, fechaingreso,id,telefono);
		c.crear();

		break;
	case 2:
		cout << "Ingrese id:";
		cin >> id;
		cin.ignore();
		cout << "Ingrese Nombres:";
		getline(cin, nombres);
		cout << "Ingrese Apellidos:";
		getline(cin, apellidos);
		cout << "Ingrese nit:";
		getline(cin, nit);
		cout << "Ingrese genero(m/f):";
		getline(cin, genero);
		cout << "Ingrese correo electronico:";
		getline(cin, correo_ele);
		cout << "Ingrese telefono:";
		cin >> telefono;
		cin.ignore();
		c = Cliente(nombres, apellidos, nit, genero, correo_ele, fechaingreso, id, telefono);
		c.Modificar();
		break;
	case 3:
		cout << "Ingrese id:";
		cin >> id;
		c = Cliente(nombres, apellidos, nit, genero, correo_ele, fechaingreso, id, telefono);
		c.Eliminar();

		break;
	case 4:

		c = Cliente(nombres, apellidos, nit, genero, correo_ele, fechaingreso, id, telefono);

		c.leer();

		break;


	}
	system("pause");

}
void tabla_ventas() {
	system("cls");
	int op;
	string nombres, apellidos, nit,  serie ,fechafactura,fechaingreso,correo,genero;
	int id = 0, id_empleado = 0, id_cliente=0, nofactura=0, id_venta=0, id_producto=0, cantidad=0, telefono =0;
	float precio_u=0;
	Ventas c;
	cout << "ventas" << endl;
	cout << "1.Crear ventas " << endl;
	cout << "2.Modificar ventas" << endl;
	cout << "3.Eliminar ventas" << endl;
	cout << "4.Mostrar ventas" << endl;
	cout << "Ingrese opcion :";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		system("cls");
		cout << "Ingrese nit:";
		getline(cin, nit);
		c = Ventas(nit, nombres, apellidos, serie, nofactura, fechafactura, fechaingreso,correo, genero,cantidad, id, id_cliente, id_empleado,id_venta,id_producto,precio_u,telefono);
		c.f_nit();
		break;
	case 2:
		cout << "Ingrese idventa:";
		cin >> id;
		cin.ignore();
		cout << "Ingrese No_factura:";
		cin >> nofactura;
		cin.ignore();
		cout << "Ingrese serie:";
		getline(cin, serie);
		cout << "Ingrese fecha-factura:";
		getline(cin, fechafactura);
		cout << "Ingrese idcliente:";
		cin>> id_cliente;
		cin.ignore();
		cout << "Ingrese idempleado:";
		cin >> id_empleado;
		cin.ignore();
		c = Ventas(nit, nombres, apellidos, serie, nofactura, fechafactura, fechaingreso, correo, genero, cantidad, id, id_cliente, id_empleado, id_venta, id_producto, precio_u, telefono);
		c.Modificar();
		break;
	case 3:
		cout << "Ingrese id:";
		cin >> id;
		c = Ventas(nit, nombres, apellidos, serie, nofactura, fechafactura, fechaingreso, correo, genero, cantidad, id, id_cliente, id_empleado, id_venta, id_producto, precio_u, telefono);
		c.Eliminar();

		break;
	case 4:
		c = Ventas(nit, nombres, apellidos, serie, nofactura, fechafactura, fechaingreso, correo, genero, cantidad, id, id_cliente, id_empleado, id_venta, id_producto, precio_u, telefono);
		c.leer();

		break;


	}
	system("pause");

}
void tabla_compras(){
	system("cls");
	int op;
	string nit, nombres, apellidos, fecha_factura, fechaingreso;
	int id=0, no_orden = 0, id_proveedor = 0, id_producto = 0, id_compra = 0, cantidad = 0;
	float precio_u = 0;
	Compras c;
	cout << "Compras" << endl;
	cout << "1.Crear Compras" << endl;
	cout << "2.Modificar Compras" << endl;
	cout << "3.Eliminar Compras" << endl;
	cout << "4.Mostrar Compras" << endl;
	cout << "Ingrese opcion :";
	cin >> op;
	cin.ignore();
	switch (op) {
	case 1:
		system("cls");
		cout << "Ingrese NO_ORDEN:";
		cin >> no_orden;
		cin.ignore();
		cout << "Ingrese idproveedor:";
		cin >> id_proveedor;
		cin.ignore();
		c = Compras(nit, nombres, apellidos, fecha_factura, fechaingreso, id, no_orden, id_proveedor, id_producto, id_compra, cantidad, precio_u);
		c.crear();
		break;
	case 2:
		cout << "Ingrese id:";
		cin >> id;
		cout << "Ingrese NO_ORDEN:";
		cin >> no_orden;
		cin.ignore();
		cout << "Ingrese idproveedor:";
		cin >> id_proveedor;
		cin.ignore();
		cout << "Ingrese fecha-factura:";
		getline(cin, fecha_factura);
		c = Compras(nit, nombres, apellidos, fecha_factura, fechaingreso, id, no_orden, id_proveedor, id_producto, id_compra, cantidad, precio_u);
		c.Modificar();
		break;
	case 3:
		cout << "Ingrese id:";
		cin >> id;

		c = Compras(nit, nombres, apellidos, fecha_factura, fechaingreso, id, no_orden, id_proveedor, id_producto, id_compra, cantidad, precio_u);
		c.Eliminar();

		break;
	case 4:

		c = Compras(nit, nombres, apellidos, fecha_factura, fechaingreso, id, no_orden, id_proveedor, id_producto, id_compra, cantidad, precio_u);

		c.leer();

		break;


	}
	system("pause");
}