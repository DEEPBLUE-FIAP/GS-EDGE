#include <LiquidCrystal.h> // Biblioteca para controle do LCD
#include <DallasTemperature.h> // Biblioteca para sensor de temperatura Dallas
#include <OneWire.h> // Biblioteca para comunicação OneWire

OneWire oneWire(3); // Configura o pino 3 para comunicação OneWire
DallasTemperature sensor(&oneWire); // Inicializa o sensor de temperatura Dallas no barramento OneWire

int buzzerLCD = 2; // Pino do buzzer
int ledVermelho = 11; // Pino do LED vermelho
int ledAmarelo = 10; // Pino do LED amarelo
int ledVerde = 9; // Pino do LED verde
int ph = A0; // Pino analógico para leitura do pH
LiquidCrystal lcd(13, 12, 7, 6, 5, 4); // Configuração dos pinos do LCD

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps
  delay(2); // Aguarda 2ms
  sensor.begin(); // Inicializa o sensor de temperatura
  delay(20); // Aguarda 20ms
  pinMode(ledVermelho, OUTPUT); // Define o pino do LED vermelho como saída
  pinMode(ledVerde, OUTPUT); // Define o pino do LED verde como saída
  pinMode(ledAmarelo, OUTPUT); // Define o pino do LED amarelo como saída
  pinMode(buzzerLCD, OUTPUT); // Define o pino do buzzer como saída  
  lcd.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas

  // Arrays de frequências e delays para tocar a música do Mario
  int frequencies[] = {2637, 2637, 2637, 2093, 2637, 3136, 1568};
  int songdelay[] = {100, 100, 200, 200, 100, 200, 320};

  // Toca o som de introdução do Mario
  for (int i = 0; i < 7; i++) {
    delay(songdelay[i]); // Aguarda o tempo especificado no array songdelay
    tone(buzzerLCD, frequencies[i]); // Toca a frequência especificada no array frequencies
    delay(80); // Duração de cada beep
    noTone(buzzerLCD); // Para de tocar o beep
  }
  
  introDisplay(); // Chama a função que exibe a introdução no LCD
}

void loop() {
  sensor.requestTemperatures(); // Solicita a leitura de temperatura do sensor
  float temperature = sensor.getTempCByIndex(0); // Obtém a temperatura em graus Celsius

  // Leitura do potenciômetro e mapeamento para pH
  int potValue = analogRead(ph); // Lê o valor do pino analógico A0
  float pH = map(potValue, 0, 1023, 0, 14); // Mapeia o valor lido para a escala de pH (0-14)

  // Exibição da temperatura no Serial Monitor e no LCD
  Serial.print("Temperatura: ");
  Serial.println(temperature);
  
  lcd.clear(); // Limpa o LCD
  lcd.print("Temp: ");
  lcd.print(temperature); // Exibe a temperatura no LCD
  lcd.print(" C");
  if (temperature > 25) {
    Serial.println("Muito quente");
    lcd.setCursor(0, 1); // Move o cursor para a segunda linha
    lcd.print("Muito quente");
  } 
  else if (temperature <= 25 && temperature > 20) {
    Serial.println("Temperatura ambiente");
    lcd.setCursor(0, 1);
    lcd.print("Temperatura ambiente");
  }
  else {
    Serial.println("Muito frio");
    lcd.setCursor(0, 1);
    lcd.print("Muito frio");
  }
  delay(2000); // Aguarda 2 segundos antes de atualizar novamente

  // Exibição do pH no Serial Monitor e no LCD
  Serial.print("pH: ");
  Serial.println(pH);
  lcd.clear(); // Limpa o LCD
  lcd.print("pH: ");
  lcd.print(pH); // Exibe o pH no LCD
  if (pH >= 6 && pH <= 9) {
    Serial.println("Condições ideais");
    lcd.setCursor(0, 1); // Move o cursor para a segunda linha
    lcd.print("Condicao ideal");
  } 
  else if (pH < 6) {
    Serial.println("Ácido");
    lcd.setCursor(0, 1);
    lcd.print("Acido");
  } 
  else {
    Serial.println("Básico");
    lcd.setCursor(0, 1);
    lcd.print("Basico");
  }
  delay(2000); // Aguarda 2 segundos antes de atualizar novamente
}

void introDisplay() {
  // Função para exibir a introdução no LCD
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
    delay(100); // Aguarda 100ms antes do próximo movimento
    lcd.clear(); // Limpa o display para o próximo movimento
  }
}