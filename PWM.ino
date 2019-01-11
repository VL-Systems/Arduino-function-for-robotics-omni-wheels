int PWM1[]={10,11,9};
int Umotor_1[]={2,3};
int Umotor_2[]={6,7};
int Umotor_3[]={8,12};

void setup() {
  for (int pin=0;pin<=2;pin++)pinMode(PWM1[pin],OUTPUT);
  for (int pin1=0;pin1<=2;pin1++)pinMode(Umotor_1[pin1],OUTPUT);
  for (int pin2=0;pin2<=2;pin2++)pinMode(Umotor_2[pin2],OUTPUT);
  for (int pin3=0;pin3<=2;pin3++)pinMode(Umotor_3[pin3],OUTPUT);

}

void loop() {
  int Psi=90;
int data[]={0,0,0,0,0,0};  
uint8_t r=Evalf(data,Psi);
int Rotation_1=data[0];
int Rotation_2=data[1];
int Rotation_3=data[2];
int PWM_1=data[3];
int PWM_2=data[4];
int PWM_3=data[5];
Motor_1(Rotation_1,PWM_1);
Motor_2(Rotation_2,PWM_2);
Motor_3(Rotation_3,PWM_3);
delay(2000);
}

uint8_t Evalf(int *data,int Psi)
{int PWM_1=0;int PWM_2=0;int PWM_3=0;
 int Rotation_1=0;int Rotation_2=0;int Rotation_3=0;
 float U3=1.81818*cos(0.0174444*Psi);
 float U2=-0.909091*cos(0.0174444*Psi)-1.57459*sin(0.0174444*Psi);
 float U1=-1.04973*(cos(0.523599+0.0174444*Psi)-sin(0.0174444*Psi));
 if (abs(U1)>=abs(U2)&&abs(U1)>=abs(U3)){PWM_1=U1/abs(U1)*255;PWM_2=U2/abs(U1)*255;PWM_3=U3/abs(U1)*255;}
 if (abs(U2)>=abs(U1)&&abs(U2)>=abs(U3)){PWM_1=U1/abs(U2)*255;PWM_2=U2/abs(U2)*255;PWM_3=U3/abs(U2)*255;}
 if (abs(U3)>=abs(U1)&&abs(U3)>=abs(U2)){PWM_1=U1/abs(U3)*255;PWM_2=U2/abs(U3)*255;PWM_3=U3/abs(U3)*255;}

 if(PWM_1>0){Rotation_1=1;}else{Rotation_1=2;PWM_1=abs(PWM_1);}
 if(PWM_2>0){Rotation_2=1;}else{Rotation_2=2;PWM_2=abs(PWM_2);}
 if(PWM_3>0){Rotation_3=1;}else{Rotation_3=2;PWM_3=abs(PWM_3);}
 data[0]=Rotation_1;
 data[1]=Rotation_2;
 data[2]=Rotation_3;
 data[3]=PWM_1;
 data[4]=PWM_2;
 data[5]=PWM_3;
 return 1;
 
  }

void Motor_1(int Rotation_1,int PWM_1)
{if(Rotation_1==1)
 {digitalWrite(Umotor_1[0],HIGH);digitalWrite(Umotor_1[1],LOW);analogWrite(PWM1[0],PWM_1);}
 if(Rotation_1==2)
 {digitalWrite(Umotor_1[0],LOW);digitalWrite(Umotor_1[1],HIGH);analogWrite(PWM1[0],PWM_1);}
  }
  
  void Motor_2(int Rotation_2,int PWM_2)
{if(Rotation_2==1)
 {digitalWrite(Umotor_2[0],HIGH);digitalWrite(Umotor_2[1],LOW);analogWrite(PWM1[1],PWM_2);}
 if(Rotation_2==2)
 {digitalWrite(Umotor_2[0],LOW);digitalWrite(Umotor_2[1],HIGH);analogWrite(PWM1[1],PWM_2);}
  }
  
  void Motor_3(int Rotation_3,int PWM_3)
{if(Rotation_3==1)
 {digitalWrite(Umotor_3[0],HIGH);digitalWrite(Umotor_3[1],LOW);analogWrite(PWM1[2],PWM_3);}
 if(Rotation_3==2)
 {digitalWrite(Umotor_3[0],LOW);digitalWrite(Umotor_3[1],HIGH);analogWrite(PWM1[2],PWM_3);}
  }
