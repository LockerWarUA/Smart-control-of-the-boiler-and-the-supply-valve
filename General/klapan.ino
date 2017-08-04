void klapan(float temp_podacha, float temp_bochka, float temp_priem){
  byte pospers        // Нужная позиция клапана в процентах
  byte tekpos         // Текущая позиция в процентах
  byte possec         // Нужная позиция в секндах
  byte teksec         // текущая позиция в секундах
  byte deltaklapan    // Насколько нужно открыть клапан (в проц)
  long timeprev       // переменная для прошедшего времени
  long timecurrent    // переменная для текущего времени
  pospers = (100(temp_podacha - temp_bochka))/(temp_priem-temp_bochka);// общаяя формула клапана
  possec = pospers*1,2 //перевод процентов в секунды
  if (tekpos > pospers){
    tekpos - pospers = deltaklapan
    possec = deltaklapan*1,2
    timecurrent = 
    if (
  }else if (tekpos < pospers) { 
    pospers - tekpos = deltaklapan 
  }
  if (deltaklapan <= 0) { 
    deltaklapan = 0 
  }else if (deltaklapan > 100) { 
    deltaklapan = 100
  }
  if (deltaklapan > tekpos){
    possec = deltaklapan*1,2
    if (possec == teksec
  }
  
  
  



















}
  void rele_on1(){                 //Для удобства переключения переведены в отдельные войды и вызываются по названию войда
    digitalWrite(releklapan1, LOW);
  };
  void rele_off1(){
    digitalWrite(releklapan1, HIGH);
  };
  void rele_on2(){
    digitalWrite(releklapan2, LOW);
  };
  void rele_off2(){
    digitalWrite(releklapan2, HIGH);
  };
