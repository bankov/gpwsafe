//
// StdoutEmitter.cc
//
//     Created: 25.01.2012
//      Author: A. Sakhnik
//
// This file is part of gpwsafe.
//
// Gpwsafe is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Gpwsafe is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with gpwsafe.  If not, see <http://www.gnu.org/licenses/>

#include "StdoutEmitter.hh"
#include "i18n.h"

#include <iostream>
#include <boost/format.hpp>

namespace gPWS {

using namespace std;
typedef boost::format bfmt;

void StdoutEmitter::PrintIntention(string const &subject) const
{
	cerr << bfmt(_("Going to print %s to stdout")) % subject << endl;
}

void StdoutEmitter::Emit(StringX const &name, StringX const &val)
{
	cout << name << ": " << val << endl;
}

} //namespace gPWS;

// vim: set noet ts=4 sw=4 tw=80:
