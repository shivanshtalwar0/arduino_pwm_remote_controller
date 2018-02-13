/*
 Author Of This Code:Shivansh Talwar
 For any Queries Related to this open-Source Code
 You can Contact Me:shivanshtalwar0@gmail.com
 Or can Follow me on Instagram username:shivansh.talwar
 


NOTE:THIS CODE REQUIRES USE OF TWO MICROCONTROLLERS ONE ON EACH
SIDE FOR COMMUNICATION,ENCODING AND DECODING OF TRANSMITTED SIGNALS
INSHORT THIS CODE REQUIRES TWO ARDUINO BOARD.

 
 
 For Proper Working of this code just follow as Described 
 Materials Required for Wireless Communication
 (1)433 Mhz ASK(Amplitude Shift Keying) TransReciever Module
 (2)HT12E & HT12D (12 Bit Encoder Decoder Pair)
 (3)47K & 1Mhz Resistor(Rosc value of HT12E and HT12D)
 (4)Breadboard or PCB
 (5)Some Jumper Wires or Soldering Wire for Connections
 (6)Two 10K Potentiometer

  first of all hook up HT12D and Reciever on breadboard and test 
  it Whether it is Working fine or Not.
  Now, After Testing it just connect as given

  digital pin 3: AD0 of HT12D
  digital pin 4: AD1 of HT12D
  digital pin 5: AD2 of HT12D
  digital pin 6: AD3 of HT12D
  

ALL Done for Reciever  PART  



REMEMBER::::: OUTPUT1 and OUTPUT2 are the two output variables whose
values will change when you rotate the potentiometer knob
 */

//PROGRAM BEGINS HERE....
int o1=3,o2=4,o3=5,o4=6;
int rv1,rv2,rv3,rv4;
int output1,output2;
int m;
int i;

int arr[8][4]={ {0,0,0,0},//0  
                 {0,0,0,1},//1
                 {0,0,1,0},//2
                 {0,0,1,1},//3
                 {0,1,0,0},//4
                 {0,1,0,1},//5
                 {0,1,1,0},//6
                 {0,1,1,1},//7
                 

};
int arr1[8][4]={  {1,0,0,0},//0
                 {1,0,0,1},//1
                 {1,0,1,0},//2
                 {1,0,1,1},//3
                 {1,1,0,0},//4
                 {1,1,0,1},//5
                 {1,1,1,0},//6
                 {1,1,1,1},//7
};

void d2a()
{ 
  rv1=!digitalRead(o1);
rv2=!digitalRead(o2);
rv3=!digitalRead(o3);
rv4=!digitalRead(o4);

if(rv1==0)
{for(i=0;i<8;i++)

  {   if(rv1==arr[i][0]&&rv2==arr[i][1]&&rv3==arr[i][2]&&rv4==arr[i][3])
        { output1=i;
         break;
         

              }
  }
  

}
else
if(rv1==1)
{for(i=0;i<8;i++)

  {   if(rv1==arr1[i][0]&&rv2==arr1[i][1]&&rv3==arr1[i][2]&&rv4==arr1[i][3])
        { output2=i;
         break;
         

              }
  }


  
}

  

}
void setup() {
  Serial.begin(9600);
  pinMode(o1,INPUT);
  pinMode(o2,INPUT);
  pinMode(o3,INPUT);
  pinMode(o4,INPUT);
  // put your setup code here, to run once:

}

void loop() {
 d2a();

  Serial.print("output1=");
  Serial.println(output1);

d2a();
  Serial.print("output2=");
 Serial.println(output2);

   
   
  
}
