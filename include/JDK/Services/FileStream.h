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

#ifndef JDK_SERVICES_FILESTREAM_H
#define JDK_SERVICES_FILESTREAM_H

#include "defs.h"

#include <fstream>
#include <string>
#include <vector>

__DECL_START ( Roblox4j )

namespace Services
{
class FileStream final
{
private:
  std::string m_Path;
  std::vector<std::string> m_Contents;
  std::ifstream m_File;

public:
  FileStream ( const std::string& path );
  ~FileStream ();

public:
  // TODO: Convert to static member later
  const std::vector<std::string> read_file () noexcept;

public:
  static void write_file ( const char*, const std::string& ) noexcept;
};
}

__DECL_END ()

#endif /* JDK_SERVICES_FILESTREAM_H */