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

#include "JDK/Compiler/AST/StreamValiator.h"
#include "JDK/Compiler/Tokens.h"

#include "JDK/assert.h"
#include "JDK/except.h"
#include "JDK/keywords.h"

#include <iostream>
#include <string>

using namespace Roblox4j::Compiler;

__DECL_START ( Roblox4j )

namespace Ast
{

using TokenMap = const std::vector<Compiler::lexer_map_t>&;

static bool verify_package ( TokenMap vec, std::vector<std::string>&, bool& mod );
static bool isrange ( TokenMap vec, const Compiler::Tokens& type, const int start, const int stop );

static void spiterr ( TokenMap vec, const int start, const int stop, const std::string& cause, const std::string& where, const int line );
static void dumprange ( TokenMap vec, std::string& source, const int start, const int range );

StreamValidator::StreamValidator ( const std::vector<Compiler::lexer_map_t>& token_stream )
    : m_TokenStream ( token_stream )
{
}
StreamValidator::~StreamValidator () = default;

bool
StreamValidator::scan_tokens () noexcept
{
  bool shouldPass = true;
  size_t cursor = 0;
  size_t real_cursor = 0;
  size_t stream_size = m_TokenStream.size ();

  /// TODO: Need to swallow new lines and trailing spaces

#ifdef __R4J_DEBUG__
  JDK_ASSERT ( m_TokenStream[ 0 ].value == Tokens::TOKEN_CHARACTER, "File did not start with a character" );
#endif

  std::string content;
  std::vector<std::string> package_folders;

  while ( cursor != stream_size )
    {
      // Critical Constants
      static bool checked_package = false;
      // End Critical Constants
      if ( !shouldPass )
        break;
      if ( m_TokenStream[ cursor ].value == Tokens::TOKEN_WHITESPACE )
        {
          /* Do Nothing */
        }
      else
        {
          /* Verify Java Package */
          if ( !isrange ( m_TokenStream, Tokens::TOKEN_CHARACTER, 0, 6 ) )
            {
              spiterr ( m_TokenStream, 0, 6, "Invalid identifier. Exepected package at top level.", content, real_cursor );
              shouldPass = false;
              break;
            }
          if ( !verify_package ( m_TokenStream, package_folders, checked_package ) && !checked_package )
            {
              spiterr ( m_TokenStream, 0, 7, "Missing package identifier. Expected package at top level.", content, real_cursor );
              shouldPass = false;
              break;
            }
        }
      content += m_TokenStream[ cursor ].key;
      cursor++;
    }

  return shouldPass;
}

static bool
verify_package ( TokenMap vec, std::vector<std::string>& pvec, bool& mod )
{
  if ( !mod )
    {
      std::string word;
      for ( int i = 0; i < 7; i++ )
        {
          word += vec[ i ].key;
        }
      if ( word == jdk_keywords[ 0 ] )
        {
          if ( vec[ 8 ].key == ';' || vec[ 8 ].key == '.' || std::isdigit ( vec[ 8 ].key ) )
            return false;
          /* Check for package name and or dot separator */
          word = "";
          int i = 7;
          while ( vec[ i ].key != ';' )
            {
              if ( vec[ i ].value == Tokens::TOKEN_CHARACTER || vec[ i ].value == Tokens::TOKEN_NUMBER )
                {
                  // append character array to a package stream (this is the folder name)
                  word += vec[ i ].key;
                  std::cout << "Word: " << word << std::endl;
                }
              if ( vec[ i ].value == Tokens::TOKEN_SEPARATOR )
                {
                  pvec.push_back ( word );
                }
              i++;
            }
          // REMOVE:
          for ( const auto& pkg : pvec )
            {
              std::cout << "Package Name: " << pkg << std::endl;
            }
          return true;
        }
      return false;
    }
  mod = true;
  return false;
}

static bool
isrange ( TokenMap vec, const Compiler::Tokens& type, const int start, const int stop )
{
  for ( int i = start; i < stop; i++ )
    if ( vec[ i ].value != type )
      return false;
  return true;
}

static void
dumprange ( TokenMap vec, std::string& source, const int start, const int range )
{
  for ( int i = start; i < range; i++ )
    source += vec[ i ].key;
}

static void
spiterr ( TokenMap vec, const int start, const int stop, const std::string& cause, const std::string& where, const int line )
{
  dumprange ( vec, const_cast<std::string&> ( where ), start, stop );
  jdk_raise_exception ( cause.c_str (), where.c_str (), std::to_string ( line ).c_str () );
}

}

__DECL_END ()