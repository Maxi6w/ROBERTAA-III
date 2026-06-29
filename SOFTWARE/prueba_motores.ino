// Pines de los motores
const int M1_RPWM = 4;
const int M1_LPWM = 18;

const int M2_RPWM = 13;
const int M2_LPWM = 14;

const int M3_RPWM = 21;
const int M3_LPWM = 19;

const int M4_RPWM = 23;
const int M4_LPWM = 22;

// Configuración PWM
const int freq = 1000;
const int resolution = 8;

// Canales PWM
const int CH_M1_R = 0;
const int CH_M1_L = 1;
const int CH_M2_R = 2;
const int CH_M2_L = 3;
const int CH_M3_R = 4;
const int CH_M3_L = 5;
const int CH_M4_R = 6;
const int CH_M4_L = 7;

void setup() {
  Serial.begin(115200);
  
// LedAttach sirve pra configurar la modulación por ancho de pulso (PWM) en un pin especifico del esp32
  ledcAttach(M1_RPWM, freq, resolution);
  ledcAttach(M1_LPWM, freq, resolution);

  ledcAttach(M2_RPWM, freq, resolution);
  ledcAttach(M2_LPWM, freq, resolution);

  ledcAttach(M3_RPWM, freq, resolution);
  ledcAttach(M3_LPWM, freq, resolution);

  ledcAttach(M4_RPWM, freq, resolution);
  ledcAttach(M4_LPWM, freq, resolution);

  Serial.println("Iniciando prueba de motores...");
}

void probarMotor(int rpwm, int lpwm, const char* nombre) {

  Serial.print("Probando ");
  Serial.println(nombre);

  ledcWrite(rpwm, 0);
  ledcWrite(lpwm, 0);

  for (int vel = 0; vel <= 128; vel += 4) {
    ledcWrite(rpwm, vel);
    delay(100);
  }

  delay(2000);

  ledcWrite(rpwm, 0);
  delay(1000);
}

void loop() {

  probarMotor(M1_RPWM, M1_LPWM, "Motor 1");
  probarMotor(M2_RPWM, M2_LPWM, "Motor 2");
  probarMotor(M3_RPWM, M3_LPWM, "Motor 3");
  probarMotor(M4_RPWM, M4_LPWM, "Motor 4");

  Serial.println("Prueba finalizada.");
  while (true);
}
