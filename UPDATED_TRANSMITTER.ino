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

  first of all hook up HT12E and transmitter on breadboard and test 
  it Whether it is Working fine or Not.
  Now, After Testing it just connect as given

  digital pin 3: AD0 of HT12E
  digital pin 4: AD1 of HT12E
  digital pin 5: AD2 of HT12E
  digital pin 6: AD3 of HT12E
For reference See this:https://www.engineersgarage.com/sites/default/files/HT12E.jpg

next Hook Two 10K Potentiometer onto breadboard and connect
two legs on same side to 5Volt(Vcc) and GND
and Connect third leg of one Potentiometer to ANALOG 0
and third leg of Second Potentiometer to ANALOG 1

ALL Done for Transmitter PART 
For Reciever part Checkout Reciever code. 
 */

//program begins
int ntv1=0;                  // Updated Transmitted Value 1
int ntv2=0;                  //Updated Transmitted Value 2
 int potv1,potv2;            //Potentiometer Read Values
 int tv1,tv2;                //old Transmitted Vaue
int r1=3,r2=4,r3=5,r4=6;     //HT12E INPUT PINS

int arr[8][4]={ {0,0,0,0},//0             //Array for Potentiometer 1  
                 {0,0,0,1},//1
                 {0,0,1,0},//2
                 {0,0,1,1},//3
                 {0,1,0,0},//4
                 {0,1,0,1},//5
                 {0,1,1,0},//6
                 {0,1,1,1},//7
                 

};
int arr1[8][4]={  {1,0,0,0},//0           //Array for Potentiometer 2
                 {1,0,0,1},//1
                 {1,0,1,0},//2
                 {1,0,1,1},//3
                 {1,1,0,0},//4
                 {1,1,0,1},//5
                 {1,1,1,0},//6
                 {1,1,1,1},//7
};
 void a2d()//Analog to Digital Converter and Transmitter.
 {potv1=analogRead(0);                 
potv2=analogRead(1);
  tv1=potv1/127.5;
 tv2=potv2/127.5;
 while(tv1!=ntv1)
 {for(k=0;k<8;k++)
   {if(tv1==k)
   {digitalWrite(r1,!arr[k][0]);
   digitalWrite(r2,!arr[k][1]);
   digitalWrite(r3,!arr[k][2]);
   digitalWrite(r4,!arr[k][3]);
   break;
   }
    
    }
    ntv1=analogRead(0)/127.5;
     }

while(tv2!=ntv2)
 {for(k=0;k<8;k++)
   {if(tv2==k)
   {digitalWrite(r1,!arr1[k][0]);
   digitalWrite(r2,!arr1[k][1]);
   digitalWrite(r3,!arr1[k][2]);
   digitalWrite(r4,!arr1[k][3]);
   break;
   }
    
    }
    ntv2=analogRead(1)/127.5;
     }


     
     }
  
  
void setup() {
  Serial.begin(9600);
  
   pinMode(r1,OUTPUT);
   pinMode(r2,OUTPUT);
   pinMode(r3,OUTPUT);
   pinMode(r4,OUTPUT);


  
  // put your setup code here, to run once:

}

void loop() {
a2d();
Serial.print("transmitted value 1=");
  Serial.println(tv1);//OUTPUT 1
  Serial.print("transmitted value 2=");
  Serial.println(tv2);//OUTPUT 2
  


  }
