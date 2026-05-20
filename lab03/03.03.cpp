#include <iostream>
#include <string>

using namespace std;

enum PaymentType
{
    PAYMENT_CASH,
    PAYMENT_CARD,
    PAYMENT_BANK
};

union PaymentDetails
{
    int receiptNumber;
    long long cardNumber;
    long long bankAccount;
};

struct Payment
{
    int paymentId;
    PaymentType currentType;
    PaymentDetails currentDetails;

    void printPaymentInfo();
};

void Payment::printPaymentInfo()
{
    cout<<"Payment ID:"<<paymentId<<endl;
    if(currentType==PAYMENT_CASH)
    {
        cout<<"Type:Cash"<<endl;
        cout<<"Receipt:"<<currentDetails.receiptNumber<<endl;
    }
    else if(currentType==PAYMENT_CARD)
    {
        cout<<"Type:Card"<<endl;
        cout<<"Card Number:"<<currentDetails.cardNumber<<endl;
    }
    else if(currentType==PAYMENT_BANK)
    {
        cout<<"Type:Bank Transfer"<<endl;
        cout<<"Account:"<<currentDetails.bankAccount<<endl;
    }
    cout<<"---"<<endl;
}

int main()
{
    Payment paymentsArray[4];
    int i;
    int cashCount;
    int cardCount;
    int bankCount;

    paymentsArray[0].paymentId=101;
    paymentsArray[0].currentType=PAYMENT_CASH;
    paymentsArray[0].currentDetails.receiptNumber=555123;

    paymentsArray[1].paymentId=102;
    paymentsArray[1].currentType=PAYMENT_CARD;
    paymentsArray[1].currentDetails.cardNumber=4111222233334444;

    paymentsArray[2].paymentId=103;
    paymentsArray[2].currentType=PAYMENT_BANK;
    paymentsArray[2].currentDetails.bankAccount=987654321;

    paymentsArray[3].paymentId=104;
    paymentsArray[3].currentType=PAYMENT_CASH;
    paymentsArray[3].currentDetails.receiptNumber=555999;

    cashCount=0;
    cardCount=0;
    bankCount=0;

    for(i=0;i<4;i++)
    {
        paymentsArray[i].printPaymentInfo();
        if(paymentsArray[i].currentType==PAYMENT_CASH)
        {
            cashCount=cashCount+1;
        }
        else if(paymentsArray[i].currentType==PAYMENT_CARD)
        {
            cardCount=cardCount+1;
        }
        else if(paymentsArray[i].currentType==PAYMENT_BANK)
        {
            bankCount=bankCount+1;
        }
    }

    cout<<"Cash payments:"<<cashCount<<endl;
    cout<<"Card payments:"<<cardCount<<endl;
    cout<<"Bank payments:"<<bankCount<<endl;

    return 0;
}