#include<iostream>
using namespace std;
#include<random>
class coinflipd{
    int heads, tails;
    public:
    void getdata(int a){
        heads=a;
        tails= a-1;
    };
    void backend(){
        if (heads==1){
            cout<<"You have chosen Heads\n";
        }
        else{
            cout<<"You have chosen Tails\n";
        }
            int c;
            c= (rand()%2)+1;
            if (c==1){
            cout<<"The coin has landed on Heads\n";
                if (heads==1){
                    cout<<"You have won the game\n";
                }
                else{
                    cout<<"You have lost the game\n";
                }
            }
            else{
                cout<<"The coin has landed on Tails\n";
                    if (tails==1){
                    cout<<"You have won the game\n";
                }
                    else{
                    cout<<"You have lost the game\n";
                }
            }
        
    }
};
int main(){
    int a;
    cout<<"Welcom to the Coin Flip Simulator\n";
    cout<<"What you want to choose 1. Heads or 2. Tails\n";
    cin>>a;
    coinflipd cf;
    cf.getdata(a);
    cf.backend();
};