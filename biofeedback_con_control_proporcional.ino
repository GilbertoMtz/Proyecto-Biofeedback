int TiempoMuestreo = 100;       // tiempo de muestreo Se encuentra en milisegundos
unsigned long pasado = 0;     // tiempo pasado (Se hace para asegurar tiempo de muestreo)
unsigned long ahora;

//Pin analógico para obtener valores deL FSR1
int pinFSR1 = 0;
//Variable para almacenar el valor deL FSR1
int valorFSR1 = 0;
//Pin analógico para obtener valores deL FSR2
int pinFSR2 = 1;
//Variable para almacenar el valor deL FSR2
int valorFSR2 = 0;
//Pin analógico para obtener valores deL FSR3
int pinFSR3 = 2;
//Variable para almacenar el valor deL FSR3
int valorFSR3 = 0;

//Pin digital para controlar un Vibrador1
int pinV1 = 9;
//Variable para almacenar el valor del Vibrador1
int V1Value = 0;
//Pin digital para controlar un Vibrador1
int pinV2 = 10;
//Variable para almacenar el valor del Vibrador1
int V2Value = 0;
//Pin digital para controlar un Vibrador1
int pinV3 = 11;
//Variable para almacenar el valor del Vibrador1
int V3Value = 0;

//Valores mínimo y máximo del FSR
int min = 10;
int max = 1000;

/*-------------------------------------------------------------------
VALORES PID
-------------------------------------------------------------------*/
//Referencia, también llamado SetPoint
float Ref = 255;
//Salida, también llamada Process Variable ó PV
double Y1;
//Salida, también llamada Process Variable ó PV
double Y2;
//Salida, también llamada Process Variable ó PV
double Y3;
//Error1
double error1;
//Error2
double error2;
//Error3
double error3;
//Señal de control1
double U1;
//Señal de control2
double U2;
//Señal de control3
double U3;
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
  Y1 = valorFSR1;

  valorFSR2 = analogRead(pinFSR2);
  valorFSR2 = constrain(valorFSR2, min, max);
  valorFSR2 = map(valorFSR2, min, max, 255, 0);  
  Y2 = valorFSR2;

  valorFSR3 = analogRead(pinFSR3);
  valorFSR3 = constrain(valorFSR3, min, max);
  valorFSR3 = map(valorFSR3, min, max, 255, 0);  
  Y3 = valorFSR3;

  // tiempo actual
  ahora = millis();
  // diferencia de tiempo actual- pasado
  int CambioTiempo = ahora - pasado;
  // si se supera el tiempo de muestreo
  if (CambioTiempo >= TiempoMuestreo)
  {
    //Ejecución de código
    error1 = Ref - Y1;
    Serial.print("error1 = Ref - Y1: ");
    Serial.print(error1);
    Serial.print(" = ");
    Serial.print(Ref);
    Serial.print(" - ");
    Serial.println(Y1);

   U1 = Kp * error1;
    Serial.print("U1 = Kp * error1: ");
    Serial.print(U1);
    Serial.print(" = ");
    Serial.print(Kp);
    Serial.print(" * ");
    Serial.println(error1);

    error2 = Ref - Y2;
    Serial.print("error2 = Ref - Y2: ");
    Serial.print(error2);
    Serial.print(" = ");
    Serial.print(Ref);
    Serial.print(" - ");
    Serial.println(Y2);

    U2 = Kp * error2;
    Serial.print("U2 = Kp * error2: ");
    Serial.print(U2);
    Serial.print(" = ");
    Serial.print(Kp);
    Serial.print(" * ");
    Serial.println(error2);

    error3 = Ref - Y3;
    Serial.print("error3 = Ref - Y3: ");
    Serial.print(error3);
    Serial.print(" = ");
    Serial.print(Ref);
    Serial.print(" - ");
    Serial.println(Y3);

    U3 = Kp * error3;
    Serial.print("U3 = Kp * error3: ");
    Serial.print(U3);
    Serial.print(" = ");
    Serial.print(Kp);
    Serial.print(" * ");
    Serial.println(error3);

    if (U1 < -255)     // límites de saturación de la señal de control
    {
      U1 = -255;
    }
    if (U1 > 255)    // límites de saturación de la señal de control
    {
      U1 = 255;
    }
    //Actualizamos el valor del ledValue
    
    analogWrite(pinV1, U1);
    Serial.println(U1);
    Serial.println("");

    if (U2 < -255)     // límites de saturación de la señal de control
    {
      U2 = -255;
    }
    if (U2 > 255)    // límites de saturación de la señal de control
    {
      U2 = 255;
    }
    //Actualizamos el valor del ledValue
    
    analogWrite(pinV2, U2);
    Serial.println(U2);
    Serial.println("");

    if (U3 < -255)     // límites de saturación de la señal de control
    {
      U3 = -255;
    }
    if (U3 > 255)    // límites de saturación de la señal de control
    {
      U3 = 255;
    }
    //Actualizamos el valor del ledValue
    
    analogWrite(pinV3, U3);
    Serial.println(U3);
    Serial.println("");

    // actualizar tiempo
    pasado = ahora;
  }
}



    
