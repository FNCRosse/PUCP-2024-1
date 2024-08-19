class ClasesYObjetos{
	public static void main(String [] arg){
		Persona persona;
		Persona persona2 = new Persona();
		
		persona =  new Persona(22443253,"Ivan martines",34355.34);
		persona.imprimirDatos();
		
		persona2.SetDni(576839234);
		persona2.SetNombre("Wunder te quiero");
		persona2.SetSueldo(245545.466);
		persona2.imprimirDatos();
		
		Persona persona3 =  new Persona(persona2);
		// persona3 = persona2;//Las clases se puede copiar con = 
		/*En caso usar = : Si le cambio algo se cambia en ambos, 
		por que ambos tiene la misma memoria*/
		persona3.imprimirDatos();
		persona3.SetDni(111111111);
		persona3.imprimirDatos();
		persona2.imprimirDatos();
	}
}