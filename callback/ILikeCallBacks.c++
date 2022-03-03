#include <iostream>

void ILikeSayHello()
{
    std::cout << "Hello";
}

void ILikeSayWhatYouLike(char *something)
{
    std::cout << "Hey i'm going to say: " << something;
}

int ILikeReturnAnInt(int whatToMultiply)
{
    int result = whatToMultiply * 2;
    return result;
}

//                what returns     pointer of the function    required arguments
//void ILikeDoAll(    void                 (*fn1)                   (void));

void ILikeDoAll(void (*fn1)(void), void (*fn2)(char*), int (*fn3)(int))
{
    fn1();

    std::cout << ", ";

    fn2("World");

    std::cout << std::endl;

    std::cout << fn3(5) << std::endl;
}

int main()
{
    ILikeDoAll(
        ILikeSayHello,
        ILikeSayWhatYouLike,
        ILikeReturnAnInt
    );
    return 0;
}