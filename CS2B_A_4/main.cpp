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

   virtual double computeCharge();

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

   virtual double computeCharge(int count);
   void setTextMessage(string t_m);
   string getTextMessage();

   //friend ostream & operator<< (ostream &, const TextMessage &);

};



class VoiceMessage : public Message
{
private:
   int voiceMessage;

public:
   VoiceMessage();
   VoiceMessage(string senderPN, string receiverPN, int voiceMessage);
   ~VoiceMessage();

   virtual double computeCharge(int count);
   void setVoiceMessage(int v_m);
   int getVoiceMessage();

   //friend ostream & operator<< (ostream &, const VoiceMessage &);
};



class MediaMessage : public Message
{
private:
   int mediaMessage;

public:
   MediaMessage();
   MediaMessage(string senderPN, string receiverPN, int mediaMessage);
   ~MediaMessage();

   virtual double computeCharge(int count);
   void setMediaMessage(int m_m);
   int getMediaMessage();

   //friend ostream & operator<< (ostream &, const MediaMessage &);

};





int main ()
{

   SmartCarrier *p = new SmartCarrier("At&t");
   p->startService();
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
   Message *text_message = NULL;
   Message *voice_message = NULL;
   Message *media_message = NULL;

   //650-267-1289
   text_message = new TextMessage("650-267-1289", "650-345-9001",
                                 "Do you want to learn how to program in C++?");
   smartPhone_Accounts["650-267-1289"].push_back(text_message);

   voice_message = new VoiceMessage("650-267-1289", "650-322-865", 178);
   smartPhone_Accounts["650-267-1289"].push_back(voice_message);

   media_message = new MediaMessage ("650-267-1289", "310-777-8888", 25) ;
   smartPhone_Accounts["650-267-1289"].push_back (media_message);


   // 408-235-1500
   text_message = new TextMessage("408-235-1500", "555-656-4536", "whats up?");
   smartPhone_Accounts["408-235-1500"].push_back(text_message);

   text_message = new TextMessage("408-235-1500", "555-656-4536", "Wanna go to watch a movie?");
   smartPhone_Accounts["408-235-1500"].push_back(text_message);

   text_message = new TextMessage("408-235-1500", "555-656-4536", "What movie do you want to watch?");
   smartPhone_Accounts["408-235-1500"].push_back(text_message);

   voice_message = new  VoiceMessage ("408-235-1500", "702-838-0812", 100);
   smartPhone_Accounts ["408-235-1500"].push_back (voice_message);

   voice_message = new  VoiceMessage ("408-235-1500", "702-838-0812", 189);
   smartPhone_Accounts ["408-235-1500"].push_back (voice_message);

   voice_message = new  VoiceMessage ("408-235-1500", "302-938-0822", 25);
   smartPhone_Accounts ["408-235-1500"].push_back (voice_message);

   media_message = new MediaMessage ("408-235-1500", "888-345-9803", 60);
   smartPhone_Accounts ["408-235-1500"].push_back (media_message);

   media_message = new MediaMessage ("408-235-1500", "568-345-9803", 46);
   smartPhone_Accounts ["408-235-1500"].push_back (media_message);

   media_message = new MediaMessage ("408-235-1500", "568-345-9803", 34);
   smartPhone_Accounts ["408-235-1500"].push_back (media_message);

   media_message = new MediaMessage ("408-235-1500", "568-345-9803", 86);
   smartPhone_Accounts ["408-235-1500"].push_back (media_message);


   // 650-781-7900
   text_message = new TextMessage ("650-781-7900", "233-342-4523", "How are you?") ;
   smartPhone_Accounts ["650-781-7900"].push_back (text_message);

   text_message = new TextMessage ("650-781-7900", "233-342-4523", "Nice!") ;
   smartPhone_Accounts ["650-781-7900"].push_back (text_message);

   media_message = new MediaMessage ("650-781-7900", "568-345-9803", 10);
   smartPhone_Accounts ["650-781-7900"].push_back (media_message);

   media_message = new MediaMessage ("650-781-7900", "568-335-6843", 24);
   smartPhone_Accounts ["650-781-7900"].push_back (media_message);

   media_message = new MediaMessage ("650-781-7900", "568-355-5803", 21);
   smartPhone_Accounts ["650-781-7900"].push_back (media_message);

   // 415-298-2162
   voice_message = new VoiceMessage ("415-298-2162", "232-343-5676", 21);
   smartPhone_Accounts["415-298-2162"].push_back(voice_message);

   media_message = new MediaMessage ("415-298-2162", "342-435-5636", 12);
   smartPhone_Accounts["415-298-2162"].push_back(media_message);

   //  945-890-5913
   text_message = NULL;
   smartPhone_Accounts["945-890-5913"].push_back(text_message); //-----------------------------

   //  408-720-0012
   text_message = new TextMessage("408-720-0012", "314-246-2563", "What did you have for lunch?");
   smartPhone_Accounts["408-720-0012"].push_back(text_message);

   voice_message = new VoiceMessage ("408-720-0012", "232-343-5676", 21);
   smartPhone_Accounts["408-720-0012"].push_back(voice_message);

   voice_message = new VoiceMessage ("408-720-0012", "435-546-2341", 6);
   smartPhone_Accounts["408-720-0012"].push_back(voice_message);

   voice_message = new VoiceMessage ("408-720-0012", "245-245-5346", 21);
   smartPhone_Accounts["408-720-0012"].push_back(voice_message);

   voice_message = new VoiceMessage ("408-720-0012", "232-343-5676", 9);
   smartPhone_Accounts["408-720-0012"].push_back(voice_message);

   //  650-230-9912
   media_message = new MediaMessage ("650-230-9912", "650-555-333", 230);
   smartPhone_Accounts["650-230-9912"].push_back(media_message);

   media_message = new MediaMessage ("650-230-9912", "888-343-2542", 123);
   smartPhone_Accounts["650-230-9912"].push_back(media_message);

   media_message = new MediaMessage ("650-222-4543", "888-343-2542", 12);
   smartPhone_Accounts["650-230-9912"].push_back(media_message);

   //  408-462-7890
   text_message = new TextMessage ("408-462-7890", "423-435-3546", "Hello, it's me") ;
   smartPhone_Accounts ["408-462-7890"].push_back (text_message);

   text_message = new TextMessage ("408-462-7890", "354-356-3563", "I was wondering if after") ;
   smartPhone_Accounts ["408-462-7890"].push_back (text_message);

   text_message = new TextMessage ("408-462-7890", "354-356-3563", "all these years you'd like to meet") ;
   smartPhone_Accounts ["408-462-7890"].push_back (text_message);

   text_message = new TextMessage ("408-462-7890", "202-343-5363", "To go over everything") ;
   smartPhone_Accounts ["408-462-7890"].push_back (text_message);

   voice_message = new VoiceMessage ("408-462-7890", "808-312-4252", 35);
   smartPhone_Accounts ["408-462-7890"].push_back(voice_message);

   voice_message = new VoiceMessage ("408-462-7890", "808-312-4252", 23);
   smartPhone_Accounts ["408-462-7890"].push_back(voice_message);

   media_message = new MediaMessage ("408-462-7890", "999-234-5948", 90);
   smartPhone_Accounts ["408-462-7890"].push_back(media_message);

   media_message = new MediaMessage ("408-462-7890", "808-312-4252", 35);
   smartPhone_Accounts ["408-462-7890"].push_back(media_message);

   media_message = new MediaMessage ("408-462-7890", "808-312-4252", 32);
   smartPhone_Accounts ["408-462-7890"].push_back(media_message);

   //  415-902-9581
   text_message = new TextMessage ("415-902-9581", "423-435-3546", "They say that time's") ;
   smartPhone_Accounts ["415-902-9581"].push_back (text_message);

   voice_message = new VoiceMessage ("415-902-9581", "808-312-4252", 3);
   smartPhone_Accounts ["415-902-9581"].push_back(voice_message);

   voice_message = new VoiceMessage ("415-902-9581", "808-312-4252", 6);
   smartPhone_Accounts ["415-902-9581"].push_back(voice_message);

   media_message = new MediaMessage ("415-902-9581", "808-312-4252", 89);
   smartPhone_Accounts ["415-902-9581"].push_back(media_message);

   media_message = new MediaMessage ("415-902-9581", "702-989-0876", 23);
   smartPhone_Accounts ["415-902-9581"].push_back(media_message);

   //  310-290-1666
   text_message = new TextMessage ("310-290-1666", "999-234-5948", "supposed to heal ya");
   smartPhone_Accounts ["310-290-1666"].push_back(text_message);

   text_message = new TextMessage ("310-290-1666", "999-234-5948", "But I ain't done much healing");
   smartPhone_Accounts ["310-290-1666"].push_back(text_message);

   text_message = new TextMessage ("310-290-1666", "999-234-5948", "Hello, can you hear me");
   smartPhone_Accounts ["310-290-1666"].push_back(text_message);

}


void SmartCarrier::startService()
{
   do
   {
      char userInput;
      initalizeMap();
      Menu();
      cin >> userInput;

      switch (userInput) {
         case '1':
            listAll();
            break;
         case '2':
            searchMessage();
            break;
         case '3':
            eraseMessage();
            break;
         case '4':
            disconnectAccount();
            break;
         case '5':

            break;
         default:
            break;
      }
   }
   while (true);
}


void SmartCarrier::Menu()
{
   cout << "1. List summary of message usages/charges for all accounts" << endl;
   cout << "2. Search a message from an account" << endl;
   cout << "3. Erase a message from an account" << endl;
   cout << "4. Disconnect an account" << endl;
   cout << "5. Quit" << endl;
}


void SmartCarrier::getChoice()
{

}


void SmartCarrier::listAll()
{
   cout << "Phone number          " << "Total messages  " << "  Text  " << "  voice  " << "  Media  " << "  Total" << endl;

   map<string, vector<Message*> >::iterator m_iter;
   vector<Message*>::iterator v_iter;

   TextMessage *text_Message = NULL;
   VoiceMessage *voice_Message = NULL;
   MediaMessage *media_Message = NULL;

   int text_message_count = 0;
   int voice_message_count = 0;
   int media_message_count = 0;
   double text_charge = 0;
   double voice_charge = 0;
   double media_charge = 0;
   int total_message = 0;
   double total_charge = 0;



   for(m_iter = smartPhone_Accounts.begin(); m_iter != smartPhone_Accounts.end(); m_iter++)
   {
      cout << m_iter->first << "  ";


      for(v_iter = m_iter->second.begin(); v_iter != m_iter->second.end(); v_iter++)
      {
         if((text_Message = dynamic_cast<TextMessage*>(*v_iter)))
         {
            text_message_count++;
            text_charge = text_Message->computeCharge(text_message_count);
         }
         else if((voice_Message = dynamic_cast<VoiceMessage*>(*v_iter)))
         {
            voice_message_count++;
            voice_charge += voice_Message->computeCharge(voice_message_count);
         }
         else if((media_Message = dynamic_cast<MediaMessage*>(*v_iter)))
         {
            media_message_count++;
            media_charge += media_Message->computeCharge(media_message_count);
         }


      }


      total_message = text_message_count + voice_message_count + media_message_count;
      total_charge = text_charge + voice_charge + media_charge;







      cout << "          " <<total_message << "                " << text_message_count << "        "
      << voice_message_count << "        " << media_message_count << "        " << total_charge << endl;

      total_message = 0;
      total_charge = 0;
      text_message_count = 0;
      voice_message_count = 0;
      media_message_count= 0;

   }
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





//-----------------------class Message definition----------------
Message::Message():sender_PhoneNumber(""), receiver_PhoneNumber(""){}

Message::Message(string senderPN, string receiverPN):sender_PhoneNumber(senderPN),receiver_PhoneNumber(receiverPN){}

Message::~Message()
{

}


bool Message::operator==(const Message &another) const
{
   return (this->sender_PhoneNumber == another.sender_PhoneNumber
           && this->receiver_PhoneNumber == another.receiver_PhoneNumber);
}


ostream & operator<< (ostream &os, const Message &object)
{
   os << object.sender_PhoneNumber << object.receiver_PhoneNumber;

   return os;
}

double Message::computeCharge()
{
   return 0.0;
}





//----------------------class TextMessage definition-----------------------
TextMessage::TextMessage():Message(),textMessage(""){}

TextMessage::TextMessage(string senderPN, string receiverPN, string textMessage):
Message(senderPN, receiverPN), textMessage(textMessage){}

TextMessage::~TextMessage()
{

}


double TextMessage::computeCharge(int count)
{
   double charge;

   charge = count * 0.20;

   return charge;

}


void TextMessage::setTextMessage(string t_m)
{
   this->textMessage = t_m;
}


string TextMessage::getTextMessage()
{
   return textMessage;
}




//-------------------class VoiceMessage definition-------------------
VoiceMessage::VoiceMessage():voiceMessage(0){}

VoiceMessage::VoiceMessage(string senderPN, string receiverPN, int voiceMessage):
Message(senderPN,receiverPN), voiceMessage(voiceMessage){}

VoiceMessage::~VoiceMessage()
{

}


double VoiceMessage::computeCharge(int count)
{
   double charge;

   charge = count * 0.015;

   return charge;
}


void VoiceMessage::setVoiceMessage(int v_m)
{
   this->voiceMessage = v_m;
}


int VoiceMessage::getVoiceMessage()
{
   return voiceMessage;
}





//----------------class MediaMessage definition----------------------
MediaMessage::MediaMessage():mediaMessage(0){}

MediaMessage::MediaMessage(string senderPN, string receiverPN, int mediaMessage):
Message(senderPN, receiverPN), mediaMessage(mediaMessage){}

MediaMessage::~MediaMessage()
{

}


double MediaMessage::computeCharge(int count)
{
   double charge;

   charge = count * 0.10;

   return charge;
}


void MediaMessage::setMediaMessage(int m_m)
{
   this->mediaMessage = m_m;
}


int MediaMessage::getMediaMessage()
{
   return mediaMessage;
}



