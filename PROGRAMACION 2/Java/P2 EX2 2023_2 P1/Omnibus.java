import java.util.Scanner;
import java.util.ArrayList;

class Omnibus{
	private String placa;
	private String chofer;
	private ArrayList<String> ruta;
	private int asientosPC;
	private int asientosCT;
	private ArrayList<Pasajero> pasajeros;
	
	public Omnibus(){
		ruta = new ArrayList<String>();
		pasajeros = new ArrayList<Pasajero>();
	}
	
	public void SetPlaca(String placa){
		this.placa = placa;
	}
	public String GetPlaca(){
		return placa;
	}
	public void SetChofer(String chofer){
		this.chofer = chofer;
	}
	public String GetChofer(){
		return chofer;
	}
	public void SetAsientosPC(int asientosPC){
		this.asientosPC = asientosPC;
	}
	public int GetAsientosPC(){
		return asientosPC;
	}
	public void SetAsientosCT(int asientosCT){
		this.asientosCT = asientosCT;
	}
	public int GetAsientosCT(){
		return asientosCT;
	}
	public void SetCiudad(String ciudad){
		ruta.add(ciudad);
	}

	public boolean LeerDatos(Scanner arch){
		String ciudad;
		placa = arch.next();
		if(placa.compareTo("FIN")==0) return false;
		chofer = arch.next();
		while(!arch.hasNextInt()){
			ciudad = arch.next();
			ruta.add(ciudad);
		}
		asientosPC = arch.nextInt();
		asientosCT = arch.nextInt();
		return true;
	}
	public void ImprimirDatos(){
		System.out.println("Placa: "+placa);
		System.out.println("Chofer: "+chofer);
		System.out.println("Asientos Libros PC: "+asientosPC);
		System.out.println("Asientos Libros CT: "+asientosCT);
		System.out.println("Ruta:");
		for(String ciudad: ruta)
			System.out.print(" "+ciudad);
		System.out.println();
		System.out.println("Pasajeros:");
		int n=1;
		for(Pasajero pas: pasajeros){
			System.out.print(" "+n+") ");
			pas.ImprimirDatos();
			n++;
		}
		for(int i=0;i<100;i++)
			System.out.print("=");
		System.out.println();
		System.out.println();
	}
	public boolean SePuedeUbicar(Pasajero pas){
		String destino, tipo;
		destino = pas.GetDestino();
		tipo = pas.GetTipo();
		if(PasaPor(destino)){
			if(tipo.compareTo("P")==0 && asientosPC>0){
				pasajeros.add(pas);
				asientosPC--;
				return true;
			}
			else if(tipo.compareTo("T")==0 && asientosCT>0){
				pasajeros.add(pas);
				asientosCT--;
				return true;
			}
			else return false;
		}
		return false;
	}
	public boolean PasaPor(String destino){
		for(String ciudad: ruta)
			if(ciudad.compareTo(destino)==0) return true;
		return false;
	}
}