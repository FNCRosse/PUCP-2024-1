import java.util.Scanner;
class Programa{
	public static void main(String [] arg){
		Empresa empresa = new Empresa();
		Scanner arch = new Scanner(System.in);
		empresa.LeerDatos(arch);
		empresa.UbicarPasajeros(arch);
		empresa.ImprimirDatos();
	}
}