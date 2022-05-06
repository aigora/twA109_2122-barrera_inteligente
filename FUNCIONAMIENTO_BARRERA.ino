#define LEDAMARILLO 3
#define TRIGGER 5 
#define ECHO 6  
#define BUZZER 9 
  #include <Servo.h> 
     Servo myservo;
     
// Constantes
const float sonido = 34300.0;
const float umbral3 = 20.0; 
 
void setup() {
  Serial.begin(9600);
 
  pinMode(LEDAMARILLO, OUTPUT);
  pinMode(ECHO, INPUT); 
  pinMode(TRIGGER, OUTPUT);  
  pinMode(BUZZER, OUTPUT); 
 myservo.attach(13);  
  
  apagarLEDs();
 
}
 
void loop() {
  iniciarTrigger();
 

  float distancia = calcularDistancia();
 
  apagarLEDs();
 
  {
    // Lanzamos alertas
    alertas(distancia);
  }
 
}
 
// Apaga todos los LEDs
void apagarLEDs()
{
  digitalWrite(LEDAMARILLO, LOW);
  myservo.write(0); //ponemos el servomotor en osicin 0, es decir, la barera estara en posicin horizontal
}
 
void alertas(float distancia)
{
  if (distancia <= umbral3)
  {
    digitalWrite(LEDAMARILLO, HIGH); //encendemos el LED
    tone(BUZZER, 2000, 6000); //hacemos que sene el zumbador
    {myservo.write(90);
    delay (30000);} 

  }
}
float calcularDistancia()
{
  unsigned long tiempo = pulseIn(ECHO, HIGH);

  float distancia = tiempo * 0.000001 * sonido / 2.0;
 
  return distancia;
}
 
void iniciarTrigger()
{
  
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
 
 
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
}

Schematics
Esquema cableado
Fritzing mjfr1wqova
