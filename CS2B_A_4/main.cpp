//
//  main.cpp
//  CS2B_A_4
//
//  Created by yuteng Wu on 8/27/20.
//  Copyright © 2020 Yuteng Wu. All rights reserved.
//
//
//

#include <iostream>
#include <vector>
#include <map>

using namespace  std;


class Message
{
protected:
   string sender_PhoneNumber;
   string receiver_PhoneNumber;

public:
   Message();
   Message(string senderPN, string receiverPN);
   ~Message();

   virtual void computeCharge();
   bool operator== (const Message & right) const;

   friend ostream & operator<< (ostream &, const Message &);



};






class SmartCarrier
{
private:
   string carrierName;
   map <string, vector<Message*> > smartPhone_Accounts;

   void Menu();
   void getChoice();
   void listAll();
   void searchMessage();
   void eraseMessage();
   void disconnectAccount();
   void stopService();

public:
   SmartCarrier();
   SmartCarrier(string carrierName);
   ~SmartCarrier();

   void setCarrierName(string carrierName);
   string getCarrierName();

   const map<string, vector<Message*> > &getSmartPhone_Accounts();

   void initalizeMap();
   void startService();




};



class TextMessage : public Message
{
private:
   string textMessage;

public:
   TextMessage();
   TextMessage(string senderPN, string receiverPN, string textMessage);
   ~TextMessage();

   virtual void computeCharge();
   void setTextMessage();
   string getTextMessage();

   //friend ostream & operator<< (ostream &, const TextMessage &);

};



class VoiceMessage : public Message
{
private:
   string voiceMessage;

public:
   VoiceMessage();
   VoiceMessage(string senderPN, string receiverPN, string voiceMessage);
   ~VoiceMessage();

   virtual void computeCharge();
   void setVoiceMessage();
   string getVoiceMessage();

   //friend ostream & operator<< (ostream &, const VoiceMessage &);
};



class MediaMessage : public Message
{
private:
   string mediaMessage;

public:
   MediaMessage();
   MediaMessage(string senderPN, string receiverPN, string mediaMessage);
   ~MediaMessage();

   virtual void computeCharge();
   void setMediaMessage();
   string getMediaMessage();

   //friend ostream & operator<< (ostream &, const MediaMessage &);

};





int main ()
{


}




//------------------class SmartCarrier definition----------------------

SmartCarrier::SmartCarrier():carrierName(""){}

SmartCarrier::SmartCarrier(string carrierName):carrierName(carrierName){}

SmartCarrier::~SmartCarrier()
{

}

void SmartCarrier::setCarrierName(string carrierName)
{
   this->carrierName = carrierName;
}


string SmartCarrier::getCarrierName()
{
   return carrierName;
}


const map<string, vector<Message*> > &SmartCarrier::getSmartPhone_Accounts()
{
   return smartPhone_Accounts;
}


void SmartCarrier::initalizeMap()
{

}


void SmartCarrier::startService()
{

}


void SmartCarrier::Menu()
{

}


void SmartCarrier::getChoice()
{

}


void SmartCarrier::listAll()
{

}


void SmartCarrier::searchMessage()
{

}


void SmartCarrier::eraseMessage()
{

}


void SmartCarrier::disconnectAccount()
{

}


void SmartCarrier::stopService()
{

}



