void setup()
{
  pinMode(22, OUTPUT);
}

void loop()
{                         // fixed frequency, fixed duty cycle input
  digitalWrite(22, HIGH);
  delayMicroseconds(25); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(13, LOW);
  delayMicroseconds(25);


/*
  for ( int i = 0 ; i <1000 ; i++) {  // fixed frequency, Variable duty cycle 
  digitalWrite(13, HIGH);
  delayMicroseconds(i); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(13, LOW);
  delayMicroseconds(1000 - i);
  }
  */
}

                    