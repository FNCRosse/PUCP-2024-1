import java.util.Scanner;
import java.util.ArrayList;
import java.util.Comparator;

class ListaDePersonas{
	private ArrayList <Persona> Lista;
	
	public ListaDePersonas(){
		Lista = new ArrayList<Persona>();
	}
	
	public void leerPersonas(){
		Scanner arch =  new Scanner (System.in);
		Persona persona;
		while(arch.hasNext()){
			persona =  new Persona();
			persona.leerDato(arch);
			Lista.add(persona);
		}
	}
	public void mostrarDatos(){
		for(Persona per: Lista)
			per.imprimirDatos();
	}
	public void ordenar(){
		Lista.sort(Comparator.comparing(Persona::GetDni));
	}
}