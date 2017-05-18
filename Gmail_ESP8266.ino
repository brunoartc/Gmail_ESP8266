#include <ESP8266WiFi.h>
#include "Gsender.h"

#pragma region Globals
const char* ssid = "a";                           // SSID do wifi
const char* password = "bcd12345";                       // Senha do Wifi
#pragma endregion Globals


void enviar(String subject = "Teste", String destinatario = "brunoartc@yahoo.com", String mensagem = "Funciona mesmo"){
  Gsender *gsender = Gsender::Instance();    // configura o email 
    if(gsender->Subject(subject)->Send(destinatario, mensagem)) {
        Serial.println("Message send.");
    } else {
        Serial.print("Error sending message: ");
        Serial.println(gsender->getError());
    }
}


void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Espera ate conectar 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  enviar();
}

void loop(){}
