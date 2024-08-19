class Triangulo extends Figura{
	public Triangulo (String id, double base, double altura){
		super(id,base,altura);
	}
	
	@Override
	public void CalcularArea(){
		System.out.printf("Figura: Triangulo (" + GetID() + ") \n"); 
		System.out.printf("Formulaa = (base x altura)/2\n"); 
		System.out.printf("Area: %.2f\n", (GetBase()*GetAltura())/2);
	}
}