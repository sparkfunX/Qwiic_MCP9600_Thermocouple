/*
  Simple, quick test sketch
*/

#define statLED 5

#include <SparkFun_MCP9600.h>
MCP9600 tempSensor;

void setup() {
  Serial.begin(115200);

  pinMode(statLED, OUTPUT);
  digitalWrite(statLED, LOW);

  Wire.begin();
}

void loop()
{
  if (tempSensor.begin() == true)
  {
    if (tempSensor.available())
    {
      float temperature = tempSensor.getAmbientTemp();
      float delta = tempSensor.getTempDelta();

      Serial.print("Thermocouple: ");
      Serial.print(tempSensor.getThermocoupleTemp());
      Serial.print(" °C   Ambient: ");
      Serial.print(temperature);
      Serial.print(" °C   Temperature Delta: ");
      Serial.print(delta);
      Serial.print(" °C");
      Serial.println();

    if (temperature < 28.0 && temperature > 22.0 && delta < 3.0)
      digitalWrite(statLED, HIGH);
    }
  }
  else
  {
    Serial.println("Nothing detected");
    digitalWrite(statLED, LOW);
  }

  delay(100);
}
