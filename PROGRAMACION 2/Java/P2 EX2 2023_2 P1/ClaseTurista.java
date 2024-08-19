import java.util.Scanner;

class ClaseTurista extends Pasajero{
	private boolean valija;
	private boolean almuerzo;
	private double tarifaExtra;

	public ClaseTurista(){
		valija = false;
		almuerzo = false;
		tarifaExtra = 0.0;
	}
	
	public void SetValija(boolean valija){
		this.valija = valija;
	}
	public boolean GetValija(){
		return valija;
	}
	public void SetAlmuerzo(boolean almuerzo){
		this.almuerzo = almuerzo;
	}
	public boolean GetAlmuerzo(){
		return almuerzo;
	}
	public void SetTarifaExtra(double tarifaExtra){
		this.tarifaExtra = tarifaExtra;
	}
	public double GetTarifaExtra(){
		return tarifaExtra;
	}
	@Override
	public String GetTipo(){
		return "T";
	}
	@Override
	public void leeDatos(Scanner arch){
		String SN;
		super.leeDatos(arch);
		SN = arch.next();
		if(SN.compareTo("S")==0){
			valija = true;
			tarifaExtra += 85.50;
		} 
		else valija = false;
		SN = arch.next();
		if(SN.compareTo("S")==0){
			almuerzo = true;
			tarifaExtra += 55.90;
		} 
		else almuerzo = false;
		
		
	}
	@Override
	public void ImprimirDatos(){
		super.ImprimirDatos();
		System.out.print("   Clase Turista - Extras: ");
		if(valija) System.out.print("   Valija");
		if(almuerzo) System.out.print("   Almuerzo");
		System.out.println(" - Tarifa Extra: "+tarifaExtra);
	}
}