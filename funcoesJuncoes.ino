/*int ledGreen = 11;
 int ledRed = 10;
 int ledYellow = 9;*/

void attRight_Left(float inclinacaoZ, float inclinacaoX, int ledGreen, int ledRed){
  for(int i = 0; i < 4; i++){
    if(inclinacaoZ <= -30){
      Serial.println("Entrei na condicao, esperando proxima assinatura!");
      digitalWrite(ledGreen, HIGH);
      delay(3000);
      if(inclinacaoZ > 0 && inclinacaoZ <= 12){
        Serial.println("ainda estou no for, RETO!");
        digitalWrite(ledRed, HIGH);
        if(inclinacaoZ >= 25 && inclinacaoZ <=35){
          Serial.println("ainda estou no for, ESQUEDA!");
          digitalWrite(ledRed, HIGH);
          if(inclinacaoX >= 35){
            Serial.println("sai do for");
            break;
          }
        }    
      } 
    }
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
  }
}












