#include "SlFile.h"

SlFile::SlFile()
{
}

SlFile::~SlFile()
{
    close();
}

bool SlFile::open(const QString &file, const QString &mode)
{
    close();

    m_pFile = fopen( file.toUtf8().data(), mode.toUtf8().data() );

    return ( m_pFile != nullptr );
}

FILE *SlFile::getHandle()
{
    return m_pFile;
}

void SlFile::close()
{
    if( m_pFile != nullptr)
    {
        fclose( m_pFile );
        m_pFile = nullptr;
    }
}

int SlFile::getSize()
{
    if( m_pFile == nullptr)
    {
        return -1;
    }

    int pos = ftell( m_pFile );//先记录文件指针的位置
    fseek( m_pFile, 0, SEEK_END );//移动文件指针到文件尾
    int size = ftell( m_pFile );//记录文件尾的位置，即为size
    fseek( m_pFile, pos, SEEK_SET );//将文件指针移动会原来的位置

    return  size;
}

int SlFile::getPos()
{
    if( m_pFile == nullptr )
    {
        return -1;
    }

    return ftell( m_pFile );
}

bool SlFile::setPos(int pos)
{
    if( m_pFile == nullptr )
    {
        return -1;
    }

    fseek( m_pFile, pos, SEEK_SET );
    return ( ftell( m_pFile ) == pos );
}

bool SlFile::read(void *pData, int bytes, int pos)
{
    if( m_pFile == nullptr
        || pData == nullptr
        || bytes <= 0)
    {
        return  false;
    }

    if( pos >= 0
        && 0 != fseek( m_pFile, pos, SEEK_SET))
    {
        return false;
    }

    return ( fread( pData, 1, bytes, m_pFile ) == bytes );
}

bool SlFile::read(QByteArray &data, int bytes, int pos)
{
    if( bytes <= 0 )
    {
        return false;
    }

    data.clear();
    data.resize( bytes );

    return read( data.data(), bytes, pos);
}

bool SlFile::write(const void *pData, int bytes, int pos)
{
    if( m_pFile == nullptr
        || pData == nullptr
        || bytes <= 0)
    {
        return false;
    }

    if( pos >= 0
        && 0 != fseek( m_pFile, pos, SEEK_SET))
    {
        return false;
    }

    return ( fwrite( pData, 1, bytes, m_pFile ) == bytes );
}

bool SlFile::write(const QByteArray &data, int pos)
{
    return write( data.data(), data.size(), pos);
}

void SlFile::test()
{

}





