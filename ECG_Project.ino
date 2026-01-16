/*
#define ECG_PIN 36
#define INTERVAL 20

unsigned long lastTime = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  pinMode(ECG_PIN, INPUT);
}

void loop() {
  if (millis() - lastTime >= INTERVAL) {
    lastTime = millis();
    int rawValue = analogRead(ECG_PIN);
    
    Serial.print("Signal:");
    Serial.println(rawValue);
  }
}
*/

#define ECG_PIN 36   // Định nghĩa chân Analog Input (GPIO 36 - VP)
#define INTERVAL 20  // Khoảng thời gian lấy mẫu: 20ms (tương ứng tần số 50Hz)

unsigned long lastTime = 0; // Biến lưu trữ mốc thời gian lấy mẫu cuối cùng

void setup() {
  Serial.begin(115200);        // Khởi tạo giao tiếp Serial tốc độ cao 115200 baud
  analogReadResolution(12);    // Thiết lập độ phân giải ADC 12-bit (0 - 4095)
  pinMode(ECG_PIN, INPUT);     // Thiết lập chân ECG_PIN làm đầu vào tín hiệu
}

void loop() {
  // Kỹ thuật lập trình không chặn (Non-blocking) sử dụng hàm millis()
  if (millis() - lastTime >= INTERVAL) {
    lastTime = millis();       // Cập nhật lại mốc thời gian cho lần lấy mẫu kế tiếp
    
    int rawValue = analogRead(ECG_PIN); // Đọc giá trị điện áp từ mạch Analog
    
    // Xuất dữ liệu theo định dạng Serial Plotter để vẽ biểu đồ
    Serial.print("Signal:");
    Serial.println(rawValue); 
  }
}