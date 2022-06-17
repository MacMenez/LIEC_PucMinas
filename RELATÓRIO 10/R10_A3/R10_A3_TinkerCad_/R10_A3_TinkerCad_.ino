int sensor = A1; //Pino analógico em que o sensor está conectado.
int valorSensor = 0; //Usado para ler o alor do sensor em tempo real

//Configurando o Buzzer
int buzzer = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Taxa do sensor varia entre 0 e 1023. 0 = 0V  |  1023 = 5V
  
  //Lendo a Intensidade da Luz
  int valorSensor = analogRead(sensor);

  //Classificando a Taxa de Luz -> 679 / 4 = 169,75

  //Muito Escuro - P10(Azul) -> 6 - 169,75
  if(valorSensor <= 169.75){

    //Buzzer Ligado - Frequência de 500 Hz
    tone(buzzer, 500);
  
    //Exibindo o valor do sensor no serial monitor.
    Serial.println(valorSensor);
    Serial.println("Muito Escuro");
    delay(100);
  }
  
  //Escuro - P11(Verde) -> 169,76 - 339,5
  if((valorSensor > 169.75) && (valorSensor <= 339.5)){
    
    //Buzzer Ligado - Frequência de 1000 Hz
    tone(buzzer, 1000);
    
    //Exibindo o valor do sensor no serial monitor.
    Serial.println(valorSensor);
    Serial.println("Escuro");
    delay(100);
  }
  
  //Claro - P12(Amarelo) -> 336,51 - 509,25
  if((valorSensor > 339.50) && (valorSensor <= 509.25)){

    //Buzzer Ligado - Frequência de 1500 Hz
    tone(buzzer, 1500);
    
    //Exibindo o valor do sensor no serial monitor.
    Serial.println(valorSensor); 
    Serial.println("Claro");
    delay(100);
  }
  
  //Muito Claro - P13(Vermelho) -> 509,25 - 679
  if((valorSensor > 509.25) && (valorSensor <= 679)){
  
    //Buzzer Ligado - Frequência de 2000 Hz
    tone(buzzer, 2000);
    
    //Exibindo o valor do sensor no serial monitor.
    Serial.println(valorSensor);
    Serial.println("Muito Claro");
    delay(100);
  }
}
