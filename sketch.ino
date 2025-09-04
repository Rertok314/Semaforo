const int pinoLedVermelho = 8;
const int pinoLedAmarelo = 9;
const int pinoLedVerde = 10;
const int botao = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
    sinalVermelho();
    sinalVerde();
    sinalAmarelo();
}

void botaoApertado() {
    sinalAmarelo();
}

void sinalVermelho() {
  digitalWrite(pinoLedVermelho, HIGH);
  delay(5000);
  digitalWrite(pinoLedVermelho, LOW);
}

void sinalVerde() {
    digitalWrite(pinoLedVerde, HIGH);
    for (int i=0; i<1000; i++) {  
      int estadoBotao = digitalRead(botao);
      if (estadoBotao==0){
        Serial.println(estadoBotao);
        i=1000;
        delay(500);
      }
      else {
        Serial.println(estadoBotao);
        delay(5);
        }
    }
    digitalWrite(pinoLedVerde, LOW);
}

void sinalAmarelo() {
  for(int i=0; i<4; i++){
    digitalWrite(pinoLedAmarelo, HIGH);
    delay(1000);
    digitalWrite(pinoLedAmarelo, LOW);
    delay(1000);
  }
}