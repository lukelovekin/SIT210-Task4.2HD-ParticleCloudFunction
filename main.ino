
int red = D6;
int green = D4;
int blue = D2;

int lightSwitch(String color);

void setup() {

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  Particle.function("ledColor", lightSwitch);

}


void loop() {
 
}

void allColorsOff(){
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}

int lightSwitch(String color){
    allColorsOff();

    if(color == "red"){
      digitalWrite(red, HIGH);
      Particle.publish("ChangeLED", color);
      return 1;
    }else if(color == "green"){
      digitalWrite(green, HIGH);
      Particle.publish("ChangeLED", color);
      return 1;
    }else if(color == "blue"){
      digitalWrite(blue, HIGH);
      Particle.publish("ChangeLED", color);
      return 1;
    }else{
        return -1;
    }
}