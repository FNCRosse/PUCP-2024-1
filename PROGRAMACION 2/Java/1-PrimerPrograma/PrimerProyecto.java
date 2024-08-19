class PrimerProyecto{
	//Es importante hacer el main
	public static void main(String[]arg){
		//Declaracion de variables (igual a c)
		int a =23;
		double x=376.87;
		String nombre = "Juan Perez";
		boolean activo = true;
		//Para comparar string
		int cmp = nombre.compareTo("Maria");
		//Opciones para imprimir
		System.out.println("A= "+ a);
		System.out.printf("A= %4d\n", a);//Se puede poner formato
		System.out.println("X=" + x);
		System.out.println("Nombre=" + nombre);
		System.out.println("Activo=" + activo);
		
		if(cmp == 0)System.out.println("son iguales");
		else if(cmp > 0)System.out.println("Es mayor que Maria");
		else System.out.println("Es menor que Maria");
		
	}
}