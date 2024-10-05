#include <OneWire.h>
#include <DallasTemperature.h>
#include <FirebaseArduino.h> // Inclure la bibliothèque Firebase

const int sensorPinDS18B20 = 2; // Broche de données du capteur DS18B20
OneWire oneWire(sensorPinDS18B20);
DallasTemperature sensors(oneWire);

const int sensorPinSM130_RX = 3; // Broche de réception (RX) du module SM130 (NFC)
const int sensorPinSM130_TX = 4; // Broche de transmission (TX) du module SM130 (NFC)

void setup() {
    Serial.begin(9600); // Initialiser la communication série pour le débogage
    sensors.begin(); // Initialiser le capteur DS18B20
    pinMode(sensorPinSM130_RX, INPUT);
    pinMode(sensorPinSM130_TX, OUTPUT);
    Serial.begin(9600); // Initialiser la communication série (UART) avec le module SM130
}

void loop() {
    // Lire la température avec le capteur DS18B20
    sensors.requestTemperatures();
    float temperatureC = sensors.getTempCByIndex(0);

    // Lire les données NFC avec le module SM130
    String nfcData = readNFCData();

    // Envoyer les données via la communication série (UART)
    Serial.print("Temp: ");
    Serial.print(temperatureC);
    Serial.print(" C, NFC: ");
    Serial.println(nfcData);

    // Envoyer les données à Firebase
    Firebase.pushFloat("Temperature", temperatureC); // Envoyer la température
    Firebase.setString("nfcData", nfcData); // Envoyer les données NFC

    delay(1000); // Attendre 1 seconde avant de lire à nouveau
}

// Fonction pour lire les données NFC avec le module SM130
String readNFCData() {
    // Remplacer ce code par le code pour lire les données NFC avec le module SM130
    // Vous devrez utiliser la bibliothèque appropriée pour communiquer avec le module NFC
    // Remplacez le retour fictif par les données réelles lues par le module NFC

    // Exemple de données fictives
    String nfcData = "ID123456";

    return nfcData;
}
