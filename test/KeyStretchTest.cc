//
// KeyStretchTest.cc
//
//     Created: 16.01.2012
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


#include <gtest/gtest.h>

#include "../src/KeyStretch.hh"
#include "../src/Defs.hh"

using namespace std;


TEST(KeyStretchTest, First)
{
	using namespace gPWS;
	StringX pass("first123");
	string salt("\x12\xE8\xA7\x6F\x0B\x20\x84\x7A"
	            "\x51\x49\xC3\x9D\xD3\xA5\xB1\xD5"
	            "\x44\x46\x3A\xE6\x2D\x89\x99\x10"
	            "\x44\x44\x85\x59\x7A\x89\xE3\x87");
	KeyStretch key_stretch(pass.c_str(), pass.size(),
	                       salt.c_str(), salt.size(),
	                       2048);
	const uint8_t ref[] =
	{
		0x97, 0xE3, 0xD3, 0x0F, 0x55, 0x86, 0x76, 0xC1,
		0x1C, 0x2A, 0xA6, 0xFE, 0xD1, 0xEC, 0xA4, 0x04,
		0xD9, 0xF4, 0xB2, 0x88, 0xB4, 0x73, 0x14, 0x07,
		0xDC, 0x76, 0xD0, 0x1B, 0xEC, 0x2A, 0x02, 0x65
	};

	ASSERT_EQ(end(ref) - begin(ref), key_stretch.LENGTH);
	for (size_t i{0}; i != key_stretch.LENGTH; ++i)
		EXPECT_EQ(int{ref[i]}, int{key_stretch.Get()[i]});
}

// vim: set noet ts=4 sw=4 tw=80:
