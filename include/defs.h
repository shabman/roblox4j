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

#ifndef _DEFS_H_
#define _DEFS_H_

#if __cplusplus
#define __DECL_START( name ) \
  namespace name             \
  {
#define __DECL_END() }
#else
#define __DECL_START( name )
#define __DECL_END()
#endif

#define IMMUTABLE_OBJ( obj ) const obj const

#endif /* _DEFS_H_ */