//
// Created by aldes on 15.12.2021.
//

#ifndef LAB6_MESSAGETYPES_H
#define LAB6_MESSAGETYPES_H


enum class MessageTypes : int {
    CREATE_REQUEST,
    CREATE_RESULT,
    CREATE_FAIL,
    EXEC_REQUEST,
    EXEC_RESULT,
    EXEC_FAIL,
    HEARTBIT_REQUEST,
    HEARTBIT_RESULT,
    HEARTBIT_FAIL,
    RELATE_RESULT,
    RELATE_REQUEST,
    QUIT,
    EMPTY,
    TEST,
};

#endif //LAB6_MESSAGETYPES_H