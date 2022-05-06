// Libreria del servomotor

#include <Servo.h>

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

Servo barrera;
const int pulsoMin = 500, pulsoMax = 2400;
LiquidCrystal_I2C lcd (0x3F, 2, 1, 0, 4, 5, 6, 7);

//Los numeros de pines UTILIZADOS SON:

const int trigger= 3, echo = 4, led = 5, buzzer = 6, btnBarrera = 7, pinservo = 9;
long tiempo= 1000;
int distancia = 501;
int estado = -1, contador = 0;

void setup(){
pinMode(trigger, OUTPUT);
pinMode (echo,INPUT);
pinMode (led, OUTPUT);
pinMode (buzzer, OUTPUT);
pinMode (btnBarrera, INPUT);
pinMode(pinServo, OUTPUT);

\\INICIALIZACION DEL SERVOMOTOR(PARTE ALVARO Y HUGO)//
barrera.attach (pinServo, pulsoMin, pulsoMaX);
lcd.setBacklightPin(3,POSITIVE);
lcd.setBacklightPin(HIGH);
lcd.begin (16,2);
lcd.clear();

void loop (){

switch (estado) { 

 case -1:
{
distancia = calcularDistancia();
lcd.setCursor (0,0);
lcd.print("presentamos a");
delay(1000);
lcd.setCursor (2,1);
lcd.print ("Barrera intel"),
delay (1000);
estado = 0;
lcd.clear();
}
break;
//estado espera  
case 0:
{
//50 milisegundos es el tiempo entre lecturas
delay (50);
distancia = calcularDistancia();

lcd.setCursor (4,0);
lcd.print("esperando...");
lcd.setCursor(0,1);
lcd.print("salieron= ");
lcd.setCursor(9,1);
lcd.print(contador);
  
if(distancia<=5)
{
  estado=1;
  lcd.clear();
}

}
break;
case 1:
{
 digitalWrite(led,HIGH);
 distancia=calcularDistancia();
 if(distancia <=5)
 {
  lcd.setCursor(4,0);
  lcd.print("vehiculo");
  lcd.setCursor(0,1);
  lcd.print("[VERDE]=levantar");
  if(digitalRead(btnBarrera)}
  {
   digitalWrite(led,LOW);
   lcd.clear();
   estado=2;
   while(digitalRead(btnBarrera));
  }
}
else
{
  digitalWrite(led,LOW);
  lcd.clear();
  estado=0;
  }
}
break;
case 2:
{
  lcd.setCursor(0,0);
  lcd.print("vehiculo");
  lcd.setCursor(0,1);
  lcd.print("Saliendo CUIDADO");
  accionarBarrera();
  lcd.clear();
  estado=0;
  contador++;
}
break;
}

}
int calcularDistancia()
{
  digitalWrite (trigger,LOW);
  delayMicroseconds(10);
  digitalWrite(trigger,HIGH);
  tiempo=pulseIn(echo,HIGH);
  tiempo=tiempo/2;
  return int(0.034 * tiempo);
}
void accionarBarrera()
{
  barrera.write(0);
  for(int i=0; i<=10;i++)
  {
    tone(buzzer,1024);
    digitalWrite(led,HIGH);
    delay(100);
    
    noTone(buzzer);
    digitalWrite(led,LOW);
    delay(100);
    
    tone(buzzer,400);
    digitalWrite(led,HIGH);
    delay(200);

    noTone(buzzer);
    digitalWrite(led,LOW);
    delay(200);
  }
  barrera.write(90);
}


  
