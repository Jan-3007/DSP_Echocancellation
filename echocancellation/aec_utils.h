#pragma once


enum aec_status
{
    SUCCESS                 =  0,        // No error 
    ERROR                   = -1,        // general error
    ARGUMENT_ERROR          = -2,        // One or more arguments are incorrect 
    LENGTH_ERROR            = -3,        // Length of data buffer is incorrect 
    BUFFER_ERROR            = -4,        // Error while writing to or reading from buffer
};







