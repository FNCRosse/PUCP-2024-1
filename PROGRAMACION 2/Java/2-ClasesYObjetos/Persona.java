class Persona{
	private int dni;
	private String nombre;
	private double sueldo;
	//Constructores
	public Persona(){
		sueldo = 0.0;
	}
	public Persona(int dni, String nombre, double sueldo){
		this.dni = dni;
		this.nombre = nombre;
		this.sueldo = sueldo;
	}
	public Persona(Persona per){
		asignar(per);
	}
	//Destructor
	//No se implementa, se encarga el recolector de basura
	
	//Metodo selectores
	public void SetDni(int d){
		dni = d;
	}
	public int GetDni(){
		return dni;
	}
	public void SetNombre(String n){
		nombre = n;
	}
	public String GetNombre(){
		return nombre;
	}
	public void SetSueldo(double s){
		sueldo = s;
	}
	public double GetSueldo(){
		return sueldo;
	}
	public void imprimirDatos(){
		System.out.printf("%10d %-30s %10.2f\n",dni,nombre,sueldo);
	}
	public void asignar(Persona per){
		this.dni = per.dni;
		this.nombre = per.nombre;
		this.sueldo = per.sueldo;
	}
}