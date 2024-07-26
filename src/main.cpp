/**
 * @file Whatsapp_Message.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief Example Whatsapp Message
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/Callmebot_ESP8266
 */

#include <ESP8266WiFi.h>
#include <Callmebot_ESP8266.h>

const char* ssid = "Flia Martinez";
const char* password = "biblioteca";
// Note :
// phoneNumber : Indonesia +62, Example: "+62897461238"
// apiKey : Follow instruction on https://www.callmebot.com/blog/free-api-whatsapp-messages/
/*String phoneNumber = "+595993278373";
String apiKey = "9604968"; de arturo
String messsage = "fallasjdsajds";*/

// Arrays de números de teléfono y API keys
String phoneNumbers[] = {"+595981545165", "+595983662432"};
String apiKeys[] = {"5464226", "4457464"};
String message = "Prueba de mensajes: ¿hay fallo?";

void sendWhatsAppMessages();

void setup() {
	Serial.begin(115200);

	WiFi.begin(ssid, password);
	Serial.println("Connecting");
	while(WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.print("Connected to WiFi network with IP Address: ");
	Serial.println(WiFi.localIP());

	Callmebot.begin();

	// Whatsapp Message
	/*Callmebot.whatsappMessage(phoneNumber, apiKey, messsage);
	Serial.println(Callmebot.debug());*/
	sendWhatsAppMessages();

}

void loop() {
	
}

void sendWhatsAppMessages() {
    for (int i = 0; i < sizeof(phoneNumbers) / sizeof(phoneNumbers[0]); i++) {
        Callmebot.whatsappMessage(phoneNumbers[i], apiKeys[i], message);
        Serial.println(Callmebot.debug());
    }
}