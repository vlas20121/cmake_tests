#pragma once
#include <ostream>
#include <string>
#include <functional>

using OnLine = std::function<void(const char* s)>;
struct LineStreamer : std::ostream, std::streambuf
{
    LineStreamer(OnLine _onLine= [](const char* s) {std::cout << s; })
        :std::ostream(this), onLine(_onLine)
    {}
    ~LineStreamer()
    {
	if(!buffer.empty())
        	FlashLine();
    }
private:
    std::string buffer;
    OnLine onLine;

    virtual int overflow(int c)
    {
        buffer.push_back(c);
        if(c=='\n')
            FlashLine();
        return 0;
    }
    void FlashLine()
    {
        onLine(buffer.c_str());
        buffer.clear();
    }
};
