/*
	Se quieren manejar los leds y el display 
    con el potenciometro de la siguiente manera:
	el display tendrá 5 estados desde a hasta e
    (Pueden ser minúsculas o en algunos casos mayúsculas)
    En el estado a: se mostrara la letra en el display y 
    estarán todos los leds apagados.
    En el estado b: se mostrara la letra en el display y 
    se prenderá el led verde.
    En el estado c: se mostrara la letra en el display y 
    se prenderá el led verde y naranja.
    En el estado d: se mostrara la letra en el display y 
    se prenderá el led verde, naranja y azul.
    En el estado e: se mostrara la letra en el display y 
    todos los leds.
    Pulsador 2: encendera y apagara el sistema(leds y display).
    (Punto extra)Pulsador 1: Deberá activar la una secuencia 
    completa de encendido del sistema.
    Nota: se valorara el uso de funciones propias.
*/

int pontenciometroValue=0;
#define ROJO A3
#define NARANJA A1
#define AZUL A2
#define VERDE A0

#define A 12
#define B 11
#define C 10
#define D 9
#define E 8
#define F 7
#define G 6
#define P1 4
#define P2 2
int btnUno=0;
int btnDos=0;

void setup()
{
  Serial.begin(9600);
  pinMode(ROJO, OUTPUT);
  pinMode(NARANJA, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
}


void imprimirDisplay(int potenciometro)
{
  for(int i=6; i<13; i++){
    digitalWrite(i,LOW);
  }
  
	switch (potenciometro)
    {
    	case 1:
      		digitalWrite(A, HIGH);
      		digitalWrite(B, HIGH);
      		digitalWrite(C, HIGH);
      		digitalWrite(G, HIGH);
      		digitalWrite(E, HIGH);
      		digitalWrite(F, HIGH);
      		break;

      	case 2:
      		digitalWrite(F, HIGH);
      		digitalWrite(C, HIGH);
      		digitalWrite(D, HIGH);
    		digitalWrite(E, HIGH);
      		digitalWrite(G, HIGH);
      		break;
      
      	case 3:
      		digitalWrite(A, HIGH);
      		digitalWrite(F, HIGH);
      		digitalWrite(E, HIGH);
    		digitalWrite(D, HIGH);
      		//c
      		break;
      	case 4:
      		digitalWrite(B, HIGH);
      		digitalWrite(C, HIGH);
      		digitalWrite(D, HIGH);
      		digitalWrite(E, HIGH);
      		digitalWrite(G, HIGH);
      		break;
      	case 5:
      		digitalWrite(A, HIGH);
      		digitalWrite(G, HIGH);
      		digitalWrite(D, HIGH);
      		digitalWrite(F, HIGH);
      		digitalWrite(E, HIGH);
      		break;
      	case 0:
			digitalWrite(A, LOW);
      		digitalWrite(B, LOW);
      		digitalWrite(C, LOW);
      		digitalWrite(D, LOW);
      		digitalWrite(E, LOW);
      		digitalWrite(F, LOW);
      		digitalWrite(G, LOW);
      		break;
    }

}

void ledEncender(int r, int n, int a,int ve,int tiempo)
{
	digitalWrite(ROJO,r);
  	//delay(tiempo);
    digitalWrite(AZUL,a);
  	//delay(tiempo);
    digitalWrite(NARANJA,n);
  	//delay(tiempo);
    digitalWrite(VERDE,ve);
  	delay(tiempo);
}



void secuencia(int tiempo)
{
	digitalWrite(ROJO,1);
  	delay(tiempo);
    digitalWrite(AZUL,1);
  	delay(tiempo);
    digitalWrite(NARANJA,1);
  	delay(tiempo);
    digitalWrite(VERDE,1);
  	delay(tiempo);
	digitalWrite(ROJO,0);
  	delay(tiempo);
    digitalWrite(AZUL,0);
  	delay(tiempo);
    digitalWrite(NARANJA,0);
  	delay(tiempo);
    digitalWrite(VERDE,0);
  	delay(tiempo);
}

void loop()
{

  btnUno= digitalRead(P1);
  btnDos= digitalRead(P2);
  pontenciometroValue=map(analogRead(A4),0,1023,0,5);
  Serial.println(pontenciometroValue);
  //imprimirDisplay(pontenciometroValue);
  if (pontenciometroValue==1)
  {
    //a
    imprimirDisplay(pontenciometroValue);
  	ledEncender(0,0,0,0,0);
  }
  else if(pontenciometroValue==2)
  {
    //b
    imprimirDisplay(pontenciometroValue);
	ledEncender(0,0,0,1,0);
  }
  else if(pontenciometroValue==3)
  {
    //c
    imprimirDisplay(pontenciometroValue);
	ledEncender(0,1,0,1,0);
  }
  else if(pontenciometroValue==4)
  {
    //d
    imprimirDisplay(pontenciometroValue);
	ledEncender(0,1,1,1,0);
  }
  else if(pontenciometroValue==5)
  {
    //e
    imprimirDisplay(pontenciometroValue);
	ledEncender(1,1,1,1,0);
  }
  
  if (btnUno==0)
  {
    //boton 1 inicia secuencia
  	secuencia(1000);
  
  }
  
    if (btnDos==0)
  {
    //boton 2 apaga display y led 
  	imprimirDisplay(0);
    ledEncender(0,0,0,0,5000);
    
  
  }
  
	
  
}