import java.util.Scanner;
import java.util.ArrayList;
class UsoDeArrayList{
	public static void main(String [] arg){
		ListaDePersonas lista = new ListaDePersonas();
		lista.leerPersonas();
		lista.mostrarDatos();
		System.out.println();
		lista.ordenar();
		lista.mostrarDatos();
	}
}