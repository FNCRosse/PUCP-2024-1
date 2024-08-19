class Cilindro extends Circulo{
	//Nuevas variables
	private double altura;
	
	//Constructor
	public Cilindro(String i, double r, double a){
		super(i,r);
		altura = a;
	}
	
	//Metodos Selectivos
	public void SetAltura (double a){
		altura = a;
	}
	public double GetAltura(){
		return altura;
	}
	
	//Otros metodos
	//Indicar que estamos sobreescribiendo funciones
	@Override
	public double area(){
		//Es como llamar Circulo::area();
		//Solo se usa el super en la misma funcion sobreescrita
		return 2*super.area()+altura*perimetro();
	}
	
	//Hacer una mascara
	//No podemos usar la misma funcion que la del padre(Circulo::area)
	public double areaBase(){
		return super.area();
	}
	public double volumen(){
		return super.area()*altura;
	}
}