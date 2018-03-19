#ifndef OPTIONVALUE_H
#define OPTIONVALUE_H

#include<cstdint>
#include<string>

namespace optionsql
{
    using byte=uint8_t;

    class OptionValue
    {
    public:
        OptionValue() = default;
        virtual ~OptionValue(){}
    };

    class OptionTinyInt:public OptionValue
    {
    public:
        OptionTinyInt()=default;
        OptionTinyInt(uint8_t val);
        OptionTinyInt & operator =(uint8_t val);
        virtual ~OptionTinyInt(){}
    private:
        uint8_t data;
    };

    class OptionSmallInt:public OptionValue
    {
    public:
        OptionSmallInt()=default;
        OptionSmallInt(uint16_t val);
        OptionSmallInt & operator =(uint16_t val);
        virtual ~OptionSmallInt(){}
    private:
        uint16_t data;
    };

    class OptionInt:public OptionValue
    {
    public:
        OptionInt()=default;
        OptionInt(uint32_t val);
        OptionInt & operator =(uint32_t val);
        virtual ~OptionInt(){}
    private:
        uint32_t data;
    };

    class OptionBigInt:public OptionValue
    {
    public:
        OptionBigInt()=default;
        OptionBigInt(uint64_t val);
        OptionBigInt & operator =(uint64_t val);
        virtual ~OptionBigInt(){}
    private:
        uint64_t data;
    };

    class OptionFloat:public OptionValue
    {
    public:
        OptionFloat()=default;
        OptionFloat(float val);
        OptionFloat & operator =(float val);
        virtual ~OptionFloat(){}
    private:
        float data;
    };

    class OptionDouble:public OptionValue
    {
    public:
        OptionDouble()=default;
        OptionDouble(double val);
        OptionDouble & operator =(double val);
        virtual ~OptionDouble(){}
    private:
        double data;
    };
    class OptionString:public OptionValue
    {
    public:
        OptionString()=default;
        OptionString(std::string val);
        OptionString & operator =(std::string val);
        virtual ~OptionString(){}
    private:
        std::string data;
    };
}


#endif // OPTIONVALUE_H
