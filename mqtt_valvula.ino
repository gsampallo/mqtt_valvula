#include <ESP8266WiFi.h>
#include <PubSubClient.h>



const char* ssid = "wifi";
const char* password = "clave";
const char* mqtt_server = "servidor_broker";
const char* keyDevice = "VALVULA";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

int pinValvula = 5;

void setup() {
  Serial.begin(9600);
  Serial.println("iniciando");
  pinMode(pinValvula, OUTPUT);
  setup_wifi();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);   
}

void setup_wifi() {

  delay(10);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("OK");
}


void callback(char* topic, byte* payload, unsigned int length) {
  
  if (((char)payload[0] == '1')) {
    digitalWrite(pinValvula,HIGH);
    client.publish("VALVULA","ABIERTA");  
  } else if (((char)payload[0] == '2')) {
    digitalWrite(pinValvula,LOW);
    client.publish("VALVULA","CERRADA");  
  }

}

void reconnect() {

  while (!client.connected()) {

    if (client.connect(keyDevice,"usuario","clave")) {
      Serial.println("connected");
      client.subscribe("JARDIN");
    } else {
      delay(5000);
    }
  }
}

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10000;    // the debounce time; increase if the output flickers

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop(); 

  if ((millis() - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = millis();
    client.publish("JARDIN","VALVULA ONLINE");  
  }
}
