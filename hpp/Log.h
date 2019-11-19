#ifndef LOG_H
#define LOG_H
#include <iostream>

/*class Log
{
    public:
        Log();
        virtual ~Log();

    protected:

    private:
};*/

template<typename T>
void log(T logvalue)
{
    std::cout<<logvalue<<std::endl;
}

#endif // LOG_H
