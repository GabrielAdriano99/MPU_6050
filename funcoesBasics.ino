void movimentFront(float inclinacaoX){
  if(inclinacaoX > -45) {
    Serial.println("FRENTE");
  }
}

void movimentBack(float inclinacaoX){
  if(inclinacaoX >= 30  && inclinacaoX <= 35) {
    Serial.println("TRAS");
  }
}

void movimentLeft(float inclinacaoZ){
  if(inclinacaoZ > 35){
    Serial.println("ESQUERDA");
  }
}

void movimentRight(float inclinacaoZ){
  if(inclinacaoZ > -35) {
    Serial.println("DIREITA");
  }
}

