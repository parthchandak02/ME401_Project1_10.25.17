void irDetect(){
//  Serial.println("\n\ntargetAngle:");
 // Serial.println("\n\nChecking Distance\n\n");
  newPosition = position;
  
  Kp = 17;
  Kd = 3.0;
  Ki = 0.5;

    //TAKING THE AVERAGE DISTANCE READING AT A POSITION
  p = -200;
  
    while( state != DETECT ){ //takes multiple readings at each position
    
    
      if(p<=220 && flag == false){
        p+=5;
        
        if(p == 200){
          flag = true;
        }
      }
  
      if(p>=-200 && flag == true){
        p-=5;
        
        if(p <= -200){
          flag = false;
          }
        }
//====================================== HARD CODED
        if(p == 100){break;}
//======================================      
        targetAngle = p;
        Serial.println(targetAngle);
        start_time = millis();
        while (millis() < start_time + 50) {
        }//wait 0.01 seconds
        
        Serial.print("Val: ");
        int state = readIRFrequency();
        if (state== NOSIGNAL){
         Serial.println("NO SIGNAL DETECTED");
           digitalWrite(irDetectLEDPin, LOW);
        }
        else if (state == DETECT){
         Serial.println("BEACON DETECTED!");
         digitalWrite(irDetectLEDPin, HIGH);
        }
        
    }

  //determines which way to turn based on the angle at which the greatest value was found
  
  if(p<0){ // turn right
  right();

   start_time = millis();
   while(millis()<start_time+int(abs(p)*encoderToDeg*degToMs)){
    }
  }
  else if(p>0){// turn left
  left();

   start_time = millis();
   while(millis()<start_time+int(abs(p)*encoderToDeg*degToMs)){
    }
  } 
}

int readIRFrequency ()
{
  if (frequency >= 75 && frequency < 135)
    return DETECT;
  else
    return NOSIGNAL;
  
}
