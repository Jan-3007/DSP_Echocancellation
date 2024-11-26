#pragma once






class AEC
{
protected:
    // LMS filter
    LMSFilter lms_;


    // flag for de-/activating the AEC
    bool aec_active_ {false};



public:
    void
    init();

    void
    run();

protected:
    void
    update_aec_flag();


};

