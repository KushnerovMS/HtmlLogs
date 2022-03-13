#ifndef LOGS_HEADER
#define LOGS_HEADER

#include <stdio.h>

const char DEFAULT_LOG_NAME[] = "Logs.html";

class Logs
{
    private:

        FILE* file_;

    public:

        explicit Logs ();
        explicit Logs (const char* name);

        ~Logs ();
        
        
        void error  (const char* text);
        void warn   (const char* text);
        void debug  (const char* text);
        void trace  (const char* text);

        void print  (const char* text);

    private:

        char* getTimeString_ (char* buf);
};

extern Logs Logs;

#endif
