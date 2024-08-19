import java.util.Scanner;

class Venta{
	private int dni;
	private int calificacion;
	private int fecha;
	
	public Venta(int dni,int calificacion,int fecha){
		this.dni = dni;
		this.calificacion = calificacion;
		this.fecha =fecha;
	}
	public Venta(){
		
	}
	public void SetDni(int dni){
		this.dni = dni;
	}
	public int GetDni(){
		return dni;
	}
	public void SetCalificacion(int calificacion){
		this.calificacion = calificacion;
	}
	public int GetCalificacion(){
		return calificacion;
	}
	public void SetFecha(int fecha){
		this.fecha = fecha;
	}
	public int GetFecha(){
		return fecha;
	}

	
	public void leerDatos(Scanner arch){
		int dd,mm,aa;
		dni = arch.nextInt();
		dd = arch.nextInt();
		mm = arch.nextInt();
		aa = arch.nextInt();
		calificacion = arch.nextInt();
		SetFecha(aa*10000+mm*100+dd);
	}
	public void mostrarDatos(){
		System.out.printf("%12d %-15d %12d\n",dni,fecha,calificacion);
	}
}