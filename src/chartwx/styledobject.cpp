/********************************************************************************
 *                                                                              *
 * chartwx - base class of objects with a style                                 *
 *                                                                              *
 * modified: 2024-07-27                                                         *
 *                                                                              *
 ********************************************************************************
 * Copyright (C) Harald Braeuning                                               *
 ********************************************************************************
 * This file is part of 'chartwx'.                                              *
 * 'chartwx' is free software: you can redistribute it and/or modify it         *
 * under the terms of the GNU General Public License as published by the Free   *
 * Software Foundation, either version 3 of the License, or (at your option)    *
 * any later version.                                                           *
 * 'chartwx' is distributed in the hope that it will be useful, but             *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY   *
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for  *
 * more details.                                                                *
 * You should have received a copy of the GNU General Public License along with *
 * imca. If not, see <https://www.gnu.org/licenses/>.                           *
 ********************************************************************************/

#include "styledobject.h"

namespace chartwx {

StyledObject::StyledObject(StyledObject* parent):
  style(parent?parent->GetStyle():Style::GetDefaultStyle())
{

}

const Style& StyledObject::GetStyle() const
{
  return style;
}

void  StyledObject::SetStyle(const Style& s)
{
  style = s;
}



} // namespace chartwx

