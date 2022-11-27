// Shahriar Nasim Nafi
// ID: 190205154
// Section: C1
// Github Link: https://github.com/SNNafi/EEE3210/blob/main/Assignment1/P3/P3.ino

// 3.  Consider an array of 4 elements (initialize inputs in the code). 
// Write a program that calculates the average of these 4 numbers.

/**
  Input: 1,2,3,4

  Output: 
  Numbers: 1 2 3 4
  Average 2.50

*/

void setup()  {
   Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char buffer[100];
    int i = -1;
    int nums[4];
    String string = Serial.readString();

    int index1 = string.indexOf(',');
    nums[++i] = string.substring(0, index1).toInt(); 

    int index2 = string.indexOf(',', index1 + 1);
    nums[++i] = string.substring(index1 + 1, index2).toInt(); 

    int index3 = string.indexOf(',', index2 + 1);
    nums[++i] = string.substring(index2 + 1, index3).toInt(); 

    nums[++i] = string.substring(index3 + 1).toInt(); 

    double avg = average4(nums[0], nums[1], nums[2], nums[3]);
    sprintf(buffer, "\nNumbers: %d %d %d %d\nAverage %s\n", nums[0], nums[1], nums[2], nums[3], String(avg, 2).c_str());
    Serial.print(buffer);
  }
   
}

double average4(int a, int b, int c, int d) {
    return static_cast<double>(a + b + c + d) / 4.0;
}