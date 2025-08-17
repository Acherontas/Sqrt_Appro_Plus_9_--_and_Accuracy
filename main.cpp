#include <iostream>
#include <math.h>
#include <iomanip>
#include <thread>
using namespace std;
int preci;
int v_log;
int adv_log;
int x_s(long double a,long double b,int c,long double dmc,int shm){
    cout<<"entering function with " << a << " " << b << " " <<c << " " << dmc << " " << shm <<"\n";
    if(b==0 || (dmc==0 || dmc==0.0 || dmc==0.00)){cout<<"missing variable of a parameter exiting\n";return 0;}
    int lfor=0;
    int lfom=0;
    //kx_me=a;
    //x_me=b;
    //x=c;
    long double fractpart,intpart;
   for(;;){
      a=b*b;
      fractpart=modf(a,&intpart);
      //cout<<"A " <<kx_me << " " << fractpart << " " << kx_me << " " << intpart<<"\n";
      if(shm==1){cout<<"using " <<std::setprecision(preci)<< b <<" with result " <<std::setprecision(preci)<< a <<"\n";}
      if(a==c ||  intpart==c){lfor=1; goto A;}
      if(a>c){lfom=1; goto B;}
      A:if(lfor==1){
         cout<<"\n";
         cout<<" ------> precise value is " << std::setprecision(preci)<< b <<"\n";
         break;
      }
      B:if(lfom==1){
         cout<<"\n";
         cout<<" ------> almost precise value is " << std::setprecision(preci)<<b <<"\n";
         break;
      }
      if(lfor==0 && lfom==0){b=b+dmc;a=0;}
    }
    cout<<"\n";
return 0;
}


int main(int argc,char** argv)
{
    cout<<"voyeristic behaviours and other have fun. Opoios klefei prepei na plironei \n";
    cout<<"OPOS PARAKALISTHE NA MIN PIGAINE TO PONTIKI STOY DIAOLOY TIN MANA\n";
    cout<<"GIA NA MOY VGAZETE TO MATI. Eyxaristo \n";
    cout<<"warning values are approximation of the original calculated sqrt value method \n";
    cout<<"some +-z values from [1-9] will be missing \n";
    cout<<"intended to find the approximate beginning in order to search with the dot comma starting from a value \n";
    cout<<"for example from 27.00 and increasing to 27.99 to find the result u want \n";
    cout<<"me seira: [1] number, \n";
    cout<<"|[2] 1 gia block foron,[3] fores * 81 | , \n";
    cout<<"|| [4] 1 gia akrivi ipologismo,[5] epilogi arithmou ,[6]dekadikos akrivi ipologismou ||  ,\n";
    cout<<" [7] 1 gia emfanisi allon arithmon || [8] dekadikos akrivi ipologismou_fast_mode , [9] diafora akeraion  || [10] fast_mode_state \n";
    cout<<" [11] enter precision\n";
    cout<<"[1]=number \n";
    cout<<"[2]=0 i 1 gia energopoiisi foron\n";
    cout<<"[3]=oi fores px 4 * 81\n";
    cout<<"[4]=0 i 1 gia times stin x_s function \n";
    cout<<"[12]=0 i 1 gia log\n";
    cout<<"[13]=0 i 1 gia adv_log\n";
    cout<<"an example ./sqrt_arm64    [1]   [2] [3] [4] [5]  [6]    [7] [8] [9] [10] [11] [12] [13] \n";
    cout<<"or         ./sqrt_arm64 7889562   1   52  1   0   0.01    0   0   0   1    30    1   1   \n";

    //cout<<"an example ./sqrt_arm64 2785412 1 20 0 0 0 0 0.01 || a second example ./sqrt_arm64 2785 0 0 0 0 0 0 0.01 \n";
    cout<<"\n";
    int want_fast_mode=0;
    int x;
    float y;
    int stbl=0;
    preci=stoi(argv[11]);
    v_log=stoi(argv[12]);
    adv_log=stoi(argv[13]);
    cout<<"ur log level [12] " << v_log <<"\n";
    cout<<"ur precision is [11]"<< preci <<"\n";
    cout<<"ur advance log of 9 [13] "<< adv_log <<"\n";
    stbl=81;
    int s_stbl=0;
    s_stbl=9;
    x=stold(argv[1]);
    cout<<"ur number u want to check is [1] " << std::setprecision(preci)<< x<<"\n";
    y=sqrt(x);
    cout<<"ur sqrt value is : " << std::setprecision(preci)<<y <<"\n";
    long double k;
    k=(long double)x/(long double)stbl;
    cout<<"ur k /81 number is : "<<std::setprecision(preci)<< k <<"\n";
    int xy=abs(k-y);
    cout<<"abs difference of k-y: " << std::setprecision(preci)<<k <<" - " << std::setprecision(preci) << y << " ::== "  <<std::setprecision(preci)<<xy <<"\n";
    int z=0;
    long double dfr=0;
    dfr=(long double)y/(long double)stbl;
    cout<<"suggested value of difference for the gap is : "<< std::setprecision(preci)<<dfr <<" use the integer part \n";
    //the other incredible way
    long double other_way;
    y=x/6561;
    other_way=sqrt(y);
    cout<<"the other incredible way is " <<std::setprecision(preci)<< y << " with sqrt of " <<std::setprecision(preci)<< other_way <<"\n";
    z=stoi(argv[2]);
    cout<<"z is [2] " << z <<"\n";
    if(z==1){
       int tms=0;
       tms=stoi(argv[3]);
       cout<<"tms is [3]" << tms <<"\n";
       stbl=stbl*tms;
       k=(long double)x/(long double)stbl;
       cout<<"ur new k /81 * " <<std::setprecision(preci)<< tms << " is " <<std::setprecision(preci)<< stbl <<" and k is " <<std::setprecision(preci)<< k <<"\n";
    }
    if(z==0){goto C;}
    C:
    cout<<"\n";
    if(adv_log==1){
    cout<<"calculating backward to find the " <<std::setprecision(preci)<< y <<" ~ \n";
    for(int i=0;i<=10;i++){
      cout<<"@i " << i << " @k " <<std::setprecision(preci)<< k <<" with ^ " <<std::setprecision(preci)<< k*k << "\n";
      k=k-9;
    }
    cout<<"outter k backward " <<std::setprecision(preci)<< k << " with ^ " << std::setprecision(preci)<<k*k << "\n";
    cout<<"\n";
    k=(long double)x/(long double)stbl;
    cout<<"calculating forward to find the " <<std::setprecision(preci)<< y <<" ~ \n";
    for(int i=0;i<=10;i++){
       cout<<"@i " <<i <<" @k " <<std::setprecision(preci)<< k <<" with ^ " <<std::setprecision(preci)<< k*k <<"\n";
       k=k+9;
    }
    cout<<"outter k forward " <<std::setprecision(preci)<< k << " with ^ " <<std::setprecision(preci)<< k*k <<"\n";
    }
    int ask_me=0;
    long double x_me;
    cout<<"\n";
    ask_me=stoi(argv[4]);
    if(ask_me==0){cout<<"ask me is zero\n";}
    cout<<"passing ask_me value [4]" << ask_me <<"\n";
    long double kx_me=0;
    long double dcm_p;
    int sh_them=0;
    want_fast_mode=stoi(argv[10]);
    cout<<"want fast mode value [10]" << want_fast_mode <<"\n";
    if (ask_me==1){
       x_me=stold(argv[5]);
       cout<<"x_me [5] " << x_me <<"\n";
       dcm_p=stold(argv[6]);
       cout<<"dcm_p [6] "<< dcm_p <<"\n";
       sh_them=stoi(argv[7]);
       cout<<"sh_them [7] "<<sh_them <<"\n";
       if(want_fast_mode==0){
            cout<<"for ask_me [4]  " << ask_me << " and want_fast_mode [10] " << want_fast_mode <<"\n";
            x_s(kx_me,x_me,x,dcm_p,sh_them);}
    }
    //this i a highly great optimization technic developed by me
    //as me not intended any java sh1t except the worker which may burn u up
    cout<<"optimization\n";
    k=0;
    k=(long double)x/(long double)stbl;
    long double first_result=0;
    first_result=k*k;
    cout<<"stable value is : " <<std::setprecision(preci)<< stbl <<"\n";
    cout<<"for number x "<<std::setprecision(preci)<< x << " and k = x/81*times :==" <<std::setprecision(preci)<< k << " and result of k*k :== " <<std::setprecision(preci)<< first_result <<"\n";
    long double fk;
    int abs_type=0;
    if(first_result>x){fk=(long double)first_result/(long double)x;abs_type=1;
                       cout<<"i diairesi tou " <<std::setprecision(preci)<< first_result << " / " <<std::setprecision(preci)<< x << " = " <<std::setprecision(preci)<< fk <<" type 1\n";}
    if(x>first_result){fk=(long double)x/(long double)first_result;abs_type=2;
                       cout<<"i diairesi tou " <<std::setprecision(preci)<< x << " / " << std::setprecision(preci)<<first_result << " = " <<std::setprecision(preci)<< fk <<" type 2\n";}
    long double fractpart,intpart;
    fractpart=0;
    fractpart=modf(fk,&intpart);
    cout<<"we get the set of numbers " <<std::setprecision(preci)<< fractpart <<" as " <<std::setprecision(preci)<< fk <<  " and integer part as " <<std::setprecision(preci)<< intpart <<"\n";
    cout<<"now we make the magic with 9 * intpart : ";
    int mgk=0;
    mgk=9*(intpart);
    long double last_number_all_around;
    last_number_all_around=k;
    cout<<"magik number is : " <<std::setprecision(preci)<< mgk << " + "  << std::setprecision(preci)<<k << " with lst " << std::setprecision(preci)<<last_number_all_around <<"\n";
    cout<<"and the approximation without any fors " << last_number_all_around <<"\n";
    if(stbl>81){last_number_all_around=last_number_all_around-81;cout<<"stb is bigger new nmb is " <<std::setprecision(preci)<< last_number_all_around <<"\n";}
    long double dekd;
    dekd=stold(argv[8]);
    cout<<"dekd [8] " << dekd <<"\n";
    long double new_number;
    long double xx;
    new_number=last_number_all_around*last_number_all_around;
    fractpart=modf(new_number,&intpart);
    int fl=1;
    int xlpart=0;
    int ylpart=0;
    cout<<"starting with " <<std::setprecision(preci)<< last_number_all_around <<"\n";
    int fdrt_ask=0;
    fdrt_ask=stoi(argv[9]);
    cout<<"fdrt_ask [9] " << fdrt_ask <<"\n";
    int dfrt=0;
    for(;;){
       dfrt=0;
       dfrt=intpart-x;
       if(intpart==x){
                if(v_log==1){
                cout<<" ---> WHILE INT EQ X \n";}
                fl=0;
                break;
                }
       if(intpart>x){last_number_all_around=last_number_all_around-9;
            if(v_log==1){
            cout<<" ---> decreasing by 9 "<<std::setprecision(preci)<<last_number_all_around<<"\n";}
                    fl=0;}
       if(intpart<x){last_number_all_around=last_number_all_around+9;
            if(v_log==1){
            cout<<" ---> increasing by 9 "<<std::setprecision(preci)<<last_number_all_around<<"\n";}
                    }
       new_number=last_number_all_around*last_number_all_around;
       fractpart=modf(new_number,&intpart);
       if(v_log==1){
       cout<<"\n";
       cout<<" ---> exiting internal for with " << "new number " << std::setprecision(preci)<<new_number <<"\n";
       cout<<" ---> and last_number " <<std::setprecision(preci)<< last_number_all_around <<"\n";
       cout<<" ---> and fractpart " <<std::setprecision(preci)<< fractpart <<" with integer part " <<std::setprecision(preci)<< intpart <<"\n";
       cout<<" ---> and dfrt " <<std::setprecision(preci)<< dfrt << " with main number as " <<std::setprecision(preci)<< x << " and main sqrt as " <<std::setprecision(preci)<< y <<"\n";
       cout<<"\n";
       }
     if(fl==0){fl=0;break;}
    }
    if(v_log==0){
        cout<<"\n";
       cout<<" ---> exiting internal for with " << "new number " << std::setprecision(preci)<<new_number <<"\n";
       cout<<" ---> and last_number " <<std::setprecision(preci)<< last_number_all_around <<"\n";
       cout<<" ---> and fractpart " <<std::setprecision(preci)<< fractpart <<" with integer part " <<std::setprecision(preci)<< intpart <<"\n";
       cout<<" ---> and dfrt " <<std::setprecision(preci)<< dfrt << " with main number as " <<std::setprecision(preci)<< x << " and main sqrt as " <<std::setprecision(preci)<< y <<"\n";
       cout<<"\n";
    }
    if(want_fast_mode==1){
                          x_s(0,last_number_all_around-9,x,dcm_p,sh_them);
                         }
    return 0;
}
