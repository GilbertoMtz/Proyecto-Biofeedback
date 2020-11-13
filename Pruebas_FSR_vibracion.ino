
 
int fsrAnalogPin = 0; // FSR esta en analogo 0
int Vpin = 11;      // vibrador en pin 11 (PWM pin)
int fsrReading;      // lectura del sensor FSR
int VIntensidad;
 
void setup(void) {
  Serial.begin(9600);   
  pinMode(Vpin, OUTPUT);
}
 
void loop(void) {
  fsrReading = analogRead(fsrAnalogPin); //lectura del fsr
  Serial.print("Analogo entrada = ");    //lectura del fsr en el monitor serie
  Serial.println(fsrReading);
 

  VIntensidad = map(fsrReading, 0, 983, 0, 255);   //Con Map cambio de analogo (0-1023) a digital pwm (0-255) Se normalizo la entrada de datos la cual variaba de 0-983 como maxima en vez de 0-1023
  // La vibracion se incrementara si se presiona con fuerza el sensor
  analogWrite(Vpin, VIntensidad);
  Serial.print("PWM = ");
  Serial.println(VIntensidad);
 
  delay(100);
}
