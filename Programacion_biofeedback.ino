/* FSR testing sketch.  
   
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */

int fsr1AnalogPin = 0; // FSR estan conectados a los pines 0,1,3
int fsr2AnalogPin = 1;
int fsr3AnalogPin = 3;
int V1pin = 8; // conectar vibrador al pin 8,9,10 (PWM pin)
int V2pin = 9;
int V3pin = 10;
int fsr1Reading; // lectura analoga del sensor FSR resistor divider
int fsr2Reading;
int fsr3Reading;
int V1Intensidad; //Respuesta del vibrador
int V2Intensidad;
int V3Intendidad;

void setup(void) {
Serial.begin(9600); // Declaramos las salidas de los vibradores
pinMode(V1pin, OUTPUT);
pinMode(V2pin, OUTPUT);
pinMode(V3pin, OUTPUT);
 }
 
void loop(void) {
fsr1Reading = analogRead(fsr1AnalogPin);   //Lectura de los sensores
Serial.print("Analog reading 1 = ");
Serial.println(fsr1Reading);

fsr2Reading = analogRead(fsr2AnalogPin);
Serial.print("Analog reading 2 = ");
Serial.println(fsr2Reading);

fsr3Reading = analogRead(fsr3AnalogPin);
Serial.print("Analog reading 3 = ");
Serial.println(fsr3Reading);

// we'll need to change the range from the analog reading (0-1023) down to the range
// used by analogWrite (0-255) with map!
V1Intensidad = map(fsr1Reading, 0, 1023, 0, 255);    //Cambio de la señal analoga (0-1023) a digital pwm (0-255)
// LED gets brighter the harder you press
analogWrite(V1pin, V1Intensidad);                    //Salida intendisad de vibracion
Serial.print("PWM V1 = ");
Serial.println(V1Intensidad);

V2Intensidad = map(fsr2Reading, 0, 1023, 0, 255);
// LED gets brighter the harder you press
analogWrite(V2pin, V2Intensidad);
Serial.print("PWM V2 = ");
Serial.println(V2Intensidad);

V3Intensidad = map(fsr3Reading, 0, 1023, 0, 255);
// LED gets brighter the harder you press
analogWrite(V3pin, V3Intensidad);
Serial.print("PWM V3 = ");
Serial.println(V3Intensidad);
 
delay(100);
 }
