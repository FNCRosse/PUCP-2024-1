import java.util.Scanner;
class Programa{
	public static void main(String []arg){
		Libreria lib = new Libreria();
		Scanner arch = new Scanner (System.in);
		lib.leerLibros(arch);
		lib.leerClientes(arch);
		lib.ColocarVentas(arch);
		lib.ColocarRankings();
		lib.mostrarDatos();
	}
}