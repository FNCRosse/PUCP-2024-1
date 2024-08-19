import java.util.Scanner;
class RedireccionamientoE_SConClase{
	public static void main(String [] arg){
		Scanner arch = new Scanner (System.in);
		Persona persona =  new Persona();
		while(arch.hasNext()){
			persona.leerDato(arch);
			persona.imprimirDatos();
		}
	}
}