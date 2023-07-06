#include<WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // Set Wifi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Scan start");

  //WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks(); // returns the number of networks found
  Serial.println("Scan done");
  if(n == 0)
  {
    Serial.println("No networks found");
  }
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for(int i = 0; i < n; i++)
    {
      //print SSID and RSSI for each network found (RSSI - received signal strength indicator)
      Serial.print(i + 1);
      Serial.print(":  ");
      Serial.print(WiFi.SSID(i)); //prints the SSID for a specific networ -> SSID_ ten wifi
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i)); 
      /* Trả ve gia tri RSSI cua mạng đó, RSSI dai dien cho cuong do ti hieu da nhan,
      Day la thuoc do uoc tinh ve muc nang luong ma thiet bị khách RF đang nhận được từ 
      một điểm truy cập hoặc bộ định tuyến */
      Serial.print(" )");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      /* WiFi.encryptionType() trả về loại mã hóa mạng Ví dụ cụ thể đó đặt dấu * trong trường hợp mạng mở.
      Tuy nhiên, chức năng đó có thể trả về một trong các tùy chọn sau (không chỉ các mạng mở):
      WIFI_AUTH_OPEN
      WIFI_AUTH_WEP
      WIFI_AUTH_WPA_PSK
      WIFI_AUTH_WPA2_PSK
      WIFI_AUTH_WPA_WPA2_PSK
      WIFI_AUTH_WPA2_ENTERPRISE
      */
      delay(10);
    }
  }
  Serial.println("");
  // Wait a bit before scanning again
  delay(5000);
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
}
