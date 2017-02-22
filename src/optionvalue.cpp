#include "optionvalue.h"
namespace optionsql
{

    OptionTinyInt::OptionTinyInt(uint8_t val)
        :data(val){}

    OptionTinyInt &OptionTinyInt::operator =(uint8_t val)
    {
        data=val;
        return *this;
    }


    OptionSmallInt::OptionSmallInt(uint16_t val)
        :data(val){}

    OptionSmallInt &OptionSmallInt::operator =(uint16_t val)
    {
        data=val;
        return *this;
    }

    OptionInt::OptionInt(uint32_t val)
        :data(val){}

    OptionInt &OptionInt::operator =(uint32_t val)
    {
        data=val;
        return *this;
    }

    OptionBigInt::OptionBigInt(uint64_t val)
        :data(val){}

    OptionBigInt &OptionBigInt::operator =(uint64_t val)
    {
        data=val;
        return *this;
    }

    OptionFloat::OptionFloat(float val)
        :data(val){}

    OptionFloat &OptionFloat::operator =(float val)
    {
        data=val;
        return *this;
    }

    OptionDouble::OptionDouble(double val)
        :data(val){}

    OptionDouble &OptionDouble::operator =(double val)
    {
        data=val;
        return *this;
    }

    OptionString::OptionString(std::string val)
        :data(val){}

    OptionString &OptionString::operator =(std::string val)
    {
        data=val;
        return *this;
    }
}
