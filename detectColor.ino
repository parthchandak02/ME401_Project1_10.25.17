void detectColor()
{
  // turn on the red led only
     digitalWrite(rPin, HIGH); //Set rPin to HIGH++++++++++++++++
     digitalWrite(bPin, LOW); //Set bPin to LOW+++++++++++++++
  
      start_time = millis();
       while(millis()<start_time+50){
      }//wait
      
      sensorValue = analogRead(sensorPin); 
      color[0]=sensorValue;

      color[0]=constrain(sensorValue,minwhite[0],maxblack[0]);

      Serial.println("Red: ");
      Serial.print(color[0]);
      Serial.print("\n"); 
    
      // turn on the blue led only
      digitalWrite(rPin, LOW); 
      digitalWrite(bPin, HIGH);
    
      
      start_time = millis();
       while(millis()<start_time+50){
      }
      
      sensorValue = analogRead(sensorPin); 
      color[1]=sensorValue;
      color[1]=constrain(sensorValue,minwhite[1],maxblack[1]);
      
      Serial.println("Blue: ");
      Serial.print(color[1]);
      Serial.println(" Blue Counter: ");
      Serial.print(blueCounter);
      Serial.print("\n");  

      if(color[0] < 500 && color[1] < 500)
      {
        state = WHITE;
      }
      else if(color[1] > 650 && color[0] > 650)
      {
        state = BLACK;
      }
      else if(color[0]<color[1])
      {
        state = RED;
      }
      else if(color[1]<color[0])
      {
        state = BLUE;
      }
      
}

