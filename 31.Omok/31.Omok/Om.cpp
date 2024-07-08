#include "Om.h"



void Om::OmokMap(int colum, int row)
{
    int i, j;

    unsigned char a = 0xa6;

    unsigned char b[12];

    // std::string a = "¦¦";

    


    for (i = 1; i < 12; i++)
    {

        b[i] = 0xa0 + i;
    }

    std::cout << "¦£";




    for (i = 0; i < colum - 1; i++)
    {
        std::cout << "¦¨";

    }

    std::cout << a << b[4];

    printf("\n");



    for (i = 0; i < row - 1; i++)

    {

        std::cout << "¦§";

        for (j = 0; j < colum - 1; j++)

            std::cout << "¦«";

        std::cout << "¦©";

        printf("\n");

    }

    std::cout << "¦¦";

    for (i = 0; i < colum - 1; i++)

        std::cout << "¦ª";

    std::cout << "¦¥";

    printf("\n");

}


