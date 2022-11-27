// Shahriar Nasim Nafi
// ID: 190205154
// Section: C1
// Github Link: https://github.com/SNNafi/EEE3210/blob/main/Assignment1/P4/P4.ino

// 4. Take 2 inputs (integer) from user. 
// Then ask user what arithmetic operation they want to do with these number (take as a String Input). 
// Then show the output result.

/**
  --Input--
  14,2,Add

  --Output-- 
  First Input: 14
  Second Input: 2
  Operation: Add
  Output = 16.00  

*/



void setup()  {
   Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char buffer[100];
    int i = -1;
    int nums[2];

    String string = Serial.readString();

    int index1 = string.indexOf(',');
    nums[++i] = string.substring(0, index1).toInt(); 

    int index2 = string.indexOf(',', index1 + 1);
    nums[++i] = string.substring(index1 + 1, index2).toInt(); 

    String op = string.substring(index2 + 1);

    double result = calculate(nums[0], nums[1], op);

    sprintf(buffer, "\nFirst Input: %d\nSecond Input: %d\nOperation: %sOutput = %s\n", nums[0], nums[1], op.c_str(), String(result, 2).c_str());
    Serial.print(buffer);
  }
   
}

double calculate(int a, int b, String op) {
  if (op.equals(String("Add\n"))) {
    return a + b;
  } else if (op.equals(String("Division\n"))) {
    return (double) a / (double) b;
  } else if (op.equals(String("Multiplication\n"))) {
    return a * b;
  } else {
    return a - b;
  } 
}
