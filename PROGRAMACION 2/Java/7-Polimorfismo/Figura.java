abstract class Figura{
	//variables
	private String id;
	private double base;
	private double altura;
	
	//Constructor
	public Figura(String id, double base, double altura){
		this.id = id;
		this.base = base;
		this.altura = altura;
	}
	
	//Metodo selectores
	public void SetID(String id){
		this.id=id;
	}
	public String GetID(){
		return id;
	}public void SetBase(double base){
		this.base = base;
	}
	public double GetBase(){
		return base;
	}
	public void SetAltura(double altura){
		this.altura = altura;
	}
	public double GetAltura(){
		return altura;
	}
	
	//Remplazar el virtual por abstract
	public abstract void CalcularArea();
}