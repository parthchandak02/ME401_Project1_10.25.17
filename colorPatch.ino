void colorPatch()
{
  if( redCounter > blueCounter){
    colorState = RED;
  }
  else if (redCounter < blueCounter){
    colorState = BLUE;
  }
  else{
    stopServos();
  }

  while(!found)
  {
    detectColor();
    if (state == colorState)
    {
      stopServos();
    }
    else
    {
      fwd();
      delay(750);
      right();
      delay(750);
      fwd();
      delay(750);
      left();
    }
  }
}

