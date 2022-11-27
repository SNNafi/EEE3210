// Shahriar Nasim Nafi
// ID: 190205154
// Section: C1
// Github Link: https://github.com/SNNafi/EEE3210/blob/main/Assignment1/P5/P5.ino

// 5. Take Student ID as a user input.
// From ID, you have to find out the relevant information such as Admission year, Term, Department and Roll No.

/**
  Input: 190205154

  Output: 
  Student ID: 190205154
  Admission Year: 2019
  Term: Fall
  Department: EEE
  Roll. No.: 154

*/


void setup()  {
   Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char buffer[1000];
    String id = Serial.readString();
    sprintf(buffer, "\nStudent ID: %sAdmission Year: %d\nTerm: %s\nDepartment: %s\nRoll. No.: %d\n", id.c_str(), year(id), term(id).c_str(), department(id).c_str(), roll(id));
    Serial.print(buffer);
  }
}

int year(String id) {
  String y = id.substring(0, 2);
  return y.toInt() + 2000;
}

String term(String id) {
  int t = id.substring(2, 4).toInt();
  if (t == 2) {
    return String("Fall");
  } else {
    return String("Spring");
  }
}

String department(String id) {
  int t = id.substring(4, 6).toInt();
  if (t == 1) {
    return String("ARCH");
  } else if (t == 2) {
    return String("BBA");
  } else if (t == 3) {
    return String("CE");
  } else if (t == 4) {
    return String("CSE");
  } else if (t == 5) {
    return String("EEE");
  } else if (t == 6) {
    return String("TE");
  } else if (t == 7) {
    return String("IPE");
  }  else if (t == 8) {
    return String("ME");
  }
}

int roll(String id) {
  return id.substring(6).toInt();
}
