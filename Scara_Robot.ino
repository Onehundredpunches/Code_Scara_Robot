#include <AccelStepper.h>
#include <math.h>

// Driver: FULL STEP, Motor 1.8' => 200 bước = 1 vòng 360'

AccelStepper mystepper1(1, 2, 5); //
AccelStepper mystepper2(1, 3, 6); //
AccelStepper mystepper3(1, 4, 7); 



String content = ""; 
int data[10];

int tam_x[26];
int tam_y[26];

int tamdX[26];
int tamdY[26];

int move_Z[26];


float theta1;
float theta2;

float x;
float y;

float l1 = 310;
float l2 = 220; 
float q1;
float q2;
float c1;
float c2;
float s1;
float s2;


int pulse1;
int pulse2;

float temp1;
float temp2;

int pulse1a = 0;
int pulse2a = 0;

int pulse1b = 0;
int pulse2b = 0;


float temp3;
int temp4;
int temp5;

float t;
float t1;
float t2;

float tamOx;
float tamOy;

float tam_dx;
float tam_dy;

int tam;
int tamX;
int z;




void setup() 
{
  Serial.begin(9600);

  pinMode(8,OUTPUT);
  digitalWrite(8,LOW); 

  mystepper1.setMaxSpeed(4000);
  mystepper1.setSpeed(4000);
  mystepper1.setAcceleration(3000);
  mystepper1.setMinPulseWidth(20); 

  mystepper2.setMaxSpeed(4000);
  mystepper2.setSpeed(4000);
  mystepper2.setAcceleration(3000);
  mystepper2.setMinPulseWidth(20); 

  mystepper3.setMaxSpeed(4000);
  mystepper3.setSpeed(4000);
  mystepper3.setAcceleration(3000);
  mystepper3.setMinPulseWidth(20); 
}


void loop(){

if (Serial.available()) {

content = Serial.readString();

    for (int i = 0; i < 10; i++) {
      int index = content.indexOf(","); // locate the first ","
      data[i] = atol(content.substring(0, index).c_str()); //Extract the number from start to the ","
      content = content.substring(index + 1); //Remove the number from the string
    }
tam_x[1] = 30; tam_y[1] = 130;
tam_x[2] = 90; tam_y[2] = 130; 
tam_x[3] = 150; tam_y[3] = 130;
tam_x[4] = 210; tam_y[4] = 130; 
tam_x[5] = 270; tam_y[5] = 130; 

tam_x[6] = 30; tam_y[6] = 190;
tam_x[7] = 90; tam_y[7] = 190; 
tam_x[8] = 150; tam_y[8] = 190;
tam_x[9] = 210; tam_y[9] = 190; 
tam_x[10] = 270; tam_y[10] = 190; 

tam_x[11] = 30; tam_y[11] = 250;
tam_x[12] = 90; tam_y[12] = 250; 
tam_x[13] = 150; tam_y[13] = 250;
tam_x[14] = 210; tam_y[14] = 250; 
tam_x[15] = 270; tam_y[15] = 250; 

tam_x[16] = 30; tam_y[16] = 310;
tam_x[17] = 90; tam_y[17] = 310; 
tam_x[18] = 150; tam_y[18] = 310;
tam_x[19] = 210; tam_y[19] = 310; 
tam_x[20] = 270; tam_y[20] = 310; 

tam_x[21] = 30; tam_y[21] = 370;
tam_x[22] = 90; tam_y[22] = 370; 
tam_x[23] = 150; tam_y[23] = 370;
tam_x[24] = 210; tam_y[24] = 370; 
tam_x[25] = 270; tam_y[25] = 370;

tamdX[1] = 10; tamdY[1] = 110;
tamdX[2] = 70; tamdY[2] = 110; 
tamdX[3] = 130; tamdY[3] = 110;
tamdX[4] = 190; tamdY[4] = 110;
tamdX[5] = 250; tamdY[5] = 110;

tamdX[6] = 10; tamdY[6] = 170;
tamdX[7] = 70; tamdY[7] = 170; 
tamdX[8] = 130; tamdY[8] = 170;
tamdX[9] = 190; tamdY[9] = 170;
tamdX[10] = 250; tamdY[10] = 170;

tamdX[11] = 10; tamdY[11] = 230;
tamdX[12] = 70; tamdY[12] = 230; 
tamdX[13] = 130; tamdY[13] = 230;
tamdX[14] = 190; tamdY[14] = 230;
tamdX[15] = 250; tamdY[15] = 230;

tamdX[16] = 10; tamdY[16] = 290;
tamdX[17] = 70; tamdY[17] = 290; 
tamdX[18] = 130; tamdY[18] = 290;
tamdX[19] = 190; tamdY[19] = 290;
tamdX[20] = 250; tamdY[20] = 290;

tamdX[21] = 10; tamdY[21] = 350;
tamdX[22] = 70; tamdY[22] = 350; 
tamdX[23] = 130; tamdY[23] = 350;
tamdX[24] = 190; tamdY[24] = 350;
tamdX[25] = 250; tamdY[25] = 350;

move_Z[1] = 650;move_Z[2] = 600;move_Z[3] = 530;
move_Z[4] = 450;move_Z[5] = 400;

move_Z[6] = 620;move_Z[7] = 570;move_Z[8] = 520;
move_Z[9] = 420;move_Z[10] = 350;

move_Z[11] = 550;move_Z[12] = 550;move_Z[13] = 500;
move_Z[14] = 400;move_Z[15] = 330;

move_Z[16] = 500;move_Z[17] = 500;move_Z[18] = 450;
move_Z[19] = 340;move_Z[20] = 320;

move_Z[21] = 530;move_Z[22] = 370;move_Z[23] = 380;
move_Z[24] = 350;move_Z[25] = 280;
//----------------------------------------------Vẽ O-------------------------------------------------------------------------
if (data[1]==1){

tam = data[0];
z = data[0];
tamOx = tam_x[tam];
tamOy = tam_y[tam];

draw_O();
}
//---------------------------------------------------------------------------------------------------------------------


//----------------------------------------------Vẽ X-----------------------------------------------------------------------
if (data[1]==2){

tamX = data[0];
z = data[0];
tam_dx= tamdX[tamX];
tam_dy= tamdY[tamX];

draw_X();

}
//-------------------------------------------------------------------------------------------------------------------



//------------------------------------------------Về Home-------------------------------------------------------------
if (data[1]==0){
  theta1 = 0.0;
  theta2 = 0.0;
  dichuyendengoc();
}
//---------------------------------------------------------------------------------------------------------------------



}

//--------------------------------------------End----------------------------------------------
}
























//---------------------------------------------Function-------------------------------------------------------
void dichuyendengoc()
{

//theta1 = px;
//theta2 = py;

temp1 = (3*theta1/1.8)*16;
temp2 = (1.5*theta2/1.8)*16;

pulse1 = round(temp1);
pulse2 = round(temp2);

mystepper1.setCurrentPosition(0);
mystepper2.setCurrentPosition(0);

mystepper1.moveTo(pulse1 - pulse1a);
mystepper2.moveTo(pulse2 - pulse2a);

while (mystepper1.currentPosition() != (pulse1 - pulse1a) || mystepper2.currentPosition() != (pulse2 - pulse2a) )
    {
      mystepper1.run();
      mystepper2.run();
    } 
    pulse1a = pulse1;
    pulse2a = pulse2;

}
//-------------------------------------------------------------------------------------------------------

void Inverse_Kinematic()
{
    c2=(pow(x,2)+pow(y,2)-pow(l1,2)-pow(l2,2))/(2*l1*l2);
    s2=sqrt(abs(1-pow(c2,2)));
    q2=atan2(s2,c2);
    c1=(l1+l2*c2)*x+l2*s2*y;
    s1=(l1+l2*c2)*y-l2*s2*x;
    q1=atan2(s1,c1);

    //if (q2<0){
   //   q2=q2+PI;
   // }
   // if (q1<0){
   //   q1=q1+PI;
   // }    



} 


//-------------------------------------Draw_O Function--------------------------------------------

void draw_O(){

for (int temp3 = 0; temp3 < 3601 ; temp3++)
    {
t = ((temp3*PI)/1800); 
   
x = tamOx + 16.0 + 20*cos(t);
y = tamOy + 20*sin(t);


Inverse_Kinematic();

theta1 = q1*180/PI;
theta2 = q2*180/PI;
//Serial.println(temp1);
//Serial.println(pulse1);

dichuyendengoc();

    if (temp3==0){
        mystepper3.setCurrentPosition(0);
        mystepper3.moveTo((move_Z[z])*16);
        while (mystepper3.currentPosition() != (move_Z[z])*16)
        {
          mystepper3.run();
        }
    }

    
    if (temp3==3600){
      
        mystepper3.setCurrentPosition(0);
        mystepper3.moveTo(-(move_Z[z])*16);
        while (mystepper3.currentPosition() != (-(move_Z[z])*16))
        {
          mystepper3.run();
        }
        data[1]=0;        
    }
    
    }

}
//-----------------------------------------------------------------------------------------


//-----------------------Draw X function-------------------------------------------------------
void draw_X() {

for (temp4 = 0; temp4 < 57 ; temp4++)
    {
t1 = temp4;
x = tam_dx + 12.0 + t1*cos(PI/4);
y = tam_dy + 7.5 +  t1*sin(PI/4); 

Serial.println(x);   
Serial.println(y);   

Inverse_Kinematic();

theta1 = q1*180/PI;
theta2 = q2*180/PI;

dichuyendengoc();

    if (temp4==0){
        mystepper3.setCurrentPosition(0);
        mystepper3.moveTo((move_Z[z])*16);
        while (mystepper3.currentPosition() != ((move_Z[z])*16))
        {
          mystepper3.run();
        }
    }

    
    if (temp4==56){
      
        mystepper3.setCurrentPosition(0);
        mystepper3.moveTo(-(move_Z[z])*16);
        while (mystepper3.currentPosition() != (-(move_Z[z])*16))
        {
          mystepper3.run();
        }
        data[1]=0;
                
    }
    
    }

//-----------------------

for (temp5 = 0; temp5 < 57 ; temp5++)
    {
t2 = temp5;
x = tam_dx + 40 + 12.0 - t2*cos(PI/4);
y = tam_dy + 7.5 +  t2*sin(PI/4); 

Serial.println(x);   
Serial.println(y);   

Inverse_Kinematic();

theta1 = q1*180/PI;
theta2 = q2*180/PI;

dichuyendengoc();

    if (temp5==0){
        mystepper3.setCurrentPosition(0);
        mystepper3.moveTo((move_Z[z])*16);
        while (mystepper3.currentPosition() != ((move_Z[z])*16))     
        {
          mystepper3.run();
        }
    }

    
    if (temp5==56){
      
        mystepper3.setCurrentPosition(0);
        mystepper3.moveTo(-(move_Z[z])*16);
        while (mystepper3.currentPosition() != (-(move_Z[z])*16))
        {
          mystepper3.run();
        }
        data[1]=0;
                
    }
    
    }


}

//----------------------------------------------------------------------------------------------



