#include <iostream>
#include <fstream>
using namespace std;

class temp{
        string itemID,itemName;
        int itemQuality,itemPrice,itemQuantity;
        fstream file,file1;
        int totalAmount,quantity,itemRate;
        string search;
        char _choice;
    public:
    void addProduct(void);
    void viewProduct(void);
    void buyProduct(void);
}obj;

int main(){
char choice;


    cout <<"Press 1 ---> Start Shoping" <<endl;
    cout <<"Press 0 ---> EXit" <<endl;
    cin>>choice;
    switch(choice)
    {
        case 'A':
            obj.addProduct();
        break;
        case '1':
            obj.viewProduct();
        break;
        case '0':
            system("exist");
        break;
        default:
            cout <<"Ivalid Selection...!";
            break;
    }

    return 0;
}
void temp :: addProduct(){
        cout <<"Enter Product ID :: ";
        cin>>itemID;
        cout <<"Enter Product Name :: ";
        cin>>itemName;
        cout <<"Enter Product quality :: ";
        cin>>itemQuality;
        cout <<"Enter Product Price :: ";
        cin>>itemPrice;

        file.open("data.txt",ios :: out | ios :: app );
        file<<itemID<<"\t"<<itemName<<"\t"<<itemQuality<<"\t"<<itemPrice<<endl;
        file.close();
}
void temp :: viewProduct(){
    file.open("data.txt",ios :: in);
        file>>itemID>>itemName>>itemQuality>>itemPrice;
        while(!file.eof()){
            cout <<"____________________" <<endl;
            cout <<"Product Id\t\tProduct Name\t\tQuality\t\tProduct Price"<<endl;
            cout <<itemID<<"\t\t\t"<<itemName<<"\t\t\t"<<itemQuantity<<"\t\t\t"<<itemPrice<<endl;
            cout <<"____________________" <<endl;
        file>>itemID>>itemName>>itemQuality>>itemPrice;
        }
    file.close();
}
void temp :: buyProduct(){
    _choice = 'y';

    while(_choice == 'y'){

    file.open("datad.txt",ios :: in);
    file.open("temp.txt,ios :: out | ios :: app");
    file>>itemID>>itemName>>itemQuality>>itemPrice;

    cout <<"Enter Product ID :: ";
    cin>>search;
    cout <<"enter Quantity";
    cin>>quantity;

    while(!file.eof()){
        if(itemID == search){
            itemQuantity = itemQuality - quantity;
            file1<<itemID<<"\t"<<itemName<<"\t"<<itemQuality<<"\t"<<itemPrice<<endl;

            itemRate = quantity = itemPrice;
            totalAmount = totalAmount + itemRate;
            cout <<"____________Payment Bill___________"<<endl;
            cout <<"Total Purchase Amount ::"<<totalAmount<<endl;
            cout <<"_____________________________"<<endl;
        }else{
            file1<<itemID<<"\t"<<itemName<<"\t"<<itemQuantity<<"\t"<<itemPrice<<endl;
        }
        file>>itemID>>itemName>>itemQuality>>itemPrice;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("temp.txt","data.txt");

    cout <<"\n Continue Shoping ? (Y/ N)";
    cin>>_choice;
}
}