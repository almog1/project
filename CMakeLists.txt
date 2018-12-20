cmake_minimum_required(VERSION 3.12)
project(progect)

set(CMAKE_CXX_STANDARD 14)

add_executable(progect main.cpp Expression.cpp Expression.h Var.cpp Var.h Number.cpp Number.h Plus.cpp Plus.h Pow.cpp Pow.h Mult.cpp Mult.h Minus.cpp Minus.h Div.cpp Div.h Command.cpp Command.h BinaryExpression.cpp BinaryExpression.h Var.cpp Var.h ExpressionHeaders.h expressionDetect.cpp expressionDetect.h Reader.cpp Reader.h OpenDataServer.cpp OpenDataServer.h ConnectCommand.cpp ConnectCommand.h VarCommand.cpp VarCommand.h Parser.cpp Parser.h OtherFunctions.cpp OtherFunctions.h CommandExpression.cpp CommandExpression.h openSocket.cpp openSocket.h)