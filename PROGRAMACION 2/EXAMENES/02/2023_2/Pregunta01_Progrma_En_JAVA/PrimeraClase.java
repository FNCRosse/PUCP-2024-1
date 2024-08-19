import java.util.Scanner;
import java.util.ArrayList;

class PrimeraClase extends Pasajero{
	private ArrayList<String> articulosSolicitados;
	
	public PrimeraClase(){
		articulosSolicitados = new ArrayList<String>();
	}
	@Override
	public String GetTipo(){
		return "P";
	}
	@Override
	public void leeDatos(Scanner arch){
		int numArt;
		String art;
		super.leeDatos(arch);
		numArt = arch.nextInt();
		for(int i=0;i<numArt;i++){
			art = arch.next();
			articulosSolicitados.add(art);
		}
	}
	@Override
	public void ImprimirDatos(){
		super.ImprimirDatos();
		System.out.println("Articulos Solicitados:");
		System.out.printf("Cantidad: %d Articulos: ",articulosSolicitados.size());
		for(String art : articulosSolicitados){
			System.out.printf("-%8s",art);
		}
		System.out.println();
	}
}