//
// DatabaseTest.cc
//
//     Created: 15.03.2014
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


#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#define private public
#include "../src/Database.hh"
#undef private
#include "../src/Gcrypt.hh"

using namespace std;
using namespace gPWS;

struct sGlobalFixture
{
	sGlobalFixture()
	{
		gPWS::cGcrypt::Init(true);
	}

} global_fixture;

BOOST_AUTO_TEST_SUITE(DatabaseTest)

BOOST_AUTO_TEST_CASE(TestFollowSymlink)
{
#define DEFS \
		"#/bin/bash\n" \
		"d=/tmp/gpws\n" \
		"t=$d/sym/link/1.psafe3\n" \
		"f=$d/f.psafe3\n"

	BOOST_ASSERT(
		0 ==
		system(DEFS
		       "rm -rf $d\n"
		       "mkdir -p `dirname $t`\n"
		       "echo asdf > $t\n"
		       "ln -s $t $f\n")
		);

	BOOST_CHECK_EQUAL("/tmp/gpws/sym/link/1.psafe3",
	                  cDatabase::FollowSymlink("/tmp/gpws/f.psafe3"));
	cDatabase d;
	d._fname = "/tmp/gpws/f.psafe3";
	d._pass = "password";
	d.Write();

	BOOST_ASSERT(0 == system(DEFS "test asdf = `cat $t~`\n"));
	BOOST_ASSERT(0 == system(DEFS "test $t = `readlink -f $f`\n"));
}

BOOST_AUTO_TEST_SUITE_END()

// vim: set noet ts=4 sw=4 tw=80: