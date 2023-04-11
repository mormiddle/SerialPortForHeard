#pragma once

#include "SlBase_global.h"
#include <QString>

class SLBASE_EXPORT SlStr
{
public:
    static inline bool isEmpty(const char* psz) { return (psz == NULL || *psz == '\0'); }

    //return false when buf not enough
    static bool copy(char* pszDst, size_t bufSize, const char* pszSrc, int n = 0);

    //return false when buf not enough
    template<size_t _Size>
    static inline bool copy( char( &szDst )[ _Size ], const char* pszSrc, int n = 0 )
    {
        return copy( ( char* ) szDst, _Size, pszSrc, n );
    }

    static QString toString( int val );
    static QString toString( __int64 val );
    static QString toString( float val);
    static QString toString( double val);
    static QString toString( const char* pszData, int bytes);

    static QString format( const char* pszFormat, va_list args);
    static QString format( const char* pszFormat, ...);

};
