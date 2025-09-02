#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <BH1750.h>

// Définir les pins SDA et SCL pour l'ESP32
#define SDA_PIN 21
#define SCL_PIN 22

// Adresse I2C du BME280 (0x76 ou 0x77 selon le modèle)
#define BME280_ADDRESS 0x76

// Pins du capteur de pluie, du niveau d'eau et de la commande de la pompe
#define RAIN_SENSOR_PIN 4
#define CMD_POMPE 2
#define NIV_EAU 15

Adafruit_BME280 bme;
BH1750 lightMeter;

// Variables pour stocker les valeurs des capteurs
float temperature = 0;
float pression = 0;
float humidite = 0;
float luminosite = 0;
float rainPercentage = 0;

// Variable pour suivre l'état de la pompe
bool pompeActive = false;

void setup() {
  Serial.begin(115200);
  
  // Initialiser le bus I2C sur les pins spécifiés
  Wire.begin(SDA_PIN, SCL_PIN);
  
  // Configurer le capteur de pluie, le capteur de niveau d'eau, et la pompe
  pinMode(RAIN_SENSOR_PIN, INPUT);
  pinMode(NIV_EAU, INPUT);
  pinMode(CMD_POMPE, OUTPUT);

  /*
  
  // Vérifier la connexion au capteur BME280
  if (!bme.begin(BME280_ADDRESS)) {
    Serial.println("Erreur : BME280 non détecté !");
    while (1);
  } else {
    Serial.println("BME280 détecté avec succès.");
  }
  
  // Initialiser le capteur de luminosité BH1750
  if (!lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("Erreur : BH1750 non détecté !");
    while (1);
  } else {
    Serial.println("BH1750 détecté avec succès.");
  }

  // Créer les tâches sur les cœurs 0 et 1
  xTaskCreatePinnedToCore(taskSensorReadings, "TaskSensorReadings", 10000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskPumpControl, "TaskPumpControl", 10000, NULL, 1, NULL, 1);
}

void loop() {
  // La boucle principale reste vide car nous utilisons FreeRTOS pour gérer les tâches
}

// Tâche pour lire les valeurs des capteurs (BME280, BH1750, capteur de pluie) sur le cœur 0
void taskSensorReadings(void * parameter) {
  for (;;) {
    // Lire les valeurs du capteur BME280
    temperature = bme.readTemperature();
    pression = bme.readPressure() / 100.0F;  // Conversion en hPa
    humidite = bme.readHumidity();

    // Lire la valeur analogique du capteur de pluie et convertir en pourcentage
    int rainAnalogValue = analogRead(RAIN_SENSOR_PIN);
    rainPercentage = ((4095 - rainAnalogValue) / 4095.0) * 100;

    // Lire la luminosité du capteur BH1750
    luminosite = lightMeter.readLightLevel();

    // Afficher les valeurs des capteurs
    Serial.print("Température : ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Pression : ");
    Serial.print(pression);
    Serial.println(" hPa");

    Serial.print("Humidité : ");
    Serial.print(humidite);
    Serial.println(" %");

    Serial.print("Pourcentage de détection de pluie : ");
    Serial.print(rainPercentage);
    Serial.println(" %");

    Serial.print("Luminosité : ");
    Serial.print(luminosite);
    Serial.println(" lux");

    delay(2000); // Pause de 2 secondes avant la prochaine lecture
  }
}

// Tâche pour vérifier le niveau d'eau et activer/désactiver la pompe sur le cœur 1
void taskPumpControl(void * parameter) {
  for (;;) {
    int waterLevel = digitalRead(NIV_EAU);
    
    // Vérifier si l'état de la pompe doit être modifié
    if (waterLevel == HIGH && !pompeActive) { // Activer la pompe si le niveau d'eau est élevé et la pompe est inactive
      digitalWrite(CMD_POMPE, HIGH);  // Activer la pompe
      pompeActive = true;
      Serial.println("Niveau d'eau élevé : Pompe activée.");
    } else if (waterLevel == LOW && pompeActive) { // Désactiver la pompe si le niveau d'eau est bas et la pompe est active
      digitalWrite(CMD_POMPE, LOW);  // Désactiver la pompe
      pompeActive = false;
      Serial.println("Niveau d'eau bas : Pompe désactivée.");
    }
    
    delay(500); // Vérifier le niveau d'eau toutes les 500 ms
  }*/

        digitalWrite(CMD_POMPE, HIGH);  // Activer la pompe
        delay(5000);
        digitalWrite(CMD_POMPE, LOW);
}
