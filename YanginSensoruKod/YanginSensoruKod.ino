
#define SENSOR_AO A0
#define SENSOR_DO 2
#define LED_PIN 8
#define BUZZER_PIN 9

int gazDegeri = 0;
int esikDegeri = 350;  // Bu değerle hassasiyet ayarlanabilir (0–1023 arası)

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_AO, INPUT);             
  pinMode(SENSOR_DO, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Gaz ve Duman Algılama Sistemi Baslatildi...");
}

void loop() {
  gazDegeri = analogRead(SENSOR_AO);
  Serial.print("Gaz/Duman Degeri: ");
  Serial.println(gazDegeri);

  if (gazDegeri > esikDegeri) {
    digitalWrite(LED_PIN, HIGH);
    analogWrite(BUZZER_PIN, 120);  // PWM ile voltajı düşür (yaklaşık 2.3V)
    delay(200);
    analogWrite(BUZZER_PIN, 0);
    delay(100);
  } else {
    digitalWrite(LED_PIN, LOW);
    analogWrite(BUZZER_PIN, 0);
  }

  delay(200);
}
