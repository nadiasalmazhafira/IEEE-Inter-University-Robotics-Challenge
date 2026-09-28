// ==========================================
// PIN DRIVER TB6612FNG & MOTOR N20
// ==========================================
#define STBY_PIN 23

// Motor Kiri (A)
#define PWMA_PIN 25
#define AIN1_PIN 16
#define AIN2_PIN 17

// Motor Kanan (B)
#define PWMB_PIN 26
#define BIN1_PIN 18
#define BIN2_PIN 19

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println("========================================");
  Serial.println("       TES MANDIRI DRIVER & MOTOR       ");
  Serial.println("========================================");

  // Set semua pin sebagai OUTPUT
  pinMode(STBY_PIN, OUTPUT);
  pinMode(PWMA_PIN, OUTPUT);
  pinMode(AIN1_PIN, OUTPUT);
  pinMode(AIN2_PIN, OUTPUT);
  pinMode(PWMB_PIN, OUTPUT);
  pinMode(BIN1_PIN, OUTPUT);
  pinMode(BIN2_PIN, OUTPUT);

  // Aktifkan driver TB6612
  digitalWrite(STBY_PIN, HIGH);
  Serial.println("[OK] Pin STBY aktif (HIGH)");
  
  berhentiSemua();
  delay(1000);
}

void loop() {
  // ----------------------------------------------------
  // TAHAP 1: Tes Motor KIRI Saja (Maju)
  // ----------------------------------------------------
  Serial.println(">>> 1. MOTOR KIRI MAJU (2 Detik)...");
  digitalWrite(AIN1_PIN, HIGH);
  digitalWrite(AIN2_PIN, LOW);
  digitalWrite(PWMA_PIN, HIGH); // Daya 100%
  delay(2000);

  berhentiSemua();
  delay(1000);

  // ----------------------------------------------------
  // TAHAP 2: Tes Motor KANAN Saja (Maju)
  // ----------------------------------------------------
  Serial.println(">>> 2. MOTOR KANAN MAJU (2 Detik)...");
  digitalWrite(BIN1_PIN, HIGH);
  digitalWrite(BIN2_PIN, LOW);
  digitalWrite(PWMB_PIN, HIGH); // Daya 100%
  delay(2000);

  berhentiSemua();
  delay(1000);

  // ----------------------------------------------------
  // TAHAP 3: Tes KEDUA MOTOR MAJU Bareng
  // ----------------------------------------------------
  Serial.println(">>> 3. KEDUA MOTOR MAJU BERSAMA (2 Detik)...");
  // Kiri Maju
  digitalWrite(AIN1_PIN, HIGH);
  digitalWrite(AIN2_PIN, LOW);
  digitalWrite(PWMA_PIN, HIGH);
  // Kanan Maju
  digitalWrite(BIN1_PIN, HIGH);
  digitalWrite(BIN2_PIN, LOW);
  digitalWrite(PWMB_PIN, HIGH);
  delay(2000);

  berhentiSemua();
  delay(1000);

  // ----------------------------------------------------
  // TAHAP 4: Tes KEDUA MOTOR MUNDUR Bareng
  // ----------------------------------------------------
  Serial.println(">>> 4. KEDUA MOTOR MUNDUR BERSAMA (2 Detik)...");
  // Kiri Mundur
  digitalWrite(AIN1_PIN, LOW);
  digitalWrite(AIN2_PIN, HIGH);
  digitalWrite(PWMA_PIN, HIGH);
  // Kanan Mundur
  digitalWrite(BIN1_PIN, LOW);
  digitalWrite(BIN2_PIN, HIGH);
  digitalWrite(PWMB_PIN, HIGH);
  delay(2000);

  berhentiSemua();
  Serial.println("--- SIKLUS SELESAI, MENGULANG DALAM 2 DETIK ---\n");
  delay(2000);
}

// Fungsi pembantu untuk mematikan kedua motor
void berhentiSemua() {
  digitalWrite(PWMA_PIN, LOW);
  digitalWrite(PWMB_PIN, LOW);
  digitalWrite(AIN1_PIN, LOW);
  digitalWrite(AIN2_PIN, LOW);
  digitalWrite(BIN1_PIN, LOW);
  digitalWrite(BIN2_PIN, LOW);
}