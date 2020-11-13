//Fichero generado gracias al canal TutosIngenieria (https://www.youtube.com/channel/UCJxSqZILUQeVE5Ej4sygpWQ)
int TiempoMuestreo = 100;       // tiempo de muestreo Se encuentra en milisegundos
unsigned long pasado = 0;     // tiempo pasado (Se hace para asegurar tiempo de muestreo)
unsigned long ahora;

//Pin analógico para obtener valores deL FSR
int pinFSR1 = 0;
//Variable para almacenar el valor deL FSR
int valorFSR1 = 0;
//Pin digital para controlar un Vibrador1
int pinV1 = 9;
//Variable para almacenar el valor del Vibrador1
int ledValue = 0;
//Valores mínimo y máximo del FSR
int min = 10;
int max = 1000;

/*-------------------------------------------------------------------
VALORES PID
-------------------------------------------------------------------*/
//Referencia, también llamado SetPoint
float Ref = 255;
//Salida, también llamada Process Variable ó PV
double Y;
//Error
double error;
//Señal de control
double U;
//Ganancia proporcional
int Kp = 2;
/*-------------------------------------------------------------------
FIN VALORES PID
-------------------------------------------------------------------*/

void setup()
{
  Serial.begin(9600);
  //pinV1(pinV1, OUTPUT);
}
void loop()
{
  //Obtenemos algún valor de un sensor, en este caso,
  //una fotoresistencia, el resultado es Y
  valorFSR1 = analogRead(pinFSR1);
  valorFSR1 = constrain(valorFSR1, min, max);
  valorFSR1 = map(valorFSR1, min, max, 255, 0);  
  Y = valorFSR1;

  // tiempo actual
  ahora = millis();
  // diferencia de tiempo actual- pasado
  int CambioTiempo = ahora - pasado;
  // si se supera el tiempo de muestreo
  if (CambioTiempo >= TiempoMuestreo)
  {
    //Ejecución de código
    error = Ref - Y;
    Serial.print("error = Ref - Y: ");
    Serial.print(error);
    Serial.print(" = ");
    Serial.print(Ref);
    Serial.print(" - ");
    Serial.println(Y);

    U = Kp * error;
    Serial.print("U = Kp * error: ");
    Serial.print(U);
    Serial.print(" = ");
    Serial.print(Kp);
    Serial.print(" * ");
    Serial.println(error);

    if (U < -255)     // límites de saturación de la señal de control
    {
      U = -255;
    }
    if (U > 255)    // límites de saturación de la señal de control
    {
      U = 255;
    }
    //Actualizamos el valor del ledValue
    
    analogWrite(pinV1, U);
    Serial.println(U);
    Serial.println("");

    // actualizar tiempo
    pasado = ahora;
  }
}
