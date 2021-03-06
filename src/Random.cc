//
// Random.cc
//
//     Created: 27.01.2012
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

#include "Random.hh"

#include <gcrypt.h>

namespace gPWS {

void Random::CreateNonce(uint8_t *buffer, unsigned len)
{
	gcry_create_nonce(buffer, len);
}

void Random::Randomize(uint8_t *buffer, unsigned length,
                       bool very_strong)
{
	gcry_randomize(buffer, length,
	               very_strong ? GCRY_VERY_STRONG_RANDOM : GCRY_STRONG_RANDOM);
}

} //namespace gPWS;

// vim: set noet ts=4 sw=4 tw=80:
