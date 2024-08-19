class Cuadrado extends Figura{
	public Cuadrado(String id, double base, double altura){
		super(id,base,altura);
	}
	
	@Override
	public void CalcularArea(){
		System.out.printf("Figura: Cuadrado (" + GetID() + ") \n"); 
		System.out.printf("Formulaa = (base x altura)\n"); 
		System.out.printf("Area: %.2f\n", (GetBase()*GetAltura()));
	}
}