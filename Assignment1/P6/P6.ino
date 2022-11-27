// Shahriar Nasim Nafi
// ID: 190205154
// Section: C1
// Github Link: https://github.com/SNNafi/EEE3210/blob/main/Assignment1/P6/P6.ino

/** 6. Design a Binary Encoder (One-Hot encoded). It will take 4-digit binary input from user
and show the equivalent decimal number. It will also check whether user is giving correct
input or not.
*/

/**
  --Input--
  0010

  --Output--
  Input: 10
  Output: 1 (D1)

*/

void setup()  {
   Serial.begin(9600);
}

void loop() {
  char buffer[100];
  int dec = 0;
  if (Serial.available()) {
    int byte = Serial.readString().toInt();
    int input = byte;

    for (; (byte % 2) == 0; ++dec) {
      byte >>= 1;
    }

    if (dec == 0) {
      Serial.print("\nInput: ");
      Serial.println(input);
      Serial.println("Wrong");
      return;
    }
    
    sprintf(buffer, "\nInput: %d\nOutput: %d (D%d)\n", input, dec, dec2bin(dec));
    Serial.print(buffer);

  }

}

int dec2bin(int n) {
  int bin = 0;
  int rem, i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }

  return bin;
}
