import java.util.Scanner;
import java.util.ArrayList;

class Libreria{
	private String nombre;
	private String direccion;
	private ArrayList<Libro> libros;
	private ArrayList<Cliente> clientes;
	private int cantidadVendida;
	private double totalVendido;

	public Libreria(){
		libros = new ArrayList<Libro>();
		clientes = new ArrayList<Cliente>();
		cantidadVendida =0;
		totalVendido =0.0;
	}

	public void SetNombre(String nombre){
		this.nombre = nombre;
	}
	public String GetNombre(){
		return nombre;
	}
	public void SetDireccion(String direccion){
		this.direccion = direccion;
	}
	public String GetDireccion(){
		return direccion;
	}
	public void SetCantidadVendida(int cantidadVendida){
		this.cantidadVendida = cantidadVendida;
	}
	public int GetCantidadVendida(){
		return cantidadVendida;
	}
	public void SetTotalVendido(double totalVendido){
		this.totalVendido = totalVendido;
	}
	public double GetTotalVendido(){
		return totalVendido;
	}
	
	public void leerLibros(Scanner arch){
		nombre = arch.next();
		direccion = arch.next();
		Libro dato;
		while(true){
			dato = new Libro();
			if(!dato.leerDatos(arch)) break;
			libros.add(dato);
		}
	}
	public void leerClientes(Scanner arch){
		Cliente dato;
		while(true){
			dato = new Cliente();
			if(!dato.leerDatos(arch)) break;
			clientes.add(dato);
		}
	}
	public void ColocarVentas(Scanner arch){
		Venta vt;
		String codLibro;
		while(arch.hasNext()){
			vt = new Venta();
			codLibro = arch.next();
			vt.leerDatos(arch);
			Libro lib = ExisteLaVenta(codLibro);
			if(lib != null){
				lib.PonerVenta(vt);
				cantidadVendida++;
				totalVendido += lib.GetPrecio();
			}
		}
	}
	public Libro ExisteLaVenta(String codLibro){
		for(Libro lib : libros){
			if(lib.GetCodigo().compareTo(codLibro)== 0) return lib;
		}
		return null;
	}
	public void ColocarRankings(){
		for(Libro lib : libros){
			lib.ColocarRanking();
		}
	}
	public void mostrarDatos(){
		System.out.println(nombre);
		System.out.println(direccion);
		System.out.println("RESULTADO DE LAS VENTAS REALIZADAS:");
		System.out.println();
		int i=1;
		for(Libro lib: libros){
			System.out.println("LIBRO NO. "+i);
			lib.mostrarDatos(clientes);
			i++;
		}
		
	}
}