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

#ifndef JDK_COMPILER_AST_STREAMVALIDATOR_H
#define JDK_COMPILER_AST_STREAMVALIDATOR_H

// Validates and checks the tokens

#include "JDK/Compiler/Lexer.h"
#include "defs.h"

#include <vector>

__DECL_START ( Roblox4j )

namespace Ast
{
class StreamValidator final
{
private:
  std::vector<Compiler::lexer_map_t> m_TokenStream;

public:
  StreamValidator ( const std::vector<Compiler::lexer_map_t>& token_stream );
  ~StreamValidator ();

public:
  bool scan_tokens () noexcept;
};
}

__DECL_END ()

#endif /* JDK_COMPILER_AST_STREAMVALIDATOR_H */