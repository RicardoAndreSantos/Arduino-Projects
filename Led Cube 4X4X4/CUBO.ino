int coluna[] = {2,3,5,4,9,8,7,6,A4,A5,0,1,A0,A1,A2,A3};				// cube columns connections
int camada[] = {13,12,11,10};										// cube layers


int t = 200;


void setup(){
  for(int i=0 ; i<16 ; i++){
    pinMode(coluna[i], OUTPUT);
  }
  
  for(int j=0 ; j<4 ; j++){
    pinMode(camada[j], OUTPUT);
  }
}


void loop(){

  cubo_esq_baixo_frente();
  delay(t);
  desligar();
  cubo_dir_baixo_frente();
  delay(t);
  desligar();
  cubo_dir_baixo_tras();
  delay(t);
  desligar();
  cubo_esq_baixo_tras();
  delay(t);
  desligar();
  cubo_esq_baixo_frente();
  delay(t);
  desligar();
  cubo_esq_cima_frente();
  delay(t);
  desligar();
  cubo_dir_cima_frente();
  delay(t);
  desligar();
  cubo_dir_cima_tras();
  delay(t);
  desligar();
  cubo_esq_cima_tras();
  delay(t);
  desligar();
  cubo_esq_cima_frente();
  delay(t);
  desligar();
  
  
  baixo_cima();
  delay(t);
  desligar();
  esq_dir();
  desligar();
  esq_dir_encher();
  delay(t);
  desligar();
  diagonal_esq_dir_f();
  desligar();
  diagonal_esq_dir_t();
  delay(t);
  desligar();
  roda();
  roda();
  roda_encher();
  delay(t);
  desligar();
  delay(t+300);
}
   

//-----------------------------------------
//--Some animations--
//-----------------------------------------

void colunas_exteriores_roda(){
  for(int j=0 ; j<4 ; j++){
    digitalWrite(camada[j],1);
  }
  int v=0, final_1=3, final_2=12;
  for(int i=0 ; i<4 ; i++){
    digitalWrite(coluna[i],1);
    digitalWrite(coluna[final_1],1);
    digitalWrite(coluna[final_2],1);
    digitalWrite(coluna[15-i],1);
    delay(t);
    digitalWrite(coluna[i],0);
    digitalWrite(coluna[final_1],0);
    digitalWrite(coluna[final_2],0);
    digitalWrite(coluna[15-i],0);
    v=4;
    final_1 += v; 
    final_2 -= v;    
  }    
}


//---------------------------------------------------

void diagonal_esq_dir_t(){
    for(int j=0 ; j<4 ; j++){
    digitalWrite(camada[j],1);
  }
  
  digitalWrite(coluna[3],1);
  delay(t);
  digitalWrite(coluna[3],0);
  
  digitalWrite(coluna[2],1);
  digitalWrite(coluna[7],1);
  delay(t);
  digitalWrite(coluna[2],0);
  digitalWrite(coluna[7],0);

  digitalWrite(coluna[1],1);
  digitalWrite(coluna[6],1);
  digitalWrite(coluna[11],1);
  delay(t);
  digitalWrite(coluna[1],0);
  digitalWrite(coluna[6],0);
  digitalWrite(coluna[11],0);

  digitalWrite(coluna[0],1);
  digitalWrite(coluna[5],1);
  digitalWrite(coluna[10],1);
  digitalWrite(coluna[15],1);
  delay(t);
  digitalWrite(coluna[0],0);
  digitalWrite(coluna[5],0);
  digitalWrite(coluna[10],0);
  digitalWrite(coluna[15],0);
   
  digitalWrite(coluna[4],1);
  digitalWrite(coluna[9],1);
  digitalWrite(coluna[14],1);
  delay(t);
  digitalWrite(coluna[4],0);
  digitalWrite(coluna[9],0);
  digitalWrite(coluna[14],0);
  
  digitalWrite(coluna[8],1);
  digitalWrite(coluna[13],1);
  delay(t);
  digitalWrite(coluna[8],0);
  digitalWrite(coluna[13],0); 
  
  digitalWrite(coluna[12],1);
  delay(t);
  digitalWrite(coluna[12],0);
}

//---------------------------------------------------

void diagonal_esq_dir_f(){
    for(int j=0 ; j<4 ; j++){
    digitalWrite(camada[j],1);
  }
  
  digitalWrite(coluna[0],1);
  delay(t);
  digitalWrite(coluna[0],0);
  
  digitalWrite(coluna[1],1);
  digitalWrite(coluna[4],1);
  delay(t);
  digitalWrite(coluna[1],0);
  digitalWrite(coluna[4],0);

  digitalWrite(coluna[2],1);
  digitalWrite(coluna[5],1);
  digitalWrite(coluna[8],1);
  delay(t);
  digitalWrite(coluna[2],0);
  digitalWrite(coluna[5],0);
  digitalWrite(coluna[8],0);

  digitalWrite(coluna[3],1);
  digitalWrite(coluna[6],1);
  digitalWrite(coluna[9],1);
  digitalWrite(coluna[12],1);
  delay(t);
  digitalWrite(coluna[3],0);
  digitalWrite(coluna[6],0);
  digitalWrite(coluna[9],0);
  digitalWrite(coluna[12],0);
   
  digitalWrite(coluna[7],1);
  digitalWrite(coluna[10],1);
  digitalWrite(coluna[13],1);
  delay(t);
  digitalWrite(coluna[7],0);
  digitalWrite(coluna[10],0);
  digitalWrite(coluna[13],0);
  
  digitalWrite(coluna[11],1);
  digitalWrite(coluna[14],1);
  delay(t);
  digitalWrite(coluna[11],0);
  digitalWrite(coluna[14],0); 
  
  digitalWrite(coluna[15],1);
  delay(t);
  digitalWrite(coluna[15],0);
}

//---------------------------------------------------

void roda_encher(){
     for(int j=0 ; j<4 ; j++){
    digitalWrite(camada[j],1);
  }
  
    digitalWrite(coluna[0],1);
    delay(t);    
    digitalWrite(coluna[4],1);
    delay(t);  
    digitalWrite(coluna[8],1);
    delay(t);
    digitalWrite(coluna[12],1);
    delay(t);    
    digitalWrite(coluna[13],1);
    delay(t);
    digitalWrite(coluna[14],1);
    delay(t); 
    digitalWrite(coluna[15],1);
    delay(t);    
    digitalWrite(coluna[11],1);
    delay(t);    
    digitalWrite(coluna[7],1);
    delay(t);  
    digitalWrite(coluna[3],1);
    delay(t);    
    digitalWrite(coluna[2],1);
    delay(t);
    digitalWrite(coluna[1],1);
    delay(t);
    digitalWrite(coluna[5],1);
    delay(t);
    digitalWrite(coluna[9],1);
    delay(t);
    digitalWrite(coluna[10],1);
    delay(t);
    digitalWrite(coluna[6],1);
    delay(t);
}

//---------------------------------------------------

void roda(){
   for(int j=0 ; j<4 ; j++){
    digitalWrite(camada[j],1);
  }
  
    digitalWrite(coluna[0],1);
    delay(t);
    digitalWrite(coluna[0],0);
    
    digitalWrite(coluna[4],1);
    delay(t);
    digitalWrite(coluna[4],0); 
    
    digitalWrite(coluna[8],1);
    delay(t);
    digitalWrite(coluna[8],0);
    
    digitalWrite(coluna[12],1);
    delay(t);
    digitalWrite(coluna[12],0);
    
    digitalWrite(coluna[13],1);
    delay(t);
    digitalWrite(coluna[13],0);
    
    digitalWrite(coluna[14],1);
    delay(t);
    digitalWrite(coluna[14],0);
    
    digitalWrite(coluna[15],1);
    delay(t);
    digitalWrite(coluna[15],0);
    
    digitalWrite(coluna[11],1);
    delay(t);
    digitalWrite(coluna[11],0);
    
    digitalWrite(coluna[7],1);
    delay(t);
    digitalWrite(coluna[7],0);
    
    digitalWrite(coluna[3],1);
    delay(t);
    digitalWrite(coluna[3],0);
    
    digitalWrite(coluna[2],1);
    delay(t);
    digitalWrite(coluna[2],0);
    
    digitalWrite(coluna[1],1);
    delay(t);
    digitalWrite(coluna[1],0);
}

//---------------------------------------------------
    
void cubo_dir_cima_tras(){
  for(int j=2 ; j<4 ; j++){
    digitalWrite(camada[j],1);
  }
  for(int i=10 ; i<12 ; i++){
    digitalWrite(coluna[i],1);
    digitalWrite(coluna[i+4],1);
  }
}
  
//---------------------------------------------------

void cubo_dir_cima_frente(){
  for(int j=2 ; j<4 ; j++){
    digitalWrite(camada[j],1);
  }
  for(int i=8 ; i<10 ; i++){
    digitalWrite(coluna[i],1);
    digitalWrite(coluna[i+4],1);
  }
}

//---------------------------------------------------
  
void cubo_esq_cima_frente(){
  for(int j=2 ; j<4 ; j++){
    digitalWrite(camada[j],1);
  }
  for(int i=0 ; i<2 ; i++){
    digitalWrite(coluna[i],1);
    digitalWrite(coluna[i+4],1);
  }
}

//---------------------------------------------------
  
void cubo_dir_baixo_tras(){
  for(int j=0 ; j<2 ; j++){
    digitalWrite(camada[j],1);
  }
  for(int i=10 ; i<12 ; i++){
    digitalWrite(coluna[i],1);
    digitalWrite(coluna[i+4],1);
  }
}

//---------------------------------------------------
  
void cubo_dir_baixo_frente(){
  for(int j=0 ; j<2 ; j++){
    digitalWrite(camada[j],1);
  }
  for(int i=8 ; i<10 ; i++){
    digitalWrite(coluna[i],1);
    digitalWrite(coluna[i+4],1);
  }
}

//---------------------------------------------------

void cubo_esq_baixo_tras(){
  for(int j=0 ; j<2 ; j++){
    digitalWrite(camada[j],1);
  }
  for(int i=2 ; i<4 ; i++){
    digitalWrite(coluna[i],1);
    digitalWrite(coluna[i+4],1);
  }
}

//---------------------------------------------------
  
void cubo_esq_cima_tras(){
    for(int i=2 ; i<4 ; i++){
      digitalWrite(camada[i], 1);
      digitalWrite(coluna[i], 1);
      digitalWrite(coluna[i+4], 1);
  }
}

//---------------------------------------------------

void cubo_esq_baixo_frente(){
    for(int i=0 ; i<2 ; i++){
    digitalWrite(camada[i], 1);
    digitalWrite(coluna[i], 1);
    digitalWrite(coluna[i+4], 1);
  }
}

//---------------------------------------------------

void baixo_cima(){
  for(int i=0 ; i<16 ; i++){
    digitalWrite(coluna[i],HIGH);
  }
  for(int j=0 ; j<4 ; j++){
    digitalWrite(camada[j],HIGH); 
    delay(t);
    digitalWrite(camada[j],LOW);
  }
}

//---------------------------------------------------

void esq_dir(){
  for(int i=0; i<4; i++){
    digitalWrite(camada[i], 1);
  }
  
  for(int j=0 ; j<4 ;j++){
     digitalWrite(coluna[j],1);
  }
  delay(t);
  for(int j=0 ; j<4 ;j++){
     digitalWrite(coluna[j],0);
  } 

  for(int j=4 ; j<8 ;j++){
     digitalWrite(coluna[j],1);
  }
  delay(t);
  for(int j=4 ; j<8 ;j++){
     digitalWrite(coluna[j],0);
  }   
  
  for(int j=8 ; j<12 ;j++){
     digitalWrite(coluna[j],1);
  }
  delay(t);
  for(int j=8 ; j<12 ;j++){
     digitalWrite(coluna[j],0);
  }   
  
  for(int j=12 ; j<16 ;j++){
     digitalWrite(coluna[j],1);
  }
  delay(t);
  for(int j=12 ; j<16 ;j++){
     digitalWrite(coluna[j],0);
  }   
}

//----------------------------------------------------------  

void esq_dir_encher(){
  for(int i=0; i<4; i++){
    digitalWrite(camada[i], 1);
  }
  
  for(int j=0 ; j<4 ;j++){
     digitalWrite(coluna[j],1);
  }
  delay(t);
  for(int j=4 ; j<8 ;j++){
     digitalWrite(coluna[j],1);
  }
  delay(t);  
  
  for(int j=8 ; j<12 ;j++){
     digitalWrite(coluna[j],1);
  }
  delay(t);
  
  for(int j=12 ; j<16 ;j++){
     digitalWrite(coluna[j],1);
  }
  delay(t);   
}

//---------------------------------------------------
//--Turn on--

void ligar(){
  for(int i=0 ; i<16 ; i++){
    digitalWrite(coluna[i],HIGH);
  }
  for(int j=0 ; j<4 ; j++){
    digitalWrite(camada[j],HIGH);
  }
}

//---------------------------------------------------
//--Turn off--

void desligar(){
  for(int i=0 ; i<16 ; i++){
    digitalWrite(coluna[i],LOW);
  }
  for(int j=0 ; j<4 ; j++){
    digitalWrite(camada[j],LOW);
  }
}
