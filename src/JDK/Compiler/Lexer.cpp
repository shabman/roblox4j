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

#include "JDK/Compiler/Lexer.h"
#include "JDK/Compiler/Tokens.h"
#include "JDK/Services/FileStream.h"

#include <cstdlib>
#include <iostream>

__DECL_START ( Roblox4j )

namespace Compiler
{

Lexer::Lexer ( const std::vector<std::string>& contents )
{
  this->m_Contents = contents;
}

Lexer::~Lexer () = default;

const std::vector<lexer_map_t>
Lexer::generate_tokens () noexcept
{
  if ( this->m_Contents.empty () )
    return m_CharacterMap;

  std::string source;
  for ( auto& line : this->m_Contents )
    {
      source += line;
    }

  const char* src = source.c_str ();
  while ( *src != '\0' )
    {
      if ( std::isspace ( *src ) )
        {
          /* Check for spaces */
          m_CharacterMap.push_back ( { *src, Tokens::TOKEN_WHITESPACE } );
        }
      else if ( std::isalpha ( *src ) )
        {
          /* Check for characters */
          m_CharacterMap.push_back ( { *src, Tokens::TOKEN_CHARACTER } );
        }
      else if ( std::isdigit ( *src ) )
        {
          /* Check for digits */
          m_CharacterMap.push_back ( { *src, Tokens::TOKEN_NUMBER } );
        }
      else
        {
          /* Check for other symbols */
          // TODO: Use switch cases even though the compiler probably will do this for me lol
          switch ( *src )
            {
            case ';':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_TERMINATOR } );
              break;
            case '{':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_CURLY_BRACE_OPEN } );
              break;
            case '}':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_CURLY_BRACE_CLOSE } );
              break;
            case '[':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_SQUARE_OPEN } );
              break;
            case ']':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_SQUARE_CLOSE } );
              break;
            case '\'':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_SINGLE_QUOTE } );
              break;
            case '"':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_DOUBLE_QUOTE } );
              break;
            case '.':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_SEPARATOR } );
              break;
            case '/':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_DIV_OP } );
              break;
            case '*':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_MUL_OP } );
              break;
            case '+':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_ADD_OP } );
              break;
            case '-':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_SUB_OP } );
              break;
            case '%':
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_MOD_OP } );
              break;
            default:
              m_CharacterMap.push_back ( { *src, Tokens::TOKEN_UNKNOWN } );
              break;
            }
        }
      src++;
    }

#ifdef __R4J_DEBUG__
  for ( auto tree : m_CharacterMap )
    {
      std::cout << "Key: " << ( char )tree.key << " Value: " << static_cast<int> ( tree.value ) << std::endl;
    }

  std::cout << "-----------------------\n";
  dump_tokens_to ( "rblxout_stage_1.txt" );
#endif

  return m_CharacterMap;
}

void
Lexer::dump_tokens_to ( const char* file ) noexcept
{
  std::string content;
  for ( const auto& map : m_CharacterMap )
    {
      content += "[K]: " + std::string ( 1, map.key ) + " [V]: " + std::to_string ( static_cast<int> ( map.value ) ) + "\n";
    }

  Services::FileStream::write_file ( file, content );
}

}

__DECL_END ()