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

#ifndef JDK_COMPILER_LEXER_H
#define JDK_COMPILER_LEXER_H

#include "defs.h"

#include <string>
#include <vector>

__DECL_START ( Roblox4j )

namespace Compiler
{

enum class Tokens;

typedef struct lexer_map
{
  const char* key;
  Tokens value;
} lexer_map_t;

class Lexer final
{
private:
  std::vector<lexer_map_t> m_TokenMap;
  std::vector<std::string> m_Contents;
  std::string m_CurrentErrMsg;

public:
  Lexer ( const std::vector<std::string>& );
  ~Lexer ();

public:
  const std::vector<lexer_map_t> generate_tokens () noexcept;
  void dump_tokens_to ( const char* ) noexcept;
};

}

__DECL_END ()

#endif /* JDK_COMPILER_LEXER_H */
