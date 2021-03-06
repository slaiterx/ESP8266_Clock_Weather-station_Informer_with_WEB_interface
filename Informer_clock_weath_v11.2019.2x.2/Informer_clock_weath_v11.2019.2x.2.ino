/*_______By IvanUA_____________________________
 Піни LED------NodeMCU  1.0                    |
 DataIn________________________D7/GPIO 13      |
 LOAD/CS_______________________D8/GPIO 15      |
 CLK___________________________D5/GPIO 14      |
 Кнопка________________________D0/GPIO 16      |
 Бaзер_________________________D6/GPIO 12      |
 DS18B20_______________________D3/GPIO 0       |
 Si7021/BMP/BME280/DS3231 SDA__D2/GPIO 4       |
 Si7021/BMP/BME280/DS3231 SCL__D1/GPIO 5       |
 GND - FotoRezistor ___________A0              |
 +3,3 - rezistor 2-100k _______A0              |
______________________________________________*/
#include <Wire.h>
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <ArduinoJson.h>
#include <WiFiUdp.h>
#include <OneWire.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
#include <ESP8266HTTPUpdateServer.h>
#include "Adafruit_Si7021.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_BMP085.h>
#include "BlueDot_BME280.h"
#include <Ticker.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
Ticker blinker;
ESP8266HTTPUpdateServer httpUpdater;
WiFiClient ESPclient;
ESP8266WebServer server(80);
File fsUploadFile;
IPAddress apIP(192, 168, 4, 1);
#include "P_js.h"
#include "P_css.h"
#include "P_index.h"
#include "P_time.h"
#include "P_weath.h"
#include "P_Setup.h"
#include "P_help.h"

// ===================================================
String ssid = "Wifi";
String password = "";
String ssidAP      = "ESP-Info";
String passwordAP  = "";
boolean weatherHost = 0;
String weatherHost0 = "api.weatherbit.io";
String weatherKey0  = "";
String cityID0      = "Барнаул";
String cityID1      = "1510853";
String weatherLang = "ru";
String location_name = "";
String location_region = "";
String location_country = "";
String location_localtime = "";
float  location_temp;
float  location_app_temp;
int    location_rh;
float  location_pres;
float  location_wind_spd;
String location_wind_cdir_full = "";
String location_sunrise = "";
String location_sunset = "";
int    location_clouds;
int    location_vis;
int    location_uv;
String location_weather_description = "";
// =====================================================================================
bool printCom = true;
#define MAX_DIGITS 16
byte NUM_MAX0 = 4;
byte NUM_MAX1 = 4;
byte fontCLOCK = 0;      // 0-крупный, 1-крупный цифровой, 2-полу жирный, 3-полу жирный цифровой, 4-обычный, 5-обычный цифровой, 6-узкий, 7-узкий цифровой. 
bool fontSizeCLOCK = 0;  // 0-8 строк, 1-7 строк
bool fontSizeData = 1;   // 0-8 строк, 1-7 строк
byte aliData = 8;
bool textDown = 0;
bool dataDown = 1;
byte volBrightnessD  = 11;
byte volBrightnessN  = 2;
bool volBrightnessAuto = 0;
byte levelBridhtness = 0;
byte timeDay = 5;
byte timeNight = 24;
int rotate0 = 90;
int rotate1 = 90;
byte timeScrollStart = 6;
byte timeScrollStop = 23;
byte timeScrollSpeed = 40;
byte lang = 1;             // 0-ukr, 1-rus, 2-pol,  3-czech, 4-de, 5-en
#define DIN_PIN   13                                                                    //GPIO 13 / D7
#define CS_PIN    15                                                                    //GPIO 15 / D8
#define CLK_PIN   14                                                                    //GPIO 14 / D5
#define buzzerPin 12                                                                    //GPIO 12 / D6
bool buzzerOnOffku = 0;
bool buzzerOnOff = 0;
bool buzzerSet = 1;
#define brightPin A0
OneWire  ds(0);                                                                         // DS18B20 подключен к 0 пину (резистор на 4.7к обязателен)
#define BUT_PIN   16
// ----------
#include "max7219.h"
#include "fonts.h"
boolean WIFI_connected = false;
// ---------- Настройка оновлення часу
IPAddress timeServerIP;
String ntpServerName = "ntp3.stratum2.ru";
const int NTP_PACKET_SIZE = 48;
byte packetBuffer[NTP_PACKET_SIZE];
WiFiUDP udp;
unsigned int localPort = 2390;
unsigned long epochNM;
static const uint8_t monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};        // Кількість днів у місяцях
#define LEAP_YEAR(Y) (((1970+Y)>0) && !((1970+Y)%4) && (((1970+Y)%100)||!((1970+Y)%400)))   // Високосні літа
String weatherMain = "";
String weatherDescription = "";
String weatherLocation = "";
String country;
String tempz;
int clouds;
int windDeg;
float windSpeed;
String dw, _month;
String jsonConfig = "{}";
String jsonTime = "{}";
// ---------- Змінні для роботи локального годинника
float timeZone = 7.0;                                                                       //  часовий пояс
bool isDayLightSaving = false;
long localEpoc = 0;
long localMillisAtUpdate = 0;
int hour=2,   minute=40,  second=42,  month=4,   day=6,   dayOfWeek=6,   year=2018;
int g_hour, g_minute, g_second, g_month=1, g_day, g_dayOfWeek, g_year;
bool statusUpdateNtpTime = 0;                                                               // якщо не "0" - то останнє оновленя часу було вдалим
String y, mon, wd, d, h, m, s, mes;
uint8_t hourTest[3], minuteTest[3];
int secFr, lastSecond, lastMinute;
String date;
byte kuOn = 7;
byte kuOff = 23;
bool clockNight = 1;
bool cn = 0;
// ----------
String cityName;
//int cityID0;
String weatherString;
String weatherStringZ;
// ----------
byte dig[MAX_DIGITS] = {0};
byte digold[MAX_DIGITS] = {0};
byte digtrans[MAX_DIGITS] = {0};
int dx = 0;
int dy = 0;
byte del = 0;
int updateOTA = 1;
bool outForecast = true;
int updateForecast = 0;
int updateForecasttomorrow = 0;
float t0 = 0.0;    // температура в  доме  со знаком и плавающей запятой
int t1 = 85;    // температура в  доме  целая беззнаковая часть
int t2 = 0;     // температура в  доме  дробная часть
int t3 = 85;    // температура на улице целая беззнаковая часть
int t4 = 0;     // температура на улице дробная часть
float t5 = 0.0;    // температура на улице со знаком и плавающей запятой
byte h1 = 0;
byte h2 = 0;
byte h3 = 0;
byte humidity;                        // влажность для прогноза
float pressure;                       // давление для прогноза
float temp;                           // температура для прогноза
float tempDs18b20;                    // температура с датчика DS18B20
BlueDot_BME280 bme;
float tempBme = 0;
float humBme = 0;
float pressBme = 0;
float altBme = 0;
Adafruit_BMP280 bmp;
Adafruit_BMP085 bmp180;
float tempBmp = 0;
float pressBmp = 0;
float altBmp = 0;
bool bmp280 = false;
bool BMP180 = false;
bool bme280 = false;
Adafruit_Si7021 sensor = Adafruit_Si7021();
float hum = 0;
float humSi7021 = 0;
float celsiusSi7021 = 0;
bool si7021 = false;
float corrTempD = -3.3;
float corrTempU = -1.5;
float corrHumi  = 0;
int   corrPress = -21;
byte sensorDom = 0;          //NONE = 0, DS18B20 = 1, Si7021 = 2, BMP280 = 3, BME280 = 4;
byte sensorUl = 0;           //NONE = 0, DS18B20 = 1, Si7021 = 2, BMP280 = 3, BME280 = 4;
byte sensorHumi = 0;         //NONE = 0, NONE    = 1, Si7021 = 2, NONE   = 3, BME280 = 4;
byte sensorPrAl = 0;         //NONE = 0, NONE    = 1, NONE   = 2, BMP280 = 3, BME280 = 4;
String tNow, tCurr, tPress, tSpeed, tMin, tTom, tYour, tPoint, tWeatrNot, tWeatrTN;
String tJanuary, tFebruary, tMarch, tApril, tMay, tJune, tJuly, tAugust, tSeptember, tOctober, tNovember, tDecember;
String tMonday, tTuesday, tWednesday, tThursday, tFriday, tSaturday, tSunday, tYear;
bool alarm_stat=0;
bool alarm_hold=0;
byte alarm_numer=255;
byte alarme[5][3]{{12, 30, 0},{7, 15, 0},{22, 55, 0},{0, 30, 0},{0, 0, 0}}; //1-часы, 2-минуты, 3-откл(0)/1раз(11)/пон-пят(8)/пон-сб(9)/сб-вс(10)/вс(1)/пон(2)/вто(3)/сре(4)/чет(5)/пят(6)/сб(7)/всегда(12)
byte memory_hour_start=9;
byte memory_hour_end=23;
byte m_date=0;
byte memory_date[9][2]{{1, 1},{2, 1},{6, 1},{7, 1},{13, 1},{19, 1},{8, 3},{1, 5},{1, 9}}; //1-день, 2-месяц
char memory_date_mes0[51] = "Новый Год!";
char memory_date_mes1[51] = "Новый Год кончился (";
char memory_date_mes2[51] = "Ночь перед Рождеством";
char memory_date_mes3[51] = "Рождество";
char memory_date_mes4[51] = "Старый Новый Год!";
char memory_date_mes5[51] = "Крещение";
char memory_date_mes6[51] = "Женский день";
char memory_date_mes7[51] = "Мир! Труд! Май!";
char memory_date_mes8[51] = "День Победы!";
bool firstStart=0;
byte amountNotStarts=0;
String jsonLine = "";
bool rtcStat = true;
int rtcAddr = 0x68;
int hour_rtc, minute_rtc, second_rtc, month_rtc, day_rtc, dayOfWeek_rtc, year_rtc;
#include "rtc.h"
byte errorRTC;
//======================================================================================
void setup() {
  Wire.begin(); 
  Serial.begin(115200);
  if(printCom) Serial.println("");
  pinMode(BUT_PIN, INPUT);
  digitalWrite(BUT_PIN, LOW);
  delay(500);
  initMAX7219();
  sendCmdAll(CMD_SHUTDOWN, 1);
  sendCmdAll(CMD_INTENSITY, 1);
  SPIFFS.begin();
  loadConfig();
  loadTime();
  Wire.beginTransmission(0x67);
  errorRTC = Wire.endTransmission();
  if(errorRTC==0){
    rtcAddr = 0x67;
    if(printCom) Serial.println("YES!!! find RTC module addr: 0x67!");
  } else {
    Wire.beginTransmission(0x68);
    errorRTC = Wire.endTransmission();
    if(errorRTC==0){
      rtcAddr = 0x68;
      if(printCom) Serial.println("YES!!! find RTC module addr: 0x68!");
    } else rtcStat = false;
  }
  if(rtcStat){
    if(printCom) Serial.println("RTC START");
    getRTCDateTime();
    hour=hour_rtc;
    minute=minute_rtc;
    second=second_rtc;
    day=day_rtc;
    month=month_rtc;
    year=year_rtc;
    dayOfWeek=dayOfWeek_rtc;
    if(printCom){
      Serial.println("RTC update: "+String(hour)+":"+String(minute)+":"+String(second)+"    "+String(day)+"."+String(month)+"."+String(year)+" D="+String(dayOfWeek));
    }
  } else if(printCom) Serial.println("RTC module off!");
  // ------------------
  if(bmp.begin()) {
    if(printCom) Serial.println("YES!!! find BMP280 sensor!");
    bmp280 = true;
    sensorsBmp();
  } else if(printCom) Serial.println("Did not find BMP280 sensor!");
  if(bmp180.begin()) {
    if(printCom) Serial.println("YES!!! find BMP180 sensor!");
    BMP180 = true;
    sensorsBmp();
  } else if(printCom) Serial.println("Did not find BMP180 sensor!");
  bme.parameter.communication = 0;                            //Подключение сенсора по I2C 
  bme.parameter.I2CAddress = 0x76;                            //I2C Адрес сенсора или 0x77
  bme.parameter.sensorMode = 0b11;                            //0b00 спящий режим измерения не выполняются, 0b01: выполняется одно измерение, 0b11: датчик постоянно измеряет
  bme.parameter.IIRfilter = 0b100;                            //высокое значение коэффициента означает меньше шума, но измерения также менее чувствительны 0b000-0(off), 0b001-2, 0b010-4, 0b011-8, 0b100-16 (default value)
  bme.parameter.humidOversampling = 0b100;                    //коэффициент избыточной дискретизации для измерений влажности 0b000-0 (фильтр откл), 0b001-1, 0b010-2, 0b011-4, 0b100-8, 0b101-16 (максимум)
  bme.parameter.tempOversampling = 0b101;                     //коэффициент передискретизации для измерения температуры 0b000-0 (фильтр откл), 0b001-1, 0b010-2, 0b011-4, 0b100-8, 0b101-16 (максимум)
  bme.parameter.pressOversampling = 0b101;                    //коэффициент избыточной дискретизации для измерений давления. Для измерений высоты более высокий коэффициент обеспечивает более стабильные значения
  bme.parameter.pressureSeaLevel = 1013.25;                   //текущее давление, скорректированное для уровня моря 1013.25 hPa. Для точных измерений высоты
  bme.parameter.tempOutsideCelsius = 15;                      //средняя температура снаружи 15°C
  bme.parameter.tempOutsideFahrenheit = 59;                   //средняя температура снаружи 59°F
  if(bme.init() == 0x60) {
    if(printCom) Serial.println("YES!!! find BME280 sensor!");
    bme280 = true;
    sensorsBme();
  } else if(printCom) Serial.println("Did not find BME280 sensor!");
  if (sensor.begin()) {
    if(printCom) Serial.println("YES!!! find Si7021 sensor!");
    si7021 = true;
    sensorsSi7021();
  } else if(printCom) Serial.println("Did not find Si7021 sensor!");
  serverInit();
// ----------
  blinker.attach(0.05, showAnimClock);
  localMillisAtUpdate = millis();
  localEpoc = (hour * 60 * 60 + minute * 60 + second);
  udp.begin(localPort);
  pinMode(buzzerPin, OUTPUT);
// ---------- Перемикаємо мови в залежності від вибраної
  if (lang == 0) ukrText();
  else if (lang == 1) rusText();
  else if (lang == 2) polText();
  else if (lang == 3) czText();
  else if (lang == 4) deText();
  else if (lang == 5) enText();
  bip();
// ---------- Підключення до WiFi
  wifiConnect();
// ***********  OTA SETUP
  if(updateOTA) {
    ArduinoOTA.setPort(8266);
    ArduinoOTA.setHostname("Informer"); 
    ArduinoOTA.onEnd([](){ESP.restart();});
    ArduinoOTA.onError([](ota_error_t error){Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR && printCom) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR && printCom) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR && printCom) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR && printCom) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR && printCom) Serial.println("End Failed");
      ESP.restart(); 
    });
    ArduinoOTA.begin();
  }
  if(WiFi.status() == WL_CONNECTED) {
    if(outForecast){
      if(weatherHost==0) {
        getWeatherData0();
        getWeatherDataz0();
      }
    }
  }
}
//======================================================================================
//======================================================================================
void loop() {
  if(updateOTA) ArduinoOTA.handle();
  server.handleClient();                                                                // дозволяємо HTTP серверу відповідать на запити
  updateTime();                                                                         // оновлюємо час
  cn = (clockNight && (hour<timeDay || hour>=timeNight) && (digitalRead(BUT_PIN) == LOW));
  if(second != lastSecond) {                                                            // на початку нової секунди скидаємо secFr в "0"
    lastSecond = second;
    if(volBrightnessAuto) {
      levelBridhtness = map(analogRead(brightPin), 1023, 0, 2, 15);
      sendCmdAll(CMD_INTENSITY, levelBridhtness);
    } else {
      if(hour >= timeDay && hour < timeNight) sendCmdAll(CMD_INTENSITY, volBrightnessD);
      else sendCmdAll(CMD_INTENSITY, volBrightnessN);
    }
    secFr = 0;
    if(lastMinute!=minute) {
      if(hour==0 && minute==0 && second==0) {
        day++;
        if(day==32 || (day==31 && (month==4 || month==6 || month==9 || month==11)) || (month==2 && ((day==29 && year%4!=0) || (day==30 && year%4==0)))) {
          day=1;
          month++;
          if(month>12){
            month=1;
            year++;
          }
        }
        dayOfWeek++;
        if(dayOfWeek>7) dayOfWeek=1;
      }
      lastMinute=minute;
    }
  } else secFr++;                                                                       // якщо секунда ще не скінчилась то нарощуємо лічильник циклів secFr
  if(minute == 0 && second == 0 && secFr == 0 && (hour >= kuOn && hour < kuOff)) {      // сигнал кожду годину 
    bips();
    bips();
  }
  //----------- РОБОТА З БУДИЛЬНИКОМ------------------------------------------------------
  if(secFr == 0) {
    if(second > 0 && alarms()) {
      if(!alarm_stat && alarm_numer != 255 && !alarm_hold) alarm_stat = 1;
    } else if(alarm_stat) {
      alarm_stat = 0;
      if(alarme[alarm_numer][2] == 11) alarme[alarm_numer][2] = 0;
    } else if(alarm_hold != 0);
  }
  //------------- РОБОТА ЗІ СВЯТКОВИМИ ДАТАМИ ---------------------------------------------
  if(secFr == 0) {
    if(minute == 0) {
      if(hour >= memory_hour_start && hour <= memory_hour_end && second < 15 && second > 2 && !alarm_stat){
        for(byte i = 0; i < 9; i++) {
          if(memory_date[i][0] == day && memory_date[i][1] == month){
            m_date = i;
            bip();
            bip();
            bip();
            printStringWithShift(("         "), timeScrollSpeed, 1);
            printStringWithShift((m_date==0?memory_date_mes0:m_date==1?memory_date_mes1:m_date==2?memory_date_mes2:m_date==3?memory_date_mes3:m_date==4?memory_date_mes4:m_date==5?memory_date_mes5:m_date==6?memory_date_mes6:m_date==7?memory_date_mes7:memory_date_mes8), timeScrollSpeed, 1);
            printStringWithShift(("         "), timeScrollSpeed, 1);
            break;
          }
        }
      } 
    } else m_date = 0;
  }
  //------------- РОБОТА З КНОПКОЮ --------------------------------------------------------
  if(digitalRead(BUT_PIN) == HIGH) {
    if(alarm_stat) {
      alarm_stat = 0;
      alarm_hold = 1;
      if(alarme[alarm_numer][2] == 11) alarme[alarm_numer][2] = 0;
    } else {
      bip();
      showSimpleTemp();
      return;
    }
  }
  // ---------- ВИВІД НА ЕКРАН ГОДИННИКА АБО ТЕМПЕРАТУРИ ЧИ ВОЛОГОСТІ------------------------

  if(!alarm_stat && secFr == 0) {
    if((clockNight && hour>=timeDay && hour<timeNight) || !clockNight) {   //???????????????????????????????????????????
      if(second == 25 && t1 != 85 && sensorDom) {
        showSimpleTemp();
      } else if(second == 38 && sensorUl && t3 != 85) {
        showSimpleTempU();
      } else if(second == 48 && (sensorHumi == 2 || sensorHumi == 4 || sensorHumi == 5) && (h1!=0 && h2!=0)) {
        showSimpleHum();
      } else if(second == 58 && (sensorPrAl == 3 || sensorPrAl == 4)) {
        showSimplePre();
      } else if((hour < timeScrollStart || hour >= timeScrollStop) && second == 10) {
        showSimpleDate();
      }
    }
  } else if(alarm_stat) {
    if(secFr == 0 && second > 1 && second <= 59) {
      clr(1);
      refreshAll();
      bip();
      bip();
    }
  }
  // --------------------------------------------------------------------------------------------------------
  if(secFr == 0) {
    if(second == 10 && minute == 1 && hour == 3) {
      if(rtcStat){
        getRTCDateTime();
        hour=hour_rtc;
        minute=minute_rtc;
        second=second_rtc;
        day=day_rtc;
        month=month_rtc;
        year=year_rtc;
        dayOfWeek=dayOfWeek_rtc;
        if(printCom){
          Serial.println("RTC update: "+String(hour)+":"+String(minute)+":"+String(second)+"    "+String(day)+"."+String(month)+"."+String(year)+" D="+String(dayOfWeek));
        }
      }
    }
    // ---------- 10 секунда - виводимо дату/погоду----------------------------------------------------------
    if(second == 10 && !alarm_stat) {
      sensors();
      if(hour >= timeScrollStart && hour < timeScrollStop && !(clockNight && (hour<timeDay || hour>=timeNight))) {        // працує тілки в дозволений час
        clr(1);
        if(minute % 2 == 0 || !outForecast) {                        // по чотним хвилинам виводимо повідомлення дати та курсу валют
          convertDw();
          convertMonth();
          date = "     " + dw + ", " + String(day) + " " + _month + " " + String(year)+ " " + tYear + "              ";
          printStringWithShift(date.c_str(), timeScrollSpeed, 1);
        } else {                                                      // по не чотним хвилинам виводимо погоду
          printStringWithShift(weatherString.c_str(), timeScrollSpeed, 1);
          printStringWithShift(weatherStringZ.c_str(), timeScrollSpeed, 1);
          if(updateForecast > 0 && updateForecast < 360) printStringWithShift(("  (" + tWeatrTN + String(updateForecast) + tMin + ")        ").c_str(), timeScrollSpeed, 1);
        }
        if(sensorDom) showSimpleTemp();
      }
    }
    // ---------- 30 перевірка доступності WiFi мережі ---// повторне підк. до WiFi кожну 1, 6, 11, 16...56 хв.
    if((second>30 && second<38) && (WiFi.status() != WL_CONNECTED || !WIFI_connected) && !alarm_stat && firstStart) {
      WIFI_connected = false;
      WiFi.disconnect();
      if(minute % 5 == 1) {
        wifiConnect();
        if(WiFi.status() == WL_CONNECTED) WIFI_connected = true;
      }
    }
    // ---------- 43 секунда оновленя мережевого часу кожну хвилину або в 5 хвилину кожного часу
    if(((statusUpdateNtpTime == 0 && second == 43) || (minute == 02 && second == 43)) && !alarm_stat) timeUpdateNTP();
    // ---------- 46 cек. оновлюємо прогноз погоди ------------------------------------- 
    if(second == 46 && hour >= timeScrollStart && hour <= timeScrollStop && !alarm_stat) {
      if(minute == 14 || minute == 44 || updateForecast || updateForecasttomorrow) {
        if((minute == 14 || minute == 44) && outForecast) {
          if(weatherHost==0) {
            getWeatherData0();
          }
          if(weatherHost==0) {
            getWeatherDataz0();
          }
        } else {
          if(updateForecast){
            if(weatherHost==0) {
              getWeatherData0();
            }
          }
          if(updateForecasttomorrow){
            if(weatherHost==0) {
              getWeatherDataz0();
            } 
          }
        }
      }
    }
  }
}
//======================================================================================
//==========ВИВІД НА ЕКРАН ТЕМПЕРАТУРИ В БУДИНКУ========================================
void showSimpleTemp() {
  byte indent = aliData*(NUM_MAX1-4);
  dx = dy = 0;
  clr(1);
  showDigit((t0 < 0.0 ? 4 : 3), 0 + indent, (fontSizeData?znaki5x7:znaki5x8), 1); // друкуємо D+ альбо D-
  if(t1 <= -10.0 || t1 >= 10) showDigit((t1 < 0 ? (t1 * -1) / 10 : t1 / 10), 4 + indent, (fontSizeData?dig5x7:dig5x8), 1);
  showDigit((t1 < 0 ? (t1 * -1) % 10 : t1 % 10), 10 + indent, (fontSizeData?dig5x7:dig5x8), 1);
  showDigit(2, 16 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
  showDigit(t2, 18 + indent, (fontSizeData?dig5x7:dig5x8), 1);
  showDigit(0, 24 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
  showDigit(1, 27 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
  if(dataDown) scrollDown(1);
  refreshAll();
}
//==========ВИВІД НА ЕКРАН ТЕМПЕРАТУРИ НА ВУЛИЦІ========================================
void showSimpleTempU() {
  if(WiFi.status() == WL_CONNECTED) {
    byte indent = aliData*(NUM_MAX1-4);
    dx = dy = 0;
    clr(1);
    showDigit((t5 < 0.0 ? 6 : 5), 0 + indent, (fontSizeData?znaki5x7:znaki5x8), 1); //друкуємо U+ альбо U-
    if(t3 <= -10.0 || t3 >= 10) showDigit((t3 < 0 ? (t3 * -1) / 10 : t3 / 10), 4 + indent, (fontSizeData?dig5x7:dig5x8), 1);
    showDigit((t3 < 0 ? (t3 * -1) % 10 : t3 % 10), 10 + indent, (fontSizeData?dig5x7:dig5x8), 1);
    showDigit(2, 16 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
    showDigit(t4, 18 + indent, (fontSizeData?dig5x7:dig5x8), 1);
    showDigit(0, 24 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
    showDigit(1, 27 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
    if(dataDown) scrollDown(1);
    refreshAll();
  }
}
//==========ВИВІД НА ЕКРАН ВОЛОГОСТІ В БУДИНКУ========================================
void showSimpleHum() {
  byte indent = aliData*(NUM_MAX1-4);
  dx = dy = 0;
  clr(1);
  showDigit(7, 0 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);     // друкуємо знак вологості
  if(h1 >= 0) showDigit(h1, 6 + indent, (fontSizeData?dig5x7:dig5x8), 1);
  showDigit(h2, 12 + indent, (fontSizeData?dig5x7:dig5x8), 1);
  showDigit(2, 18 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
  showDigit(h3, 20 + indent, (fontSizeData?dig5x7:dig5x8), 1);
  showDigit(8, 26 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
  if(dataDown) scrollDown(1);
  refreshAll();
}
//==========ВИВІД НА ЕКРАН ТИСКУ В БУДИНКУ========================================
void showSimplePre() {
  byte indent = aliData*(NUM_MAX1-4);
  dx = dy = 0;
  clr(1);
  showDigit(9, 0 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);     // друкуємо знак тиску
  showDigit(int((sensorPrAl==3?pressBmp:pressBme) / 100), 6 + indent, (fontSizeData?dig5x7:dig5x8), 1);
  showDigit((int((sensorPrAl==3?pressBmp:pressBme) / 10) - int((sensorPrAl==3?pressBmp:pressBme) / 100) * 10) , 12 + indent, (fontSizeData?dig5x7:dig5x8), 1);
  showDigit(((sensorPrAl==3?pressBmp:pressBme) - int((sensorPrAl==3?pressBmp:pressBme) / 10) *10) , 18 + indent, (fontSizeData?dig5x7:dig5x8), 1);
  showDigit(10, 24 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
  showDigit(11, 29 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
  if(dataDown) scrollDown(1);
  refreshAll();
}
//==========ВИВІД НА ЕКРАН ДАТИ=========================================================
void showSimpleDate() {
  byte indent = aliData*(NUM_MAX1-4);
  dx = dy = 0;
  clr(1);
  showDigit(day / 10, 0 + indent, (fontSizeData?dig4x7:dig4x8), 1);
  showDigit(day % 10, 5 + indent, (fontSizeData?dig4x7:dig4x8), 1);
  showDigit(2, 10 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
  showDigit(month / 10, 12 + indent, (fontSizeData?dig4x7:dig4x8), 1);
  showDigit(month % 10, 17 + indent, (fontSizeData?dig4x7:dig4x8), 1);
  showDigit(2, 22 + indent, (fontSizeData?znaki5x7:znaki5x8), 1);
  showDigit((year - 2000) / 10, 23 + indent, (fontSizeData?dig4x7:dig4x8), 1);
  showDigit((year - 2000) % 10, 28 + indent, (fontSizeData?dig4x7:dig4x8), 1);
  if(dataDown) scrollDown(1);
  refreshAll();
}
//==========ВИВІД НА ЕКРАН АНІМАЦІЙНОГО ГОДИННИКА=======================================
void showAnimClock() {
  byte digPos[6] {5, 10, 18, 23, 15, 47,};
  if(hour < 10) {digPos[1]=7; digPos[2]=15; digPos[3]=20; digPos[4]=12; digPos[5]=44;}
  if(fontCLOCK < 2 || cn) {
    if(hour < 10) {digPos[1]=5; digPos[2]=15; digPos[3]=22; digPos[4]=12; digPos[5]=44;}
    else {digPos[0]=1; digPos[1]=8; digPos[2]=18; digPos[3]=25; digPos[4]=15; digPos[5]=47;}
  } else if(fontCLOCK < 6 && !cn) {
    if(hour < 10) {digPos[1]=6; digPos[2]=15; digPos[3]=21; digPos[4]=12;}
    else {digPos[0]=3; digPos[1]=9; digPos[2]=18; digPos[3]=24; digPos[4]=15;}
  }
  int digHt = 16;
  bool num = hour < 10 ? 1 : 0;
  int i;
  if(del == 0) {
    del = digHt;
    for(i = num; i < 4; i++) digold[i] = dig[i];
    dig[0] = hour / 10 ;
    dig[1] = hour % 10;
    dig[2] = minute / 10;
    dig[3] = minute % 10;
    for(i = num; i < 4; i++)  digtrans[i] = (dig[i] == digold[i]) ? 0 : digHt;
  } else del--;
  clr(0);
  if(cn) clr(1);
  for(i = num; i < 4; i++) {   
    if(digtrans[i] == 0) {
      dy = 0;
      if(!cn) {
        if(fontCLOCK == 0) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig6x7 : dig6x8), 0);
        else if(fontCLOCK == 1) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig6x7dig : dig6x8dig), 0);
        else if(fontCLOCK == 2) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig5x7rn : dig5x8rn), 0);
        else if(fontCLOCK == 3) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig5x7rndig : dig5x8rndig), 0);
        else if(fontCLOCK == 4) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig5x7 : dig5x8), 0);
        else if(fontCLOCK == 5) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig5x7dig : dig5x8dig), 0);
        else if(fontCLOCK == 6) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig4x7 : dig4x8), 0);
        else if(fontCLOCK == 7) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig4x7dig : dig4x8dig), 0);
      } else {
        showDigit(dig[i], digPos[i], dig6x8bigH, 0);
        showDigit(dig[i], digPos[i]+(aliData*(NUM_MAX1-4)), dig6x8bigL, 1);
      }
    } else {
      dy = digHt - digtrans[i];
      if(!cn) {
        if(fontCLOCK == 0) showDigit(digold[i], digPos[i], (fontSizeCLOCK ? dig6x7 : dig6x8), 0);
        else if(fontCLOCK == 1) showDigit(digold[i], digPos[i], (fontSizeCLOCK ? dig6x7dig : dig6x8dig), 0);
        else if(fontCLOCK == 2) showDigit(digold[i], digPos[i], (fontSizeCLOCK ? dig5x7rn : dig5x8rn), 0);
        else if(fontCLOCK == 3) showDigit(digold[i], digPos[i], (fontSizeCLOCK ? dig5x7rndig : dig5x8rndig), 0);
        else if(fontCLOCK == 4) showDigit(digold[i], digPos[i], (fontSizeCLOCK ? dig5x7 : dig5x8), 0);
        else if(fontCLOCK == 5) showDigit(digold[i], digPos[i], (fontSizeCLOCK ? dig5x7dig : dig5x8dig), 0);
        else if(fontCLOCK == 6) showDigit(digold[i], digPos[i], (fontSizeCLOCK ? dig4x7 : dig4x8), 0);
        else if(fontCLOCK == 7) showDigit(digold[i], digPos[i], (fontSizeCLOCK ? dig4x7dig : dig4x8dig), 0);
      } else {
        showDigit(digold[i], digPos[i], dig6x8bigH, 0);
        showDigit(digold[i], digPos[i]+(aliData*(NUM_MAX1-4)), dig6x8bigL, 1);
      }
      dy =- digtrans[i];
      if(!cn  ) {
        if(fontCLOCK == 0) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig6x7 : dig6x8), 0);
        else if(fontCLOCK == 1) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig6x7dig : dig6x8dig), 0);
        else if(fontCLOCK == 2) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig5x7rn : dig5x8rn), 0);
        else if(fontCLOCK == 3) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig5x7rndig : dig5x8rndig), 0);
        else if(fontCLOCK == 4) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig5x7 : dig5x8), 0);
        else if(fontCLOCK == 5) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig5x7dig : dig5x8dig), 0);
        else if(fontCLOCK == 6) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig4x7 : dig4x8), 0);
        else if(fontCLOCK == 7) showDigit(dig[i], digPos[i], (fontSizeCLOCK ? dig4x7dig : dig4x8dig), 0);
      } else {
        showDigit(dig[i], digPos[i], dig6x8bigH, 0);
        showDigit(dig[i], digPos[i]+(aliData*(NUM_MAX1-4)), dig6x8bigL, 1);
      }
      digtrans[i]--;
    }
  }
  dy = 0;
  int flash = millis() % 1000;
  if(!cn) {
    if(!alarm_stat){
      if((flash >= 180 && flash < 360) || flash >= 540) { // мерегтіння двокрапок в годиннику підвязуємо до личильника циклів
        setCol(digPos[4], WIFI_connected ? (fontSizeCLOCK ? 0x36 : 0x66) : (fontSizeCLOCK ? 0x30 : 0x60));
        setCol(digPos[4]+1, WIFI_connected ? (fontSizeCLOCK ? 0x36 : 0x66) : (fontSizeCLOCK ? 0x30 : 0x60));
      }
      if(statusUpdateNtpTime) { // якщо останнє оновленя часу було вдалим, то двокрапки в годиннику будуть анімовані
        if(flash >= 0 && flash < 180) {
          setCol(digPos[4], WIFI_connected ? (fontSizeCLOCK ? 0x14 : 0x24) : (fontSizeCLOCK ? 0x10 : 0x20));
          setCol(digPos[4]+1, WIFI_connected ? (fontSizeCLOCK ? 0x22 : 0x42) : (fontSizeCLOCK ? 0x20 : 0x40));
        }
        if(flash >= 360 && flash < 540) {
          setCol(digPos[4], WIFI_connected ? (fontSizeCLOCK ? 0x22 : 0x42) : (fontSizeCLOCK ? 0x20 : 0x40));
          setCol(digPos[4]+1, WIFI_connected ? (fontSizeCLOCK ? 0x14 : 0x24) : (fontSizeCLOCK ? 0x10 : 0x20));
        }
      }
      if(updateForecast && WIFI_connected) setCol(00, flash < 500 ? 0x80 : 0x00);
      if(updateForecasttomorrow && WIFI_connected) setCol(31, flash < 500 ? 0x80 : 0x00);
    } else {
      setCol(digPos[4], (fontSizeCLOCK ? 0x36 : 0x66));
      setCol(digPos[4]+1, (fontSizeCLOCK ? 0x36 : 0x66));
    }
  } else {
    if(!alarm_stat){
    if((flash >= 180 && flash < 360) || flash >= 540) { // мерегтіння двокрапок в годиннику підвязуємо до личильника циклів
      setCol(digPos[4], WIFI_connected ? 0x60 : 0x00);
      setCol(digPos[4]+1, WIFI_connected ? 0x60 : 0x00);
      setCol(digPos[5]+(aliData*(NUM_MAX1-4)), WIFI_connected ? 0x06 : 0x00);
      setCol(digPos[5]+1+(aliData*(NUM_MAX1-4)), WIFI_connected ? 0x06 : 0x00);
    }
    if(statusUpdateNtpTime) { // якщо останнє оновленя часу було вдалим, то двокрапки в годиннику будуть анімовані
      if(flash >= 0 && flash < 180) {
        setCol(digPos[4], WIFI_connected ? 0x20 : 0x00);
        setCol(digPos[4]+1, WIFI_connected ? 0x40 : 0x00);
        setCol(digPos[5]+(aliData*(NUM_MAX1-4)), WIFI_connected ? 0x04 : 0x00);
        setCol(digPos[5]+1+(aliData*(NUM_MAX1-4)), WIFI_connected ? 0x02 : 0x00);
      }
      if(flash >= 360 && flash < 540) {
        setCol(digPos[4], WIFI_connected ? 0x40 : 0x00);
        setCol(digPos[4]+1, WIFI_connected ? 0x20 : 0x00);
        setCol(digPos[5]+(aliData*(NUM_MAX1-4)), WIFI_connected ? 0x02 : 0x00);
        setCol(digPos[5]+1+(aliData*(NUM_MAX1-4)), WIFI_connected ? 0x04 : 0x00);
      }
    }
    if(updateForecast && WIFI_connected) setCol(00, flash < 500 ? 0x80 : 0x00);
    if(updateForecasttomorrow && WIFI_connected) setCol(31, flash < 500 ? 0x80 : 0x00);
  } else {
    setCol(digPos[4], 0x66);
    setCol(digPos[4]+1, 0x66);
    setCol(digPos[5]+(aliData*(NUM_MAX1-4)), 0x36);
    setCol(digPos[5]+1+(aliData*(NUM_MAX1-4)), 0x36);
  }
  }
  refreshAll();
}
//=================================================
void showAnimWifi(byte probaWifi) {
  dy = 0;
  showDigit(probaWifi / 10, 8, dig6x7dig, 1);
  showDigit(probaWifi % 10, 15, dig6x7dig, 1);
  if(dataDown) scrollDown(1);
  refreshAll();
}

//==========ДРУКУВАННЯ БІГУЧОЇ СТРОКИ *s - текст, shiftDelay - швидкість, zone - зона екрану==================
void printStringWithShift(const char* s, int shiftDelay, byte zone) {
  while(*s) {
    printCharWithShift(*s, shiftDelay, zone);
    s++;
    server.handleClient();
  }
}
//==========ДРУКУВАННЯ БІГУЧОГО СИМВОЛУ с - символ, shiftDelay - швидкість, zone - зона екрану================
void printCharWithShift(unsigned char c, int shiftDelay, byte zone) {
  c = convert_fonts(c);
  if(c < ' ') return;
  c -= 32;
  int w = showChar(c, fonts, zone);
  for(int i = 0; i < w + 1; i++){
    delay(shiftDelay);
    scrollLeft(zone);
    refreshAll();
  }
}
//==========ВИІД СИМВОЛУ НА ЕКРАН ch -  код символу, *data -  посилання на шрифт, zone - зона екрану===========
int showChar(char ch, const uint8_t *data, byte zone) {
  int len = pgm_read_byte(data);
  int i,w = pgm_read_byte(data + 1 + ch * len);
  for(i = 0; i < w; i++){
    scr[(zone?NUM_MAX0+NUM_MAX1:NUM_MAX0) * 8 + i] = pgm_read_byte(data + 1 + ch * len + 1 + i) << textDown ;
  }
  scr[(zone?NUM_MAX0+NUM_MAX1:NUM_MAX0) * 8 + i] = 0;
  return w;
}
//==========ВИІД СИМВОЛУ НА ЕКРАН ch -  код символу, col- позиція, *data -  посилання на шрифт, zone - зона екрану===========
void showDigit(char ch, int col, const uint8_t *data, byte zone) {
  if(dy < -8 | dy > 8) return;
  int len = pgm_read_byte(data);
  int w = pgm_read_byte(data + 1 + ch * len);
  col += dx + (zone ? NUM_MAX0*8:0);
  for(int i = 0; i < w; i++) {
    if(col + i >= 0 && col + i < 8 * (NUM_MAX0 + NUM_MAX1)) {
      byte v = pgm_read_byte(data + 1 + ch * len + 1 + i);
      if(!dy) scr[col + i] = v;
      else scr[col + i] |= dy > 0 ? v >> dy : v << -dy;
    }
  }
}
//======================================================================================
void setCol(int col, byte v) {
  if(dy < -8 | dy > 8) return;
  col += dx;
  if(col >= 0 && col < 8 * (NUM_MAX0 + NUM_MAX1)) {
    if(!dy) scr[col] = v; else scr[col] |= dy > 0 ? v >> dy : v << -dy;
  }
}

//==========КОНВЕРТАЦІЯ СИМВОЛІВ В РАЗІ ВИКОРИСТАННЯ УКРАЇНСЬКИХ ЛІТЕР==================
byte dualChar = 0;
unsigned char convert_fonts(unsigned char _c) {
  unsigned char c = _c;
  // конвертирование латиницы
  if(c == 208) {
    dualChar = 1;
    return 0;
  }
  else if(c == 209 || c == 210) {
    dualChar = 2;
    return 0;
  }
  if(c == 32 && dualChar != 3) {
    dualChar = 3;
    return c;
  }
  if(dualChar == 1) {
    if(c >= 144 && c < 192) {c += 48;}
    dualChar = 0;
    return c;
  }
  if(dualChar == 2) {
    if(c >= 128 && c < 144) {
      c += 112;
    } 
    switch(_c) {
      case 144: c = 133; break;
      case 145: c = 149; break;
    }
    dualChar = 0;
    return c;
  }
  // конвертирование польского и немецкого
  if(c == 195) {
    dualChar = 4;
    return 0;
  }
  if(c == 196) {
    dualChar = 5;
    return 0;
  }
  if(c == 197) {
    dualChar = 6;
    return 0;
  }
  if(dualChar == 4) {
    switch(_c) {
      case 132: c = 177; break;
      case 147: c = 166; break;
      case 150: c = 179; break;
      case 156: c = 181; break;
      case 159: c = 183; break;
      case 164: c = 178; break;
      case 179: c = 167; break;
      case 182: c = 180; break;
      case 188: c = 182; break;
    }
    dualChar = 0;
    return c;
  }
  if(dualChar == 5) {
    if(c >= 132 && c < 136) {
      c += 26;
    }
    switch(_c) {
      case 152: c = 168; break;
      case 153: c = 169; break;
    }
    dualChar = 0;
    return c;
  }
  if(dualChar == 6) {
    if(c >= 129 && c < 133) {
      c += 33;
    }
    if(c >= 154 && c < 156) {
      c += 16;
    }
    if(c >= 185 && c < 189) {
      c -= 13;
    }  
    dualChar = 0;
    return c;
  }
}


//==========
void saveChrMas(String string_t, byte lenght_off, byte number_s) {
  byte lenght = string_t.length();
  if(lenght>lenght_off) return;
  const char *s = string_t.c_str();
  
  for(int i=0; i<lenght; i++) {
    //snprintf(*memory_date_mes[number_s], 1, "%s", *s);
    s++;
  }
}
//==========ОНОВЛЕННЯ ЛОКАЛЬНОГО ЧАСУ (ЛОКАЛЬНІ ЧАСИ)===============================================================
void updateTime() {
  long curEpoch = localEpoc + ((millis() - localMillisAtUpdate) / 1000);
  long epoch = round(curEpoch + 86400L);
  epoch = (epoch % 86400L);
  hour = ((epoch % 86400L) / 3600) % 24;
  minute = (epoch % 3600) / 60;
  second = epoch % 60;
}
//==========ОНОВЛЕННЯ МЕРЕЖЕВОГО ЧАСУ (перевірка в три проходи)====================================================
void timeUpdateNTP() {
  if(!WIFI_connected) return;
  if(printCom) printTime();
  statusUpdateNtpTime = 1;
  for(int timeTest = 0; timeTest < 3; timeTest++) {
    getNTPtime();
    if(printCom) {
      if(timeTest) Serial.print("          ");
      Serial.println("Proba #"+String(timeTest+1)+"   "+String(g_hour)+":"+((g_minute<10)?"0":"")+String(g_minute)+":"+((g_second<10)?"0":"")+String(g_second));
    }
   // updateTime();

    hourTest[timeTest] = g_hour;
    minuteTest[timeTest] = (g_minute || (g_minute==59?0:g_minute++));
    if(statusUpdateNtpTime == 0) {
      if(printCom) {
        printTime();
        Serial.print("ERROR TIME!!!\r\n");
      }
        return;
    }
    if(timeTest > 0) {
      if((hourTest[timeTest] != hourTest[timeTest - 1]||minuteTest[timeTest] != minuteTest[timeTest - 1])) {
        statusUpdateNtpTime = 0;
        if(printCom) {
          printTime();
          Serial.print("ERROR TIME!!!\r\n");
        }
        return;
      }
    }
  }
  hour=g_hour;
  minute=g_minute;
  second=g_second;
  day=g_day;
  dayOfWeek=g_dayOfWeek;
  month=g_month;
  year=g_year;
  if(rtcStat){
    hour_rtc = hour;
    minute_rtc = minute;
    second_rtc = second;
    month_rtc = month;
    day_rtc = day;
    dayOfWeek_rtc = dayOfWeek;
    year_rtc = year;
    setRTCDateTime();
  }
  localMillisAtUpdate = millis();
  localEpoc = (hour * 60 * 60 + minute * 60 + second);
  convertDw();
  convertMonth();
  saveTime();
  if(printCom) {
    printTime();
    Serial.println((day < 10 ? "0" : "") + String(day) + "." + (month < 10 ? "0" : "") + String(month) + "." + String(year) + " DW = " + String(dayOfWeek));
    Serial.println("          Time update OK.");
  }
}
//==========ОТРИМАННЯ ДАТИ ТА ЧАСУ ВІД СЕРВЕРА ТОЧНОГО ЧАСУ =============================================================
void getNTPtime() {
  WiFi.hostByName(ntpServerName.c_str(), timeServerIP); 
  int cb;
  for(int i = 0; i < 3; i++){
    memset(packetBuffer, 0, NTP_PACKET_SIZE);
    packetBuffer[0] = 0b11100011;
    packetBuffer[1] = 0;
    packetBuffer[2] = 6;
    packetBuffer[3] = 0xEC;
    packetBuffer[12] = 49;
    packetBuffer[13] = 0x4E;
    packetBuffer[14] = 49;
    packetBuffer[15] = 52;
    udp.beginPacket(timeServerIP, 123);                     //NTP порт 123
    udp.write(packetBuffer, NTP_PACKET_SIZE);
    udp.endPacket();
    delay(800);                                             // чекаємо пів секуни
    cb = udp.parsePacket();
    if(!cb && printCom) Serial.println("          no packet yet..." + String (i + 1)); 
    if(!cb && i == 2) {                                              // якщо час не отримано
      statusUpdateNtpTime = 0;
      return;                                             // вихіз з getNTPtime()
    }
    if(cb) i = 3;
  }
  if(cb) {                                                   // якщо отримали пакет з серверу
    udp.read(packetBuffer, NTP_PACKET_SIZE);
    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    const unsigned long seventyYears = 2208988800UL;        // Unix час станом на 1 січня 1970. в секундах, то 2208988800:
    unsigned long epoch = secsSince1900 - seventyYears;
    epochNM = epoch - (millis()/1000);
    boolean summerTime;
    if(month < 3 || month > 10) summerTime = false;             // не переходимо на літній час в січні, лютому, листопаді і грудню
    if(month > 3 && month < 10) summerTime = true;              // Sommerzeit лічимо в квіні, травні, червені, липні, серпені, вересені
    if(month == 3 && (hour + 24 * day) >= (3 + 24 * (31 - (5 * year / 4 + 4) % 7)) || month == 10 && (hour + 24 * day) < (3 + 24 * (31 - (5 * year / 4 + 1) % 7))) summerTime = true; 
    epoch = epoch + (int)(timeZone*3600 + (3600*(isDayLightSaving && summerTime)));      
    g_year = 0;
    int days = 0;
    uint32_t time;
    time = epoch/86400;
    g_hour = (epoch % 86400L) / 3600;
    g_minute = (epoch % 3600) / 60;
    g_second = epoch % 60;
    g_dayOfWeek = (((time) + 4) % 7) + 1;
    while((unsigned)(days += (LEAP_YEAR(g_year) ? 366 : 365)) <= time) {
      g_year++;
    }
    days -= LEAP_YEAR(g_year) ? 366 : 365;
    time -= days;
    days = 0;
    g_month = 0;
    uint8_t monthLength = 0;
    for(g_month = 0; g_month < 12; g_month++){
      if(g_month == 1){
        if(LEAP_YEAR(g_year)) monthLength = 29;
        else monthLength = 28;
      }
      else monthLength = monthDays[g_month];
      if(time >= monthLength) time -= monthLength;
      else break;
    }
    g_month++;
    g_day = time + 1;
    g_year += 1970;
    return;
  }
  if(printCom) Serial.println("Nie ma czasu(((");
}
//===============================================================================================================================//
//                              БЕРЕМО ПОГОДУ З САЙТУ  https://www.weatherbit.io                                                 //
//===============================================================================================================================//
void getWeatherData0() {
  location_name = "";
  location_region = "";
  location_country = "";
  location_localtime = "";
  location_temp = 0;
  location_app_temp = 0;
  location_rh = 0;
  location_pres = 0;
  location_wind_spd = 0;
  location_wind_cdir_full = "";
  location_sunrise = "";
  location_sunset = "";
  location_clouds = 0;
  location_vis = 0;
  location_uv = 0;
  location_weather_description = "";
  if(!WIFI_connected) {
    updateForecast++;
    if(updateForecast >= 360) weatherString = tWeatrNot;
    return;
  }
  if(printCom) {
    printTime();
    Serial.println("Getting weather forecast for City " +  cityID0 + "...");
  }
  if(ESPclient.connect(weatherHost0.c_str(), 80)) {
  } else {
    if(printCom) Serial.println("          Not connection server!!!");
    updateForecast++;
    if(updateForecast >= 360) weatherString = tWeatrNot;
    return;
  }

  HTTPClient http;
  String line="";
  String reqline="http://"+weatherHost0+"/v2.0/current/daily?city="+urlencode(cityID0)+"&lang="+weatherLang+"&key="+weatherKey0;
  if(printCom) {
    Serial.println("=======================================================");
    Serial.println(reqline);
    Serial.println("=======================================================");
  }  
  if (http.begin(ESPclient, reqline)) { // HTTP
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        line = http.getString();
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  } else {
    Serial.printf("[HTTP} Unable to connect\n");
  }  
  if(printCom) {
    Serial.print("line =");
    Serial.println(line);
  }
  const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(37) + 1128; //https://arduinojson.org/v6/assistant/
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, line);
  if(!doc.capacity()){
    if(printCom) Serial.println("          Parse weather forecast - FAILED!!!");
    updateForecast++;
    if(updateForecast >= 360) weatherString = tWeatrNot;
    return;
  }

  JsonObject data = doc["data"][0];
  location_rh = data["rh"]; // 69
  location_pres = data["pres"]; // 999.3
  location_pres /= 1.3332239;
  const char* data_timezone = data["timezone"]; // "Europe/Kiev"
  location_region = data_timezone;
  const char* data_ob_time = data["ob_time"]; // "2019-09-19 17:57"
  location_localtime = data_ob_time;
  const char* data_country_code = data["country_code"]; // "UA"
  location_country = data_country_code;
  location_clouds = data["clouds"]; // 4
  const char*   data_city_name = data["city_name"]; // "Kiev"
  location_name = data_city_name;
  location_wind_spd = data["wind_spd"]; // 1
  const char* data_wind_cdir_full = data["wind_cdir_full"]; // "пі́вдень-пі́вдень-схід"
  location_wind_cdir_full = data_wind_cdir_full;
  location_vis = data["vis"]; // 5
  const char*   data_sunset = data["sunset"]; // "16:01"
  location_sunset = data_sunset;
  location_uv = data["uv"]; // 0
  int           data_wind_dir = data["wind_dir"]; // 166
  const char*   data_sunrise = data["sunrise"]; // "03:39"
  location_sunrise = data_sunrise;   //int         data_dni = data["dni"]; // 0
  JsonObject    data_weather = data["weather"];
  const char*   data_weather_description = data_weather["description"]; // "ясного неба"
  location_weather_description = data_weather_description;
  location_temp = data["temp"]; // 10.6
  location_app_temp = data["app_temp"]; // 10.6

  //const char* data_pod = data["pod"]; // "n"
  //float       data_lon = data["lon"]; // 30.5238
  //float       data_dewpt = data["dewpt"]; // 5.2
  //int         data_precip = data["precip"]; // 0
  //int         data_snow = data["snow"]; // 0
  //long        data_ts = data["ts"]; // 1568915820
  //int         data_solar_rad = data["solar_rad"]; // 0
  //const char* data_state_code = data["state_code"]; // "12"
  //const char* data_last_ob_time = data["last_ob_time"]; // "2019-09-19T17:57:00"
  //const char* data_wind_cdir = data["wind_cdir"]; // "ЮЮВ"
  //float       data_slp = data["slp"]; // 1017.9
  //int         data_h_angle = data["h_angle"]; // -90
  //int         data_ghi = data["ghi"]; // 0
  //int         data_dhi = data["dhi"]; // 0
  //int         data_aqi = data["aqi"]; // 25
  //float       data_lat = data["lat"]; // 50.45466
  //const char* data_weather_icon = data_weather["icon"]; // "c01n"
  //const char* data_weather_code = data_weather["code"]; // "800"
  //const char* data_datetime = data["datetime"]; // "2019-09-19:18"
  //const char* data_station = data["station"]; // "E0036"
  //float       data_elev_angle = data["elev_angle"]; // -18.88
  //int count = doc["count"]; // 1

  String windDegString;
  if(data_wind_dir >= 345 || data_wind_dir <= 22)  windDegString = "С";    //"\211";    //"Північний";
  if(data_wind_dir >= 23  && data_wind_dir <= 68)  windDegString = "СВ";   //"\234";    //"Північно-східний";
  if(data_wind_dir >= 69  && data_wind_dir <= 114) windDegString = "В";    //"\230";    //"Східний";
  if(data_wind_dir >= 115 && data_wind_dir <= 160) windDegString = "ЮВ";   //"\235";    //"Південно-східний";
  if(data_wind_dir >= 161 && data_wind_dir <= 206) windDegString = "Ю";    //"\210";    //"Південний";
  if(data_wind_dir >= 207 && data_wind_dir <= 252) windDegString = "ЮЗ";   //"\232";    //"Південно-західний";
  if(data_wind_dir >= 253 && data_wind_dir <= 298) windDegString = "З";     //"\231";    //"Західний";
  if(data_wind_dir >= 299 && data_wind_dir <= 344) windDegString = "СЗ";   //"\233";    //"Північно-західний";

  weatherString = "         " + tNow + ": \212 " + String(location_temp, 1) + ("\202") + "C";
  weatherString += ", \213 " + String(location_rh) + "%"; 
  weatherString += ", \215 " + String((location_pres), 0) + tPress;
  weatherString += ", \214 " + windDegString + ", " + String(location_wind_spd, 1) + tSpeed;
  weatherString += ", \216 " + String(location_clouds) + "%, " + data_weather_description + ". ";
  updateForecast = 0;
}
// ============================================================================//
//               Беремо ПРОГНОЗ!!! погоди з сайту https://www.weatherbit.io     // 
// ============================================================================//
void getWeatherDataz0() {
  if(!WIFI_connected) {
    updateForecasttomorrow++;
    if(updateForecast >= 360) weatherStringZ = "";
    return;
  }
    //if(printCom) printTime();
  //if(printCom) Serial.println("Getting weather forecast for tomorrow...");
  HTTPClient http;
  String line="";
  String reqline="http://"+weatherHost0+"/v2.0/forecast/daily?city="+urlencode(cityID0)+"&lang="+weatherLang+"&days=2&key="+weatherKey0;
  if(printCom) {
    Serial.println("=======================================================");
    Serial.println(reqline);
    Serial.println("=======================================================");
  }  
  if (http.begin(ESPclient, reqline)) { // HTTP

   int httpCode = http.GET();
   if (httpCode > 0) {
     Serial.printf("[HTTP] GET... code: %d\n", httpCode);
     if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
      line = http.getString();
     }
   } else {
     Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
   }
   http.end();
  } else {
   Serial.printf("[HTTP} Unable to connect\n");
  }
  if(printCom) {
    Serial.print("line2=");
    Serial.println(line);
  }
  
  const size_t capacity = JSON_ARRAY_SIZE(2) + 2*JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(7) + 2*JSON_OBJECT_SIZE(37) + 2321;
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, line);
  if(!doc.capacity()){
    if(printCom) Serial.println("          Parse weather forecast for tomorrow - FAILED!!!");
    updateForecasttomorrow++;
    if(updateForecast >= 360) weatherStringZ = "";
    return;
  }
  JsonObject data_0 = doc["data"][0];
  JsonObject data_0_weather = data_0["weather"];
  const char* data_0_weather_description = data_0_weather["description"]; // "Помірний дощ"
  float data_0_max_temp = data_0["max_temp"]; // 13.4
  float data_0_min_temp = data_0["min_temp"]; // 10.9
  JsonObject data_1 = doc["data"][1];
  int data_1_rh = data_1["rh"]; // 75
  float data_1_pres = data_1["pres"]; // 1000.56
  int data_1_clouds = data_1["clouds"]; // 58
  int data_1_wind_dir = data_1["wind_dir"]; // 166
  float data_1_wind_spd = data_1["wind_spd"]; // 3.75302
  JsonObject data_1_weather = data_1["weather"];
  const char* data_1_weather_description = data_1_weather["description"]; // "Світло душ дощ"
  float data_1_max_temp = data_1["max_temp"]; // 16.3
  float data_1_min_temp = data_1["min_temp"]; // 10

  String windDegString_1;
  if(data_1_wind_dir >= 345 || data_1_wind_dir <= 22)  windDegString_1 = "С";    //"\211";    //"Північний";
  if(data_1_wind_dir >= 23  && data_1_wind_dir <= 68)  windDegString_1 = "СВ";   //"\234";    //"Північно-східний";
  if(data_1_wind_dir >= 69  && data_1_wind_dir <= 114) windDegString_1 = "В";    //"\230";    //"Східний";
  if(data_1_wind_dir >= 115 && data_1_wind_dir <= 160) windDegString_1 = "ЮВ";   //"\235";    //"Південно-східний";
  if(data_1_wind_dir >= 161 && data_1_wind_dir <= 206) windDegString_1 = "Ю";    //"\210";    //"Південний";
  if(data_1_wind_dir >= 207 && data_1_wind_dir <= 252) windDegString_1 = "ЮЗ";   //"\232";    //"Південно-західний";
  if(data_1_wind_dir >= 253 && data_1_wind_dir <= 298) windDegString_1 = "З";     //"\231";    //"Західний";
  if(data_1_wind_dir >= 299 && data_1_wind_dir <= 344) windDegString_1 = "СЗ";   //"\233";    //"Північно-західний";
  
  weatherStringZ = "";
  if(hour<18) weatherStringZ += tCurr + ": ";
  if(hour<12) weatherStringZ += "\212" + String(data_0_max_temp, 1) + "..." + String(data_0_min_temp, 1) + "\202" + "C, ";
  if(hour<18) weatherStringZ += String(data_0_weather_description) + ". ";
  weatherStringZ += tTom + ": \212" + String(data_1_max_temp, 1) + "..." + String(data_1_min_temp, 1) + "\202" + "C";
  weatherStringZ += ", \213 " + String(data_1_rh) + "%";
  weatherStringZ += ", \214 " + windDegString_1 + ", " + String(data_1_wind_spd, 1) + tSpeed;
  weatherStringZ += ", " + String(data_1_weather_description) + ".  ";
  if(printCom) Serial.println("          Getting weather forecast for tomorrow - is OK.");
  updateForecasttomorrow = 0;
}
//=========================================================================================================
void wifiConnect(){
  if(printCom) {
    printTime();
    Serial.print("Connecting WiFi (ssid="+String(ssid.c_str())+"  pass="+String(password.c_str())+") ");
  }
  if(!firstStart) printStringWithShift("WiFi", 15, 1);
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  delay (800);
  clr(1);
  for(int i=1; i<21; i++){
    if(WiFi.status()==WL_CONNECTED){
      WIFI_connected=true;
      if(printCom) {
        Serial.print(" IP adress : ");
        Serial.println(WiFi.localIP());
        
      }
      if(!firstStart && !cn){
        String aaa = WiFi.localIP().toString() + "                ";
        if(NUM_MAX1>4){
          for(int j=0; j<NUM_MAX1-4; j++) aaa+="  ";
        }
        clr(1);
        printStringWithShift(" IP: ", 15, 1);
        printStringWithShift(aaa.c_str(), 25, 1);
      }
      firstStart=1;
      timeUpdateNTP();
      amountNotStarts=0;
      return;
    }
    if(printCom) Serial.print(".");
    if(!firstStart){
      int j = 0;
      while(j < 500){
        if(j % 10 == 0 && !cn) showAnimWifi(i);
        j++;
        delay(1);
      }
    }
    delay (800);
  }
  WiFi.disconnect();
  if(printCom) Serial.println(" Not connected!!!");
  amountNotStarts++;
  if(printCom) {
    Serial.print("Amount of the unsuccessful connecting = ");
    Serial.println(amountNotStarts);
  }
  if(amountNotStarts>21) {
    amountNotStarts=0;
    firstStart=0;
    cn=0;
    //ESP.reset();
  }
  if(!firstStart){
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    WiFi.softAP(ssidAP.c_str(), passwordAP.c_str());
    if(printCom) {
      printTime();
      Serial.println("Start AP mode!!!");
      Serial.print("          Wifi AP IP : ");
      Serial.println(WiFi.softAPIP());
    }
    updateTime();
    printStringWithShift(tPoint.c_str(), 35, 1);
    //firstStart=1;
  }
}
// ===========================КОНВЕРТАЦІЯ НАЗВ ДНІВ ТИЖНЯ НА УКРАЇНСЬКУ МОВУ============================================
void convertDw(){
  switch(dayOfWeek){
    case 1 : dw = tSunday;    break;
    case 2 : dw = tMonday;    break;
    case 3 : dw = tTuesday;   break;
    case 4 : dw = tWednesday; break;
    case 5 : dw = tThursday;  break;
    case 6 : dw = tFriday;    break;
    case 7 : dw = tSaturday;  break;
  }
}
// ===========================КОНВЕРТАЦІЯ НАЗВ МІСЯЦІВ НА УКРАЇНСЬКУ МОВУ============================================
void convertMonth(){
  switch(month){
    case 1 : _month = tJanuary;      break;
    case 2 : _month = tFebruary;     break;
    case 3 : _month = tMarch;        break;
    case 4 : _month = tApril;        break;
    case 5 : _month = tMay;          break;
    case 6 : _month = tJune;         break;
    case 7 : _month = tJuly;         break;
    case 8 : _month = tAugust;       break;
    case 9 : _month = tSeptember;    break;
    case 10 : _month = tOctober;     break;
    case 11 : _month = tNovember;    break;
    case 12 : _month = tDecember;    break;
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void sensors() {
    sensorsDs18b20();
    sensorsSi7021();
    sensorsBmp();
    sensorsBme();
    t0 = (sensorDom==0?0:sensorDom==1?tempDs18b20:sensorDom==2?celsiusSi7021:sensorDom==3?tempBmp:sensorDom==4?tempBme:0);
    t1 = (sensorDom==0?0:sensorDom==1?(int)tempDs18b20:sensorDom==2?(int)celsiusSi7021:sensorDom==3?(int)tempBmp:sensorDom==4?(int)tempBme:0);
    t2 = (sensorDom==0?0:sensorDom==1?((int)(tempDs18b20*(tempDs18b20<0?-10:10))%10):sensorDom==2?((int)(celsiusSi7021*(celsiusSi7021<0?-10:10))%10):sensorDom==3?((int)(tempBmp*(tempBmp<0?-10:10))%10):sensorDom==4?((int)(tempBme*(tempBme<0?-10:10))%10):0);
    t3 = (sensorUl==0?0:sensorUl==1?(int)tempDs18b20:sensorUl==2?(int)celsiusSi7021:sensorUl==3?(int)tempBmp:sensorUl==4?(int)tempBme:0);
    t4 = (sensorUl==0?0:sensorUl==1?((int)(tempDs18b20*(tempDs18b20<0?-10:10))%10):sensorUl==2?((int)(celsiusSi7021*(celsiusSi7021<0?-10:10))%10):sensorUl==3?((int)(tempBmp*(tempBmp<0?-10:10))%10):sensorUl==4?((int)(tempBme*(tempBme<0?-10:10))% 10):0);
    t5 = (sensorUl==0?0:sensorUl==1?tempDs18b20:sensorUl==2?celsiusSi7021:sensorUl==3?tempBmp:sensorUl==4?tempBme:0);
  if(sensorHumi == 0) {
    h1 = 0;
    h2 = 0;
    h3 = 0;
  }
  if(sensorHumi == 2){
    h1 = humSi7021 / 10;
    h2 = int(humSi7021) % 10;
    h3 = int(humSi7021 * 10) % 10;
  }
  if(sensorHumi == 4){
    h1 = humBme / 10;
    h2 = int(humBme) % 10;
    h3 = int(humBme * 10) % 10;
  }
}
//--------------------------------------------------------------------------
void sensorsDs18b20() {  //1
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  if(!ds.search(addr)) {                                // Стартуємо функцію пошук першого або наступного датчика в addr-возвращаем ответ датчика
    ds.reset_search();                                  // Якщо добігли кінця адресного простору, то скидуємо адрес на початок простору
    delay(250);                                         // Пауза
    return;                                             // Виходимо з підпрограми
  }
  if(OneWire::crc8(addr, 7) != addr[7]) return;           // перевіряємо 7 байт в addr - он содержит crc8 
  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);
  delay(750);
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);
  for(byte i = 0; i < 9; i++) {
    data[i] = ds.read();
  }
  int16_t raw = (data[1] << 8) | data[0];
  if(type_s) {
    raw = raw << 3;
    if(data[7] == 0x10) {
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    if(cfg == 0x00) raw = raw & ~7;
    else if(cfg == 0x20) raw = raw & ~3;
    else if (cfg == 0x40) raw = raw & ~1;
  }
  tempDs18b20 = (float)raw / 16.00;
  tempDs18b20 = tempDs18b20  + (sensorDom == 1 ? corrTempD : corrTempU);
  if(printCom) {
    printTime();
    Serial.println("Temperature DS18B20: " + String(tempDs18b20) + " *C");
  }
}
//--------------------------------------------------------------------------
void sensorsSi7021() {  //2
  if(si7021 == false) return;
  humSi7021 = sensor.readHumidity() + corrHumi;
  celsiusSi7021 = sensor.readTemperature() + (sensorDom == 2 ? corrTempD : corrTempU);
  if(printCom) {
    printTime();
    Serial.println("Temperature Si7021: " + String(celsiusSi7021) + " *C,  Humidity: " + String(humSi7021) + " %");
  }
}
//--------------------------------------------------------------------------
void sensorsBmp() {  //3
  if(bmp280 == true) {
    tempBmp = bmp.readTemperature() + (sensorDom == 3 ? corrTempD : corrTempU);
    pressBmp = bmp.readPressure() * 0.00750063755419211 + corrPress;
    pressBmp = (int) pressBmp;
    altBmp = bmp.readAltitude(1013.25);
    if(printCom) {
      printTime();
      if(bmp280 == true) Serial.println("Temperature BMP280: " + String(tempBmp) + " *C,  Pressure: " + String(pressBmp) + " mmHg,  Approx altitude: " + String(altBmp) + " m");
    }
  }
  if(BMP180 == true) {
    tempBmp = bmp180.readTemperature() + (sensorDom == 3 ? corrTempD : corrTempU);
    pressBmp = bmp180.readPressure() * 0.00750063755419211 + corrPress;
    pressBmp = (int) pressBmp;
    altBmp = bmp180.readAltitude(101500);
    if(printCom) {
      printTime();
      if(BMP180 == true) Serial.println("Temperature BMP180: " + String(tempBmp) + " *C,  Pressure: " + String(pressBmp) + " mmHg,  Approx altitude: " + String(altBmp) + " m");
    }
  }
}
//--------------------------------------------------------------------------
void sensorsBme() {  //4
  if(bme280 == false) return;
  tempBme = bme.readTempC() + (sensorDom == 4 ? corrTempD : corrTempU);          //bme.readTempF()
  humBme = bme.readHumidity() + corrHumi;
  pressBme = bme.readPressure() / 1.333223689017149 + corrPress;
  pressBme = (int) pressBme;
  altBme = bme.readAltitudeFeet();   //bme.readAltitudeMeter()  bme.readAltitudeFeet()
  if(printCom) {
    printTime();
    Serial.println("Temperature BME280: " + String(tempBme) + " *C,  Humidity: " + String(humBme) + " %,  Pressure: " + String(pressBme) + " mmHg,  Approx altitude: " + String(altBme) + " m");
  }
}
//--------------------------------------------------------------------------
void printTime() {
  if(printCom) Serial.print((hour < 10 ? "0" : "") + String(hour) + ":" + (minute < 10 ? "0" : "") + String(minute) + ":" + (second < 10 ? "0" : "") + String(second) + "  ");
}
//--------------------------------------------------------------------------
void bip(){
  if(buzzerOnOff == 1){
  if(!buzzerSet){
    tone(buzzerPin, 2000, 40);
    delay(250);
    noTone(buzzerPin);
  } else {
    digitalWrite(buzzerPin, HIGH);
    delay(120);
    digitalWrite(buzzerPin, LOW);
    delay(120);
  }
 }
}
//--------------------------------------------------------------------------
void bips(){
  if(buzzerOnOffku == 1){
  if(!buzzerSet){
    tone(buzzerPin, 2000, 40);
    delay(250);
    noTone(buzzerPin);
  } else {
    digitalWrite(buzzerPin, HIGH);
    delay(120);
    digitalWrite(buzzerPin, LOW);
    delay(120);
 }
 }
}
//--------------------------------------------------------------------------
byte alarms() {
  for(byte i = 0; i < 5; i++) {
    if(alarme[i][0]==hour&&alarme[i][1]==minute&&(alarme[i][2]==dayOfWeek||(alarme[i][2]==8&&(dayOfWeek>1&&dayOfWeek<7))||(alarme[i][2]==9&&dayOfWeek>1)||(alarme[i][2]==10&&(dayOfWeek==1||dayOfWeek==7))||alarme[i][2]>10)){
      alarm_numer=i;
      return 1;
    }
  }
  alarm_numer=255;
  return 0;
}
//------------ function urlencode for weather parameters --------------------
String urlencode(String str) {    // функция взята от http://forum.amperka.ru/members/benben.19545/
    String encodedString="";
    char c;
    char code0;
    char code1;
    for (int i =0; i < str.length(); i++){
      c=str.charAt(i);
      if (c == ' '){
        encodedString+= '+';
      } else if (isalnum(c)){
        encodedString+=c;
      } else{
        code1=(c & 0xf)+'0';
        if ((c & 0xf) >9){
            code1=(c & 0xf) - 10 + 'A';
        }
        c=(c>>4)&0xf;
        code0=c+'0';
        if (c > 9){
            code0=c - 10 + 'A';
        }
        encodedString+='%';
        encodedString+=code0;
        encodedString+=code1;
      }
      yield();
    }
    return encodedString;
}
//------------ function chr_to_str --------------------
String chr_to_str(String str) {
  String chr_to_str = "";
  for (int i =0; i < str.length(); i++){
    chr_to_str += str.charAt(i);
  }
  return chr_to_str;
}
