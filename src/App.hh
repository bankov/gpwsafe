//
// App.hh
//
//     Created: 24.01.2012
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

#pragma once

#include "../config.h"
#include "Command.hh"

#include <string>
#include <boost/noncopyable.hpp>

namespace gPWS {

struct iEmitter;

class cApp
	: boost::noncopyable
{
public:
	cApp(char const *program_name);

	void Init(int argc, char *argv[]);

	void Run();

private:
	char const *_program_name;
	cCommand::PtrT _command;
	cCommand::Params _params;

	char const *_argument;

	void _Run();
	void _Usage(bool fail);
	void _DoCreate();
	void _DoEdit();
	void _SetCommand(cCommand::PtrT command);
};

} //namespace gPWS;

// vim: set noet ts=4 sw=4 tw=80:
