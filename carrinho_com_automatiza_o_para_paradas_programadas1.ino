float cm,duracao; // comprimento da onda
const int trig = 8; // transmissao
const int echo = 9; // recepcao

const int motor = 11; // porta 11 utilizada pelos 2 motores

void setup() {
  Serial.begin(9600);
  pinMode(motor, OUTPUT); 
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
}

void loop() {
  cm =  distancia(); // distancia em centímetros
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.print("Cm: ");
  Serial.println();
  
  if(cm > 45) { // se a distância captada pelo sensor for maior
    digitalWrite (motor, HIGH); // liga o motor
  }  
  else {
    digitalWrite (motor, LOW); // desliga o motor
  } 
  delay(5000);
}

// funcao que calcula distancia
float distancia()
{  
  // apenas para limpar o pino transmissor, cortar o sinal e aguardar 5us segundos  
  // (recomendado p/ melhor funcionamento) 
  digitalWrite(trig, LOW);
  delayMicroseconds(5); 
   
  digitalWrite(trig, HIGH); // envio do pulso de ultrassom
  
  delayMicroseconds(10);  // aguarda 10 microsegundos / tempo para o pulso ir e voltar para a leitura
  
  digitalWrite(trig, LOW); // desliga o pino que envia para habiliar o pino que recebe
 
  duracao = pulseIn(echo, HIGH); // calcula a duracao em microsegundos do pulso para ir e voltar
  
  // velocidade do som 343 m/s -> 34300 cm / 1000000 us -> 0.00343
  float calcDistancia= (duracao/2) * 0.0343; // em centímetro
  if (calcDistancia>=331){ // fora do limite do sensor
      calcDistancia=0;
  }
  return calcDistancia;  
}

