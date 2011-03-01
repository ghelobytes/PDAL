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

#ifndef INCLUDED_LIBLASWRITER_HPP
#define INCLUDED_LIBLASWRITER_HPP

#include "libpc/Writer.hpp"

namespace liblas
{
    class Writer;
    class Header;
}


namespace libpc
{

// we default to LAS 1.2, point format 0
class LIBPC_DLL LiblasWriter : public Writer
{
public:
    LiblasWriter(Stage& prevStage, std::ostream&);
    ~LiblasWriter();

    const std::string& getName() const;
    
    void setFormatVersion(boost::uint8_t majorVersion, boost::uint8_t minorVersion);
    void setPointFormat(boost::int8_t pointFormat);
    void setDate(boost::uint16_t dayOfYear, boost::uint16_t year);
    
    // up to 32 chars (default is "libPC")
    void setSystemIdentifier(const std::string& systemId); 
    
    // up to 32 chars (default is "libPC x.y.z")
    void setGeneratingSoftware(const std::string& softwareId);

    // default false
    void setCompressed(bool);

protected:
    // this is called once before the loop with the writeBuffer calls
    virtual void writeBegin();

    // called repeatedly, until out of data
    virtual boost::uint32_t writeBuffer(const PointData&);

    // called once, after the writeBuffer calls
    virtual void writeEnd();

private:
    void setupExternalHeader();

    std::ostream& m_ostream;
    liblas::Writer* m_externalWriter;
    liblas::Header* m_externalHeader;

    LiblasWriter& operator=(const LiblasWriter&); // not implemented
    LiblasWriter(const LiblasWriter&); // not implemented
};

} // namespace libpc

#endif
