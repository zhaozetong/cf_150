# include<iostream>

int main()
{
    int kilo;
    std::cin>>kilo;
    if(kilo>0&&kilo!=2&&(kilo&1)==0)
    {
        std::cout<<"Yes"<<std::endl;

    }
    else
    {
        std::cout<<"No"<<std::endl;
    }

    return 0;
}