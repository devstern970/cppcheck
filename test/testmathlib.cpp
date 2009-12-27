/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2009 Daniel Marjamäki and Cppcheck team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include "mathlib.h"
#include "testsuite.h"

class TestMathLib : public TestFixture
{
public:
    TestMathLib() : TestFixture("TestMathLib")
    { }

private:

    void run()
    {
        TEST_CASE(calculate);
        TEST_CASE(convert);
        TEST_CASE(isint);
    }

    void calculate()
    {
		// addition
        ASSERT_EQUALS("256", MathLib::add("0xff", "1"));
        ASSERT_EQUALS("249", MathLib::add("250", "-1"));
        ASSERT_EQUALS("251", MathLib::add("250", "1"));
        ASSERT_EQUALS("-2" , MathLib::add("-1.", "-1"));
        ASSERT_EQUALS("-1" , MathLib::add("0", "-1"));
        ASSERT_EQUALS("1"  , MathLib::add("1", "0"));
        ASSERT_EQUALS("0"  , MathLib::add("0", "0."));

		// subtraction
        ASSERT_EQUALS("254", MathLib::subtract("0xff", "1"));
        ASSERT_EQUALS("251", MathLib::subtract("250", "-1"));
        ASSERT_EQUALS("249", MathLib::subtract("250", "1"));
        ASSERT_EQUALS("0"  , MathLib::subtract("-1.", "-1"));
        ASSERT_EQUALS("1"  , MathLib::subtract("0", "-1"));
        ASSERT_EQUALS("1"  , MathLib::subtract("1", "0"));
        ASSERT_EQUALS("0"  , MathLib::subtract("0", "0."));

		// multiply
        ASSERT_EQUALS("-0.003", MathLib::multiply("-1e-3", "3"));
        ASSERT_EQUALS("-11.96", MathLib::multiply("-2.3", "5.2"));
        ASSERT_EQUALS("3000"  , MathLib::multiply("1E3", "3"));
        ASSERT_EQUALS("3000"  , MathLib::multiply("1E+3", "3"));
        ASSERT_EQUALS("3000"  , MathLib::multiply("1.0E3", "3"));
        ASSERT_EQUALS("-3000" , MathLib::multiply("-1.0E3", "3"));
        ASSERT_EQUALS("-3000" , MathLib::multiply("-1.0E+3", "3"));
        ASSERT_EQUALS("0" 	  , MathLib::multiply("-1.0E+3", "0"));
        ASSERT_EQUALS("0" 	  , MathLib::multiply("+1.0E+3", "0"));

		// divide
        ASSERT_EQUALS("1"	, MathLib::divide("1", "1"));
        ASSERT_EQUALS("0"	, MathLib::divide("0", "1"));
        ASSERT_EQUALS("5"	, MathLib::divide("-10", "-2"));
        ASSERT_EQUALS("-2.5", MathLib::divide("-10.", "4"));
        ASSERT_EQUALS("2.5" , MathLib::divide("-10.", "-4"));					
        ASSERT_EQUALS("5"	, MathLib::divide("25.5", "5.1"));
        ASSERT_EQUALS("7"	, MathLib::divide("21.", "3"));
        ASSERT_EQUALS("1"	, MathLib::divide("3", "2"));

    }

    void convert()
    {
		// ------------------
		// tolong conversion:
		// ------------------

		// from hex
        ASSERT_EQUALS(10	, MathLib::toLongNumber("0xa"));
        ASSERT_EQUALS(10995	, MathLib::toLongNumber("0x2AF3"));
        ASSERT_EQUALS(-10	, MathLib::toLongNumber("-0xa"));
        ASSERT_EQUALS(-10995, MathLib::toLongNumber("-0x2AF3"));
        ASSERT_EQUALS(10	, MathLib::toLongNumber("+0xa"));
        ASSERT_EQUALS(10995 , MathLib::toLongNumber("+0x2AF3"));

		// from octal
        ASSERT_EQUALS(8 	, MathLib::toLongNumber("010"));
        ASSERT_EQUALS(8 	, MathLib::toLongNumber("+010"));
        ASSERT_EQUALS(-8 	, MathLib::toLongNumber("-010"));
        ASSERT_EQUALS(125 	, MathLib::toLongNumber("0175"));
        ASSERT_EQUALS(125 	, MathLib::toLongNumber("+0175"));
        ASSERT_EQUALS(-125 	, MathLib::toLongNumber("-0175"));

		// from base 10 
        ASSERT_EQUALS(10	, MathLib::toLongNumber("10"));
        ASSERT_EQUALS(10	, MathLib::toLongNumber("10."));
        ASSERT_EQUALS(10	, MathLib::toLongNumber("10.0"));
        ASSERT_EQUALS(100	, MathLib::toLongNumber("10E+1"));
        ASSERT_EQUALS(1	    , MathLib::toLongNumber("10E-1"));
        ASSERT_EQUALS(100	, MathLib::toLongNumber("+10E+1"));
        ASSERT_EQUALS(-1	, MathLib::toLongNumber("-10E-1"));
        ASSERT_EQUALS(100	, MathLib::toLongNumber("+10.E+1"));
        ASSERT_EQUALS(-1	, MathLib::toLongNumber("-10.E-1"));
        ASSERT_EQUALS(100	, MathLib::toLongNumber("+10.0E+1"));
        ASSERT_EQUALS(-1	, MathLib::toLongNumber("-10.0E-1"));
    }

    void isint()
    {
		// zero tests
        ASSERT_EQUALS(true , MathLib::isInt("0"));
        ASSERT_EQUALS(false, MathLib::isInt("0."));
        ASSERT_EQUALS(false, MathLib::isInt("0.0"));
        ASSERT_EQUALS(false, MathLib::isInt("-0."));
        ASSERT_EQUALS(false, MathLib::isInt("+0."));
        ASSERT_EQUALS(false, MathLib::isInt("-0.0"));
        ASSERT_EQUALS(false, MathLib::isInt("+0.0"));
        ASSERT_EQUALS(false, MathLib::isInt("+0.0E+1"));
        ASSERT_EQUALS(false, MathLib::isInt("+0.0E-1"));
        ASSERT_EQUALS(false, MathLib::isInt("-0.0E+1"));
        ASSERT_EQUALS(false, MathLib::isInt("-0.0E-1"));

        ASSERT_EQUALS(true , MathLib::isInt("1"));	
        ASSERT_EQUALS(true , MathLib::isInt("-1"));	
        ASSERT_EQUALS(true , MathLib::isInt("+1"));
        ASSERT_EQUALS(true , MathLib::isInt("+1E+1"));
        ASSERT_EQUALS(true , MathLib::isInt("+1E+10000"));
        ASSERT_EQUALS(true , MathLib::isInt("-1E+1"));
        ASSERT_EQUALS(true , MathLib::isInt("-1E+10000"));
        ASSERT_EQUALS(false, MathLib::isInt("-1E-1"));
        ASSERT_EQUALS(false, MathLib::isInt("-1E-10000"));		
	
        ASSERT_EQUALS(true, MathLib::isInt("0xff"));
        ASSERT_EQUALS(true, MathLib::isInt("0xa"));
        ASSERT_EQUALS(true, MathLib::isInt("0l"));
        ASSERT_EQUALS(true, MathLib::isInt("0L"));
        ASSERT_EQUALS(true, MathLib::isInt("0ul"));
        ASSERT_EQUALS(true, MathLib::isInt("0ull"));
        ASSERT_EQUALS(true, MathLib::isInt("0llu"));
        ASSERT_EQUALS(true, MathLib::isInt("333L"));
        ASSERT_EQUALS(true, MathLib::isInt("330L"));
        ASSERT_EQUALS(true, MathLib::isInt("330llu"));
        ASSERT_EQUALS(true, MathLib::isInt("07"));
        ASSERT_EQUALS(true, MathLib::isInt("0123"));
        ASSERT_EQUALS(false, MathLib::isInt("0.4"));
        ASSERT_EQUALS(false, MathLib::isInt("2352.3f"));
        ASSERT_EQUALS(false, MathLib::isInt("0.00004"));
        ASSERT_EQUALS(false, MathLib::isInt("2352.00001f"));
        ASSERT_EQUALS(false, MathLib::isInt(".4"));
        ASSERT_EQUALS(false, MathLib::isInt("1.0E+1"));
        ASSERT_EQUALS(false, MathLib::isInt("1.0E-1"));
        ASSERT_EQUALS(false, MathLib::isInt("-1.0E+1"));
        ASSERT_EQUALS(false, MathLib::isInt("+1.0E-1"));
        ASSERT_EQUALS(false, MathLib::isInt("-1.E+1"));
        ASSERT_EQUALS(false, MathLib::isInt("+1.E-1"));
    }
};

REGISTER_TEST(TestMathLib)


