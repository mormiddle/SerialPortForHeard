#include "SlStr.h"


bool SlStr::copy(char *pszDst, size_t bufSize, const char *pszSrc, int n)
{
    if( pszDst == NULL || bufSize < 1)
    {
        return false;
    }

    if( isEmpty( pszSrc ) || n < 0)
    {
        *pszDst = '\0';
        return true;
    }

    int nMax = 0;
    if( nMax == 0 || nMax > ( int )bufSize - 1)
    {
        nMax = ( int ) bufSize - 1;
    }
    char* pszDstEnd = pszDst + nMax;
    char* pChDst = pszDst;
    const char* pChSrc = pszSrc;
    while ( pChDst < pszDstEnd && *pChSrc)
    {
        *pChDst++ = *pChSrc++;
    }
    *pChDst = '\0';

    if( *pChSrc && ( n == 0 || n > nMax ) )
    {
        return false;
    }
    return true;

}

QString SlStr::toString( int val )
{
    return QString::number( val );
}
QString SlStr::toString( __int64 val )
{
    return QString::number( val );
}
QString SlStr::toString( float val )
{
    return QString::number( val, 'g', 32 );
}
QString SlStr::toString( double val )
{
    return QString::number( val, 'g', 32 );
}
QString SlStr::toString( const char* /*pszData*/, int /*bytes*/ )
{
    return "";
}

QString SlStr::format(const char *pszFormat, va_list args)
{
    std::string str;
    if( !isEmpty( pszFormat ) )
    {
        //返回值，不包含 末尾'\0'
        int sizeWant = _vscprintf( pszFormat, args );
        if( sizeWant > 0 )
        {
            char* pszBuf = ( char* ) malloc( sizeWant + 1);
            if( pszBuf )
            {
                int sizeUsed = _vsnprintf_s( pszBuf, sizeWant + 1, _TRUNCATE, pszFormat, args );
                if( sizeUsed == sizeWant )
                {
                    str = pszBuf;
                }
                free( pszBuf );
            }
        }
    }

    return  str.c_str();
}

QString SlStr::format(const char *pszFormat, ...)
{
    va_list args;
    va_start( args, pszFormat );
    QString str = format( pszFormat, args );
    va_end( args );

    return str;
}

// 按有效数字返回数字串
//QString SlStr::getValidNumerical( const char* psz, int nValid )
//{
//	char szBuf[ ZBase::MaxRadixStringLength + 1 ];
//	if ( nValid < 1 )
//	{
//		szBuf[ 0 ] = '\0';
//		return szBuf;
//	}
//
//	szBuf[ 0 ] = szBuf[ 1 ] = '0';		// 前导零，预留存放 '-' 及 进位(或前导零)
//	char* pDst = szBuf + 2;
//
//	bool bNegative = false;
//	bool bDot = false;
//	INT32 cInteger = 0;		// 整数部分数字计数
//	INT32 cDigit = 0;		// 小数部分数字计数
//	INT32 cValid = 0;		// 总有效数字计数
//	char* pCh = ( char* ) psz;
//	while ( char ch = *pCh++ )
//	{
//		switch ( ch )
//		{
//		case ' ':			// 未遇数字或小数点时忽略空格，之后则判为数值串结束
//			if ( bDot || cInteger || cDigit )
//			{
//				goto lNumericalEnd;
//			}
//			break;
//		case '-':
//			if ( bDot || bNegative || cInteger || cDigit )
//			{
//				szBuf[ 0 ] = '\0';
//				return szBuf;
//			}
//			bNegative = true;
//			break;
//		case '.':
//			if ( bDot || cDigit )
//			{
//				szBuf[ 0 ] = '\0';
//				return szBuf;
//			}
//			*pDst++ = ch;
//			bDot = true;
//			break;
//		case CaseNumber:
//			*pDst++ = ch;
//			if ( bDot )
//			{
//				cDigit++;
//			}
//			else
//			{
//				cInteger++;
//			}
//			if ( cValid || ch != '0' )
//			{
//				if ( ++cValid > nValid && bDot )		// 超过有效数字位数，且在小数部分，截断，只多保留1位用于判断舍入
//				{
//					goto lNumericalEnd;
//				}
//			}
//			break;
//		default:
//			szBuf[ 0 ] = '\0';
//			return szBuf;
//		}
//	}
//lNumericalEnd:
//	if ( cInteger == 0 && cDigit == 0 )
//	{
//		szBuf[ 0 ] = '\0';
//		return szBuf;
//	}
//	*pDst = '\0';
//
//	// 超出有效数字位数后 四舍五入
//	if ( cInteger + cDigit > nValid )
//	{
//		pCh = szBuf + 2 + nValid + ( cInteger <= nValid ? 1 : 0 );	// 指向用于判断舍入的那个数字
//		bool bInc = ( *pCh >= '5' );		// 进位
//
//		// 先处理后面部分
//		pDst = pCh;
//		if ( cInteger <= nValid )		// 此位在小数部分，截断
//		{
//			*pDst = '\0';
//		}
//		else		// 此位在整数部分，向后填充 '0' 到小数点为止，并截断
//		{
//			while ( *pDst != '.' )
//			{
//				*pDst++ = '0';
//			}
//			*pDst = '\0';
//			bDot = false;
//		}
//
//		if ( bInc )		// 向前进位
//		{
//			for ( ;;)
//			{
//				char ch = *( --pCh );
//				if ( ch == '.' )		// 忽略
//				{
//				}
//				else if ( ch < '9' )
//				{
//					*pCh = ch + 1;
//					break;
//				}
//				*pCh = '0';
//			}
//		}
//	}
//
//	// 去除前导零，至少保留1位
//	pCh = szBuf;
//	char* pChEnd = pCh + 2 + cInteger - 1;		// 保留1位
//	while ( ++pCh < pChEnd && *pCh == '0' )
//	{
//	}
//
//	// 去除小数部分尾部的 '0'，如果末尾是小数点，也去除
//	if ( bDot )
//	{
//		for ( ;;)
//		{
//			char ch = *( --pDst );
//			if ( ch == '.' )
//			{
//				*pDst = '\0';
//				break;
//			}
//			else if ( ch != '0' )
//			{
//				pDst[ 1 ] = '\0';
//				break;
//			}
//		}
//	}
//
//	// 加负号
//	if ( bNegative && ( pCh[ 1 ] != '\0' || *pCh != '0' ) )		// 排除 '-0'
//	{
//		*( --pCh ) = '-';
//	}
//
//	return pCh;
//}


