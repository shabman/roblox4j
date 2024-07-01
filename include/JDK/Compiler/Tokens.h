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

#ifndef JDK_COMPILER_TOKENS_H
#define JDK_COMPILER_TOKENS_H

#include "defs.h"

__DECL_START ( Roblox4j )

namespace Compiler
{
enum class Tokens
{
  /* Other */
  TOKEN_WHITESPACE,
  TOKEN_UNKNOWN,

  /* Top Level */
  TOKEN_PACKAGE_IDENTIFIER,

  /* String related */
  TOKEN_STRING_LITERAL,
  TOKEN_STRING_CONCAT

};
}

__DECL_END ()

#endif /* JDK_COMPILER_TOKENS_H */
