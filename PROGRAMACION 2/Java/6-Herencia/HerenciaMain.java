class Herencia{
	public static void main (String [] arg){
		//Clase padre
		Circulo circulo = new Circulo("CirculoA",56.78);
		System.out.printf("Objeto : %-15s \nRadio: %10.2f\nArea: %10.2f\nPerimetro: %10.2f\n\n",
			circulo.GetID(), circulo.GetRadio(), circulo.area(), circulo.perimetro());
			
		//Clase Hijo - Heredado
		Cilindro cilindro = new Cilindro("CilindroA",56.78,12.7);
		System.out.printf("Objeto : %-15s \nRadio: %10.2f\nAltura: %10.2f\nArea: %10.2f\nPerimetro: %10.2f\nArea de la base: %10.2f\n\n",
			cilindro.GetID(), cilindro.GetRadio(), cilindro.GetAltura(),cilindro.area(), cilindro.perimetro(), cilindro.areaBase());
	}
}