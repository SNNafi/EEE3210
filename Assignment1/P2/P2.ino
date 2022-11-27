// Shahriar Nasim Nafi
// ID: 190205154
// Section: C1
// Github Link: https://github.com/SNNafi/EEE3210/blob/main/Assignment1/P2/P2.ino

// 2. Take 3 numbers as User Inputs (data type INT).
// Write a program to find out the minimum among these 3 numbers.

/**
  Input: 1,2,3

  Output: 
  Numbers: 1 2 3
  Minimum Number 1

*/


void setup()  {
   Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char buffer[100];
    int i = -1;
    int nums[3];
    String string = Serial.readString();

    int index1 = string.indexOf(',');
    nums[++i] = string.substring(0, index1).toInt(); 

    int index2 = string.indexOf(',', index1 + 1);
    nums[++i] = string.substring(index1 + 1, index2).toInt(); 

    nums[++i] = string.substring(index2 + 1).toInt(); 

    int minNum = min3(nums[0], nums[1], nums[2]);
    sprintf(buffer, "\nNumbers: %d %d %d\nMinimum Number %d\n", nums[0], nums[1], nums[2], minNum);
    Serial.print(buffer);
  }
   
}

int min3(int a, int b, int c) {
    int min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    return min;
}