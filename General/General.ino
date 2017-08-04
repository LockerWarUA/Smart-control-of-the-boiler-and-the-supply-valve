#include <iarduino_RTC.h>;
#include <Wire.h>;
#include <OneWire.h>;
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 8
#define TEMPERATURE_PRECISION 9
iarduino_RTC time(RTC_DS1307);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress Thermometer1, Thermometer2, Thermometer3, Thermometer4, Thermometer5, Thermometer6;
char hours_rtc;                    //переменная для часов
float temp_bochka;              //переменные показания температуры
float temp_dom;
float temp_podacha;
float temp_priem;
float temp_okrug;
float temp_kotelna;
byte relekotel = 1;            //Указать на каком пине висит релюшка
byte releklapan1 = 2;          //пины для управления релюшками клапана 
byte releklapan2 = 3;
char timer;                    //показывает насколько открыт клапан(в секундах, предпологается что для полного открытия клапана нужно 60 секунд)
//OneWire  ds(8);               //в скобках указать на каком пине расположены датчики
void setup() {
  //Wire.begin();
  Serial.begin(9600);          //расскоментировать для включения сериал порта
  time.begin();                  //включаем часы
  sensors.begin();               //включаем датчики температуры
  if (!sensors.getAddress(Thermometer1, 0)) Serial.println("Unable to find address for Device temp_dom"); //Ecли Один из датчиков сломается в сериал выведет сообщение
  if (!sensors.getAddress(Thermometer2, 1)) Serial.println("Unable to find address for Device temp_kotelna"); 
  if (!sensors.getAddress(Thermometer3, 2)) Serial.println("Unable to find address for Device temp_priem"); 
  if (!sensors.getAddress(Thermometer4, 3)) Serial.println("Unable to find address for Device temp_bochka"); 
  if (!sensors.getAddress(Thermometer5, 4)) Serial.println("Unable to find address for Device temp_okrug"); 
  if (!sensors.getAddress(Thermometer6, 5)) Serial.println("Unable to find address for Device temp_podacha"); 
  // ставим размер считываемых данных на 9 bit
  sensors.setResolution(Thermometer1, TEMPERATURE_PRECISION);
  sensors.setResolution(Thermometer2, TEMPERATURE_PRECISION);
  sensors.setResolution(Thermometer3, TEMPERATURE_PRECISION);
  sensors.setResolution(Thermometer4, TEMPERATURE_PRECISION);
  sensors.setResolution(Thermometer5, TEMPERATURE_PRECISION);
  sensors.setResolution(Thermometer6, TEMPERATURE_PRECISION);
  pinMode(relekotel, OUTPUT);      //Назначение пина как выход для последуйщего контроля
  digitalWrite(relekotel, HIGH);   //отключение релюшки
  pinMode(releklapan1, OUTPUT);
  digitalWrite(releklapan1, HIGH);
  pinMode(releklapan2, OUTPUT);
  digitalWrite(releklapan2, HIGH);
  //time.settime(0,51,21,27,10,15,2);  // 0  сек, 51 мин, 21 час, 27, октября, 2015 года, вторник  //для установки времени расскоментировать
}
void loop() {
  //hours_rtc = time.gettime("H");
  hours_rtc = 18;
  sensors.requestTemperatures();
  temp_bochka = sensors.getTempC(Thermometer4);
  temp_dom = sensors.getTempC(Thermometer1);
  temp_okrug = sensors.getTempC(Thermometer5);
  temp_kotelna = sensors.getTempC(Thermometer2);
  temp_podacha = sensors.getTempC(Thermometer6);
  temp_priem = sensors.getTempC(Thermometer3);
  //*****************Отладка**********************
  /*
  Serial.println("****************BEGIN OF MESSAGE*************");
  Serial.print("Bochka: ");
  Serial.println(temp_bochka);
  Serial.print("Dom: ");
  Serial.println(temp_dom);
  Serial.print("okrug: ");
  Serial.println(temp_okrug);
  Serial.print("kotelna: ");
  Serial.println(temp_kotelna);
  Serial.print("podacha: ");
  Serial.println(temp_podacha);
  Serial.print("priem: ");
  Serial.println(temp_priem);
  Serial.println("****************END OF MESSAGE*************");
  delay(1000);
  */
  if (hours_rtc >= 23 || hours_rtc <= 7) { //Собственно все условия для управления релюхой
    digitalWrite(relekotel, HIGH);
    Serial.println("off_time");
  }else if (temp_okrug < 30){
      digitalWrite(relekotel, LOW);
    Serial.println("on_okrug");
    }else if (temp_kotelna < 30){
       digitalWrite(relekotel, LOW);
    Serial.println("on_koteln");
    }else if (temp_dom < 30){
       digitalWrite(relekotel, LOW);
    Serial.println("on_dom");
    }else{
      digitalWrite(relekotel, HIGH);
    Serial.println("off");
    };
    Serial.println("whatssup");
}

void rele_on(){                 //Для удобства переключения переведены в отдельные войды и вызываются по названию войда
    digitalWrite(relekotel, LOW);
    Serial.println("on");
  }
  void rele_off(){
    digitalWrite(relekotel, HIGH);
    Serial.println("off");
  }
