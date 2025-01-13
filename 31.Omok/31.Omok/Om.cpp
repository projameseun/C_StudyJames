#include "Om.h"



void Om::OmokMap(int colum, int row)
{
    int i, j;

    unsigned char a = 0xa6;

    unsigned char b[12];

    // std::string a = "戌";

    


    for (i = 1; i < 12; i++)
    {

        b[i] = 0xa0 + i;
    }

    std::cout << "忙";
   std::cout << "式";




    for (i = 0; i < colum - 1; i++)
    {
        std::cout << "成";
        std::cout << "式";
    }

    std::cout << a << b[4];

    printf("\n");



    for (i = 0; i < row - 1; i++)

    {

        std::cout << "戍";
        std::cout << "式";
        for (j = 0; j < colum - 1; j++)
        {

            std::cout << "托";
            std::cout << "式";
        }

        
        std::cout << "扣";

        printf("\n");

    }


    std::cout << "戌";
    std::cout << "式";

    for (i = 0; i < colum - 1; i++)
    {

        std::cout << "扛";
        std::cout << "式";
    }

    std::cout << "戎";

    printf("\n");

}


