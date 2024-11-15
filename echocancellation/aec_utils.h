#pragma once


enum aec_status
{
    SUCCESS                 =  0,        // No error 
    ARGUMENT_ERROR          = -1,        // One or more arguments are incorrect 
    LENGTH_ERROR            = -2,        // Length of data buffer is incorrect 
    BUFFER_ERROR            = -3,        // Error while writing to or reading from buffer
};

