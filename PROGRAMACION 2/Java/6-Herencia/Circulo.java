
class Circulo{
	private String id;
	private double radio;
	private final double PI=3.141592;
	
	//Constructores
	public Circulo(){
		radio = 0.0;
	}
	public Circulo(String i, double r){
		id = i;
		radio = r;
	}
	
	//Metodos Selectores
	public void SetID (String i){
		id = i;
	}
	public String GetID(){
		return id;
	}
	public void SetRadio (double r){
		radio = r;
	}
	public double GetRadio(){
		return radio;
	}
	
	//Metodos publicos
	public double area(){
		return PI*radio*radio;
	}
	public double perimetro(){
		return 2*PI*radio;
	}
}