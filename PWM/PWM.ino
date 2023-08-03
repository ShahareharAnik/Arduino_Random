void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{                         // fixed frequency, fixed duty cycle input
  digitalWrite(13, HIGH);
  delayMicroseconds(500); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(13, LOW);
  delayMicroseconds(50);


/*
  for ( int i = 0 ; i <1000 ; i++) {  // fixed frequency, Variable duty cycle 
  digitalWrite(13, HIGH);
  delayMicroseconds(i); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(13, LOW);
  delayMicroseconds(1000 - i);
  }
  */
}

                    