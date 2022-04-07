#include <stdio.h>
#include <time.h>
#include <stdarg.h>

#include "Logs.h"

class Logs Logs;

Logs::Logs ():
    file_ (fopen (DEFAULT_LOG_NAME, "w"))
{
    if (file_ == nullptr)
        printf ("Log file can't be opened");
    else
    {
        fprintf (file_, "<pre>");
    }
}
    
Logs::Logs (const char* name):
    file_ (fopen (name, "w"))
{
    if (file_ == nullptr)
        printf ("Log file can't be opened");
}


Logs::~Logs ()
{
    fclose (file_);
}


const size_t TIME_BIFFER_SIZE = 100;

char* Logs::getTimeString (char* buffer)
{
    time_t rawtime = 0;
    struct tm* timeinfo = {};

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer, TIME_BIFFER_SIZE, "%Y.%m.%d %H:%M:%S", timeinfo);

    return buffer;
}

void Logs::error (const char* fmt, ...)
{
    char buffer[100];

    fprintf (file_, "<u>%s</u> <font color = red><b>error:</b></font>   ", getTimeString (buffer));

    va_list ap;
    va_start (ap, fmt);
    vfprintf (file_, fmt, ap);
    va_end (ap);

    fputc ('\n', file_);

    fflush (file_);
}

void Logs::warn (const char* fmt, ...)
{
    char buffer[100];

    fprintf (file_, "<u>%s</u> <font color = purple><b>warning:</b></font> ", getTimeString (buffer));

    va_list ap;
    va_start (ap, fmt);
    vfprintf (file_, fmt, ap);
    va_end (ap);

    fputc ('\n', file_);

    fflush (file_);
}

void Logs::debug (const char* fmt, ...)
{
    char buffer[100];

    fprintf (file_, "<u>%s</u> <font color = teal><b>debug:</b></font>   ", getTimeString (buffer));

    va_list ap;
    va_start (ap, fmt);
    vfprintf (file_, fmt, ap);
    va_end (ap);

    fputc ('\n', file_);

    fflush (file_);
}

void Logs::trace (const char* fmt, ...)
{
    char buffer[100];

    fprintf (file_, "<u>%s</u> <font color = #404040><b>trace:</b></font>   ", getTimeString (buffer));

    va_list ap;
    va_start (ap, fmt);
    vfprintf (file_, fmt, ap);
    va_end (ap);

    fputc ('\n', file_);

    fflush (file_);
}

void Logs::print (const char* fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    vfprintf (file_, fmt, ap);
    va_end (ap);

    fputc ('\n', file_);
}

FILE* Logs::getFile ()
{
    return file_;
}
