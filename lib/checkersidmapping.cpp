/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2024 Cppcheck team.
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
// This file is auto generated by script, do not edit
// Mappings of Cppcheck warning IDs to guidelines
#include "checkers.h"

std::vector<checkers::IdMapping> checkers::idMappingAutosar{
    {"m0-1-1", "unreachableCode,duplicateBreak"},
    {"m0-1-2", "unsignedLessThanZero"},
    {"m0-1-3", "unusedVariable,unusedStructMember"},
    {"a0-1-1", "unreadVariable,unusedValue,redundantAssignment"},
    {"m0-1-9", "redundantAssignment,redundantInitialization"},
    {"m0-1-10", "unusedFunction"},
    {"m0-2-1", "overlappingWriteUnion,overlappingWriteFunction"},
    {"a1-1-1", "g++ .."},
    {"a2-3-1", "The code contains unhandled character(s) (character code=195). Neither unicode nor extended ascii is supported. [syntaxError]"},
    {"a2-7-3", "doxygen,clang -Wdocumentation"},
    {"a2-10-1", "shadowVariable,shadowFunction,shadowArgument"},
    {"a2-13-2", "compile error"},
    {"a2-13-4", "compiler error"},
    {"m3-2-2", "ctuOneDefinitionRuleViolation"},
    {"m3-4-1", "variableScope"},
    {"a5-0-1", "-Wsequence-point"},
    {"m5-0-16", "pointerOutOfBounds"},
    {"m5-0-17", "comparePointers"},
    {"m5-0-18", "comparePointers"},
    {"a5-1-4", "returnDanglingLifetime"},
    {"a5-2-2", "cstyleCast"},
    {"a5-2-5", "arrayIndexOutOfBounds,arrayIndexOutOfBoundsCond,pointerOutOfBounds,pointerOutOfBoundsCond,negativeIndex,arrayIndexThenCheck,bufferAccessOutOfBounds,objectIndex,argumentSize"},
    {"m5-3-4", "sizeofFunctionCall"},
    {"a5-3-2", "nullPointer,nullPointerRedundantCheck,nullPointerArithmetic,nullPointerArithmeticRedundantCheck,nullPointerDefaultArg"},
    {"a5-6-1", "zerodiv,zerodivcond"},
    {"m5-8-1", "shiftTooManyBits"},
    {"m7-1-2", "constParameter"},
    {"a7-5-1", "returnDanglingLifetime"},
    {"m8-4-2", "funcArgNamesDifferent"},
    {"a8-4-2", "missingReturn"},
    {"a8-5-0", "uninitdata"},
    {"m9-3-3", "functionConst,functionStatic"},
    {"a12-1-1", "uninitMemberVar"},
    {"m12-1-1", "virtualCallInConstructor"},
    {"a12-1-4", "noExplicitConstructor"},
    {"a12-6-1", "useInitializationList"},
    {"a12-8-3", "accessMoved"},
    {"a15-1-4", "memleak"},
    {"m15-3-1", "exceptThrowInDestructor"},
    {"a15-4-2", "throwInNoexceptFunction"},
    {"m16-0-5", "preprocessorErrorDirective"},
    {"a16-2-2", "iwyu,check headers"},
    {"a18-5-3", "mismatchAllocDealloc"},
    {"a20-8-1", "doubleFree"},
    {"a23-0-2", "invalidContainer"},
};

std::vector<checkers::IdMapping> checkers::idMappingCertC{
    {"PRE30", "preprocessorErrorDirective"},
    {"PRE32", "preprocessorErrorDirective"},
    {"DCL30", "danglingLifetime,autoVariables,invalidLifetime,returnDanglingLifetime"},
    {"EXP30", "unknownEvaluationOrder"},
    {"EXP33", "uninitvar,uninitdata,uninitStructMember"},
    {"EXP34", "nullPointer,nullPointerDefaultArg,nullPointerRedundantCheck,nullPointerArithmetic,nullPointerArithmeticRedundantCheck"},
    {"EXP44", "sizeofCalculation"},
    {"EXP46", "bitwiseOnBoolean"},
    {"FLP32", "invalidFunctionArg"},
    {"FLP34", "floatConversionOverflow"},
    {"ARR36", "comparePointers"},
    {"STR30", "stringLiteralWrite"},
    {"STR37", "invalidFunctionArg"},
    {"MEM30", "doubleFree,deallocret,deallocuse"},
    {"MEM31", "memleak,leakReturnValNotUsed,leakUnsafeArgAlloc,memleakOnRealloc"},
    {"MEM34", "autovarInvalidDeallocation,mismatchAllocDealloc"},
    {"FIO39", "IOWithoutPositioning"},
    {"FIO42", "resourceLeak"},
    {"FIO46", "deallocuse,useClosedFile"},
    {"FIO47", "invalidscanf,wrongPrintfScanfArgNum,invalidLengthModifierError,invalidScanfFormatWidth,wrongPrintfScanfParameterPositionError"},
    {"MSC37", "missingReturn"},
};

std::vector<checkers::IdMapping> checkers::idMappingCertCpp{
    {"DCL57", "deallocThrow,exceptThrowInDestructor"},
    {"DCL60", "ctuOneDefinitionRuleViolation"},
    {"EXP52", "sizeofCalculation"},
    {"EXP53", "uninitvar"},
    {"EXP54", "uninitvar,danglingLifetime,danglingReference,danglingTemporaryLifetime,danglingTempReference,returnDanglingLifetime"},
    {"EXP61", "danglingLifetime,danglingReference,danglingTemporaryLifetime,danglingTempReference,returnDanglingLifetime"},
    {"EXP63", "accessMoved"},
    {"CTR51", "eraseDereference"},
    {"CTR54", "comparePointers"},
    {"CTR55", "containerOutOfBounds"},
    {"STR51", "nullPointer"},
    {"STR52", "invalidContainer"},
    {"MEM50", "deallocuse"},
    {"MEM51", "mismatchAllocDealloc"},
    {"MEM56", "doubleFree"},
    {"FIO50", "IOWithoutPositioning"},
    {"ERR57", "memleak"},
    {"OOP50", "virtualCallInConstructor"},
    {"OOP52", "virtualDestructor"},
    {"OOP53", "initializerList"},
    {"OOP54", "operatorEqToSelf"},
    {"MSC52", "missingReturn"},
};

std::vector<checkers::IdMapping> checkers::idMappingMisraC{
    {"1.1", "syntaxError"},
    {"1.3", "error"},
    {"2.1", "duplicateBreak,unreachableCode"},
    {"2.2", "redundantCondition,redundantAssignment,redundantAssignInSwitch,unreadVariable"},
    {"2.6", "unusedLabel"},
    {"2.8", "unusedVariable"},
    {"5.3", "shadowVariable"},
    {"8.3", "funcArgNamesDifferent"},
    {"8.13", "constParameterPointer"},
    {"9.1", "uninitvar"},
    {"12.5", "sizeofwithsilentarraypointer"},
    {"13.2", "unknownEvaluationOrder"},
    {"13.6", "sizeofCalculation"},
    {"14.3", "compareValueOutOfTypeRangeError,knownConditionTrueFalse"},
    {"17.4", "missingReturn"},
    {"17.5", "argumentSize"},
    {"18.1", "pointerOutOfBounds"},
    {"18.2", "comparePointers"},
    {"18.3", "comparePointers"},
    {"18.6", "danglingLifetime,danglingTemporaryLifetime,returnDanglingLifetime"},
    {"19.1", "overlappingWriteUnion,overlappingWriteFunction"},
    {"20.6", "preprocessorErrorDirective"},
    {"21.13", "invalidFunctionArg"},
    {"21.17", "bufferAccessOutOfBounds"},
    {"21.18", "bufferAccessOutOfBounds"},
    {"22.1", "memleak,resourceLeak,memleakOnRealloc,leakReturnValNotUsed,leakNoVarFunctionCall"},
    {"22.2", "autovarInvalidDeallocation"},
    {"22.3", "incompatibleFileOpen"},
    {"22.4", "writeReadOnlyFile"},
    {"22.6", "useClosedFile"},
};

std::vector<checkers::IdMapping> checkers::idMappingMisraCpp2008{
    {"0-1-1", "unreachableCode,duplicateBreak"},
    {"0-1-2", "unsignedLessThanZero"},
    {"0-1-3", "unusedVariable,unusedStructMember"},
    {"0-1-6", "redundantAssignment,unreadVariable,variableScope"},
    {"0-1-9", "redundantAssignment,redundantInitialization"},
    {"0-1-10", "unusedFunction"},
    {"0-2-1", "overlappingWriteUnion,overlappingWriteFunction"},
    {"2-10-2", "shadowVariable"},
    {"3-2-2", "ctuOneDefinitionRuleViolation"},
    {"3-4-1", "variableScope"},
    {"5-0-1", "unknownEvaluationOrder"},
    {"5-0-16", "pointerOutOfBounds"},
    {"5-0-17", "comparePointers"},
    {"5-0-18", "comparePointers"},
    {"5-2-4", "cstyleCast"},
    {"5-3-4", "sizeofFunctionCall"},
    {"5-8-1", "shiftTooManyBits"},
    {"7-1-1", "constVariable,constParameter"},
    {"7-1-2", "constParameter"},
    {"7-5-1", "autoVariables,returnReference,returnTempReference"},
    {"7-5-2", "danglingLifetime"},
    {"8-4-2", "funcArgNamesDifferent"},
    {"8-4-3", "missingReturn"},
    {"8-5-1", "uninitvar,uninitdata,uninitStructMember,uninitMemberVar,uninitMemberVarPrivate,uninitDerivedMemberVar,uninitDerivedMemberVarPrivate"},
    {"9-3-3", "functionConst,functionStatic"},
    {"12-1-1", "virtualCallInConstructor"},
    {"12-1-3", "noExplicitConstructor"},
    {"15-3-1", "exceptThrowInDestructor"},
    {"15-5-1", "exceptThrowInDestructor"},
    {"15-5-3", "exceptThrowInDestructor"},
    {"16-0-5", "preprocessorErrorDirective"},
};

std::vector<checkers::IdMapping> checkers::idMappingMisraCpp2023{
    {"0.0.1", "unreachableCode"},
    {"0.0.2", "compareBoolExpressionWithInt,compareValueOutOfTypeRangeError,identicalConditionAfterEarlyExit,identicalInnerCondition,knownConditionTrueFalse"},
    {"0.1.1", "redundantAssignInSwitch,redundantAssignment,redundantCopy,redundantInitialization,unreadVariable"},
    {"Dir 0.3.2", "invalidFunctionArg,invalidFunctionArgBool,invalidFunctionArgStr"},
    {"4.1.3", "error"},
    {"4.6.1", "unknownEvaluationOrder"},
    {"6.2.1", "ctuOneDefinitionRuleViolation"},
    {"6.4.1", "shadowVariable"},
    {"6.8.1", "danglingLifetime"},
    {"6.8.2", "autoVariables"},
    {"8.7.1", "pointerOutOfBounds,pointerOutOfBoundsCond"},
    {"8.7.2", "subtractPointers"},
    {"8.9.1", "comparePointers"},
    {"8.18.1", "overlappingWriteUnion"},
    {"9.6.5", "missingReturn"},
    {"10.1.1", "constParameter,constParameterReference"},
    {"11.6.2", "uninitvar"},
    {"15.1.1", "virtualCallInConstructor"},
    {"15.1.4", "uninitMemberVar"},
    {"Dir 15.8.1", "operatorEqToSelf"},
    {"19.3.5", "preprocessorErrorDirective"},
    {"28.6.3", "accessForwarded,accessMoved"},
    {"28.6.4", "ignoredReturnValue"},
};
