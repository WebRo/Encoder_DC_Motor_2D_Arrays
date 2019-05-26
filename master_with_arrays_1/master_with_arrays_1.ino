//i2c Master Code(UNO)
#include <Wire.h>

char arr[2][3];






void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(10);
  Wire.begin();
}


void loop()
{

  while (Serial.available() > 0)
  {
    String s = Serial.readStringUntil("\n");


    int n = s.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());


    int k = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        arr[i][j] = char_array[k];
       // Serial.println(arr[i][j]);
      k++;
      }

    }

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        //arr[i][j] = char_array[k];
      Serial.println(arr[i][j]);
      Wire.beginTransmission(i +1);
      Wire.write(arr[i][j]);
      Wire.endTransmission();
  
      }

    }


  }

//return 0;
}
