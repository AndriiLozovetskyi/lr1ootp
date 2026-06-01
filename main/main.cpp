#include <iostream>
#include <string>

using namespace std;

class Message {
public:
    virtual void send(const string& text) = 0;
    virtual ~Message() {}
};
//Конкретні продукти
class EmailMessage : public Message {
public:
    void send(const string& text) override {
        cout << "Email: " << text << endl;
    }
};

class SmsMessage : public Message {
public:
    void send(const string& text) override {
        cout << "SMS: " << text << endl;
    }
};

class PushMessage : public Message {
public:
    void send(const string& text) override {
        cout << "Push: " << text << endl;
    }
};
//Абстрактна фабрика

class MessageFactory {
public:
    virtual Message* createMessage() = 0;

    void deliver(const string& text) {
        Message* msg = createMessage();
        msg->send(text);
        delete msg;
    }

    virtual ~MessageFactory() {}
};

class EmailFactory : public MessageFactory {
public:
    Message* createMessage() override {
        return new EmailMessage();
    }
};

class SmsFactory : public MessageFactory {
public:
    Message* createMessage() override {
        return new SmsMessage();
    }
};

class PushFactory : public MessageFactory {
public:
    Message* createMessage() override {
        return new PushMessage();
    }
};


//
int main() {

    MessageFactory* factory;

    factory = new EmailFactory();
    factory->deliver("Welcome to Factory Method");
    delete factory;

    factory = new SmsFactory();
    factory->deliver("Verification code: 1234");
    delete factory;

    factory = new PushFactory();
    factory->deliver("New message received");
    delete factory;

    return 0;
}
