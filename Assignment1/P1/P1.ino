// Shahriar Nasim Nafi
// ID: 190205154
// Section: C1
// Github Link: https://github.com/SNNafi/EEE3210/blob/main/Assignment1/P1/P1.ino

// 1. Take User input Radius (r) as Float data.
// Write a program to calculate the area of the circle.

void setup() {
 
  Serial.begin(9600);

}

void loop() { 
  if (Serial.available()) {
    char buffer[100];
    double r = Serial.readString().toDouble();
    double area = calculateArea(r);   
    sprintf(buffer, "\nRadius %s\nCalculated Area %s\n", String(r, 2).c_str(), String(area, 2).c_str());
    Serial.print(buffer);
  }
}

double calculateArea(double r) {
  return 3.1415926536 * r * r;
}
