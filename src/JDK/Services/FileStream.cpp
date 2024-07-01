/**
 *   JDK Compiler - Compiles Java Source to RBLX4J Bytecode
 *   Copyright (C) 2024  Mustafa Malik (140mustafa@gmail.com)
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "JDK/Services/FileStream.h"

__DECL_START ( Roblox4j )

namespace Services
{

FileStream::FileStream ( const std::string& path )
    : m_Path ( path )
{
  this->m_File = std::ifstream ( path );
}

FileStream::~FileStream ()
{
  this->m_File.close ();
}

const std::vector<std::string>
FileStream::read_file () noexcept
{
  std::string line;
  while ( getline ( this->m_File, line ) )
    {
      this->m_Contents.push_back ( line );
    }
  return this->m_Contents;
}

void
FileStream::write_file ( const char* path, const std::string& contents ) noexcept
{
  std::ofstream writer;
  writer.open ( path );
  if ( writer.is_open () )
    writer << contents;
  writer.close ();
}

}

__DECL_END ()