/*
   Seed generator for random function using generic hardware.

   The RF 433 receiver captures any noise in its reception range,
   We can use these pulses to generate a random number.

   by Rtek1000 (06-jun-2022)

   Hardware:
   1- RF 433 recetor
   1- Analog input
   1- Resistor 10k (between receiver output and analog input)

*/

#define no_hardware_test 1 // Uncomment to test: Read input and seed in random
#define adc_test 1 // Uncomment to test: Show process data

#ifdef adc_test
byte buff[10]; // Used for sampling only, can rule out
#endif

void setup() {
  // put your setup code here, to run once:
  delay(300);

  Serial.begin(115200);

  Serial.println("Start");

#ifndef no_hardware_test

  pinMode(A7, INPUT);

  uint32_t val_sum = 0;
  uint32_t val_time1 = 0;
  uint32_t val_time2 = 0;
  uint32_t timeout = 0;

  for (int i = 0; i < 10; i++) {
    val_time1 = micros();

    timeout = 0;

    while ((analogRead(A7) > 512) || (timeout < 1000)) {
      delayMicroseconds(1);

      timeout++;
    }

    timeout = 0;
    
    while ((analogRead(A7) < 512) || (timeout < 1000)) {
      delayMicroseconds(1);

      timeout++;
    }

    val_time2 = micros() - val_time1;

    val_sum += val_time2;

#ifdef adc_test
    buff[i] = val_time2 & 0xFF;
#endif
  }

  val_sum /= 10;

#ifdef adc_test
  for (int i = 0; i < 10; i++) {
    Serial.print("buff(");
    Serial.print(i, DEC);
    Serial.print("): ");
    Serial.println(buff[i]);

    delay(5);
  }
#endif

  randomSeed(val_sum);

  Serial.print("val_sum: ");
  Serial.println(val_sum);
#endif

  Serial.print("random: ");
  Serial.println(random(0, 100));
}

void loop() {
  // put your main code here, to run repeatedly:

}
