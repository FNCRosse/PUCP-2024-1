import java.util.Scanner;
import java.util.ArrayList;

class Empresa{
	private ArrayList<Omnibus> flota;
	
	public Empresa(){
		flota = new ArrayList<Omnibus>();
	}
	
	public void LeerDatos(Scanner arch){
		Omnibus omnibus;
		while(true){
			omnibus = new Omnibus();
			if(!omnibus.LeerDatos(arch)) return;
			flota.add(omnibus);
		}
	}
	public void UbicarPasajeros(Scanner arch){
		Pasajero pasajero;
		String tipo;
		while(arch.hasNext()){
			tipo = arch.next();
			if(tipo.compareTo("P")==0) pasajero = new PrimeraClase();
			else pasajero = new ClaseTurista();
			pasajero.leeDatos(arch);
			
			for(Omnibus bus:flota)
				if(bus.SePuedeUbicar(pasajero)) break;
		}
	}
	public void ImprimirDatos(){
		System.out.println("Empresa De Transporte Turistico");
		for(Omnibus o:flota){
			o.ImprimirDatos();
		}
	}
}