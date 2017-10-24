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
    
    
      if(p<=200 && flag == false){
        p+=5;
        
        if(p == 200){
          flag = true;
        }
      }
  
      if(p>=0 && flag == true){
        p-=5;
        
        if(p == 0){
          flag = false;
          }
        }
        
        targetAngle = p;
      
        start_time = millis();
        while (millis() < start_time + 50) {
        }//wait 0.01 seconds
        
        Serial.print("Val: ");
        int state = readIRFrequency();
        if (state== NOSIGNAL){
         Serial.println("NO SIGNAL DETECTED");
        }
        else if (state == DETECT){
         Serial.println("BEACON DETECTED!");
        }
        
    }

  //determines which way to turn based on the ongle at which the greatest value was found
  
  if(p<0){ // turn right
   myServoL.writeMicroseconds(1700);
   myServoR.writeMicroseconds(1700);

   start_time = millis();
   while(millis()<start_time+int(abs(p)*encoderToDeg*degToMs)){
    }
  }
  else if(p>0){// turn left
   myServoL.writeMicroseconds(1300);
   myServoR.writeMicroseconds(1300);

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
