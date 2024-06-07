/*https://portalpnqa.ana.gov.br/indicadores-indice-aguas.aspx#_ftn0
para saber mais sobre a qualidade da água e como ela é medida: acesse o site*/
#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include <OneWire.h>

OneWire oneWire(3);
DallasTemperature sensor(&oneWire); // Temperatura da água

int buzzerLCD = 2;
int ledVermelho = 11;
int ledAmarelo = 10;
int ledVerde = 9;
int ph = A0;
LiquidCrystal lcd(13, 12, 7, 6, 5, 4);

void setup() {
  Serial.begin(9600);
  delay(2);
  sensor.begin();
  delay(20);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(buzzerLCD, OUTPUT);  
  lcd.begin(16, 2);
  
  // ARRAYS DE FREQUÊNCIA E DE DELAY PARA O SOM DE MARIO
  int frequencies[] = {2637, 2637, 2637, 2093, 2637, 3136, 1568};
  int songdelay[] = {100, 100, 200, 200, 100, 200, 320};

  // TOCA O SOM DE INTRODUÇÃO DO MARIO
  for (int i = 0; i < 7; i++) {
    delay(songdelay[i]);
    tone(buzzerLCD, frequencies[i]);
    delay(80); // DURAÇÃO DE CADA BEEP
    noTone(buzzerLCD);
  }
  
  introDisplay();
}

void loop() {
  sensor.requestTemperatures();
  float temperature = sensor.getTempCByIndex(0);
  
  // Leitura do potenciômetro e mapeamento para pH
  int potValue = analogRead(ph);
  float pH = map(potValue, 0, 1023, 0, 14);

  // Exibição da temperatura no Serial Monitor e LCD
  Serial.print("Temperatura: ");
  Serial.println(temperature);
  
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  if (temperature > 25) {
    Serial.println("Muito quente");
    lcd.setCursor(0, 1);
    lcd.print("Muito quente");
  } 
  else if (temperature <= 25 && temperature > 20) {
    Serial.println("Temperatura ambiente");
    lcd.setCursor(0, 1);
    lcd.print("Temperatura ambiente");
  }
  else{
    Serial.println("Muito frio");
    lcd.setCursor(0, 1);
    lcd.print("Muito frio");
  }
  delay(2000); // Atualiza a cada 2 segundos
  // Exibição do pH no Serial Monitor e LCD
  Serial.print("pH: ");
  Serial.println(pH);
  lcd.clear();
  lcd.print("pH: ");
  lcd.print(pH);
  if (pH >= 6 && pH <= 9) {
    Serial.println("Condições ideais");
    lcd.setCursor(0, 1);
    lcd.print("Condicao ideial");
  } 
  else if (pH < 6) {
    Serial.println("Acido");
    lcd.setCursor(0, 1);
    lcd.print("Acido");
  } 
  else {
    Serial.println("Basico");
    lcd.setCursor(0, 1);
    lcd.print("Basico");
  }
  delay(2000); // Atualiza a cada 2 segundos
}

void introDisplay() {
  // MOVE POSIÇÕES

  for (int positionCounter = 0; positionCounter < 9; positionCounter++) {
    if (positionCounter == 0) {
      lcd.setCursor(positionCounter, 0);
      lcd.print("p");
    }
    else if (positionCounter == 1) {
      lcd.setCursor(positionCounter - 1, 0);
      lcd.print("ep");
    }
    else if (positionCounter == 2) {
      lcd.setCursor(positionCounter - 2, 0);
      lcd.print("eep");
    }
    else if (positionCounter == 3) {
      lcd.setCursor(positionCounter - 3, 0);
      lcd.print("Deep");
    }
    else {
      lcd.setCursor(positionCounter - 3, 0);
      lcd.print("Deep");
    }
    lcd.setCursor(15 - positionCounter, 1);
    lcd.print("Blue");
    delay(100);
    lcd.clear(); // Limpa o display para o próximo movimento
  }
}