/******************************************************************************
* Copyright (c) 2011, Michael P. Gerlek (mpg@flaxen.com)
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following
* conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in
*       the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of Hobu, Inc. or Flaxen Geo Consulting nor the
*       names of its contributors may be used to endorse or promote
*       products derived from this software without specific prior
*       written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
****************************************************************************/

#ifndef INCLUDED_LIBLASREADER_HPP
#define INCLUDED_LIBLASREADER_HPP

#include "libpc/Reader.hpp"

#include <iostream>

#include "header.hpp"

#include <liblas/version.hpp>

// fwd decls
namespace liblas
{
    class Reader;
    // enum PointFormatName;
}


namespace libpc
{

class LIBPC_DLL LiblasReader : public Reader
{
public:
    LiblasReader(std::istream&);
    ~LiblasReader();

    const std::string& getName() const;

    virtual boost::uint32_t readPoints(PointData&);

    // default is to reset() and then read N points manually
    // override this if you can
    virtual void seekToPoint(boost::uint64_t pointNum);

    // default just resets the point index
    virtual void reset();

    const LiblasHeader& getLiblasHeader() const;

private:
    LiblasHeader& getLiblasHeader();
    void setLiblasHeader(const LiblasHeader&);
    void processExternalHeader();
    void registerFields();

    std::istream& m_istream;

    liblas::Reader *m_externalReader;

    // LAS header properties of interest to us
    boost::uint8_t m_versionMajor;
    boost::uint8_t m_versionMinor;
    double m_scaleX;
    double m_scaleY;
    double m_scaleZ;
    double m_offsetX;
    double m_offsetY;
    double m_offsetZ;
    bool m_isCompressed;
    
    liblas::PointFormatName m_pointFormat;
    bool m_hasTimeData;
    bool m_hasColorData;
    bool m_hasWaveData;

    LiblasReader& operator=(const LiblasReader&); // not implemented
    LiblasReader(const LiblasReader&); // not implemented
};

} // namespace libpc

#endif
