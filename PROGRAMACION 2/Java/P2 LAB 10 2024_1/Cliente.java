import java.util.Scanner;

class Cliente{
	private int dni;
	private String nombre;
	private double totalGastado;
	
	public Cliente(int dni,String nombre,double totalGastado){
		this.dni = dni;
		this.nombre = nombre;
		this.totalGastado =totalGastado;
	}
	public Cliente(){
		dni = 0;
		totalGastado = 0.0;
	}
	public void SetDni(int dni){
		this.dni = dni;
	}
	public int GetDni(){
		return dni;
	}
	public void SetNombre(String nombre){
		this.nombre = nombre;
	}
	public String GetNombre(){
		return nombre;
	}
	public void SetTotalGastado(double totalGastado){
		this.totalGastado = totalGastado;
	}
	public double GetTotalGastado(){
		return totalGastado;
	}
	
	public boolean leerDatos(Scanner arch){
		dni = arch.nextInt();
		if(dni == 0) return false;
		nombre = arch.next();	
		return true;
	}
	public void mostrarDatos(){
		System.out.printf("%12d %-40s %10.2f\n",dni,nombre,totalGastado);
	}
}