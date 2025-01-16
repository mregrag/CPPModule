#include <stdio.h>
#include <stdlib.h>


int main(void)
{

    /*srand(time(0));*/

    /*std::cout << "max_rand : " << RAND_MAX << std::endl;*/

    for (int i = 0; i < 3; i++)
	printf("%d\n", rand() % 10);
    return (0);
}

