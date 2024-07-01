#include "JDK/Compiler/AST/StreamValiator.h"
#include "JDK/Compiler/Lexer.h"
#include "JDK/Services/FileStream.h"

#include <iostream>

int
main ()
{
  auto stream = Roblox4j::Services::FileStream ( "/Users/mustafamalik/Desktop/Roblox4j/transpiler/resources/Sample.java" );
  std::vector<std::string> contents = stream.read_file ();

  // for ( const auto& line : contents )
  //   {
  //     std::cout << line << std::endl;
  //   }

  Roblox4j::Compiler::Lexer lexer ( contents );
  const std::vector<Roblox4j::Compiler::lexer_map_t> tok_stream = lexer.generate_tokens ();

  Roblox4j::Ast::StreamValidator validator ( tok_stream );
  bool result = validator.scan_tokens ();

  if ( !result )
    {
      std::cout << "Failed to generate AST a value was not true\n";
    }

  return 0;
}
