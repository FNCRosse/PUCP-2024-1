import java.util.Scanner;
import java.util.ArrayList;

class Libro{
	private String codigo;
	private String titulo;
	private String autor;
	private double precio;
	private ArrayList<Venta> ventas;
	private int suma;
	private int ranking;
	private double totalVendido;
	
	public Libro(){
		ventas = new ArrayList<Venta>();
		suma =0;
		ranking =0;
		totalVendido=0;
	}

	public void SetCodigo(String codigo){
		this.codigo = codigo;
	}
	public String GetCodigo(){
		return codigo;
	}
	public void SetTitulo(String titulo){
		this.titulo = titulo;
	}
	public String GetTitulo(){
		return titulo;
	}
	public void SetAutor(String autor){
		this.autor = autor;
	}
	public String GetAutor(){
		return autor;
	}
	public void SetPrecio(double precio){
		this.precio = precio;
	}
	public double GetPrecio(){
		return precio;
	}
	public void SetSuma(int suma){
		this.suma = suma;
	}
	public int GetSuma(){
		return suma;
	}
	public void SetRanking(int ranking){
		this.ranking = ranking;
	}
	public int GetRanking(){
		return ranking;
	}
	public void SetTotalVendido(double totalVendido){
		this.totalVendido = totalVendido;
	}
	public double GetTotalVendido(){
		return totalVendido;
	}
	
	public boolean leerDatos(Scanner arch){
		codigo = arch.next();
		if(codigo.compareTo("FIN")==0)return false;
		titulo = arch.next();	
		autor = arch.next();
		precio = arch.nextDouble();	
		return true;
	}
	public void mostrarDatos(ArrayList<Cliente> clientes){
		System.out.printf("CODIGO:%-12s TITULO:%-40s Autor:%-30s PRECIO:%2.2f\n",codigo,titulo,autor,precio);
		System.out.printf("LIBRO VENDIDOS:%10d RANKING:%10d\n",ventas.size(),ranking);
		System.out.println();
		System.out.println("VENTAS REALIZADAS:");
		int i=1;
		for(Venta vt: ventas){
			System.out.printf("No. %d  DNI: %d  NOMBRE: ",i,vt.GetDni());
			String nombre = BuscarNombre(clientes,vt.GetDni());
			System.out.printf("%-30s  CALIFICACION: %d\n",nombre,vt.GetCalificacion());
			i++;
		}
	}
	public String BuscarNombre(ArrayList<Cliente> clientes,int dni){
		for(Cliente cli: clientes){
			if(cli.GetDni() == dni) return cli.GetNombre();
		}
		return null;
	}
	public void PonerVenta(Venta vt){
		ventas.add(vt);
		suma = suma + vt.GetCalificacion();
		totalVendido += precio;
	}
	public void ColocarRanking(){
		if( ventas.size() == 0){
			ranking =0;
			return;
		}
		double prom = suma / ventas.size();
		if(prom < 25) ranking = 1;
		else if (prom >= 25 && prom< 50 ) ranking = 2;
		else if (prom >= 50 && prom< 75 ) ranking = 3;
		else ranking = 4;
	}
}