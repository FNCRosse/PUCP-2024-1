import java.util.ArrayList;
class PolimorfismoMain{
	public static void main(String [] arg){
		Cuadrado c1 = new Cuadrado ("cA",2.3,4.5);
		Cuadrado c2 = new Cuadrado ("cB",2,5);
		Cuadrado c3 = new Cuadrado ("cC",12.3,10.5);
		
		Triangulo t1 = new Triangulo("tA",3.4,6);
		Triangulo t2 = new Triangulo("tB",4,7);
		
		ArrayList<Figura> figuras = new ArrayList<>();
		figuras.add(c1);
		figuras.add(t1);
		figuras.add(c2);
		figuras.add(c3);
		figuras.add(t2);
		
		for(Figura f:figuras){
			f.CalcularArea();
		}
	}
}