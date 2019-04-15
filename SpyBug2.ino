/*
Steps:
1. Edit pcmConfig.h
    a: On Uno or non-mega boards, #define buffSize 128. May need to increase.
    b: Uncomment #define ENABLE_RECORDING and #define BLOCK_COUNT 10000UL

2. Usage is as below. See https://github.com/TMRh20/TMRpcm/wiki/Advanced-Features#wiki-recording-audio for
   additional informaiton.
*/

#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>
File file;

#define SD_ChipSelectPin 4
int CS_PIN = SD_ChipSelectPin;
TMRpcm audio;
int audiofile = 0;
unsigned long i = 0;
bool recmode = 0;
int rec=0;
const int sensor=A1; // Assigning analog pin A5 to variable 'sensor'

float tempc; //variable to store temperature in degree Celsius

float tempf; //variable to store temperature in Fahreinheit

float vout; //temporary variable to hold sensor reading 
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, button, LOW);
  SD.begin(SD_ChipSelectPin);
  audio.CSPin = SD_ChipSelectPin;
  pinMode(sensor,INPUT); // Configuring sensor pin as input 

}

void loop() {
  Serial.println(rec);
  if(rec==0){
    vout=analogRead(sensor); //Reading the value from sensor

    vout=(vout*500)/1023;
    
    tempc=vout; // Storing value in Degree Celsius
    
    tempf=(vout*1.8)+32; // Converting to Fahrenheit
    
    Serial.print("in DegreeC=");
    
    Serial.print("\t");
    
    Serial.print(tempc);
    
    Serial.print(" ");
    
    Serial.print("in Fahrenheit=");
    
    Serial.print("\t");
    
    Serial.print(tempf);
    
    Serial.println(); 
    createFile("test.txt");
    file.println();
    writeToFile("\nTemp : ");
    file.print(tempc  );
    writeToFile("\n");
    closeFile();
    delay(1000);
  }
}

void button() {
  rec=1;
  Serial.println("Button Pressed");
  while (i < 300000) {
    i++;
  }
  i = 0;
  if (recmode == 0) {
    recmode = 1;
    audiofile++;
    digitalWrite(6, HIGH);
    switch (audiofile) {
      case 1: audio.startRecording("1.wav", 16000, A0);rec =0; break;
      case 2: audio.startRecording("2.wav", 16000, A0);rec =0; break;
      case 3: audio.startRecording("3.wav", 16000, A0);rec =0; break;
      case 4: audio.startRecording("4.wav", 16000, A0);rec =0; break;
      case 5: audio.startRecording("5.wav", 16000, A0);rec =0; break;
      case 6: audio.startRecording("6.wav", 16000, A0);rec =0; break;
      case 7: audio.startRecording("7.wav", 16000, A0);rec =0; break;
      case 8: audio.startRecording("8.wav", 16000, A0);rec =0; break;
      case 9: audio.startRecording("9.wav", 16000, A0);rec =0; break;
      case 10: audio.startRecording("10.wav", 16000, A0);rec =0; break;
    }
  }
  else {
    recmode = 0;
    digitalWrite(6, LOW);
    switch (audiofile) {
      case 1: audio.stopRecording("1.wav");rec =0; break;
      case 2: audio.stopRecording("2.wav");rec =0; break;
      case 3: audio.stopRecording("3.wav");rec =0; break;
      case 4: audio.stopRecording("4.wav");rec =0; break;
      case 5: audio.stopRecording("5.wav");rec =0; break;
      case 6: audio.stopRecording("6.wav");rec =0; break;
      case 7: audio.stopRecording("7.wav");rec =0; break;
      case 8: audio.stopRecording("8.wav");rec =0; break;
      case 9: audio.stopRecording("9.wav");rec =0; break;
      case 10: audio.stopRecording("10.wav");rec =0; break;
    }
  }
  rec =0;
}
void initializeSD()
{
  Serial.println("Initializing SD card...");
  pinMode(CS_PIN, OUTPUT);

  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }
}

int createFile(char filename[])
{
  file = SD.open(filename, FILE_WRITE);

  if (file)
  {
    Serial.println("File created successfully.");
    return 1;
  } else
  {
    Serial.println("Error while creating file.");
    return 0;
  }
}

int writeToFile(char text[])
{
  if (file)
  {
    file.print(text);
    Serial.println("Writing to file: ");
    Serial.println(text);
    return 1;
  } else
  {
    Serial.println("Couldn't write to file");
    return 0;
  }
}

void closeFile()
{
  if (file)
  {
    file.close();
    Serial.println("File closed");
  }
}

int openFile(char filename[])
{
  file = SD.open(filename);
  if (file)
  {
    Serial.println("File opened with success!");
    return 1;
  } else
  {
    Serial.println("Error opening file...");
    return 0;
  }
}

String readLine()
{
  String received = "";
  char ch;
  while (file.available())
  {
    ch = file.read();
    if (ch == '\n')
    {
      return String(received);
    }
    else
    {
      received += ch;
    }
  }
  return "";
}
