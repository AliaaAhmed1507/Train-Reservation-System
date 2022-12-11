#include <iostream>
#include <string>
using namespace std;
int verify(int x, int y){
	string z;
	int num = 0;
	cin >> z;
	for (int i = 0; i < z.size(); i++){
		if (isdigit(z[i])==0){
			return -1;//if (z[i]>='0' &&z[i]<='9') {return 1;} else {return 0;}
		}
		num = num * 10 + (z[i] - '0');
	}

	if (num >= x && num <= y){
		return num;
	}
	return -1;
}
struct seat
{
    int num;
    bool status;

};
struct car
{
    int ID;
    seat seats[30];
};
int main()
{
    car cars[10];
    for (int i=0; i<10; i++)
    {
        cars[i].ID=i+1;
        for(int j=0; j<30; j++)
        {
            cars[i].seats[j].num=j+1;
        }
    }
     for (int i=0; i<10; i++)
    {
        cars[i].ID=i+1;
        for(int j=0; j<30; j++)
        {
            cars[i].seats[j].status=0;
        }
    }
    int x;
    do
    {
        cout<<"To view the menu press number 1 To exit enter 0"<<endl;
        x=verify(0,1);
        if (x==-1){
            cout << "please enter a valid number "<<endl;
            continue;
        }
        if(x==0)
        {
            break;
        }

            cout<<"To Reserve a ticket . press number [1] "<<endl;
            cout<<"To cancel a ticket . press number [2] "<<endl;
            cout<<"To check whether a specific car has available seat or not. press number [3]"<<endl;
            cout<<"To Check whether a specific seat is available or not.press number [4]"<<endl;
            cout<<"To Get the number of the available seats in a specific car .press number [5]"<<endl;
            cout<<"To Show all the seats status of a specific car.press number [6]"<<endl;
            cout<<"To exit press [0]" <<endl;

        int y=verify(0,6);
        if (y==-1)
            {
            cout << "please enter a valid number "<<endl;
            continue;
        }
         if(y==0)
        {
            break;
        }
        if (y==1)
        {
            int i,j;
            cout<<"Enter number of car please"<<endl;
            i=verify(1,10);
            if (i==-1)
            {
            cout << "please enter a valid number "<<endl;
            continue;
        }
            cout<<"Enter number of seat please"<<endl;
            j=verify(1,30);
            if (j==-1){
            cout << "please enter a valid number "<<endl;
            continue;
        }
            if(cars[i].seats[j].status==0)
            {
            cars[i].seats[j].status=1;
            cout<<"Your reservation is completed "<<endl;
            }
            else if(cars[i].seats[j].status==1)
            {
                cout<<"Sorry your reservation failed .please choose another seat" <<endl;
            }
        }
        else if(y==2)
        {
            int a,b;
            cout<<"Enter number of car please"<<endl;
            a=verify(1,10);
            if (a==-1){
            cout << "please enter a valid number "<<endl;
            continue;
        }
            cout<<"Enter number of seat please"<<endl;
            b=verify(1,30);
            if (b==-1){
            cout << "please enter a valid number "<<endl;
            continue;
        }
            if(cars[a].seats[b].status==1)
            {
            cars[a].seats[b].status=0;
            cout<<"Your cancelation is completed "<<endl;
            }
            else if(cars[a].seats[b].status==0)
            {
              cout<<"Sorry,your cancelation is failed"<<endl;
            }

        }
        else if(y==3)
        {
            cout<<"Enter number of car please"<<endl;
            int c=verify(1,10);
           if (c==-1){
            cout << "please enter a valid number "<<endl;
            continue;
        }
            bool f=0;
            for(int i=1; i<=30; i++)
            {

                if(cars[c].seats[i].status==0)
                {
                    f=1;
                    break;
                }
            }
            if(f==1)
            {
                cout<<"This car has available seat"<<endl;
            }
            else
            {
                cout<<"This car has not available seat"<<endl;
            }
        }
        else if(y==4)
        {
            int w;
            int q;
            cout<<"Enter number of car please"<<endl;
            w=verify(1,10);
            if (w==-1){
            cout << "please enter a valid number "<<endl;
            continue;
        }

            cout<<"Enter number of seat please"<<endl;
            q=verify(1,30);
            if (q==-1){
            cout << "please enter a valid number "<<endl;
            continue;
        }
            bool f=0;
            if(cars[w].seats[q].status==0)
            {
                f=1;
            }
            if(f==1)
            {
                cout<<"This seat is available"<<endl;
            }
            else
            {
                cout<<"this seat not available"<<endl;
            }
        }
        else if(y==5)
        {
            cout<<"Enter number of car please"<<endl;
            int k;
            k=verify(1,10);
            if (k==-1){
            cout << "please enter a valid number "<<endl;
            continue;
        }
            int C=0;
            for(int i=0; i<=30; i++)
            {

                if(cars[k].seats[i].status==0)
                {
                    C=C+1;

                }
            }
            cout<<"Number of available seats = "<<C<<endl;
        }
        else if(y==6)
        {
            int v;
            cout<<"Enter number of car please"<<endl;
            v=verify(1,10);
           if (v==-1){
            cout << "please enter a valid number "<<endl;
            continue;
        }
            for(int i=0;i<30;i++)
            {
             if(cars[v].seats[i].status==0)
             {
                 cout<<"This seat "<<i<< " available"<<endl;
             }
             else if(cars[v].seats[i].status==1)
             {
              cout<<"This seat "<<i<< " not available"<<endl;
             }
            }
        }

        }


    while (x!=0);
    cout<<"Thank you for using this program  "<<endl;
}
